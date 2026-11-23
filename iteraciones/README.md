# Historial de Iteraciones

## Propósito

Esta carpeta documenta la evolución del prototipo a través de las diferentes versiones desarrolladas durante el curso.

**CRÍTICO:** Demostrar el proceso iterativo es un requisito para obtener puntaje completo en "Integración y Refinamiento" (2.5 puntos).

---

## Estructura de Carpetas

Cada iteración tiene su propia carpeta con documentación de esa versión:

```
iteraciones/
├── iteracion_1/    # Concepto inicial - Prototipo alpha   
└── iteracion_2/    # Versión final 
```

---

## Contenido de Cada Iteración

Cada carpeta debe incluir:

1. **README.md** - Descripción de la versión
2. **Fotos** - Imágenes del prototipo en ese estado
3. **Esquema** - Circuito de esa versión (si cambió)
4. **Código** - Versión del software (si cambió)
5. **Notas** - Problemas identificados y mejoras planificadas

---

## Tabla Comparativa de Iteraciones

 Aspecto | v1 | v2 |
|---|---|---|
| **Fecha**| 25/10/2026 | 22/11/2026 |
| **Entradas** | Un botón pulsador | Dos botones pulsadores disponibles en el DEC |
| **Actuadores** | Servomotor MG996R | Actuador lineal de 12 V, modelo ARF03-12-A1-305-200-C11 |
| **Controlador** | ESP32 | ESP32 reutilizada del prototipo Alpha |
| **Control del actuador** | Control del servomotor | Driver puente H BTS7960 |
| **Alimentación** | Fuente externa de 5 V para el servomotor y conexión USB para la ESP32 | Fuente de 12 V DC y 5 A incluida con el actuador; convertidor DC-DC de 12 V a 5 V para el circuito de control |
| **Encapsulado** | Sin caja final documentada | Caja electrónica diseñada en Fusion 360, filamento disponible por un integrante del equipo |
| **Testing** | Prueba del equipo observada por el profesor | Pruebas con los integrantes del equipo y familiares de un integrante |
| **Funcionalidad** | 100% | 100% |

---

## Evolución del Diseño

### Versión 1 (Iteración 1) - Concepto Inicial
**Fecha:** [25/10/2026]  
**Estado:** Prototipo alpha - Prueba de concepto

**Características:**
- Primera versión a escala del sistema de apertura inclusiva. Busca comprobar que un botón pueda activar, a través del ESP32, un servomotor que represente el movimiento de apertura de una puerta.
- Problemas principales identificados:
Para armar el prototipo alpha medimos la puerta de la Universida Adolfo Ibañez y de acuerdo a esto calculamos el motor que necesitabamos, pero este era muy difícil de encontrar por lo que tuvimos que usar un motor más común.
La causa de este problema fue principalmente la cancelación de clases debido a las lluvias provocó que nos demoraramos en poder medir la puerta y cuando lo hicimos (más o menos una semana y media antes de la presentación del prototipo alpha) el motor que necesitabamos ya no llegaba a tiempo.
Para solucionarlo hicimos el prototipo alpha a escala para poder utilizar un motor más pequeño. 
- Aprendisajes:
  Aprendimos a entender el circuito y los componentes.

### Versión 2 (Iteración 2) - Versión Final
**Fecha:** [22/11/2026]  
**Estado:** Prototipo final

Esta iteración pasa de una representación a escala a un sistema diseñado para accionar una puerta mediante un actuador lineal de 12 V.

**Mejoras finales:**
- **Escala de aplicación:** el Alpha movía una tablita para representar una puerta. Esta iteración utiliza un actuador lineal pensado para accionar una puerta.
- **Mecanismo de movimiento:** se reemplazó el servomotor MG996R por un actuador lineal de 12 V, modelo ARF03-12-A1-305-200-C11.
- **Control del movimiento:** se incorporó un driver puente H BTS7960 para controlar la extensión y retracción del actuador.
- **Entradas de control:** se consideran dos botones pulsadores disponibles en el DEC, en lugar del único botón del Alpha.
- **Alimentación:** se utiliza la fuente de 12 V DC y 5 A incluida con el actuador, además de un convertidor DC-DC de 12 V a 5 V para el circuito de control.
- **Caja electrónica:** se diseño una caja en Fusion 360 para alojar los componentes.
- **Controlador:** se mantiene y reutiliza la ESP32 del Alpha.


**Resultado:**
Se avanzó desde una prueba a escala, en la que el servomotor movía una tablita, hacia el diseño de un sistema pensado para accionar una puerta mediante un actuador lineal. 

Al momento de subir esta documentación el prototipo pueden tener mejoras antes de la presentación del 27/11/2026.

---

## Justificación de Cambios

### Hardware

 **Cambio:** se reemplazó el servomotor MG996R por un actuador lineal de 12 V y se incorporó el driver BTS7960.  
  **Razón:** el Alpha solo movía una tablita a escala. Para desarrollar un sistema pensado para accionar una puerta se eligió un actuador lineal.

- **Cambio:** se incorporó un convertidor DC-DC de 12 V a 5 V y se utiliza la fuente incluida con el actuador.  
  **Razón:** el actuador funciona con 12 V, mientras que el circuito de control requiere una alimentación de menor voltaje.

- **Cambio:** se consideran dos botones pulsadores en lugar de uno.  
  **Razón:** el sistema requiere entradas para solicitar desde ambos lados. 


### Software

- **Cambio:** el código deberá controlar las entradas de los dos botones y enviar las señales correspondientes al driver.  
  **Razón:** el Alpha controlaba un servomotor. la nueva configuración utiliza un driver para controlar un actuador lineal.  
 
### Diseño mecánico

- **Cambio:** se pasa de una tablita a escala a un diseño pensado para accionar una puerta con un actuador lineal.  
  **Razón:** el Alpha permitió comprobar el movimiento de un mecanismo pequeño, pero no accionaba una puerta. La segunda iteración busca aplicar el movimiento a la puerta.

- **Cambio:** se diseño una caja electrónica en Fusion 360.  
  **Razón:** el nuevo sistema integra más componentes electrónicos que deben alojarse en el montaje.



### Diseño 3D
**De v1 a v2:**
- **Cambio:** se diseño en Fusion 360 una caja para alojar los componentes electrónicos del prototipo.
- **Razón:** el Alpha era una prueba a escala y no tenía una caja electrónica diseñada para esta configuración. La Iteración 2 incorpora componentes distintos, como el driver BTS7960 y el convertidor DC-DC, que deben organizarse dentro del montaje.


---

## Incorporación de Feedback

### Feedback del Avance #1 → Cambios en v2
1. [Comentario profesor/ayudante]
   - Acción tomada: [Descripción]

---

## Métricas de Mejora

| Métrica | v1 | v2 | v3 | Mejora Total |
|---------|----|----|----| -------------|
| Tiempo respuesta (ms) | 500 | 200 | 100 | ↓80% |
| Consumo (mA) | 250 | 180 | 120 | ↓52% |
| Tasa de errores (%) | 15 | 5 | 1 | ↓93% |
| Satisfacción usuario (1-5) | 3.0 | 3.8 | 4.5 | ↑50% |

---

## Lecciones Aprendidas

### Técnicas
- Manejo de arduino
- Como funcionan los circuitos
- Codigos
- Aprendimos a usar GitHub
- Organización de Equipo  
  

### De Proceso
- [Lección 1]
- [Lección 2]

### De Trabajo en Equipo
- [Lección 1]
- [Lección 2]
