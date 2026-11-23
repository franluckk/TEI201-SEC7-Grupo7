# Librerías

## Librerías Estándar (Arduino IDE)

Instalar desde el Library Manager de Arduino IDE[cite: 68]:

1. **ESP32Servo** - v3.0.5 o superior[cite: 68]
   * **Propósito**: Permite generar señales PWM por hardware de forma segura y específica para el ESP32, lo cual es obligatorio para controlar el servomotor MG996R en el pin `18` (`PIN_SERVO`), ya que la librería `Servo.h` clásica de Arduino no es compatible con la arquitectura del ESP32[cite: 17, 68].
   * **Instalación**: Sketch > Include Library > Manage Libraries > Buscar "ESP32Servo" (Autor: Kevin Harrington)[cite: 68].

## Librerías Personalizadas/Modificadas

Para la fase de este prototipo Alpha, no se requieren librerías personalizadas[cite: 68]. El filtrado de rebotes del botón (`while (digitalRead(PIN_BOTON) == LOW)` con `delay(10)`), los límites de pulso (`PULSO_MIN` = `1000` µs, `PULSO_MAX` = `2000` µs), la frecuencia (`FRECUENCIA_HZ` = `50` Hz) y el control de energía (`motorPuerta.detach()` tras `TIEMPO_MOVIMIENTO_MS` = `1000` ms) se manejan de forma nativa en `src/main.ino`[cite: 17, 66, 68].

## Dependencias Completas

Listado de todas las librerías necesarias para compilar el proyecto[cite: 68]:

| Librería | Versión | Fuente | Obligatoria |
| :--- | :--- | :--- | :---: |
| ESP32 Core | Built-in | Espressif Board Manager | ✅ |
| ESP32Servo | >= 3.0.5 | Arduino Library Manager | ✅ |
```[cite: 68]