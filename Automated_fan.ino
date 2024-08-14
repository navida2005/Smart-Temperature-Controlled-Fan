#include <dht.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
dht module;

// Pin Definitions
const int fanPin = 8;
const int dhtPin = 7;

// Temperature Threshold
const float tempThreshold = 28.0;

void setup() {
  pinMode(fanPin, OUTPUT);
  Serial.begin(9600);

  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  
  // Welcome Message
  lcd.setCursor(3, 0);
  lcd.print("Product Of");
  lcd.setCursor(4, 1);
  lcd.print("-Navida-");
  delay(5000);

  lcd.clear();
}

void loop() {
  float temp = readTemperature(); // Get the temperature

  // Display Temperature on LCD
  displayTemperature(temp);

  // Control the Fan Based on Temperature
  controlFan(temp);

  delay(10000); // Wait for 10 seconds before next update
}

// Function to Read Temperature
float readTemperature() {
  int readResult = module.read11(dhtPin);
  
  if (readResult == DHTLIB_OK) {
    Serial.print("Temperature: ");
    Serial.println(module.temperature);
    return module.temperature;
  } else {
    Serial.println("Failed to read from DHT sensor!");
    return -1; // Return -1 if reading fails
  }
}

// Function to Display Temperature and Fan Status on LCD
void displayTemperature(float temp) {
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Temp: ");
  lcd.print(temp);

  lcd.setCursor(4, 1);
  if (temp > tempThreshold) {
    lcd.print("Fan ON!!");
  } else {
    lcd.print("Fan OFF!!");
  }
}

// Function to Control Fan Based on Temperature
void controlFan(float temp) {
  if (temp > tempThreshold) {
    digitalWrite(fanPin, LOW); // Turn on the fan
  } else {
    digitalWrite(fanPin, HIGH); // Turn off the fan
  }
}

