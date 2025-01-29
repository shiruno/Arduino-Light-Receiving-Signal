## Arduino-Light-Receiving-Signal
![image](https://github.com/user-attachments/assets/d1b949f2-cfa6-45db-af95-96c4e235f882)

### Arduino
1. Functions
   - `setup() Function`: This function runs once when the Arduino is powered on or reset. It sets pin 13 as an output (where the LED is connected) and initializes serial communication at a baud rate of 9600.
   - `loop() Function`: This function runs continuously after setup(). It checks if there is any data available on the serial port. If data is available, it reads a character:
     -  If the character is `'1'`, it turns the LED on by setting pin 13 to HIGH.
     -  If the character is `'0'`, it turns the LED off by setting pin 13 to LOW.
### Python (light.py)
- This script establishes a serial connection to the Arduino on the specified port (e.g., `COM5`).
- It waits for 2 seconds to allow the Arduino to initialize.
- It sends the command `'1'` to turn the LED on and then waits for 1 second before sending the command `'0'` to turn the LED off.
- It includes error handling to catch any exceptions related to the serial connection.

### Python (api.py)
- **FastAPI Setup**: This part sets up a FastAPI application that can handle HTTP requests.'
- **Global Serial Connection**: A global variable arduino is used to maintain the serial connection to the Arduino.
- **Startup Event**: When the FastAPI application starts, it attempts to establish a serial connection to the Arduino. If successful, it prints a confirmation message.
- **Shutdown Event**: When the application shuts down, it closes the serial connection if it is open.
- **API Endpoints**:
  -  `/led/on`: This endpoint listens for POST requests to turn the LED on. It sends the command '1' to the Arduino and returns a success message.
  -  `/led/off`: This endpoint listens for POST requests to turn the LED off. It sends the command '0' to the Arduino and returns a success message.

When the FastAPI application is running, users can send HTTP POST requests to turn the LED on or off. The Arduino processes these commands and controls the LED accordingly, allowing for remote control via a web interface.
