Directional Haptic Feedback System Using VL53L0X Sensors
Firmware for a wearable obstacle detection system that uses five VL53L0X time-of-flight (ToF) sensors and five vibration motors to provide directional haptic feedback. The system detects nearby objects in multiple directions and activates the corresponding vibration motor to alert the user.
This project demonstrates multi-sensor I2C communication, microcontroller firmware development, and sensor-to-actuator integration for assistive or wearable technology.

System Overview
The system uses five VL53L0X distance sensors placed around the user to monitor different directions:

Sensor	Direction
Sensor 1	North
Sensor 2	North-East
Sensor 3	East
Sensor 4	North-West
Sensor 5	West

Each sensor is paired with a vibration motor that activates when an obstacle is detected within a specified distance threshold.

Sensor -> Distance Measurement -> Firmware Processing -> Motor Activation

This creates directional tactile feedback, allowing the user to perceive obstacle location through vibration.

Hardware Components

Microcontroller (Arduino compatible)
5 × VL53L0X Time-of-Flight distance sensors
5 × vibration motors
I2C communication bus
XSHUT control pins for address assignment
Sensor Address Configuration

Because all VL53L0X sensors share the same default I2C address, the firmware uses the XSHUT pins to initialize sensors one at a time and assign unique addresses.

Sensor	I2C Address
Sensor 1	0x30
Sensor 2	0x31
Sensor 3	0x32
Sensor 4	0x33
Sensor 5	0x34

Each sensor is brought out of shutdown sequentially and assigned a new address before enabling continuous ranging.

Pin Configuration
XSHUT Pins

Used to control sensor initialization.

XSHUT_1 -> Pin 7
XSHUT_2 -> Pin 8
XSHUT_3 -> Pin 9
XSHUT_4 -> Pin 10
XSHUT_5 -> Pin 11
Vibration Motor Outputs
Motor 1 -> Pin 2
Motor 2 -> Pin 3
Motor 3 -> Pin 4
Motor 4 -> Pin 5
Motor 5 -> Pin 6

Firmware Operation

1. Sensor Initialization
During startup the firmware:
Shuts down all sensors
Activates sensors one at a time using XSHUT
Assigns unique I2C addresses
Starts continuous ranging mode
This prevents address conflicts on the I2C bus.

2. Distance Measurement
Each sensor continuously measures distance using:
readRangeContinuousMillimeters()
Distances are monitored in millimeters and converted to centimeters for serial output.

Example serial output:
Sensor 1: 45.3 cm | Sensor 2: 60.1 cm | Sensor 3: 120.4 cm

3. Obstacle Detection

The firmware checks whether an object is within 2500 mm (2.5 meters).
distance < 2500 mm
If the threshold is met, the corresponding vibration motor is activated.

4. Haptic Feedback
Each sensor directly controls a vibration motor:
Sensor -> Direction -> Motor

Example:
North obstacle -> Motor 1 vibration
East obstacle -> Motor 3 vibration

This provides directional tactile feedback to the wearer.

Fault Handling
The firmware includes timeout detection to handle sensor communication failures.
If a timeout occurs:
the sensor reading is marked as invalid
the system prints an error message via serial output

Example:
Sensor 3 timeout!
Sensor 3: ERROR
Key Features

Multi-sensor I2C device management
Dynamic address assignment using XSHUT pins
Continuous real-time distance monitoring
Directional haptic feedback system
Sensor timeout detection and fault handling

Applications

This system can be used for:
wearable assistive navigation devices
obstacle detection systems
robotics proximity sensing
human-machine interaction systems

Libraries Used
Wire.h
VL53L0X.h

VL53L0X library:
https://github.com/pololu/vl53l0x-arduino

Author

Frederick Joshua N. Carlos
Embedded Systems | Firmware Development | Hardware Integration
