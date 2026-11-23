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
- **Control direccional de potencia (Puente H):** Se reemplaza el control angular PWM (`ESP32Servo`) de la v1 por señales digitales de inversión de polaridad (`RPWM` en pin `D18` para extender y `LPWM` en pin `D19` para retraer), gobernadas por tiempo de carrera (`TIEMPO_RECORRIDO = 10000` ms) y respaldadas por los finales de carrera internos del actuador lineal.
- **Soporte para doble pulsador sin complejidad extra:** Se mantiene la lectura en el pin `D4` (`PIN_BOTON`) con resistencia interna `INPUT_PULLUP` conectando ambos botones en paralelo hacia `GND`, permitiendo accionar apertura o cierre indistintamente desde ambos lados de la puerta con una única lógica de alternancia (`estadoPuerta`).

**Optimizaciones finales:**
- **Eliminación de librerías externas de servomotores:** Al operar el driver BTS7960 mediante salidas digitales nativas (`digitalWrite`), el código deja de depender de la librería `ESP32Servo`, reduciendo el consumo de memoria y simplificando la compilación.
- **Modo de reposo energético (`PIN_ENABLE`):** Se traslada el concepto de `detach()` del prototipo Alpha al hardware industrial utilizando los pines `R_EN` y `L_EN` unidos al pin `D21`, apagando por completo los canales del driver tras completar cada recorrido (`detenerMotor()`) para evitar consumo en reposo y calentamiento.

**Manejo de errores:**
- **Enclavamiento lógico anti-cortocircuito:** Las funciones `extenderActuador()` y `retraerActuador()` aseguran explícitamente poner en `LOW` el canal opuesto antes de activar el sentido deseado, evitando disparos simultáneos en el puente H.
- **Filtrado antirrebote (debounce) y trazabilidad:** Se conserva el bloqueo mediante ciclo `while (digitalRead(PIN_BOTON) == LOW)` para evitar múltiples activaciones por pulsaciones prolongadas, junto con mensajes de estado por Monitor Serie a `115200` baudios.
- **Estado inicial seguro:** En `setup()` se ejecuta `detenerMotor()` antes de iniciar el ciclo principal, garantizando que el actuador permanezca inmovilizado al energizar el sistema.

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

**Indicadores de impacto considerados:**

- **Accesibilidad (ODS 10):** el sistema busca facilitar la apertura de una puerta a personas con movilidad reducida y a quienes tengan las manos ocupadas. Este propósito se observó cualitativamente durante una prueba en un hogar; no se midió su impacto en una comunidad.
- **Adaptación de infraestructura existente (ODS 12):** el diseño busca instalarse de forma removible, sin perforar ni modificar permanentemente la puerta. La solución de montaje todavía debe verificarse en la instalación.
- **Reutilización de componentes (ODS 12):** se reutiliza la ESP32 del prototipo Alpha y se considera usar filamento disponible en el equipo para la caja electrónica.

No se calcularon porcentajes de mejora ni proyecciones de beneficiarios, porque no se recopilaron datos para realizar esos cálculos.

---

## Comparación de las 2 Iteraciones

| Aspecto | Iteración 1: prototipo Alpha | Iteración 2: sistema para puerta |
|---|---|---|
| Propósito | Comprobar el control del movimiento con una prueba a escala. | Diseñar un sistema removible para accionar una puerta mediante un actuador lineal. |
| Movimiento | El servomotor movía una tablita, no accionaba una puerta. | El actuador lineal está destinado a producir el movimiento de apertura y cierre. |
| Controlador | ESP32. | Se reutiliza la ESP32. |
| Actuador | Servomotor MG996R. | Actuador lineal de 12 V, modelo ARF03-12-A1-305-200-C11. |
| Control de movimiento | Señal PWM por ángulos (`0°`/`60°`) con librería `ESP32Servo` y corte térmico por software (`detach()`). | Driver puente H BTS7960 controlado por pines digitales (`D18`/`D19`) y habilitación por hardware (`D21` en `R_EN`/`L_EN`) sin librerías externas. |
| Entradas | Un botón pulsador en `D4` (`INPUT_PULLUP`). | Dos botones pulsadores en paralelo hacia `D4` (`INPUT_PULLUP`). |
| Montaje mecánico | Prueba a escala, sin unión a una puerta real. | Fijación removible entre el actuador, un soporte y la puerta, sin perforarla ni modificarla permanentemente. |
| Prueba con personas | No se registró una prueba de uso con participantes. | Prueba cualitativa en un hogar con cuatro participantes. |
| Resultados de uso | No aplica: el prototipo representaba el movimiento mediante una tablita. | Los cuatro participantes comprendieron cómo usarlo en el contexto de la prueba. Se sugirió incluir instrucciones visibles para un posible uso en espacios públicos. |
| Métricas cuantitativas | No registradas. | No se registraron tiempos, tasas de error ni promedios de satisfacción. |

