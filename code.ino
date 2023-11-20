#include <LiquidCrystal_I2C.h>
#include <dht.h>
#include <Wire.h>


dht DHTSENSOR;
int DHT_Sensor_pin = 4;
LiquidCrystal_I2C lcd_screen(0x27, 16,2);


void setup() {
  Serial.begin(9600);  
  lcd_screen.begin(16,2);
  lcd_screen.backlight();
}

void loop() {
  DHTSENSOR.read11(DHT_Sensor_pin);
  String temp = "Temp : " + String(DHTSENSOR.temperature) + " C";
  String  humid = "humid : " + String(DHTSENSOR.humidity) + " %";
  lcd_screen.setCursor(0,0);
  lcd_screen.print(temp);
  lcd_screen.setCursor(0,1);
  lcd_screen.print(humid);
  delay(500);

}
