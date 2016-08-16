#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

int potPin1 = 17;
int potPin2 = 16;
int potPin3 = 15;

int analogValue1 = 0;
int analogValue2 = 0;
int analogValue3 = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setBacklight(WHITE);

  pinMode(potPin1, INPUT);
  pinMode(potPin2, INPUT);
  pinMode(potPin3, INPUT);
}

void loop() {
  uint8_t buttons = lcd.readButtons();
  
  analogValue1 = analogRead(potPin1);
  analogValue2 = analogRead(potPin2);
  analogValue3 = analogRead(potPin3);

  buttonPress(buttons);
  show(analogValue1, analogValue2, analogValue3);
}

int buttonPress(int b){
  if (b){
    if (b & BUTTON_UP){
      lcd.setBacklight(RED);
    }

    if(b & BUTTON_DOWN){
      lcd.setBacklight(YELLOW);
    }

    if(b & BUTTON_LEFT){
      lcd.setBacklight(GREEN);
    }

    if(b & BUTTON_RIGHT){
      lcd.setBacklight(TEAL);
    }

    if(b & BUTTON_SELECT){
      lcd.setBacklight(WHITE);
    }
  }
}

void show(int ana1, int ana2, int ana3){
  lcd.setCursor(0, 0);
  lcd.print("Pot1 Pot2 Pot3");

  lcd.setCursor(0, 1);
  lcd.print(analogValue1);

  lcd.setCursor(5, 1);
  lcd.print(analogValue2);

  lcd.setCursor(10, 1);
  lcd.print(analogValue3);
}
