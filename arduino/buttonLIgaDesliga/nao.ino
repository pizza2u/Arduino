// para apagar o led de vez e ligar tambem
const int buttonPin = 2; // entrada digital - pushbutton
const int ledPin = 3; // saída digital -  LED
 
// set variáveis
boolean state = 0; //  variável para armazenar valores do pushbutton
 
void setup() {
  // define pinos de saída e entrada
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // pullup interno do Arduino
}
 
void loop(){
  readPushButton();
}

void readPushButton() {
  if (!digitalRead(buttonPin)) { // verifica se o botão foi acionado
    state = !state; // inverte valor da variável variable_buttonEstado
    state ?  digitalWrite(ledPin, HIGH) :  digitalWrite(ledPin, LOW);
    while (!digitalRead(buttonPin)) {} // aguarda soltar o botão
    delay(150); // delay para reduzir o efeito bouncing
  }
}
