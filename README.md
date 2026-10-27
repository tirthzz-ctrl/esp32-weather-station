# ESP32 Low-Cost Weather Station

A low-cost, ESP32-based weather and atmospheric pressure monitoring station. This project reads real-time temperature, pressure, and estimated altitude using a BMP180 sensor and displays the data simultaneously on a Serial Monitor and a 16x2 I2C LCD. It also features a hardware push-button to toggle the display modes.

## Features
* **Real-Time Monitoring:** Measures temperature (°C), atmospheric pressure (hPa), and estimated altitude (m).
* **Dual Output:** Data is sent to the Serial Monitor and a green 16x2 I2C LCD display.
* **Interactive Interface:** A push-button toggles the LCD view between Pressure and Altitude data streams.
* **Debounced Input:** Includes software debouncing for reliable button state changes.

## Hardware Requirements
* ESP32 Development Board
* BMP180 Barometric Pressure & Temperature Sensor
* 16x2 LCD Display with I2C Backpack
* Push Button
* Jumper Wires & Breadboard

## Wiring & Pinout

| Component | Pin | ESP32 Pin | Note |
| :--- | :--- | :--- | :--- |
| **BMP180 & LCD** | SDA | GPIO 21 | Shared I2C Data line |
| **BMP180 & LCD** | SCL | GPIO 22 | Shared I2C Clock line |
| **BMP180 & LCD** | VCC | 3.3V or 5V / VIN | Power |
| **BMP180 & LCD** | GND | GND | Ground |
| **Push Button** | Leg 1 | GPIO 4 | Trigger (Uses internal pull-up) |
| **Push Button** | Leg 2 | GND | Ground |

## Software & Libraries
This project is built using the Arduino framework. Ensure the following libraries are installed via the Arduino IDE Library Manager:
* `Adafruit_BMP085` (Fully compatible with the BMP180 sensor)
* `LiquidCrystal_I2C` by Frank de Brabander

## Setup Instructions
1. Wire the components according to the pinout table above.
2. Open the main `.ino` sketch in the Arduino IDE or Wokwi simulator.
3. Install the required libraries if running locally.
4. Select your ESP32 board and appropriate COM port from the Tools menu.
5. Compile and upload the code.
6. Open the Serial Monitor at `115200` baud rate to view the raw data logs.

## Future Enhancements Roadmap
* **IoT Web Server:** Connect to Wi-Fi to host a local web server for
<img width="961" height="718" alt="image" src="https://github.com/user-attachments/assets/48dd47bf-ccf8-47ee-b4dc-b1760b78a844" />

<img width="956" height="767" alt="image" src="https://github.com/user-attachments/assets/375fe7af-128d-446e-8059-0136753c6acf" />
