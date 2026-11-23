// ============================================================================
// SISTEMA INCLUSIVO DE PUERTAS - ITERACIÓN 2 (PROTOTIPO FINAL)
// Hardware: ESP32 DevKit V1 + Driver BTS7960 + Actuador Lineal 12V + Botón(es)
// ============================================================================

// Constantes de pines y configuración (UPPER_SNAKE_CASE)
const int PIN_BOTON = 4;            // Pulsador(es) en paralelo a GND con INPUT_PULLUP
const int PIN_EXTENDER = 18;        // Conectado a RPWM del BTS7960
const int PIN_RETRAER = 19;         // Conectado a LPWM del BTS7960
const int PIN_ENABLE = 21;          // Conectado a R_EN y L_EN del BTS7960 (reposo/habilitación)
const long BAUD_RATE = 115200;      // Velocidad del Monitor Serie
const unsigned long TIEMPO_RECORRIDO_MS = 10000; // Tiempo estimado de carrera completa (ms)
const unsigned long DEBOUNCE_MS = 10;

// Variable de estado en camelCase (false = cerrado/retraído, true = abierto/extendido)
bool estadoPuerta = false;

void detenerMotor() {
  // Apaga ambos sentidos y deshabilita el driver BTS7960 para reposo sin consumo/calor
  digitalWrite(PIN_EXTENDER, LOW);
  digitalWrite(PIN_RETRAER, LOW);
  digitalWrite(PIN_ENABLE, LOW);
}

void extenderActuador() {
  // Enclavamiento seguro: apaga retracción antes de habilitar extensión
  digitalWrite(PIN_RETRAER, LOW);
  digitalWrite(PIN_ENABLE, HIGH);
  digitalWrite(PIN_EXTENDER, HIGH);
}

void retraerActuador() {
  // Enclavamiento seguro: apaga extensión antes de habilitar retracción
  digitalWrite(PIN_EXTENDER, LOW);
  digitalWrite(PIN_ENABLE, HIGH);
  digitalWrite(PIN_RETRAER, HIGH);
}

void setup() {
  Serial.begin(BAUD_RATE);

  pinMode(PIN_BOTON, INPUT_PULLUP);
  pinMode(PIN_EXTENDER, OUTPUT);
  pinMode(PIN_RETRAER, OUTPUT);
  pinMode(PIN_ENABLE, OUTPUT);

  // Garantiza que el actuador inicie completamente apagado y en reposo
  detenerMotor();
  Serial.println("Sistema Iteracion 2 listo. Estado inicial: CERRADO.");
}

void loop() {
  // Lectura activa en LOW por configuración INPUT_PULLUP (botón conectado a GND)
  if (digitalRead(PIN_BOTON) == LOW) {
    estadoPuerta = !estadoPuerta;

    if (estadoPuerta) {
      Serial.println("[INFO] Abriendo puerta (extendiendo actuador)...");
      extenderActuador();
    } else {
      Serial.println("[INFO] Cerrando puerta (retrayendo actuador)...");
      retraerActuador();
    }

    // Espera el tiempo de recorrido (los topes internos del actuador también protegen el final)
    delay(TIEMPO_RECORRIDO_MS);

    // Corta la activación del driver para dejar el sistema en reposo
    detenerMotor();
    Serial.println("[INFO] Movimiento completado. Driver en reposo.");

    // Filtro antirrebote: espera hasta que se suelte el botón para evitar disparos dobles
    while (digitalRead(PIN_BOTON) == LOW) {
      delay(DEBOUNCE_MS);
    }
  }

  delay(DEBOUNCE_MS);
}