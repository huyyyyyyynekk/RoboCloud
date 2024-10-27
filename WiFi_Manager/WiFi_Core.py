from flask import Flask, render_template_string, request
import subprocess

app = Flask(__name__)

@app.route('/')
def index():
    return render_template_string('''
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>ESP32 Firmware Uploader</title>
        <style>
            body { font-family: Arial, sans-serif; }
            #result { margin-top: 20px; }
        </style>
    </head>
    <body>
        <h1>Upload ESP32 Firmware</h1>
        <label for="com-port">Select COM Port:</label>
        <select id="com-port">
            <option value="COM3">COM3</option>
            <option value="COM4">COM4</option>
            <option value="COM5">COM5</option>
            <!-- Thêm các cổng khác nếu cần -->
        </select><br><br>

        <label for="file-path">Enter the path to the .bin file:</label>
        <input type="text" id="file-path" placeholder="C:\\path\\to\\file.bin"><br><br>

        <button id="upload-button" onclick="uploadFirmware()">UPLOAD</button>
        <div id="result"></div>

        <script>
            async function uploadFirmware() {
                const comPort = document.getElementById('com-port').value;
                const filePath = document.getElementById('file-path').value;

                const response = await fetch('/upload', {
                    method: 'POST',
                    headers: {
                        'Content-Type': 'application/json'
                    },
                    body: JSON.stringify({ comPort: comPort, filePath: filePath })
                });

                const resultDiv = document.getElementById('result');
                const result = await response.text();
                resultDiv.innerHTML = '<pre>' + result + '</pre>';
            }
        </script>
    </body>
    </html>
    ''')

@app.route('/upload', methods=['POST'])
def upload():
    data = request.json
    com_port = data['comPort']
    file_path = data['filePath']

    command = [
        'python', '-m', 'esptool',
        '--chip', 'esp32',
        '--port', com_port,
        'write_flash', '-z', '0x10000',
        file_path
    ]

    try:
        result = subprocess.run(command, check=True, capture_output=True, text=True)
        return f"Upload Success!\n{result.stdout}"
    except subprocess.CalledProcessError as e:
        return f"Execution command failed: {e.stderr}"
    except FileNotFoundError:
        return "File Not Found. Please check your link or install esptool."
    except Exception as e:
        return f"Error: {e}"


if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)
