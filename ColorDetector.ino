
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define outPin 8
#define s0 9
#define s1 10
#define s2 11
#define s3 12

boolean DEBUG = true;

// Variables
int red, grn, blu;
String color = "";
long startTiming = 0;
long elapsedTime = 0;

void setup() {
  Serial.begin(9600);

  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(outPin, INPUT); 

  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Welcome To");
  lcd.setCursor(1, 1);
  lcd.print("Color Detector");
  delay(2000);
  lcd.clear();

  startTiming = millis();
}

void loop() {
  getColor();

  if (DEBUG) printData();
  elapsedTime = millis() - startTiming;

  if (elapsedTime > 1000) {
    showDataLCD();
    startTiming = millis();
  }
}

void readRGB() {
  red = 0; grn = 0; blu = 0;
  int n = 10;

  for (int i = 0; i < n; ++i) {
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
    red += pulseIn(outPin, LOW);

    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);
    grn += pulseIn(outPin, LOW);

    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);
    blu += pulseIn(outPin, LOW);
  }

  red /= n;
  grn /= n;
  blu /= n;
}

void printData() {
  Serial.print("red= ");
  Serial.print(red);
  Serial.print("   green= ");
  Serial.print(grn);
  Serial.print("   blue= ");
  Serial.print(blu);
  Serial.print(" - ");
  Serial.print(color);
  Serial.println(" detected!");
}

void showDataLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("R"); lcd.print(red);
  lcd.setCursor(6, 0);
  lcd.print("G"); lcd.print(grn);
  lcd.setCursor(12, 0);
  lcd.print("B"); lcd.print(blu);
  lcd.setCursor(0, 1);
  lcd.print("Color: ");
  lcd.print(color);
}

void getColor() {
  readRGB();
  if (red > 40 && red < 55 && grn > 70 && grn < 82 && blu > 45 && blu < 55)
    color = "RED";
  else if (red > 67 && red < 78 && grn > 48 && grn < 57 && blu > 40 && blu < 50)
    color = "GREEN";
  else if (red > 75 && red < 87 && grn > 60 && grn < 70 && blu > 30 && blu < 45)
    color = "BLUE";
  else if (red > 20 && red < 30 && grn > 30 && grn < 40 && blu > 30 && blu < 40)
    color = "orange";
  else if (red > 30 && red < 40 && grn > 25 && grn < 35 && blu > 15 && blu < 25)
    color = "WHITE";
  else if (red > 80 && red < 100 && grn > 75 && grn < 87 && blu > 50 && blu < 60)
    color = "BLACK";
  else if (red > 37 && red < 41 && grn > 30 && grn < 34 && blu > 23 && blu < 29)
    color = "bsila :)";
  else if (red > 35 && red < 42 && grn > 52 && grn < 56 && blu > 28 && blu < 35)
    color = "pink";
  else if (red > 69 && red < 74 && grn > 42 && grn < 48 && blu > 24 && blu < 30)
    color = "baby blue";
  else if (red > 35 && red < 42 && grn > 39 && grn < 46 && blu > 34 && blu < 40)
    color = "yellow";
  else
    color = "NO_COLOR";
}
