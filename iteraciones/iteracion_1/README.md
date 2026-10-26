# Iteración 1 - Concepto Inicial

## Información General

**Fecha:** 25/10/2026  
**Versión:** v1.0  
**Estado:** Prototipo alpha - Prueba de concepto  
**Avance asociado:** Planificación inicial / Avance #1

---

## Descripción

Nuestro prototipo alfa es una versión a escala que  demuestra cómo funcionaría el sistema. Al presionar un botón, el ESP32 envía una señal al servomotor MG996R, que gira hasta una posición programada para representar la apertura de una puerta. Al presionar nuevamente, vuelve a su posición inicial.

**Objetivo de esta iteración:**
- Probar conexión de sensores básicos
- Validar comunicación con microcontrolador
- Comprobar que el ESP32 detecte la activación del botón
- Representar a escala la apertura y el retorno de una puerta
- Controlar el servomotor MG996R mediante la ESP32
- Verificar el funcionamiento básico del circuito en una protoboard
  
---

## Componentes Utilizados

### Hardware
- Microcontrolador:
 - Placa ESP32
  

- Actuadores:
 - Servomotor MG996R con brazo y tornillo
 - Botón pulsador
 - Protoboard
 - Cables dupont 
 - Cable USB 
 - Fuente externa de 5V 
 - Adaptador de alimentación 

### Software
- IDE: Arduino IDE
- Librerías: [Lista]
- Versión código: v1.0

---

## Fotos del Prototipo

Incluir en esta carpeta:
- `v1_circuito_protoboard.jpg`
- `v1_vista_general.jpg`
- `v1_detalle_conexiones.jpg`

---

## Resultados de Testing Inicial

### Funcionalidad Lograda
✅. El botón activa la señal de entrada al ESP32.  
✅ El ESP32 controla el servomotor MG996R. 
✅.  El servo se mueve a la posición programada para representar la apertura y vuelva a su posición inicial al presionar nuevamente.

### Problemas Identificados

1. **Problema 1:**
   - Descripción: 
   - Causa probable: 
   - Solución propuesta: General 

2. **Problema 2:**
   - Descripción: [Detalles]
   - Causa probable: [Análisis]
   - Solución propuesta: [Plan]

---

## Aprendizajes

### Técnicos
- [Aprendizaje 1]
- [Aprendizaje 2]

### De Diseño
- [Aprendizaje 1]
- [Aprendizaje 2]

---

## Plan para Iteración 2

### Mejoras Planificadas

**Hardware:**
- [ ] [Mejora 1]
- [ ] [Mejora 2]

**Software:**
- [ ] [Mejora 1]
- [ ] [Mejora 2]

**Diseño:**
- [ ] Iniciar diseño de encapsulado
- [ ] Mejorar ruteo de cables

---

## Archivos en esta Carpeta

- `v1_codigo.ino` - Código de esta versión
- `v1_esquema.png` - Esquema del circuito
- `v1_fotos/` - Fotografías del prototipo
- `v1_notas.txt` - Notas adicionales del equipo
