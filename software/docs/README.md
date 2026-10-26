# Documentación de Software

## Configuración de Parámetros
Editar las siguientes constantes en `main.ino` en caso de cambiar el cableado:

```cpp
// Pines de control
const int pinServo = 18; // Pin de señal PWM para el MG996R
const int pinBoton = 4;  // Pin de lectura del pulsador

// Límites de pulso seguros
// 1000 a 2000 microsegundos para evitar choques mecánicos internos del actuador
motorPuerta.attach(pinServo, 1000, 2000);
