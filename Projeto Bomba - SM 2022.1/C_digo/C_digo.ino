#define SENSOR_UP 3
#define SENSOR_DOWN 2
#define BUZZER 7
#define PUMP 5
#define TIME 1000
 
unsigned long last_change = 0, now = 0;
bool s_up, s_down, state;
 
void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_UP, INPUT_PULLUP);
  pinMode(SENSOR_DOWN, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
  pinMode(PUMP, OUTPUT);
}
void loop() {
  s_up = !digitalRead(SENSOR_UP); // LER OS SENSORES
  s_down = digitalRead(SENSOR_DOWN);
  //Serial.println(s_down);
 // delay(1000);
  if(s_up and s_down){ // CHECA OS SENSORES
    state = false;
    alarm(3000);
   Serial.print("ERRO - Estado da bomba: ");
   Serial.println(state);
  }else if(s_up){
    state = false;
    alarm(1000);
    Serial.print("Sensor boia horizontal - Estado da bomba: ");
    Serial.println(state);
}else if(s_down){
    state = true;
    alarm(500);
   Serial.print("Sensor boia vertical - Estado da bomba: ");
    Serial.println(state);
  }else{ 
    //state = false;
    //Serial.print("teste: ");
  //  Serial.println(state);
  }
  digitalWrite(PUMP, state);  // ACIONA BOMBA
}
void alarm(int val){  // CONTROLA O BUZZER
  // 3 - ERRO     
  // 2 - VAZIO
  // 1 - CHEIO
 
 
 // for(int i=0; i<val; i++){
    //digitalWrite(BUZZER, HIGH);
    tone(BUZZER, val);
    delay(TIME);
    noTone(BUZZER);
    //digitalWrite(BUZZER, LOW);
    delay(TIME);
  //}
}
 
