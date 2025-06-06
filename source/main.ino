#define DELAY 2000 

const int ledPinRed = 10;
const int ledPinGreen = 12;
const int ledPinBlue = 8; 
const int ldrPin = A3;

void setup() {
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int red = readColor(ledPinRed);
  int green = readColor(ledPinGreen);
  int blue = readColor(ledPinBlue); 

  Serial.print(red);
  Serial.print(",");
  Serial.print(green);
  Serial.print(",");
  Serial.println(blue);

  delay(1000);  
}

int readColor(int ledPin) {
  digitalWrite(ledPin, HIGH);
  delay(DELAY); 
  int value = analogRead(ldrPin);
  digitalWrite(ledPin, LOW);
  return map(value, 0, 1023, 0, 255);
}