#include <Wire.h>

#define INT_PIN 13
#define RES_PIN 5 // or 5
#define SCL_PIN 4 // or 4
#define SDA_PIN 0
#define I2C_ADDR 0x22

void setup() {
  Serial.begin(115200);
  pinMode(INT_PIN, INPUT);
  pinMode(RES_PIN, OUTPUT);
  pinMode(SCL_PIN, OUTPUT);
  pinMode(SDA_PIN, OUTPUT);
  digitalWrite(RES_PIN, LOW);
  delay(1);
  digitalWrite(RES_PIN, HIGH);
  delay(1);
  Wire.begin(SDA_PIN, SCL_PIN);
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(0x8C);
  Wire.write(0x00);
  Wire.write(0x00);
  Wire.write(0x00);
  byte t1 = Wire.endTransmission();
  Serial.println(t1);
  Wire.requestFrom(I2C_ADDR, 3);
  byte t2 = Wire.read();
  byte t3 = Wire.read();
  byte t4 = Wire.read();
  
  Serial.println(t2);
  Serial.println(t3);
  Serial.println(t4);

  Wire.beginTransmission(I2C_ADDR);
  Wire.write(0x84);
  Wire.write(0x00);
  Wire.write(0xF0);
  Wire.write(0xFF);
  t1 = Wire.endTransmission();
  Serial.println(t1);
}

void loop() {/*
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(0x8C);
  Wire.write(0xAB);
  Wire.write(0xCD);
  Wire.write(0xEF);
  Wire.endTransmission();
  Wire.requestFrom(I2C_ADDR, 3);
  
  while(Wire.available())    // slave may send less than requested
  { 
    byte c = Wire.read();    // receive a byte as character
    Serial.print(c);         // print the character
  }
  delay(100);*/
}
