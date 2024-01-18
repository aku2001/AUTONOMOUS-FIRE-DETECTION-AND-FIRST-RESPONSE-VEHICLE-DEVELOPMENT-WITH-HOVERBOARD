from flask import Flask, render_template, Response, send_from_directory, request, jsonify, redirect, url_for
import cv2
import rclpy
from rclpy.node import Node 
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from threading import Thread, Event
import signal
from slam_toolbox.srv import SerializePoseGraph,SaveMap
from std_msgs.msg import String
import imageio.v2 as imageio


#! /usr/bin/env python3

import rclpy
from rclpy.node import Node 
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2 
import sys

def sigint_handler(signal, frame):
    """
    SIGINT handler

    We have to know when to tell rclpy to shut down, because
    it's in a child thread which would stall the main thread
    shutdown sequence. So we use this handler to call
    rclpy.shutdown() and then call the previously-installed
    SIGINT handler for Flask
    """
    rclpy.shutdown()
    if prev_sigint_handler is not None:
        prev_sigint_handler(signal)
    sys.exit(0)



def on_image(msg):
    global frame
    
    cv_image = bridge.imgmsg_to_cv2(msg, desired_encoding = "passthrough")
    frame = cv2.imencode(".jpg",cv_image)[1].tobytes()
    event.set()


frame = None # Global variable frame (the holy image)

# Objects of cvbridge and event
bridge = CvBridge()
event = Event()

rclpy.init(args=None)
node = rclpy.create_node('Show_image_python')
Thread(target=lambda:node).start()

# Create subscriptions and services
subscription = node.create_subscription(Image,"/fire_detection_image", on_image, 10) # Creating the Subscribe node
serialize_client = node.create_client(SerializePoseGraph, '/slam_toolbox/serialize_map')
map_client = node.create_client(SaveMap, '/slam_toolbox/save_map')

# while not serialize_client.wait_for_service(timeout_sec=1.0):
#     node.get_logger().info('service not available, waiting again...')

# while not map_client.wait_for_service(timeout_sec=1.0):
#     node.get_logger().info('service not available, waiting again...')

# Create Messages
serialize_map_req = SerializePoseGraph.Request()
save_map_req = SaveMap.Request()
name = String()
name.data = "/home/qty/ros2_ws/src/frontend/static/map"

serialize_map_req.filename = "/home/qty/ros2_ws/src/frontend/maps/map1"
save_map_req.name = name

app = Flask(__name__)
prev_sigint_handler = signal.signal(signal.SIGINT, sigint_handler)

def get_frame():
    rclpy.spin_once(node,timeout_sec=1.0)
    event.wait()
    event.clear()
    return frame


def detect_fire():
    return True 


def generate_frames():
    while True:
        frame = get_frame()
        yield (b'--frame\r\n'
                b'Content-Type: image/jpeg\r\n\r\n' + frame + b'\r\n')


@app.route('/')
def index():
    temperature_value = 20
    return render_template('index.html', temperature=temperature_value)

@app.route('/video_feed')
def video_feed():
    return Response(generate_frames(), mimetype='multipart/x-mixed-replace; boundary=frame')

# @app.route('/static/<path:path>')
# def send_static(path):
#     print("Hereeeeee: ",path)
#     try:
#         # Read the PGM image using imageio
#         image = imageio.imread(path, format='PGM')
#         # Save the image as JPG
#         imageio.imwrite(path, image, format='JPEG')
#     except Exception as e:
#         print(e)
#     return send_from_directory('static', path)

@app.route('/static/map')
def static_deneme():
    path = "static/map"
    print("Hereeeeee: ",path)
    try:
        # Read the PGM image using imageio
        image = imageio.imread(path+".pgm", format='PGM')
        # Save the image as JPG
        imageio.imwrite(path+".jpg", image, format='JPEG')
    except Exception as e:
        print(e)
    return send_from_directory('static', path)

@app.route("/navigation")
def navigation():
    return redirect(url_for('index'))

@app.route("/mapping")
def mapping():
    return redirect(url_for('index'))

@app.route('/start-button', methods=['POST'])
def start_button():
    selected_option = request.form['select-option']
    if selected_option == 'Navigation':
        return navigation()
    else:
        return mapping()

@app.route('/stop-button', methods=['POST'])
def stop_button():
    return redirect(url_for('index'))

@app.route('/save-button', methods=['POST'])
def save_button():
    print("Saving Map")
    future = serialize_client.call_async(serialize_map_req)
    rclpy.spin_until_future_complete(node, future)
    future = map_client.call_async(save_map_req)
    rclpy.spin_until_future_complete(node, future)
    return redirect(url_for('index'))

@app.route('/trigger-warning')
def trigger_warning():
    if detect_fire():
        print("Fire Detected!")
        return jsonify(message="Fire Detected! Check the console for details."), 200
    else:
        return jsonify(message="No fire detected."), 200

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)

