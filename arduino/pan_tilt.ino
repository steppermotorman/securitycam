#include <Servo.h> // Import the library

Servo servoPan, servoTilt; // Create servo object
String data = ""; // Store incoming commands (buffer)

void setup() {
    // Setup servos on PWM capable pins
    servoPan.attach(9); 
    servoTilt.attach(10);

    Serial.begin(9600); // Start serial at 9600 bps (speed)
}

void loop() {
    while (Serial.available() > 0)
    {
        // If there is data
        char singleChar = Serial.read(); // Read each character

        if (singleChar == 'P') {
            // Move pan servo
            servoPan.write(data.toInt());
            data = ""; // Clear buffer
        }
        else if (singleChar == 'T') {
            // Move tilt servo
            servoTilt.write(data.toInt());
            data = ""; // Clear buffer
        }
        else {
            data += singleChar; // Append new data
        }
    }
}
