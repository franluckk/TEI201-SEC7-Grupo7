# Software - Documentación

Esta carpeta contiene todo el código y documentación del software del prototipo Alpha IoT para el Sistema Inclusivo de Apertura de Puertas.

## Carpetas
* **`src/`**: Código fuente del proyecto (`main.ino` para ESP32, usando pines `D18` para el servomotor MG996R y `D4` para el botón pulsador).
* **`librerias/`**: Detalles de dependencias necesarias (`ESP32Servo`).
* **`docs/`**: Documentación técnica, manual de operación y troubleshooting.

## Stack Tecnológico
* **Plataforma**: ESP32 (DOIT DEVKIT V1)
* **Lenguaje**: C/C++
* **IDE**: Arduino IDE 2.x
* **Librerías principales**:
  * `ESP32Servo` - Versión estándar del Library Manager (Obligatoria para control de PWM seguro y compatible con ESP32).

## Instalación y Configuración
1. **Instalar Arduino IDE**: Descargar versión 2.x desde arduino.cc.
2. **Configurar ESP32**: Agregar la URL de tarjetas de Espressif en Preferencias (`https://dl.espressif.com/dl/package_esp32_index.json`) e instalar el paquete `esp32` desde el Gestor de Tarjetas.
3. **Instalar Librerías**: Abrir el Library Manager y buscar `ESP32Servo` (por Kevin Harrington).
4. **Cargar Código**:
   * Abrir `src/main.ino`.
   * Seleccionar placa **"DOIT ESP32 DEVKIT V1"** y el puerto COM correspondiente.
   * Compilar y subir con el ESP32 conectado por USB y la fuente externa de 5V del servomotor con tierra común (`GND`) unificada.