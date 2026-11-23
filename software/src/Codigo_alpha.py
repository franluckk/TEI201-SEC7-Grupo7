#include <ESP32Servo.h>

// Configuración de pines según sus estándares UPPER_SNAKE_CASE
const int PIN_BOTON = 4;
const int PIN_SERVO = 18;

Servo motorPuerta;

// Variable camelCase para recordar si la puerta está abierta (true) o cerrada (false)
bool estadoPuerta = false;

void setup() {
  // Habilitar resistencia interna para evitar lecturas falsas en el botón
  pinMode(PIN_BOTON, INPUT_PULLUP);
  
  // Iniciar el monitor serie para debugging
  Serial.begin(115200);

  // Posición inicial: Puerta cerrada a 0 grados
  motorPuerta.attach(PIN_SERVO, 1000, 2000);
  motorPuerta.write(0);
  delay(1000); // Esperar un segundo a que el motor llegue físicamente
  motorPuerta.detach(); // Cortar energía para evitar calentamiento de los cables
}

void loop() {
  // Leer el botón: LOW significa que fue presionado (por el INPUT_PULLUP)
  if (digitalRead(PIN_BOTON) == LOW) {
    
    // Invertir el estado (si estaba cerrada, ahora se abrirá y viceversa)
    estadoPuerta = !estadoPuerta;
    
    // Despertar el motor conectando su señal PWM con límites seguros
    motorPuerta.setPeriodHertz(50);
    motorPuerta.attach(PIN_SERVO, 1000, 2000);
    
    if (estadoPuerta) {
      Serial.println("[INFO] Abriendo puerta a 60 grados...");
      motorPuerta.write(60);
    } else {
      Serial.println("[INFO] Cerrando puerta a 0 grados...");
      motorPuerta.write(0);
    }
    
    // Dar tiempo al actuador mecánico para moverse antes de cortarle la señal
    delay(1000);
    
    // Modo reposo: apaga el PWM para evitar vibraciones y consumo eléctrico
    motorPuerta.detach();
    
    // Filtro antirrebote: esperar hasta que el usuario suelte físicamente el botón
    while (digitalRead(PIN_BOTON) == LOW) {
      delay(10);
    }
  }
}