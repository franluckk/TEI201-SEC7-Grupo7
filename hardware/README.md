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
1. Fuente 12 V DC, 5 A - Alimenta todo el sistema (actuador y convertidor).
2. Convertidor DC-DC (12 V a 5 V, hasta 3 A) - Baja el voltaje para alimentar el ESP32.
3. ESP32 - Lee los pulsadores y envía las órdenes de movimiento al driver.
4. Driver BTS7960 - Puente H que entrega la potencia al actuador e invierte su sentido.
5. Actuador lineal ARF03-12-A1-305-200-C11 - Abre y cierra la puerta.
6. 2 pulsadores - Activan la apertura y el cierre (en paralelo, mismo pin).

### Pasos de Ensamblaje
Realizar todo con la fuente desconectada de la red eléctrica.
1. Dividir la salida de la fuente en paralelo (regleta o bornera) hacia el driver y el convertidor, con cable de al menos 18 AWG.
2. Conectar + y − de la fuente a B+ y B− del driver, y a IN+ e IN− del convertidor.
3. Medir con multímetro la salida del convertidor y confirmar 5 V antes de conectarlo al ESP32.
4. Conectar OUT+ (5 V) del convertidor al pin VIN del ESP32 y OUT− a un GND del ESP32.
5. Conectar al driver: 3V3 del ESP32 a VCC, GND a GND, D21 a R_EN y L_EN (unidos), D18 a RPWM y D19 a LPWM.
6. Conectar M+ y M− del driver a los cables rojo y negro del actuador.
7. Conectar los dos pulsadores en paralelo entre D4 y GND del ESP32.
8. Revisar todas las conexiones contra el esquema (`esquemas/`) antes de energizar.
9. Cargar el código al ESP32 por USB y probar con el actuador sin carga.

### Precauciones
- ⚠️ Desconectar la fuente de la red antes de modificar cualquier cableado.
- ⚠️ No usar cables jumper delgados para los 12 V: usar cable de al menos 18 AWG.
- ⚠️ Verificar polaridad y los 5 V del convertidor antes de conectar el ESP32, que no admite 12 V.
- ⚠️ Respetar el ciclo de trabajo del 10 % indicado para el actuador: no operarlo de forma continua.
- ⚠️ La carcasa impresa en PLA solo protege la electrónica; no debe soportar la fuerza del actuador.
- ⚠️ Se recomienda un fusible en el positivo de 12 V (no incluido en el esquema actual).

---

## Especificaciones Técnicas

**Alimentación:** 100–240 V AC a 12 V DC, 5 A (fuente); 5 V para el ESP32 (convertidor)  
**Consumo:** Por medir con multímetro bajo carga real  
**Dimensiones:** Por medir una vez ensamblado  
**Peso:** Por medir una vez ensamblado
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
| El ESP32 no enciende | El convertidor no entrega 5 V o está mal conectado | Medir la salida del convertidor y revisar VIN y GND |
| El actuador no se mueve | R_EN / L_EN sin señal, o falta GND común | Revisar D21 hacia R_EN y L_EN, y la unión de GND entre ESP32 y driver |
| Se mueve al revés | M+ y M− invertidos | Intercambiar los cables del actuador en el driver |
| Los pulsadores no responden | Cable suelto en D4 o GND | Revisar conexiones; la consola serial debe mostrar el mensaje al presionar |
| El actuador se detiene a mitad de recorrido | `TIEMPO_RECORRIDO` menor al tiempo real (200 mm a 6 mm/s, unos 33 s) | Subir el valor en el código (por ejemplo, 35000 ms) |
| El driver se calienta | Operación continua o cable delgado | Respetar el ciclo de trabajo, revisar el calibre del cable y agregar ventilación |

## Troubleshooting

| Problema | Posible Causa | Solución |
|----------|---------------|----------|
| [Problema 1] | [Causa] | [Solución] |
| [Problema 2] | [Causa] | [Solución] |
