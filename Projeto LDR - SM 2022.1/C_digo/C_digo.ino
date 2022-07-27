// Av 1 SM EE 20221
// define variável "luz" com inteira
int luz = 0;
bool ligado = false;

void setup(){

// tudo que estiver no setup é executado uma única vez,
// quando a placa é ligada ou quando o botão RESET é pressionado

pinMode(2, OUTPUT); 
pinMode(3, OUTPUT); 
pinMode(4, OUTPUT); 
pinMode(11, OUTPUT); 
digitalWrite (2, HIGH); 
digitalWrite (3, LOW); 
digitalWrite (4, LOW); 
digitalWrite (11, LOW);
}

void loop (){

//tudo que estiver dentro do loop é executado indefinidamente

luz = analogRead(A1);
  
    if (luz > 511 && ligado == false) {
  ligado = !ligado;
    digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  analogWrite(11, 127);
  }
  
  else 
    
    if (luz < 511 && ligado == true) {
  digitalWrite (2, HIGH); 
  digitalWrite (3, LOW); 
  digitalWrite (4, LOW); 
  digitalWrite (11, LOW);
    ligado = !ligado;
      
    }
}
