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
- El prototipo Alpha era una representación a escala: el servomotor movía una tablita y no accionaba una puerta.
- Esta iteración está diseñada para accionar una puerta mediante el desplazamiento lineal del actuador.
- Para transmitir ese movimiento a la puerta se necesita una unión mecánica entre el actuador, una parte fija de la estructura y la puerta.


---

## Resultados Finales

### Prueba de uso

La prueba se realizó en el hogar de un integrante del equipo con cuatro participantes: Cuatro integrantes del grupo familiar de un integrante del grupo. Se observó si comprendían cómo activar el sistema y se recogieron comentarios sobre su uso.

| Participante | Edad | Relación con el equipo | ¿Comprendió cómo usarlo? | Observación o sugerencia |
|---|---:|---|---|---|
| P01 | 53 años | Familiar de un integrante | Sí | Comprendió cómo activar el sistema durante la prueba en el hogar. |
| P02 | 54 años | Familiar de un integrante | Sí | Sugirió incluir un cartel que explique qué botón presionar si el sistema se instala en un espacio público. |
| P03 | 21 años | Familiar de un integrante | Sí | Comprendió cómo activar el sistema durante la prueba. |
| P04 | 16 años | Familiar de un integrante | Sí | Comprendió cómo activar el sistema durante la prueba. |

Se utilizan códigos para identificar a los participantes y resguardar sus datos personales.

### Resultados observados

- Las cuatro personas comprendieron cómo activar el sistema en el contexto de la prueba en el hogar.
- Los participantes valoraron que el sistema se accione mediante botones y sea fácil de usar.
- El sistema podría ser útil para personas con movilidad reducida y también para quienes necesiten abrir una puerta con las manos ocupadas, por ejemplo, al llevar objetos.
- La prueba se realizó en un hogar, donde las personas podían conocer el propósito del prototipo. En un espacio público se necesitaría un cartel visible con instrucciones de uso.
- La prueba fue cualitativa. No se registraron tiempos de tarea, tasas de error ni puntajes de satisfacción, por lo que no se presentan promedios ni porcentajes.

### Comentarios cualitativos

La experiencia en un hogar facilitó que los participantes entendieran para qué servía el sistema. En un espacio público, las personas podrían desconocer su función; por eso, se recomienda instalar instrucciones claras y visibles que indiquen qué botón presionar para abrir la puerta. En una vivienda, quienes usan el sistema habitualmente pueden conocer su funcionamiento.

### Validación de impacto ODS

**ODS relacionados:** ODS 10, Reducción de las desigualdades; y ODS 12, Producción y consumo responsables.

- **ODS 10:** El proyecto busca facilitar la apertura de una puerta a personas con movilidad reducida y a quienes puedan beneficiarse de una apertura asistida.
- **ODS 12:** El diseño removible busca adaptar una puerta existente sin modificarla permanentemente ni reemplazarla. También se reutiliza la ESP32 del prototipo Alpha y se considera filamento disponible en el equipo para fabricar la caja electrónica.

Esta relación describe el propósito y el diseño del prototipo. La prueba realizada no mide por sí sola el impacto de la solución en una comunidad ni demuestra que sea compatible con cualquier puerta.

### Alcance y aspectos pendientes

La prueba se realizó en un hogar y sus resultados corresponden a ese contexto y a las cuatro personas participantes. No representa una validación en la universidad ni en un recinto público.

La compatibilidad depende de las dimensiones de la puerta y de que se resuelva una unión mecánica removible entre el actuador, el soporte y la puerta. La instalación no debe requerir perforaciones ni modificaciones permanentes en la puerta. El montaje y la demostración final pueden incorporar ajustes; los cambios se explicarán durante la presentación.
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
