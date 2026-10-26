## Documentación de Funciones

### Funciones Principales

**`setup()`**
* **Propósito:** Inicializar el hardware, configurar la seguridad eléctrica del actuador y establecer la posición de reposo inicial.
* **Parámetros:** Ninguno.
* **Retorna:** `void`
* **Acciones clave:** Configura el pin del botón con `INPUT_PULLUP`, inicia el Monitor Serie (115200 baudios), inicializa el servo a 0 grados y ejecuta un `detach()` preventivo.

**`loop()`**
* **Propósito:** Mantener la lectura constante del entorno y ejecutar los movimientos del motor mitigando el consumo térmico.
* **Parámetros:** Ninguno.
* **Retorna:** `void`
* **Acciones clave:** 
  1. Detecta el pulso (`LOW`) del botón.
  2. Invierte la memoria lógica (`estadoPuerta`).
  3. Despierta el motor (`attach` con pulsos 1000-2000 µs).
  4. Mueve a 60° (abrir) o 0° (cerrar).
  5. Entra en reposo (`detach`).
  6. Aplica un ciclo `while` de bloqueo como filtro antirrebote (debounce) hasta que el usuario suelta el botón.

## Manual de Operación

### Encendido del Sistema
1. Conectar la fuente de alimentación externa de 5V al adaptador Jack para energizar exclusivamente el actuador (servo).
2. Conectar el ESP32 mediante el cable USB al computador o a una fuente de 5V independiente para iniciar el sistema lógico.

### Operación Normal
1. Presionar el botón físico una vez. El sistema leerá la señal, abrirá la puerta (giro a 60°) y el motor entrará en modo de reposo automáticamente para no consumir energía.
2. Presionar el botón nuevamente para cerrar la puerta (giro a 0°).
3. Mantener el botón presionado no generará falsas activaciones gracias al filtro antirrebote del código.

### Apagado del Sistema
1. Desconectar primero la fuente de poder de 5V del actuador para evitar movimientos erráticos.
2. Desconectar el cable USB del ESP32 para apagar la placa lógica.
