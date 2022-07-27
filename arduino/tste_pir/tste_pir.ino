const int pinoLED = 7;
const int pinoPIR = 4;

void setup() {
  pinMode(pinoLED, OUTPUT);
  pinMode(pinoPIR, INPUT);
}

void loop() {
  int valor = digitalRead(pinoPIR);
  if (valor == HIGH) {
    digitalWrite(pinoLED, HIGH);
    delay(50);
    digitalWrite(pinoLED, LOW);
  }
}
