// --- SISTEMA INCLUSIVO DE PUERTAS: ITERACIÓN 2 ---
// En Wokwi no existe el driver BTS7960 ni el actuador, por eso los LEDs
// representan las señales: verde = RPWM (extender), rojo = LPWM (retraer),
// amarillo = R_EN + L_EN (driver habilitado).

const int PIN_BOTON = 4;

const int PIN_EXTENDER = 18;  // RPWM
const int PIN_RETRAER = 19;   // LPWM
const int PIN_ENABLE = 21;    // R_EN y L_EN

bool estadoPuerta = false;

// Tiempo de recorrido del actuador (ms). En la simulación puedes bajarlo a 3000.
const int TIEMPO_RECORRIDO = 10000;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_BOTON, INPUT_PULLUP);
  pinMode(PIN_EXTENDER, OUTPUT);
  pinMode(PIN_RETRAER, OUTPUT);
  pinMode(PIN_ENABLE, OUTPUT);
  detenerMotor();
}

void loop() {
  if (digitalRead(PIN_BOTON) == LOW) {
    estadoPuerta = !estadoPuerta;

    if (estadoPuerta) {
      Serial.println("[INFO] Abriendo puerta (Extendiendo actuador)...");
      extenderActuador();
    } else {
      Serial.println("[INFO] Cerrando puerta (Retrayendo actuador)...");
      retraerActuador();
    }

    delay(TIEMPO_RECORRIDO);

    detenerMotor();
    Serial.println("[INFO] Reposo de energía activado.");

    while (digitalRead(PIN_BOTON) == LOW) {
      delay(10);
    }
  }
}

void extenderActuador() {
  digitalWrite(PIN_ENABLE, HIGH);
  digitalWrite(PIN_RETRAER, LOW);
  digitalWrite(PIN_EXTENDER, HIGH);
}

void retraerActuador() {
  digitalWrite(PIN_ENABLE, HIGH);
  digitalWrite(PIN_EXTENDER, LOW);
  digitalWrite(PIN_RETRAER, HIGH);
}

void detenerMotor() {
  digitalWrite(PIN_EXTENDER, LOW);
  digitalWrite(PIN_RETRAER, LOW);
  digitalWrite(PIN_ENABLE, LOW);
}
