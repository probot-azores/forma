//Trig e Echo pin
#define trigPin 30
#define echoPin 32
//Definir variaveis
long duration;
int distance;
void setup() 
{
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600); 
}
void loop()
{
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distance = duration/58.2;

Serial.print("Distance = ");
Serial.print(distance);
Serial.println(" cm");
delay(50);
}
