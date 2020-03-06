#include <Motor.h>

Motor motor_esquerdo(5,6,7);
Motor motor_direito(10,9,8);

void setup() {
}

void loop() {
  motor_esquerdo.avancar(255);
  motor_direito.avancar(255);
}
