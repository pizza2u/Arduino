// C++ code
//
int moisture = 0;
int val = (13,392,333);
int eita = (13,900,300);
void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(7, OUTPUT); //buzzer
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  // Apply power to the soil moisture sensor
  digitalWrite(A0, HIGH);
  delay(10); // Wait for 10 millisecond(s)
  moisture = analogRead(A1);
  // Turn off the sensor to reduce metal corrosion
  // over time
  digitalWrite(A0, LOW);
  Serial.println(moisture);
  digitalWrite(9, LOW);
  digitalWrite(7, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  
  
  if (moisture < 400) {
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(9, LOW);
    tone(7,val);
  } else {
      if (moisture < 900) {
        digitalWrite(11, HIGH);
        noTone(7);
      } else {
          digitalWrite(9, HIGH);
        tone(7,eita);
        }
  }
  delay(100); // Wait for 100 millisecond(s)
}
