int s0 = 44;
int s1 = 46;
int s2 = 48;
int s3 = 50;
int out = 52;

//Variaveis cores
int red = 0;
int green = 0;
int blue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
}

void loop() {
  //Deteta a cor
  cor();
  Serial.print("Vermelho :");
  Serial.print(red, DEC);
  Serial.print(" Verde : ");
  Serial.print(green, DEC);
  Serial.print(" Azul : ");
  Serial.print(blue, DEC);
  Serial.println();
  delay(200);
}

void cor()
{
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  //Ler a cor vermelha
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  
  digitalWrite(s3, HIGH);
  //Ler a cor azul
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  
  digitalWrite(s2, HIGH);
  //Ler a cor verde
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}