---

## Fortalezas del Prototipo de la Iteración 2

1. **Pasa de una prueba a escala a un diseño pensado para accionar una puerta.**
   - En el prototipo Alpha, el servomotor movía una tablita.
   - En esta iteración se considera un actuador lineal de 12 V para generar el movimiento de apertura y cierre.

2. **Tiene un control simple de comprender.**
   - Se consideran dos botones pulsadores, ubicados a ambos lados de la puerta.
   - En la prueba realizada en un hogar, las cuatro personas participantes comprendieron cómo usar el sistema.

3. **Busca adaptarse a una puerta existente de forma removible.**
   - El diseño busca evitar perforaciones o modificaciones permanentes en la puerta.
 
---

## Limitaciones Identificadas

1. **Prueba realizada solo en un hogar**
   - **Descripción:** participaron cuatro personas en una prueba cualitativa en el hogar de un integrante del equipo.
   - **Impacto:** los resultados no permiten asegurar cómo funcionaría el sistema en un recinto público o con una cantidad mayor de usuarios.
   - **Trabajo futuro:** realizar pruebas adicionales en distintos contextos y registrar las observaciones de cada sesión.

2. **Falta de instrucciones para personas que no conocen el sistema**
   - **Descripción:** durante la prueba en el hogar, las personas conocían el contexto de uso. Para un espacio público, alguien podría no saber qué botón presionar.
   - **Impacto:** la falta de indicaciones podría dificultar el primer uso.
   - **Trabajo futuro:** incorporar un cartel visible y breve que explique cómo activar la apertura.

3. **Sin métricas cuantitativas de uso**
   - **Descripción:** no se registraron tiempos de tarea, tasas de error ni puntajes de satisfacción.
   - **Impacto:** no es posible calcular promedios ni porcentajes de mejora.
   - **Trabajo futuro:** definir una pauta de observación y recopilar esas mediciones en futuras pruebas.

---

## Aprendizajes del Proceso Completo

### Técnicos

1. El prototipo Alpha permitió probar el control del movimiento con una ESP32 y un servomotor, pero mover una tablita a escala no demuestra que el sistema pueda accionar una puerta.
2. Para pasar a un actuador lineal se deben considerar su alimentación independiente de 12 V, el aislamiento lógico mediante el driver BTS7960 y el apagado de los canales de habilitación (`R_EN`/`L_EN`) en reposo para mantener la eficiencia energética.

### De Diseño

1. Diseñar para una puerta real exige considerar sus dimensiones y definir puntos de apoyo para el actuador.
2. La condición de que el sistema sea removible debe incorporarse desde el diseño de la fijación, evitando perforar o modificar permanentemente la puerta.

### De Trabajo en Equipo

1. El proyecto requiere coordinar decisiones de electrónica, programación y diseño mecánico para que los componentes funcionen como un sistema.
2. Las pruebas y los comentarios de otras personas ayudan a detectar aspectos que el equipo puede pasar por alto, como la necesidad de instrucciones visibles en espacios públicos.

### De Gestión de Proyecto

1. Medir la puerta y verificar la disponibilidad de componentes con anticipación ayuda a tomar decisiones de diseño más realistas.
2. Conviene distinguir en la documentación entre lo que está diseñado, lo que está montado y lo que ya fue probado.

---

## Trabajo Futuro Recomendado

### Próximos pasos

- [ ] Definir y probar la fijación removible entre el actuador, el soporte y la puerta.
- [ ] Comprobar que el montaje no requiera perforaciones ni modificaciones permanentes en la puerta.
- [ ] Revisar el funcionamiento del actuador, los botones y el circuito en el montaje final.
- [ ] Incorporar instrucciones visibles para orientar a quienes no conozcan el sistema.
- [ ] Registrar observaciones y mediciones en pruebas futuras.

### Mejoras posteriores

- Evaluar la instalación en puertas con distintas dimensiones y características.
- Revisar la resistencia y estabilidad de los soportes durante ciclos repetidos de uso.
- Evaluar el uso del sistema en otros contextos, manteniendo el carácter removible de la instalación.

---

## Archivos en esta Carpeta

- `v3_codigo_final.ino` - Código final documentado para ESP32 y driver BTS7960
- `v3_esquema_final.png` - Esquema definitivo del circuito
- `v3_modelo3d_final.f3d` - Diseño 3D completo en Fusion 360
- `v3_testing_completo.pdf` - Reporte de testing con usuarios
- `v3_comparativa_versiones.xlsx` - Datos comparativos v1-v2