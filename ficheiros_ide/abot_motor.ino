// Left Motor PINS
# define EnLeft 5
# define In1Left 7
# define In2Left 6

//Right Motor PINS
# define EnRight 10
# define In1Right 8
# define In2Right 9

void setup() {
    pinMode(EnLeft, OUTPUT);
    pinMode(In1Left, OUTPUT);
    pinMode(In2Left, OUTPUT);
    pinMode(EnRight, OUTPUT);
    pinMode(In1Right, OUTPUT);
    pinMode(In2Right, OUTPUT);

}

void loop() {
    analogWrite(EnRight, 255);    
    digitalWrite(In1Right, 0);
    digitalWrite(In2Right, 1);
    delay(1); 
    analogWrite(EnLeft, 255);  
    digitalWrite(In1Left, 0);
    digitalWrite(In2Left, 1); 
    delay(1);    
}
