# Código Fuente

## Archivos Principales
**`main.ino`**
Archivo principal del prototipo Alpha para el ESP32, configurado con el servomotor MG996R en el pin `18` (`PIN_SERVO`) y el botón pulsador en el pin `4` (`PIN_BOTON`).

**Estructura:**
* **Setup**: Inicializa el Monitor Serie a `115200` baudios, configura `PIN_BOTON` con resistencia interna (`INPUT_PULLUP`), fija la frecuencia PWM (`50` Hz) y los límites de pulso seguros (`1000` a `2000` µs), posiciona el servomotor a `0°` (`ANGULO_CERRADO`) y aplica `motorPuerta.detach()` tras el movimiento inicial.
* **Loop**: Detecta cuando se presiona el botón (`digitalRead(PIN_BOTON) == LOW`), invierte la variable booleana `estadoPuerta` para alternar entre abrir (`60°` / `ANGULO_ABIERTO`) y cerrar (`0°` / `ANGULO_CERRADO`), y bloquea lecturas repetidas con un filtro antirrebote (`while` loop) hasta soltar el botón.
* **Gestión de Energía**: Reconecta la señal PWM (`attach`) solo al iniciar cada movimiento, espera `TIEMPO_MOVIMIENTO_MS` (`1000` ms) y ejecuta `motorPuerta.detach()` de inmediato para eliminar el consumo continuo, las vibraciones y el calentamiento del cableado en reposo.

## Estándares de Código
* **Variables**: `camelCase` (ej. `estadoPuerta`).
* **Constantes**: `UPPER_SNAKE_CASE` con `const int` / `const long` (ej. `PIN_SERVO`, `PIN_BOTON`, `PULSO_MIN`, `PULSO_MAX`, `FRECUENCIA_HZ`, `ANGULO_ABIERTO`, `ANGULO_CERRADO`, `TIEMPO_MOVIMIENTO_MS`, `BAUD_RATE`).