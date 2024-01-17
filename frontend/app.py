from flask import Flask, render_template, Response, send_from_directory, request, jsonify, redirect, url_for
import cv2

app = Flask(__name__)

def detect_fire():
    return True 

def generate_frames():
    camera = cv2.VideoCapture(0)  # Use 0 for default camera
    while True:
        success, frame = camera.read()
        if not success:
            break
        else:
            ret, buffer = cv2.imencode('.jpg', frame)
            frame = buffer.tobytes()
            yield (b'--frame\r\n'
                   b'Content-Type: image/jpeg\r\n\r\n' + frame + b'\r\n')
    camera.release()

@app.route('/')
def index():
    temperature_value = 20
    return render_template('index.html', temperature=temperature_value)

@app.route('/video_feed')
def video_feed():
    return Response(generate_frames(), mimetype='multipart/x-mixed-replace; boundary=frame')

@app.route('/static/<path:path>')
def send_static(path):
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

@app.route('/trigger-warning')
def trigger_warning():
    if detect_fire():
        print("Fire Detected!")
        return jsonify(message="Fire Detected! Check the console for details."), 200
    else:
        return jsonify(message="No fire detected."), 200

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)

