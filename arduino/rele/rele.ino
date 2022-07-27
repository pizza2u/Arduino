 
//Porta ligada ao pino IN1 do modulo
int porta_rele1 = 7;
//Porta ligada ao pino IN2 do modulo
int porta_rele2 = 8;

int porta_rele3 = 12;
int porta_rele4 = 13;
void setup()
{
  //Define pinos para o rele como saida
  pinMode(porta_rele1, OUTPUT); 
  pinMode(porta_rele2, OUTPUT);
 pinMode(porta_rele3, OUTPUT);
 pinMode(porta_rele4, OUTPUT);
}
   
void loop()
{
  digitalWrite(porta_rele1, LOW);  //Liga rele 1
  digitalWrite(porta_rele2, LOW); //Desliga rele 2
 digitalWrite(porta_rele3, LOW); 
 digitalWrite(porta_rele4, LOW);//Desliga rele 2
  delay(1500);
  digitalWrite(porta_rele1, HIGH); //Desliga rele 1
  digitalWrite(porta_rele2, HIGH);  //Liga rele 2
    digitalWrite(porta_rele3, HIGH);  //Liga rele 2
    digitalWrite(porta_rele4, HIGH);
  delay(1500);
}
