//MOTORES #########
//MOTOR ESquerdo
const int ENesq = 5;
const int IN1esq = 6;
const int IN2esq =7;
int velesq = 130;
//MOTOR Direito
const int ENdir = 10;
const int IN3dir = 8;
const int IN4dir = 9;
int veldir = 130;

//linha #############
const int sesq = 48;
const int scen = 50;
const int sdir = 52;

void setup(){    
  Serial.begin(9600);
  //MOTORES 
  pinMode(ENesq,OUTPUT);
  pinMode(IN1esq,OUTPUT);
  pinMode(IN2esq,OUTPUT);
  pinMode(ENdir,OUTPUT);
  pinMode(IN3dir,OUTPUT);
  pinMode(IN4dir,OUTPUT);    
  
  //LINHA
  pinMode(sesq,INPUT);
  pinMode(scen,INPUT);
  pinMode(sdir,INPUT);  
}  

   
void loop(){  

   //Serial.println(digitalRead(sdir));
   //delay(500);
 if(digitalRead(sesq)==0 && digitalRead(sdir)==0 && digitalRead(scen)==1){
  avancar();
 }
 else if(digitalRead(sesq)==1 && digitalRead(scen)==1 && digitalRead(sdir)==0){
  viraresq();
  delay(30);
 }
 else if(digitalRead(sesq)==0 && digitalRead(scen)==1 && digitalRead(sdir)==1){
  virardir();
  delay(30);
 }
 else{
  avancar();
 }
     
  }  
    

void avancar(){
  analogWrite(ENesq,velesq);
  digitalWrite(IN1esq,HIGH);
  digitalWrite(IN2esq,LOW);
  analogWrite(ENdir,veldir);
  digitalWrite(IN3dir,HIGH);
  digitalWrite(IN4dir,LOW);
}
void parar(){
  digitalWrite(ENesq,LOW);
  digitalWrite(IN1esq,HIGH);
  digitalWrite(IN2esq,HIGH);
  digitalWrite(ENdir,LOW);
  digitalWrite(IN3dir,HIGH);
  digitalWrite(IN4dir,HIGH);
}
void viraresq(){
  analogWrite(ENesq,80);
  digitalWrite(IN1esq,LOW);
  digitalWrite(IN2esq,HIGH);
  analogWrite(ENdir,veldir);
  digitalWrite(IN3dir,HIGH);
  digitalWrite(IN4dir,LOW);
}
void virardir(){
  analogWrite(ENesq,velesq);
  digitalWrite(IN1esq,HIGH);
  digitalWrite(IN2esq,LOW);
  analogWrite(ENdir,80);
  digitalWrite(IN3dir,LOW);
  digitalWrite(IN4dir,HIGH);
}
