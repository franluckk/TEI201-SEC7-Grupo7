#include <ESP32Servo.h>

// Constantes de configuración (UPPER_SNAKE_CASE)
const int PIN_SERVO = 18;
const int PIN_BOTON = 4;
const int PULSO_MIN = 1000;
const int PULSO_MAX = 2000;
const int FRECUENCIA_HZ = 50;
const int ANGULO_ABIERTO = 60;
const int ANGULO_CERRADO = 0;
const int TIEMPO_MOVIMIENTO_MS = 1000;
const long BAUD_RATE = 115200;

Servo motorPuerta;

// Variable de estado en camelCase (false = cerrado / 0°, true = abierto / 60°)
bool estadoPuerta = false;

void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(PIN_BOTON, INPUT_PULLUP);

  // Posicionamiento inicial a 0 grados y reposo inmediato para evitar calentamiento
  motorPuerta.setPeriodHertz(FRECUENCIA_HZ);
  motorPuerta.attach(PIN_SERVO, PULSO_MIN, PULSO_MAX);
  motorPuerta.write(ANGULO_CERRADO);
  delay(TIEMPO_MOVIMIENTO_MS);
  motorPuerta.detach();

  Serial.println("Sistema listo. Puerta cerrada (0 grados).");
}

void loop() {
  if (digitalRead(PIN_BOTON) == LOW) {
    estadoPuerta = !estadoPuerta;

    // Despertar el motor con límites de pulso seguros
    motorPuerta.setPeriodHertz(FRECUENCIA_HZ);
    motorPuerta.attach(PIN_SERVO, PULSO_MIN, PULSO_MAX);

    if (estadoPuerta) {
      Serial.println("Abriendo puerta a 60 grados...");
      motorPuerta.write(ANGULO_ABIERTO);
    } else {
      Serial.println("Cerrando puerta a 0 grados...");
      motorPuerta.write(ANGULO_CERRADO);
    }

    // Esperar a que complete el movimiento y cortar señal para evitar vibraciones/consumo
    delay(TIEMPO_MOVIMIENTO_MS);
    motorPuerta.detach();

    // Filtro antirrebote hasta soltar el botón
    while (digitalRead(PIN_BOTON) == LOW) {
      delay(10);
    }
  }

  delay(10);
}