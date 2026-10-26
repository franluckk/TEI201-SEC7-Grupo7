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
├── iteracion_2/    # Primera iteración - Avance #2
└── iteracion_3/    # Versión final - Avance #3
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

| Aspecto | v1 | v2 | v3 |
|---------|----|----|----| 
| **Fecha** | [25/10/2026] | [fecha] | [fecha] |
| **Entradas** | [Botón pulsador] | [lista] | [lista] |
| **Actuadores** | [Servomotor MG996R] | [lista] | [lista] |
| **Conectividad** | [ESP32, conexiones cableadas] | [tipo] | [tipo] |
| **Encapsulado** | ❌ | Prototipo | Finalizado |
| **Testing** | Prueba del equipo observada por el profesor | 2 usuarios | 5+ usuarios |
| **Funcionalidad** | 100% | 80% | 100% |

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


### Versión 2 (Iteración 2) - Primera Mejora
**Fecha:** [XX/XX/2025]  
**Estado:** Prototipo funcional mejorado

**Mejoras implementadas:**
- [Mejora 1]
- [Mejora 2]

**Problemas pendientes:**
- [Problema 1]
- [Problema 2]

### Versión 3 (Iteración 3) - Versión Final
**Fecha:** [XX/XX/2025]  
**Estado:** Prototipo de alta resolución

**Mejoras finales:**
- [Mejora 1]
- [Mejora 2]

**Resultado:**
- Sistema robusto y probado
- Listo para piloto en terreno

---

## Justificación de Cambios

### Hardware
**De v1 a v2:**
- Cambio: [Descripción]
- Razón: [Justificación técnica]
- Impacto: [Mejora cuantitativa]

**De v2 a v3:**
- Cambio: [Descripción]
- Razón: [Justificación técnica]
- Impacto: [Mejora cuantitativa]

### Software
**De v1 a v2:**
- [Cambios principales]

**De v2 a v3:**
- [Cambios principales]

### Diseño 3D
**De v1 a v2:**
- [Cambios en encapsulado]

**De v2 a v3:**
- [Cambios finales]

---

## Incorporación de Feedback

### Feedback del Avance #1 → Cambios en v2
1. [Comentario profesor/ayudante]
   - Acción tomada: [Descripción]

### Feedback del Avance #2 → Cambios en v3
1. [Comentario profesor/ayudante]
   - Acción tomada: [Descripción]

### Feedback de Usuarios → Cambios en v3
1. [Comentario común de usuarios]
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
