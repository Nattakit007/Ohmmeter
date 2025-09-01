#include <Arduino.h>
int inputPin = A0; // Analog input pin for voltage measurement
int knownResistor = 10000; // Known resistor value in ohms (10k ohm)
void setup() {
  Serial.begin(115200);
  pinMode(inputPin, INPUT);
} 
void loop() {
  int sensorValue = analogRead(inputPin);
  Serial.println(sensorValue);
  // A sensorValue of 0 will result in a division by zero.
  // This corresponds to a very high or infinite resistance (open circuit).
  if (sensorValue == 0) {
    Serial.println("Measured Resistance: Infinite (Open Circuit)");
  } else {
    float voltage = sensorValue * (5.0 / 1023.0); // Convert ADC value to voltage
    float resistance = (5.0 - voltage) * knownResistor / voltage; // Calculate unknown resistance
    Serial.print("Measured Resistance: ");
    Serial.print(resistance);
    Serial.println(" ohms");
  }
  delay(1000); // Wait for a second before the next reading
}