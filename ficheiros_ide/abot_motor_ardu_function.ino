#include <Motor.h>

Motor motor_esquerdo(5,6,7);
Motor motor_direito(10,9,8);

// Avançar o robot com os dois motores na velocidade máxima
void forward() {
  motor_esquerdo.avancar(255);
  motor_direito.avancar(255);
}


void setup() {
}

void loop() {
  forward();

}
