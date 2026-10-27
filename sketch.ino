#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <LiquidCrystal_I2C.h>

Adafruit_BMP085 bmp;
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int BUTTON_PIN = 4;
int displayMode = 0; 
bool lastButtonState = HIGH;
bool currentButtonState = HIGH;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Weather Station");
  delay(2000);
  lcd.clear();

  if (!bmp.begin()) {
    Serial.println("BMP180 Error!");
    lcd.print("BMP180 Error!");
    while (1) {}
  }
}

void loop() {
  currentButtonState = digitalRead(BUTTON_PIN);
  
  // Detect button press (transition from HIGH to LOW)
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    displayMode = !displayMode; // Toggle mode between 0 and 1
    lcd.clear();
    delay(50); // Simple debounce
  }
  lastButtonState = currentButtonState;

  float temp = bmp.readTemperature();
  int32_t pressure = bmp.readPressure();
  float altitude = bmp.readAltitude();

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C  ");

  lcd.setCursor(0, 1);
  if (displayMode == 0) {
    lcd.print("Pres: ");
    lcd.print(pressure / 100.0);
    lcd.print(" hPa  ");
  } else {
    lcd.print("Alt: ");
    lcd.print(altitude);
    lcd.print(" m     ");
  }
  
  delay(100); // Short delay for responsive button reads
}
