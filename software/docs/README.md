# Documentación de Software

## Configuración de Parámetros

Constantes y variables principales definidas en `src/main.ino`:

* **Pines y comunicación**: `PIN_SERVO = 18` (señal PWM para el MG996R), `PIN_BOTON = 4` (pulsador con `INPUT_PULLUP` a `GND`) y `BAUD_RATE = 115200`[cite: 17, 69].
* **Parámetros del actuador y tiempos**: `PULSO_MIN = 1000` µs, `PULSO_MAX = 2000` µs, `FRECUENCIA_HZ = 50` Hz, `ANGULO_ABIERTO = 60`°, `ANGULO_CERRADO = 0`°, `TIEMPO_MOVIMIENTO_MS = 1000` ms y variable `estadoPuerta` (`false` = cerrado, `true` = abierto)[cite: 17, 69].

## Documentación de Funciones

### Funciones Principales

**`setup()`**[cite: 69]
* **Propósito:** Inicializar el hardware, configurar la seguridad eléctrica del actuador y establecer la posición de reposo inicial[cite: 69].
* **Parámetros:** Ninguno[cite: 69].
* **Retorna:** `void`[cite: 69].
* **Acciones clave:** Inicia el Monitor Serie a `BAUD_RATE` (`115200`), configura `PIN_BOTON` con `INPUT_PULLUP`, fija la frecuencia a `FRECUENCIA_HZ` (`50` Hz), conecta el servo con `PULSO_MIN` (`1000`) y `PULSO_MAX` (`2000`), lo posiciona en `ANGULO_CERRADO` (`0°`), espera `TIEMPO_MOVIMIENTO_MS` (`1000` ms) y ejecuta `motorPuerta.detach()` de forma preventiva[cite: 17, 69].

**`loop()`**[cite: 69]
* **Propósito:** Mantener la lectura constante del entorno y ejecutar los movimientos del motor mitigando el consumo térmico y las vibraciones[cite: 17, 69].
* **Parámetros:** Ninguno[cite: 69].
* **Retorna:** `void`[cite: 69].
* **Acciones clave:**[cite: 69]
  1. Detecta el pulso (`LOW`) en `PIN_BOTON`[cite: 17, 69].
  2. Invierte la memoria lógica (`estadoPuerta = !estadoPuerta`)[cite: 17, 69].
  3. Configura la frecuencia (`FRECUENCIA_HZ`) y despierta el motor (`motorPuerta.attach(PIN_SERVO, PULSO_MIN, PULSO_MAX)`)[cite: 17, 69].
  4. Mueve a `ANGULO_ABIERTO` (`60°`) si `estadoPuerta` es `true`, o a `ANGULO_CERRADO` (`0°`) si es `false`[cite: 17, 69].
  5. Espera `TIEMPO_MOVIMIENTO_MS` (`1000` ms) y entra en reposo mediante `motorPuerta.detach()`[cite: 17, 69].
  6. Aplica un ciclo `while (digitalRead(PIN_BOTON) == LOW)` con `delay(10)` como filtro antirrebote (debounce) hasta que el usuario suelta el botón[cite: 17, 69].

## Manual de Operación

### Encendido del Sistema[cite: 69]
1. Conectar la fuente de alimentación externa de 5V al adaptador Jack para energizar exclusivamente el actuador (MG996R), manteniendo la tierra común (`GND`) unida al ESP32[cite: 4, 69].
2. Conectar el ESP32 mediante el cable USB al computador o a una fuente de 5V independiente para iniciar el sistema lógico[cite: 18, 69].

### Operación Normal[cite: 69]
1. Presionar el botón físico una vez[cite: 69]. El sistema leerá la señal (`LOW`), abrirá la puerta (`ANGULO_ABIERTO` = `60°`) y el motor entrará en modo de reposo (`detach()`) automáticamente tras `TIEMPO_MOVIMIENTO_MS` (`1000` ms) para evitar vibraciones y consumo eléctrico continuo[cite: 17, 69].
2. Presionar el botón nuevamente para cerrar la puerta (`ANGULO_CERRADO` = `0°`) y volver a reposo[cite: 17, 69].
3. Mantener el botón presionado no generará falsas activaciones gracias al filtro antirrebote (`while`) del código[cite: 17, 69].

### Apagado del Sistema[cite: 69]
1. Desconectar primero la fuente de poder de 5V del actuador para evitar movimientos erráticos[cite: 69].
2. Desconectar el cable USB del ESP32 para apagar la placa lógica[cite: 69].

## Troubleshooting

* **El ESP32 se reinicia al presionar el botón**: El motor está sacando corriente de la placa en vez de su fuente externa de 5V; separa la alimentación y mantén unida la tierra común (`GND`)[cite: 31].
* **El motor vibra o se calienta**: Verifica que los pulsos estén en `1000` a `2000` µs (`PULSO_MIN` y `PULSO_MAX`), que se ejecute `motorPuerta.detach()` tras cada movimiento y que las conexiones de alimentación y `GND` estén firmes[cite: 15, 17, 31].