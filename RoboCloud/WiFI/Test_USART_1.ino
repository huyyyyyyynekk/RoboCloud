#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

const char* ssidAP = "ESP32-Access-Point";
const char* passwordAP = "123456789";

AsyncWebServer server(80);

String wifi_ssid;
String wifi_password;

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Step Up Robot - Wi-Fi Connect</title>
    <link href="https://cdn.jsdelivr.net/npm/tailwindcss@2.2.19/dist/tailwind.min.css" rel="stylesheet">
    <style>
        .bg-gradient {
            background: linear-gradient(to bottom right, #9c27b0, #e91e63, #f44336);
        }
        .card-bg {
            background: rgba(255, 255, 255, 0.2);
            backdrop-filter: blur(10px);
        }
        .input-icon {
            top: 50%;
            transform: translateY(-50%);
        }
        .connect-button {
            background: linear-gradient(to right, #9c27b0, #e91e63);
            transition: all 0.3s;
        }
        .connect-button:hover {
            background: linear-gradient(to right, #7b1fa2, #c2185b);
        }
        .geometric-pattern {
            background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' width='20' height='20' viewBox='0 0 20 20'%3E%3Cpath d='M20 0L0 0 0 20' fill='none' stroke='white' stroke-width='0.5' opacity='0.5'/%3E%3C/svg%3E");
            opacity: 0.1;
        }
    </style>
</head>
<body class="min-h-screen flex items-center justify-center bg-gradient">
    <div class="relative w-full max-w-md p-8 card-bg rounded-3xl shadow-xl">
        <div class="relative z-10">
            <div class="flex justify-center mb-6">
                <svg class="w-48 h-16" viewBox="0 0 240 80" fill="none" xmlns="http://www.w3.org/2000/svg">
                    <rect width="240" height="80" rx="8" fill="url(#paint0_linear)"/>
                    <text x="20" y="55" fill="white" font-size="36" font-family="Arial" font-weight="bold">SU - ROBOT</text>
                    <defs>
                        <linearGradient id="paint0_linear" x1="0" y1="0" x2="240" y2="80" gradientUnits="userSpaceOnUse">
 <stop stop-color="#9C27B0"/>
                            <stop offset="0.5" stop-color="#E91E63"/>
                            <stop offset="1" stop-color="#F44336"/>
                        </linearGradient>
                    </defs>
                </svg>
                
            </div>
            <h1 class="text-3xl font-bold text-center mb-8 text-white">Connect to Wi-Fi</h1>
            <form id="wifiForm" class="space-y-6">
                <div class="space-y-2">
                    <label for="ssid" class="block text-sm font-medium text-white">
                        Wi-Fi Name (SSID)
                    </label>
                    <div class="relative">
                        <svg class="absolute left-3 input-icon w-5 h-5 text-gray-400" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M8.111 16.404a5.5 5.5 0 017.778 0M12 20h.01m-7.08-7.071c3.904-3.905 10.236-3.905  14.14 0M1.394 9.393c5.857-5.857 15.355-5.857 21.213 0" />
                        </svg>
                        <input id="ssid" type="text" class="pl-10 pr-10 py-2 w-full bg-white bg-opacity-50 rounded-lg focus:ring-2 focus:ring-purple-600" placeholder="Enter Wi-Fi name" required>
                        <svg class="absolute right-3 input-icon w-5 h-5 text-gray-400 cursor-help" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M13 16h-1v-4h-1m1-4h.01M21 12a9 9 0 11-18 0 9 9 0 0118 0z" />
                        </svg>
                    </div>
                </div>
                <div class="space-y-2">
                    <label for="password" class="block text-sm font-medium text-white">
                        Password
                    </label>
                    <div class="relative">
                        <svg class="absolute left-3 input-icon w-5 h-5 text-gray-400" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M12 15v2m-6 4h12a2 2 0 002-2v-6a2 2 0 00-2-2H6a2 2 0 00-2 2v6a2 2 0 002 2zm10-10V7a4 4 0 00-8 0v4h8z" />
                        </svg>
                        <input id="password" type="password" class="pl-10 pr-10 py-2 w-full bg-white bg-opacity-50 rounded-lg focus:ring-2 focus:ring-purple-600" placeholder="Enter Wi-Fi password" required>
                        <svg class="absolute right-3 input-icon w-5 h-5 text-gray-400 cursor-help" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M13 16h-1v-4h-1m1-4h.01M21 12a9 9 0 11-18 0 9 9 0 0118 0z" />
                        </svg>
                    </div>
                </div>
                <button type="submit" class="w-full py-3 px-4 connect-button text-white font-semibold rounded-lg shadow-md focus:outline-none focus:ring-2 focus:ring-purple-500 focus:ring-opacity-75">
                    Connect
                </button>
            </form>
        </div>
        <div class="absolute inset-0 geometric-pattern rounded-3xl" style="z-index: -1;"></div>
    </div>

    <script>
        window.onload = function() {
            document.getElementById ('wifiForm').addEventListener('submit', function(e) {
                e.preventDefault();
                const ssid = document.getElementById('ssid').value;
                const password = document.getElementById('password').value;
                console.log('Connecting to:', ssid);
                // Handle connection logic here
            });

            // Simple tooltip functionality
            const infoIcons = document.querySelectorAll('.cursor-help');
            infoIcons.forEach(icon => {
                icon.addEventListener('mouseenter', function(e) {
                    const tooltip = document.createElement('div');
                    tooltip.className = 'absolute bg-black text-white text-xs rounded py-1 px-2 right-0 bottom-full mb-2';
                    tooltip.textContent = this.closest('.space-y-2').querySelector('label').textContent;
                    this.appendChild(tooltip);
                });
                icon.addEventListener('mouseleave', function(e) {
                    const tooltip = this.querySelector('div');
                    if (tooltip) tooltip.remove();
                });
            });
        }
    </script>
</body>
</html>
)rawliteral";

void setup() {
  Serial.begin(115200);
  
  WiFi.softAP(ssidAP, passwordAP);
  Serial.println("Access Point ");
  Serial.print("IP Access Point: ");
  Serial.println(WiFi.softAPIP());
  
  server.on("/connect", HTTP_POST, [](AsyncWebServerRequest *request){
    if (request->hasParam("ssid", true) && request->hasParam("password", true)) {
      wifi_ssid = request->getParam("ssid", true)->value();
      wifi_password = request->getParam("password", true)->value();
      request->send(200, "text/plain", "Ðang ket noi...");
      
      WiFi.begin(wifi_ssid.c_str(), wifi_password.c_str());
      Serial.println("Connecting with WiFi...");
      int maxAttempts = 10; 
      int attempts = 0;

      while (WiFi.status() != WL_CONNECTED && attempts < maxAttempts) {
        delay(1000);
        Serial.println("Try agian...");
        attempts++;
      }

      if (WiFi.status() == WL_CONNECTED) {
        Serial.println("Connected!");
        Serial.print("IP: ");
        Serial.println(WiFi.localIP()); 
        
        request->send(200, "text/plain", "Connected! IP: " + WiFi.localIP().toString());
      } else {
        Serial.println("Fail Connected!");
        request->send(200, "text/plain", "Fail!Please try again1");
      }
      
    } else {
      request->send(400, "text/plain", "SSID or Passowrd failed!");
    }
  });
  
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });

  server.begin();
}

void loop() {
}
