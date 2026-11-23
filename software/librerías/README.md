# Librerías

## Librerías Estándar (Arduino IDE / ESP32)

Para este prototipo final (Iteración 2) con el driver puente H **BTS7960** y el actuador lineal de **12 V**, no se requieren librerías externas de terceros para el control del motor[cite: 37, 38, 71].

* **ESP32 Core (Espressif Board Manager)**: Proporciona el soporte nativo de la placa **DOIT ESP32 DEVKIT V1** y las funciones estándar de entrada/salida digital (`pinMode`, `digitalRead`, `digitalWrite`, `delay`) y comunicación serie (`Serial`) utilizadas en el código en `.cpp`[cite: 6, 32, 38, 39, 66].

## Librerías Personalizadas/Modificadas

No se requieren librerías personalizadas ni modificadas para esta iteración[cite: 32, 68]. Toda la lógica de control direccional (`RPWM` y `LPWM`), la habilitación/reposo del driver (`R_EN` y `L_EN` mediante `PIN_ENABLE`), el enclavamiento anti-cortocircuito (`extenderActuador()`, `retraerActuador()`, `detenerMotor()`) y el filtrado antirrebote del botón (`INPUT_PULLUP` con ciclo `while`) se implementan de forma nativa dentro del archivo `.cpp` en `src/`[cite: 37, 38, 39, 44, 66, 68].

## Dependencias Completas

Listado de dependencias necesarias para compilar y subir el código final del proyecto:

| Librería / Paquete | Versión | Fuente | Obligatoria |
| :--- | :--- | :--- | :---: |
| ESP32 Core | Built-in | Espressif Board Manager | ✅ |