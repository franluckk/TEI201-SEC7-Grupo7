# Código Fuente

## Archivos Principales
**`main.ino`**
Archivo principal y único del prototipo Alpha para el ESP32.

**Estructura:**
* **Setup**: Inicialización del pin del botón con resistencia PULLUP, configuración del monitor serie a 115200 baudios y posicionamiento inicial del servomotor a 0 grados.
* **Loop**: Ciclo principal que detecta pulsaciones (LOW) mediante un filtro antirrebote (while loop). Alterna la variable booleana `estadoPuerta` para abrir (60°) o cerrar (0°).
* **Gestión de Energía**: Utiliza `motorPuerta.detach()` inmediatamente después de cada movimiento para eliminar el consumo eléctrico en reposo y evitar sobrecalentamiento.

## Estándares de Código
* **Variables**: `camelCase` (ej. `estadoPuerta`, `pinBoton`).
* **Constantes**: `UPPER_SNAKE_CASE` o `const int` (ej. `pinServo`).
