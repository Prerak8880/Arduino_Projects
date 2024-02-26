#include <LiquidCrystal_I2C.h>

// Pin configuration
const int tempSensorPin = A0;  // Analog pin for temperature sensor
const int fan1Pin = 9;        // Digital pin for fan 1
const int fan2Pin = 10;       // Digital pin for fan 2

// Temperature threshold for turning fans on and off
const int fanOnThreshold = 25;  // Adjust this value according to your requirements
const int fanOffThreshold = 20; // Adjust this value according to your requirements

// LCD configuration
LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address, columns, rows

void setup() {
  pinMode(tempSensorPin, INPUT);
  pinMode(fan1Pin, OUTPUT);
  pinMode(fan2Pin, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Fan Control");
}

void loop() {
  // Read temperature from sensor
  int temperature = analogRead(tempSensorPin);

  // Convert analog reading to temperature in degrees Celsius
  float tempCelsius = map(temperature, 0, 1023, 0, 100);

  // Check if temperature is above the fanOnThreshold
  if (tempCelsius > fanOnThreshold) {
    // Turn on Fan 1 and turn off Fan 2
    digitalWrite(fan1Pin, HIGH);
    digitalWrite(fan2Pin, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Fan 1 ON ");
  } 
  // Check if temperature is below the fanOffThreshold
  else if (tempCelsius < fanOffThreshold) {
    // Turn off Fan 1 and turn on Fan 2
    digitalWrite(fan1Pin, LOW);
    digitalWrite(fan2Pin, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Fan 2 ON ");
  }
  // If temperature is between fanOffThreshold and fanOnThreshold, turn off both fans
  else {
    digitalWrite(fan1Pin, LOW);
 
    lcd.setCursor(0, 1);
    lcd.print("Both OFF");
  }

  // Display temperature on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempCelsius);
  lcd.print(" C  ");

  // Add a delay to avoid rapid switching
  delay(1000);
}
