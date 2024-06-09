# Advance-Farming-ML

## Overview
Advance-Farming-ML utilizes multiple sensors to gather soil and environmental data, including soil moisture sensor, rain sensor, DHT11, pH sensor, water pump, and ESP32. The web interface, developed with HTML, JavaScript, and Tailwind CSS, provides real-time monitoring and control. Firebase is used for database management. Additionally, the project incorporates a machine learning model to predict the best crops to cultivate based on environmental conditions, with a focus on accuracy optimization.

## Tech Stack

### Web Development
- **HTML:** For creating the structure of the web interface.
- **JavaScript:** For adding interactivity and functionality to the web pages.
- **Tailwind CSS:** For styling the web interface and ensuring a modern design.

### Database Management
- **Firebase:** Used for storing and retrieving sensor data, providing seamless integration with the web interface.

## Hardware Components

### Sensors
- **Soil Moisture Sensor:** Measures soil moisture levels.
- **Rain Sensor:** Detects rainfall.
- **DHT11:** Measures temperature and humidity.
- **pH Sensor:** Measures the acidity or alkalinity of the soil.
- **Water Pump:** Controls water supply.

### Microcontroller
- **ESP32:** Processes data from sensors and manages communication with the web interface.

## Features
- **Sensor Integration:** Utilizes multiple sensors for comprehensive data collection.
- **Web Interface:** Provides real-time monitoring and control through a user-friendly interface.
- **Database Management:** Stores and retrieves sensor data using Firebase.
- **Machine Learning Model:** Predicts the best crops to cultivate based on environmental conditions.
- **Accuracy Optimization:** Ensures high accuracy in crop prediction through rigorous model training and validation.

## Usage
1. Sensors collect soil and environmental data, sending it to Firebase.
2. The web interface displays real-time data from Firebase and feeds it to the machine learning model.
3. The machine learning model predicts the best crops to cultivate based on the received data.
4. Users can view the crop recommendations on the web interface and make informed decisions for farming practices.

## Contributing
Contributions are welcome! Fork the repository and create a pull request with your changes.

## License
This project is licensed under the MIT License.
