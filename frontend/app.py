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
import os
from std_msgs.msg import Int64,String,Empty


#! /usr/bin/env python3

import rclpy
from rclpy.node import Node 
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2 
import sys


SLAM = 0
LOCALIZATION = 1
MAPS_FILE_PATH = "/home/qty/ros2_ws/frontend/maps"
TEMP_MAPS_FILE_PATH = "/home/qty/ros2_ws/frontend/static"

def sigint_handler(signal, frame):

    rclpy.shutdown()
    if prev_sigint_handler is not None:
        prev_sigint_handler(signal)
    sys.exit(0)



def on_image(msg):
    global frame
    print("Image Received")
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
subscription = node.create_subscription(Image,"/fire_detection_image", on_image,10) # Creating the Subscribe node



# Set Publishers 
save_map_publisher = node.create_publisher(String, '/hoverboard_controller/save_map',10)
save_heatmap_publisher = node.create_publisher(String, '/hoverboard_controller/save_heatmap',10)
save_heatmap_normal_publisher = node.create_publisher(String, '/hoverboard_controller/save_map_normal',10)
start_slam_publisher = node.create_publisher(Empty, '/hoverboard_controller/launch_slam',10)
reset_slam_publisher = node.create_publisher(Empty , '/hoverboard_controller/reset_slam',10)
reset_heatmap_publisher = node.create_publisher(Empty , '/hoverboard_controller/reset_heatmap',10)
start_localization_publisher = node.create_publisher(String, '/hoverboard_controller/launch_localization',10)
load_heatmap_publisher = node.create_publisher(String, '/hoverboard_controller/load_heatmap',10)
mode_publisher = node.create_publisher(Int64,"/robot_mode",10)


mode_msg = Int64()
string_msg = String()
empty_msg = Empty()
# while not serialize_client.wait_for_service(timeout_sec=1.0):
#     node.get_logger().info('service not available, waiting again...')

# while not map_client.wait_for_service(timeout_sec=1.0):
#     node.get_logger().info('service not available, waiting again...')

# while not heatmap_client.wait_for_service(timeout_sec=1.0):
#     node.get_logger().info('service not available, waiting again...')

# Create Messages


# TMP Service Message

map_file_path = TEMP_MAPS_FILE_PATH + "/map"
heatmap_file_path = TEMP_MAPS_FILE_PATH + "/heatmap"

# Set the map path for the gui
map_filename = map_file_path + ".png"
heatmap_filename = heatmap_file_path + ".png"



app = Flask(__name__)
prev_sigint_handler = signal.signal(signal.SIGINT, sigint_handler)

mode = None


def get_frame():
    rclpy.spin_once(node,timeout_sec=1.0)
    event.wait()
    event.clear()
    return frame


def detect_fire():
    return True 


def generate_frames():
    while True:
        print("Generating")
        frame = get_frame()
        yield (b'--frame\r\n'
                b'Content-Type: image/jpeg\r\n\r\n' + frame + b'\r\n')


@app.route('/')
def index():
    temperature_value = 20
    return render_template('index.html', temperature=temperature_value)

@app.route('/video_feed')
def video_feed():
    print("Video Feed")
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
def get_map(): 
    # Use os.path.basename to get the file name from the path
    image_name = os.path.basename(map_filename)
    image_directory = os.path.dirname(map_filename)  

    return send_from_directory(image_directory, image_name)

@app.route('/static/heat_map')
def get_heatmap():  

    # Use os.path.basename to get the file name from the path
    image_name = os.path.basename(heatmap_filename)
    image_directory = os.path.dirname(heatmap_filename)   
    return send_from_directory(image_directory, image_name)  


@app.route('/maps')
def get_map_files():
    map_files = os.listdir('/home/qty/ros2_ws/frontend/maps')

    return jsonify(map_files)

@app.route('/load-button', methods=['POST'])
def handle_load_button():
    global selected_map
    selected_map = request.form['selectedMap']
    print("Loading: ",selected_map)

    mode_msg.data = LOCALIZATION
    mode_publisher.publish(mode_msg)

    # Load Heat Map
    string_msg.data = MAPS_FILE_PATH + "/"+ selected_map + "/" + "heatmap.yaml"
    load_heatmap_publisher.publish(string_msg)

    # Start AMCL Localization
    string_msg.data = MAPS_FILE_PATH + "/"+ selected_map + "/" + "map.yaml"
    start_localization_publisher.publish(string_msg)

    return redirect(url_for('index'))


@app.route('/save_maps_temp')
def save_maps_temp():
    print("Saving To Temp")

    string_msg.data = map_file_path
    save_map_publisher.publish(string_msg)

    string_msg.data = heatmap_file_path
    save_heatmap_publisher.publish(string_msg)

    return redirect(url_for('index'))
        


@app.route("/navigation")
def navigation(filename):
    # print("Starting Navigation Change Robot Mode To Local ization")
    mode_msg.data = LOCALIZATION
    mode_publisher.publish(mode_msg)
    return redirect(url_for('index'))

@app.route("/mapping")
def mapping():
    # Start Slam
    mode_msg.data = SLAM
    mode_publisher.publish(mode_msg)
    start_slam_publisher.publish(empty_msg)
    return redirect(url_for('index'))

@app.route('/start-button', methods=['POST'])
def start_button():
    selected_option = request.form['select-option']
    if selected_option == 'Navigation':
        return navigation()
    else:
        return mapping()

@app.route('/reset-button', methods=['POST'])
def reset_button():
    reset_slam_publisher.publish(empty_msg)
    reset_heatmap_publisher.publish(empty_msg)
    return redirect(url_for('index'))

@app.route('/save-map/<file_name>', methods=['POST'])
def save_map(file_name):
    # print("Saving Map To: ",file_name)
    file_path = MAPS_FILE_PATH + "/" +file_name
    # Create the file in maps
    try:
        os.mkdir(file_path)
    except Exception as e:
        print("Exception: ",e)
        return redirect(url_for('index'))    

    string_msg.data = file_path + "/" + "map"
    save_map_publisher.publish(string_msg)
    
    string_msg.data = file_path + "/" + "heatmap"
    save_heatmap_normal_publisher.publish(string_msg)
    
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

