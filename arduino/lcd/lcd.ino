//Programa: Display LCD 16x2 e modulo I2C
//Autor: Arduino e Cia
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,20,4);



void setup() {
  lcd.begin(16, 2);           // set up the LCD 16x2
  lcd.print("Sistemas microcontrolados!"); // print a message to the LCD
  delay(1000);
}

void loop() {
   lcd.setBacklight(HIGH);
  // scroll 13 positions (string length) to the left to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    lcd.scrollDisplayLeft(); // scroll one position left:
    delay(500);              // wait a bit
  }

  // scroll 29 positions (string length + display length) to the right to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    lcd.scrollDisplayRight(); // scroll one position right
    delay(500);               // wait a bit
  }

  // scroll 16 positions (display length + string length) to the left to move it back to center:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    lcd.scrollDisplayLeft(); // scroll one position left
    delay(500); // wait a bit
  }

  delay(1000); // delay at the end of the full loop:
}
