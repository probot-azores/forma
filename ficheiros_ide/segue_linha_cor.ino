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

//Sensor Cor ##########
const int s0 = 44;  
const int s1 = 42;  
const int s2 = 40;  
const int s3 = 38;  
const int out = 36;    
unsigned int red = 0;  
unsigned int green = 0;  
unsigned int blue = 0;

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

  //COR
  pinMode(s0,OUTPUT);  
  pinMode(s1,OUTPUT);  
  pinMode(s2,OUTPUT);  
  pinMode(s3,OUTPUT);  
  pinMode(out,INPUT);
  digitalWrite(s0,LOW);  
  digitalWrite(s1,HIGH);
}  

   
void loop(){  
   /*Serial.println(digitalRead(sdir));
   Serial.println(digitalRead(scen));
   Serial.println(digitalRead(sesq));
   Serial.println(".....");
   delay(500);*/
   cor();
 int readEsq=digitalRead(sesq);
  int readCen=digitalRead(scen);
  int readDir=digitalRead(sdir);
  if(readCen==1 && readEsq==0 && readDir==0 && red<30 && green<30 && blue<30){
  avancar();
  }
  else if(readDir==1){
    virardir();        
  }
  else if(readEsq==1){
    viraresq();      
  }    
  else if (red < blue && green > blue ) //RED
  {
    delay(20);  
    parar();
    delay(2000);
    avancar();   
  }   
  else if (blue < red && blue < green && green < red ) //BLUE
  {  
    delay(20);
    parar();
    delay(2000);
    avancar();        
  }  
  else if (red > green && blue >= green  ) //GREEN
  {  
    delay(20);
    parar();
    delay(2000);
    avancar();    
  }   
  else{
    avancar();
  }
  }  
    
void cor()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);   
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);   
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);    
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
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
