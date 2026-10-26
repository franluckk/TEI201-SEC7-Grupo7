# Librerías

## Librerías Estándar (Arduino IDE)

Instalar desde el Library Manager de Arduino IDE:

1. **[ESP32Servo]** - v[3.0.5 o superior]
   * **Propósito**: Permite generar señales PWM por hardware de forma segura y específica para el ESP32, lo cual es obligatorio para controlar el servomotor MG996R, ya que la librería `Servo.h` clásica de Arduino no es compatible con la arquitectura del ESP32.
   * **Instalación**: Sketch > Include Library > Manage Libraries > Buscar "ESP32Servo" (Autor: Kevin Harrington).

## Librerías Personalizadas/Modificadas

*Para la fase de este prototipo Alpha, no se requieren librerías personalizadas. El filtrado de rebotes del botón (debounce) y el control de energía (`detach()`) se manejan de forma nativa en el código fuente.*

## Dependencias Completas

Listado de todas las librerías necesarias para compilar el proyecto:

| Librería | Versión | Fuente | Obligatoria |
| :--- | :--- | :--- | :---: |
| ESP32 Core | Built-in | Espressif Board Manager | ✅ |
| ESP32Servo | >= 3.0.5 | Arduino Library Manager | ✅ |
