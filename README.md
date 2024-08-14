# Smart Temperature-Controlled Fan System

This project is a simple yet effective embedded system that monitors the ambient temperature using a DHT11 sensor and controls a fan based on the temperature readings. The system includes an LCD display to show the current temperature and the status of the fan. This project is ideal for demonstrating skills in embedded systems, sensor integration, and basic control logic.

## Features

- **Real-time Temperature Monitoring:** Continuously monitors the temperature using a DHT11 sensor.
- **Automatic Fan Control:** Automatically turns the fan on or off based on a predefined temperature threshold.
- **LCD Display:** Displays the current temperature and the fan status on a 16x2 LCD screen.
- **User-Friendly Interface:** Provides clear and simple output on the LCD, including a personalized welcome message.

## Components

- **Arduino Board (e.g., Uno, Nano)**
- **DHT11 Temperature and Humidity Sensor**
- **16x2 I2C LCD Display**
- **Fan (or LED for simulation)**
- **Resistors (as needed)**
- **Wires and Breadboard**

## Pin Configuration

- **DHT11 Sensor:** Data pin connected to `Pin 7`.
- **Fan Control:** Fan control pin connected to `Pin 8`.
- **LCD Display:** Connected via I2C interface (SDA and SCL pins).

## Code Overview

The code is divided into the following main sections:

1. **Initialization:**
   - Setup of the LCD display and pin modes.
   - A welcome message is displayed at startup.

2. **Main Loop:**
   - Reads the current temperature using the DHT11 sensor.
   - Displays the temperature and fan status on the LCD.
   - Controls the fan based on the temperature threshold.

3. **Functions:**
   - `readTemperature()`: Reads and returns the temperature from the DHT11 sensor.
   - `displayTemperature(float temp)`: Updates the LCD with the current temperature and fan status.
   - `controlFan(float temp)`: Turns the fan on or off based on the temperature.

## How to Use

1. **Hardware Setup:**
   - Connect the DHT11 sensor and fan/LED to the Arduino as per the pin configuration.
   - Connect the 16x2 LCD display via I2C.

2. **Upload the Code:**
   - Open the Arduino IDE and upload the provided code to your Arduino board.

3. **Operation:**
   - Once the system starts, the LCD will display a welcome message followed by real-time temperature and fan status updates.
   - If the temperature exceeds 28°C, the fan will turn on automatically; otherwise, it will remain off.

## Customization

- **Temperature Threshold:** Adjust the `tempThreshold` variable in the code to change the temperature at which the fan turns on/off.
- **LCD Messages:** Modify the LCD messages to personalize or change the displayed text.
- **Fan Control:** Replace the fan with another actuator (like an LED) for different projects or testing scenarios.

## Future Enhancements

- **Remote Monitoring:** Add Wi-Fi capabilities to monitor and control the system remotely.
- **Data Logging:** Implement data logging to keep track of temperature changes over time.
- **Enhanced Control:** Introduce more sensors and actuators, like humidity control or multiple fans.

## License

This project is open-source and available under the MIT License.

## Author

- **Navida Wimalaweera** - Software Engineering Student at the University of Westminster.

## Acknowledgments

- Special thanks to the Arduino community for their extensive documentation and tutorials.

