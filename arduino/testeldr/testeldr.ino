#define led 9 // pino do led é 9
#define ldr A0 // pino do ldr é A0

int niveLuz, high = 0, low = 1023;

void setup(){
pinMode(led, OUTPUT);
Serial.begin(9600);
}

void loop(){
  int sensor = A0;
niveLuz = analogRead(sensor);
Serial.println(niveLuz);
//Agora queremos usar este número para controlar o brilho
// O LED. Mas temos um problema: a função analogRead ()
// Retorna valores entre 0 e 1023, e o analogWrite ()
// Função quer valores de 0 a 255.

// Nós podemos resolver isso usando duas funções úteis chamada do map()
// E contrain ()(retringir). Map mudará de um intervalo de valores em
// Outro intervalo. Se dizemos em mapa () nosso intervalo “daqui” é de 0-1023,
// Eo nosso intervalo “para” é 0-255, mapa () vai apertar a maior
// Variar dentro do menor. (Pode fazê-lo para quaisquer dois intervalos.)

// Uma função chamada constranger (), que irá “clipar” números em
// Um ​​determinado intervalo. Se o número está acima do intervalo, ele irá repor
// para ser o número mais alto na escala. Se o número é
// Abaixo do intervalo, ele irá repô-lo para o número mais baixo.
// Se o número está dentro do intervalo, ele vai ficar na mesma.

// Aqui está uma última coisa a se pensar. O circuito fizemos
// Não terá uma gama todo o caminho de 0 a 1023. Será
// um intervalo menor, como 300 (escuro) a 800 (de luz).
// Se nós apenas passar este número diretamente para map(), o LED
// vai alterar brilho, mas ele nunca vai ser completamente desligado ou
// Completamente ligado.

// Você pode corrigir isso de duas maneiras, cada um dos quais vamos mostrar
// Nas funções abaixo.

// manualTune(); // Alterar manualmente a gama de claro a escuro de acordo com os                                         //  resultados em sua saída serial

autoTune(); // deixa o Arduino fazer o trabalho para nós!

// As funções acima irá alterar a níveluz a cobrir a gama
// partir de full-on para full-off. Agora podemos ajustar o
// brilho do LED:

//analogWrite(led, niveLuz);

// A declaração acima irá iluminar o LED junto com o
// Nível de luz. Para fazer o contrário, substitua “lightLevel” no
// Acima analogWrite (declaração), com “255-lightLevel”.
// Agora sim criamos um night-light!

//analogWrite(led, 255 – niveLuz);
}

void manualTune(){
// Como mencionado acima, o circuito de detecção de luz que nós construímos
// Não terá uma gama todo o caminho de 0 a 1023. Ele provavelmente vai
// Ser mais parecido com 300 (escuro) a 800 (de luz). Se você executar este esboço
// Como está, o LED não irá totalmente desligado, mesmo no escuro.

// Você pode acomodar a gama reduzida em manualmente
// Ajustando o “de” números alcance no mapa () função.
// Aqui nós estamos usando toda a gama de 0 a 1023.
// Tentar alterar manualmente a um intervalo menor (300 a 800
// É um bom palpite), e testá-lo novamente. Se o LED não faz
// Ir completamente fora, fazer o baixo número maior. Se o LED
// É sempre muito brilhante, faça o elevado número menor.

// Lembre-se você está apenas mudando a 0, 1.023 na linha abaixo!

niveLuz = map(niveLuz, 0, 1023, 0, 255); // mudo para 0 para o mínimo na entrada serial,    //e 1023 para o maximo lido no monitor serial
niveLuz = constrain(niveLuz, 0, 255); // restringe os numeros da saida de 0 a 255

}

void autoTune(){

// Como mencionado acima, o circuito de detecção de luz que nós construímos
// Não terá uma gama todo o caminho de 0 a 1023. Ele provavelmente vai
// Ser mais parecido com 300 (escuro) a 800 (de luz).

// Na função manualTune () acima, você precisa repetidamente
// Alterar os valores e tente novamente o programa até que ele funciona.
// Mas por que você deve ter para fazer esse trabalho? Você tem um
// Computador em suas mãos que podem descobrir as coisas por si mesmo!

// Nesta função, o Arduino vai manter o controle da mais alta
// e valores mais baixos que estamos lendo a partir analogRead ().

// Se você olhar para a parte superior do esboço, você verá que nós temos
// Inicializado “baixa” para ser 1023. Vamos salvar nada lemos
// Que seja mais baixa do que isso:

if(niveLuz < low){
low = niveLuz;
}

// Também inicializado “alto” para ser 0. Vamos salvar nada
// Lemos que é maior do que isso:

 

if(niveLuz > high){
high = niveLuz;
}

// Uma vez que temos os valores mais altos e mais baixos, podemos colocá-los
// Diretamente na função map (). Sem ajustes manual do necessário!

// Um truque que vamos fazer é adicionar um pequeno deslocamento para baixo e alto,
// Para assegurar que o diodo emissor de luz é totalmente fora e nos limites totalmente sobre
// (Caso contrário ele pode tremer um pouco).

niveLuz = map(niveLuz, low+30, high-30, 0, 255);
niveLuz = constrain(niveLuz, 0, 255);
}
