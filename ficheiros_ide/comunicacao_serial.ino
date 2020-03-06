int led=13;
int j=1;

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{   
  pisca();
  delay(5000);
  Serial.print("Pisquei: ");
  Serial.println(j);
  j=j+1;
}

void pisca(){
  digitalWrite(led, HIGH);
  delay(1000);  
  digitalWrite(led, LOW);
  delay(1000);   
}
