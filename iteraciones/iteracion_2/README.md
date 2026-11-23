# Iteración 2 - Versión Final

## Información General

**Fecha:** 22/11/2026   
**Versión:** v2.0  
**Estado:** Prototipo Final - sujeto a cambios

> Esta documentación registra el estado del prototipo al momento de subirlo a GitHub. El diseño y el montaje pueden recibir ajustes antes de la presentación. Si se realizan cambios, se informarán durante la presentación del 27/11/2026.

---

## Descripción

Esta iteración desarrolla una solución de apertura asistida para una puerta convencional, pensada para facilitar su uso a personas con movilidad reducida.

En el prototipo Alpha se comprobó el control del movimiento a escala mediante una ESP32, un botón pulsador y un servomotor MG996R. Para esta iteración se definió un sistema con actuador lineal de 12 V, controlado mediante un driver puente H BTS7960. El diseño contempla dos botones pulsadores y una caja electrónica diseñada en Fusion 360.


**Objetivos alcanzados:**

Desarrollar un prototipo que permita controlar la apertura y el cierre de una puerta mediante botones y un actuador lineal, integrando el sistema electrónico en una estructura que pueda instalarse en la puerta.

---

## Cambios Respecto a v1

### Hardware
**Mejoras implementadas:**
- Se reemplaza el servomotor MG996R por un actuador lineal de 12 V, modelo ARF03-12-A1-305-200-C11, con carrera indicada de 200 mm.
- Se incorpora un driver puente H BTS7960 para controlar la extensión y retracción del actuador.
- Se incorpora un convertidor DC-DC de 12 V a 5 V para alimentar el circuito de control.
- Se consideran dos botones pulsadores disponibles en el DEC, en lugar del botón utilizado en el prototipo Alpha.
- Se reutiliza la ESP32 del prototipo Alpha.
- Se utiliza la fuente de 12 V DC y 5 A que venía con el actuador.


### Software
**Nuevas funcionalidades:**
- [Feature final 1]
- [Feature final 2]

**Optimizaciones finales:**
- [Optimización de código]
- [Mejora de eficiencia]

**Manejo de errores:**
- Implementado manejo robusto de casos extremos
- Mensajes de error informativos
- Recuperación automática ante fallas menores

### Diseño Mecánico
**Encapsulado finalizado:**
- Diseño optimizado para impresión 3D
- Todos los componentes integrados
- Sistema de montaje robusto
- Accesibilidad para mantenimiento
- Resistencia a condiciones ambientales

---

## Fotos del Prototipo Final

Incluir en esta carpeta:
- `v3_prototipo_final_frontal.jpg`
- `v3_prototipo_final_posterior.jpg`
- `v3_interior_componentes.jpg`
- `v3_instalado_contexto.jpg`
- `v3_detalle_sensores.jpg`
- `v3_testing_usuarios.jpg` (múltiples)

---

## Resultados Finales

### Funcionalidad Completa
✅ [Todas las funciones planificadas]  
✅ Sistema opera sin intervención manual  
✅ Conectividad estable  
✅ Interfaz de usuario funcional  
✅ Manejo robusto de errores  

### Testing con 5+ Usuarios

**Participantes:**
- N = [número] usuarios
- Perfil: [Descripción del grupo objetivo]

**Resultados cuantitativos:**
| Métrica | Promedio | Desv. Std. |
|---------|----------|------------|
| Facilidad de uso (1-5) | [X.X] | [X.X] |
| Satisfacción (1-5) | [X.X] | [X.X] |
| Tiempo completar tarea (seg) | [XX] | [XX] |
| Errores cometidos | [X.X] | [X.X] |

**Feedback cualitativo más relevante:**
- Positivo: "[Cita de usuario]"
- Positivo: "[Cita de usuario]"
- A mejorar: "[Cita de usuario]"

### Validación de Impacto ODS

**ODS Seleccionado:** [Número y nombre]

**Métricas de impacto:**

1. **[Métrica 1]**
   - Baseline (sin prototipo): [Valor]
   - Con prototipo: [Valor medido]
   - Mejora: [% o valor absoluto]

2. **[Métrica 2]**
   - Baseline: [Valor]
   - Con prototipo: [Valor medido]
   - Mejora: [% o valor absoluto]

**Proyección de impacto:**
Si se despliega a escala [barrio/ciudad/región]:
- [Impacto estimado cuantitativo]
- [Beneficiarios potenciales]

---

## Comparación de las 3 Iteraciones

| Aspecto | v1 | v2 | v3 | Mejora Total |
|---------|----|----|----| -------------|
| **Sensores** | 2/3 | 3/3 | 3/3 | ✅ 100% |
| **Actuadores** | 1/2 | 2/2 | 2/2 | ✅ 100% |
| **Tiempo respuesta (ms)** | 500 | 200 | 100 | ↓ 80% |
| **Consumo (mA)** | 250 | 180 | 120 | ↓ 52% |
| **Tasa errores (%)** | 15 | 5 | 1 | ↓ 93% |
| **Encapsulado** | ❌ | Prototipo | Finalizado | ✅ |
| **Usuarios testeados** | 0 | 2 | 5+ | ✅ |
| **Satisfacción (1-5)** | - | 3.8 | 4.5 | ↑ 18% |
| **Impacto ODS validado** | ❌ | Parcial | ✅ Completo | ✅ |

---

## Fortalezas del Prototipo Final

1. **[Fortaleza 1]**
   - Evidencia: [Datos de testing]

2. **[Fortaleza 2]**
   - Evidencia: [Feedback de usuarios]

3. **[Fortaleza 3]**
   - Evidencia: [Métricas técnicas]

---

## Limitaciones Identificadas

1. **[Limitación 1]**
   - Descripción: [Detalles]
   - Impacto: [Evaluación]
   - Posible solución futura: [Ideas]

2. **[Limitación 2]**
   - Descripción: [Detalles]
   - Impacto: [Evaluación]
   - Posible solución futura: [Ideas]

---

## Aprendizajes del Proceso Completo

### Técnicos
1. [Aprendizaje técnico importante]
2. [Aprendizaje técnico importante]

### De Diseño
1. [Lección sobre proceso de diseño]
2. [Lección sobre proceso de diseño]

### De Trabajo en Equipo
1. [Lección sobre colaboración]
2. [Lección sobre colaboración]

### De Gestión de Proyecto
1. [Lección sobre planificación]
2. [Lección sobre gestión de tiempo]

---

## Trabajo Futuro Recomendado

### Mejoras a Corto Plazo
- [ ] [Mejora 1]
- [ ] [Mejora 2]

### Mejoras a Mediano Plazo
- [ ] [Feature adicional 1]
- [ ] [Optimización 1]

### Escalabilidad
- [ ] [Consideración para producción masiva]
- [ ] [Modelo de negocio / sustentabilidad]
- [ ] [Alianzas estratégicas potenciales]

---

## Archivos en esta Carpeta

- `v3_codigo_final.ino` - Código final documentado
- `v3_esquema_final.png` - Esquema definitivo del circuito
- `v3_modelo3d_final.f3d` - Diseño 3D completo en Fusion 360
- `v3_fotos/` - Fotografías del prototipo final
- `v3_testing_completo.pdf` - Reporte de testing con usuarios
- `v3_comparativa_versiones.xlsx` - Datos comparativos v1-v2-v3
