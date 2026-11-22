# Hardware - Documentación

## Contenido
Esta carpeta contiene toda la documentación técnica del hardware del proyecto.

### 📁 Carpetas

#### `esquemas/`
Diagramas de circuitos y esquemáticos del sistema

#### `bom/`
Bill of Materials (Lista de materiales)

### Prototipo Alpha:
- Microcontrolador: ESP32
- Entrada de activación: botón pulsador
- Actuador: servomotor MG996R
- Otros: protoboard y cables Dupont
- Alimentación: fuente externa de 5 V para el servo y conexión USB para el ESP32

### Prototipo Final:
### Movimiento y estructura
- Actuador lineal ARF03-12-A1-305-200-C11
  - Alimentación: 12 V DC
  - Carrera: 200 mm
  - Carga máxima indicada: 1500 N
  - Velocidad indicada: 6 mm/s
  - Ciclo de trabajo indicado: 10 %
  - Finales de carrera internos en ambos extremos
- Fuente incluida con el actuador
  - Entrada: 100–240 V AC, 50/60 Hz
  - Salida: 12 V DC, 5 A

### Control eléctrico
- ESP32
- Driver BTS7960
- Convertidor DC-DC: entrada de 12 V y salida de 5 V, hasta 3 A
- Fuente incluida con el actuador
  - Entrada: 100–240 V AC, 50/60 Hz
  - Salida: 12 V DC, 5 A
- 2 pulsadores
- Cables y conectores


#### `fotos/`
Fotografías de alta resolución del prototipo ensamblado

---

## Instrucciones de Ensamble

### Componentes Principales
1. [Componente 1] - Función
2. [Componente 2] - Función
3. [Componente 3] - Función

### Pasos de Ensamblaje
1. [Paso 1]
2. [Paso 2]
3. [Paso 3]

### Precauciones
- ⚠️ [Precaución 1]
- ⚠️ [Precaución 2]

---

## Especificaciones Técnicas

**Alimentación:** [Voltaje y corriente]  
**Consumo:** [Watts/mA]  
**Dimensiones:** [mm x mm x mm]  
**Peso:** [gramos]
| Componente | Especificaciones disponibles |
|---|---|
| Actuador lineal | 12 V DC, carrera de 200 mm, carga máxima indicada de 1500 N, velocidad de 6 mm/s, ciclo de trabajo de 10 % |
| Fuente del actuador | Entrada de 100–240 V AC; salida de 12 V DC, 5 A |
| Convertidor DC-DC | Entrada de 12 V; salida de 5 V, hasta 3 A |
| ESP32 | Modelo específico y consumo por confirmar |
| BTS7960 | Módulo puente H; corriente de operación del sistema por verificar |
---

## Troubleshooting

| Problema | Posible Causa | Solución |
|----------|---------------|----------|
| [Problema 1] | [Causa] | [Solución] |
| [Problema 2] | [Causa] | [Solución] |
