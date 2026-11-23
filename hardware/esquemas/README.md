[diagram.json](https://github.com/user-attachments/files/35251521/diagram.json)# Esquemas de Circuito
<img width="1360" height="1050" alt="esquema_circuito" src="https://github.com/user-attachments/assets/d77786a4-4894-44ae-916b-ae5b6a95d4d5" />


## Archivos Requeridos



### Formato Wokwi



<img width="947" height="722" alt="image" src="https://github.com/user-attachments/assets/3bc6f8f3-e050-49b2-b37b-1cb26e0eff5c" />


[- `wokwi_link.txt` - URL del proyecto online](https://wokwi.com/projects/481444511266939905)

---

## Notas de Diseño

### Alimentación
- Una sola fuente de 12 V / 5 A alimenta todo el sistema. Su salida se
  divide en paralelo: el voltaje (12 V) se mantiene igual en ambos
  caminos y cada módulo toma solo la corriente que necesita.
- El driver BTS7960 recibe los 12 V directo de la fuente (B+ y B−), porque
  el actuador consume entre 3 y 5 A y esa corriente no debe pasar por el
  convertidor ni por la placa del ESP32.
- El ESP32 se alimenta a 5 V por el pin VIN desde el convertidor DC-DC.
  El microcontrolador no admite 12 V directamente.

### Tierra común
- El GND de la fuente, del convertidor, del ESP32 y del driver está unido.
  Sin referencia común, las señales de control del ESP32 no son leídas
  correctamente por el driver.

### Control del actuador
- Se usa el BTS7960 (puente H) para invertir la polaridad: RPWM extiende el
  actuador y LPWM lo retrae. El ESP32 nunca activa ambos a la vez.
- Los pines R_EN y L_EN van unidos a D21. Al terminar cada movimiento se
  desactivan, equivalente al detach() del prototipo alfa, para evitar
  consumo y calentamiento en reposo.
- El VCC lógico del driver se conecta a 3V3 del ESP32.
- El actuador tiene finales de carrera internos, por lo que se detiene
  solo al llegar al tope de su recorrido.

### Entradas
- Dos botones en paralelo comparten el pin D4 con INPUT_PULLUP, sin
  resistencias externas. Cualquiera de los dos abre o cierra la puerta.

### Cableado
- Los cables de 12 V (fuente, driver, actuador) deben ser de al menos
  18 AWG. Los jumpers delgados solo se usan para señales del ESP32.
- Se recomienda un fusible de 5 A en el positivo de 12 V (no incluido en
  el esquema actual).

### Simulación
- Wokwi no incluye el BTS7960, el convertidor ni el actuador. En la
  simulación, tres LEDs representan las señales RPWM, LPWM y R_EN/L_EN.
