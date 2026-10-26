# Software - Documentación

## Contenido
Esta carpeta contiene todo el código y documentación del software del proyecto.

📂 **Carpetas**
* `src/`: Código fuente del proyecto (.ino para ESP32)
* `librerias/`: Librerías adicionales necesarias
* `docs/`: Documentación técnica del software

## Stack Tecnológico
* **Plataforma:** ESP32
* **Lenguaje:** C/C++
* **IDE:** Arduino IDE 2.x
* **Librerías principales:**
  * `ESP32Servo` - Versión estable más reciente

## Instalación y Configuración

1. **Instalar Arduino IDE**
   Descargar e instalar desde la página oficial de Arduino.

2. **Configurar ESP32 en Arduino IDE**
   Ir a Archivo > Preferencias, y añadir el enlace del gestor de tarjetas de Espressif. Luego, instalar la tarjeta "ESP32 by Espressif Systems" desde el Gestor de Tarjetas.

3. **Cargar Código**
   1. Abrir `src/main.ino`
   2. Seleccionar la placa "DOIT ESP32 DEVKIT V1" y el puerto COM correspondiente
   3. Compilar y subir
