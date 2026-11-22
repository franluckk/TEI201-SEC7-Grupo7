# Bill of Materials (BOM)

## Formato del Archivo

Esta lista registra los componentes utilizados o previstos para los prototipos del sistema automático para abrir una puerta. Se indica si cada elemento fue comprado, ya estaba disponible o fue proporcionado por el DEC.

## Prototipo Alpha

| Cantidad | Componente | Especificación conocida | Tienda o procedencia | Precio (CLP) |
|---:|---|---|---|---:|
| 1 | Microcontrolador ESP32 | Microcontrolador | Tienda por confirmar | $8.000 |
| 1 | Servomotor MG996R | Actuador del prototipo Alpha | Proporcionado por el DEC | $0 |
| 1 | Botón pulsador grande | Normalmente abierto, color negro | MCI Electronics | $990 |
| 1 | Conector DC adaptador hembra | Adaptador para conexión de alimentación | MCI Electronics | $2.990 |
| 1 | Protoboard | Para conexiones de prueba | Ya disponible | $0 |
| Según montaje | Cables para la ESP32 | Cables que el equipo ya tenía disponibles | Ya disponibles | $0 |
| Según montaje | Cables Dupont | Cables comprados para las conexiones del prototipo | MCI Electronics | $1.500 |

**Total registrado del Prototipo Alpha: aproximadamente $13.480 CLP.**

## Prototipo final

| Cantidad | Componente | Especificación conocida | Procedencia | Precio (CLP) |
|---:|---|---|---|---:|
| 1 | Actuador lineal | ARF03-12-A1-305-200-C11; 12 V DC; carrera de 200 mm; carga máxima indicada de 1500 N; velocidad de 6 mm/s; ciclo de trabajo de 10 % | Hangar77 | $44.800 |
| 1 | Fuente de alimentación | Entrada de 100–240 V AC, 50/60 Hz; salida de 12 V DC, 5 A | Hangar77 | $52.000 |
| 1 | Microcontrolador ESP32 | Microcontrolador del sistema | Comprado | Aproximadamente $8.000 |
| 1 | Driver puente H BTS7960 | Módulo para controlar el sentido de movimiento del actuador |  Mercado Libre  | $11.500 |
| 1 | Convertidor DC-DC | Entrada de 12 V; salida de 5 V, hasta 3 A (15 W) |  Mercado Libre  | $9.990 |
| 2 | Botones pulsadores | Entradas de control ubicadas a ambos lados de la puerta | Proporcionados por el DEC | $0 |
| Según montaje | Cables para la ESP32 y las conexiones | Cables que el equipo ya tenía disponibles | Ya disponibles | $0 |
| Según diseño | Soportes y elementos de fijación | Pernos, tuercas y arandelas necesarios para el montaje | el equipo ya tenia disponibles | $0 |
| 1 | Caja para electrónica | Carcasa diseñada en Fusion 360 | En diseño | Pendiente |
---

## Archivos a Incluir

- `bom_completo.xlsx` - Lista completa de materiales
- `bom_completo.pdf` - Versión PDF para visualización
- `datasheets/` - Carpeta con PDFs de componentes críticos

---

## Presupuesto Total

**Costo total registrado: aproximadamente $139.770 CLP.**

Este total suma los componentes del prototipo final y del Prototipo Alpha.

La ESP32 se cuenta una sola vez, aunque se utilice en ambos prototipos. El total no incluye soportes ni elementos de fijación cuyo precio aún no está confirmado.

### Desglose por categoría

- **Actuación y movimiento:** $44.800 CLP (actuador lineal).
- **Alimentación:** $61.990 CLP (fuente de 12 V: $52.000; convertidor DC-DC: $9.990).
- **Control electrónico:** aproximadamente $20.490 CLP (ESP32: aproximadamente $8.000; driver BTS7960: $11.500; botón del Prototipo Alpha: $990).
- **Conexiones del Prototipo Alpha:** aproximadamente $4.490 CLP (conector DC hembra: $2.990; cables comprados para el Alpha: aproximadamente $1.500).
- **Caja 3D:** $0 CLP en filamento para el equipo; se utilizará filamento que ya tenía un integrante.
- **Componentes proporcionados por el DEC o ya disponibles:** $0 CLP registrados (servomotor MG996R, botones del prototipo final, protoboard y cables que el equipo ya tenía).

> Los costos de soportes y elementos de fijación están pendientes de definir.```
