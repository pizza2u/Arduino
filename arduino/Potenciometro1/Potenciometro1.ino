//youtube.com/ArduinoBrasil
//Autor: Gustavo Augusto dos Santos Gomes

const int potenci = A1;
const int potenci1 = A2; 
//Count vai ser o nosso número de Leds, que usaremos em todos os "For's" do programa.
int Count = 6;   
//Vetor dos nossos Leds
int leds[] = {3,5,6,9,10,11};   

void setup() {
 //Setando os nossos Leds
 for (int Led = 0; Led < Count; Led++) {
   pinMode(leds[Led], OUTPUT);
 }
}

void loop(){
 //Potenciometro regulador de Brilho
 //Leitura do Potenciomentro
 int leituraP1 = analogRead(potenci1);
 /*Divisão do potenciomentro, se o seu potenciometro for de 10k use:
 [int <variavel> = map(<variavel_De_Leitura>, 0, 10023, 0, 255 (ou 0, 1024 se você estiver usando Leds de alto brilho))].
 Se ele for de 1k use:
 [int <variavel> = map(<Variavel_De_Leitura>, 0, 1023, 0, 255 (ou 0, 1024 se você estiver usando Leds de alto brilho))]*/
 int leituraD1 = map(leituraP1, 0, 10023, 0, 1023);
  
 //Potenciometro regulador dos Leds
 /*Divisão do potenciomentro, se o seu potenciometro for de 10k use:
 [int <variavel> = map(<variavel_De_Leitura>, 0, 10023, 0, 6 (se der sujeira use um valor (7) a mais para os leds))].
 Se ele for de 1k use:
 [int <variavel> = map(<Variavel_De_Leitura>, 0, 1023, 0, 6 (se der sujeira use um valor (7) a mais para os leds))]*/
 int leituraP = analogRead(potenci);
 int leituraD = map(leituraP, 0, 1023, 0, 7);
 
 //Verifição para Acender/Apagar os Leds
  for (int Led = 0; Led < Count; Led++) {
   /*Variável Led é o nosso contador, sempre que essa variável for menor que a LeitutaD
   O Led correspondente ao contador (Led) vai ficar acesso.
   E o contrário, quando o contador for maior que a LeituraD, o Led correspondente apagar
   Lembrando que LeituraD é referente ao potenciometro que controla os Leds.*/
   if(Led < leituraD){
    //E a LeituraD1 é referente ao brilho dos Leds.
    analogWrite(leds[Led], leituraD1);
   }
   else{
    //O Led correspondente apaga, como é um sinal analógico, para apagar temos que mandar [0].
    analogWrite(leds[Led], 0);
  }
 }
}



