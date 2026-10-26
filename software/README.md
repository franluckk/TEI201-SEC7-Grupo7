#  Sistema Inclusivo de Apertura de Puertas - Grupo 7

**Curso:** TEI201 - Taller de Diseño en Ingeniería  
**Institución:** Design Engineering Center (DEC) - Universidad Adolfo Ibáñez  
**Equipo:** Francisca, Carla, Sebastián e Ignacio  

##  Descripción del Proyecto
Este proyecto aborda el **ODS 10 (Reducción de Desigualdades)** eliminando las barreras físicas que representan las puertas manuales convencionales para personas con movilidad reducida. Se alinea con el **ODS 12 (Producción y Consumo Responsables)** mediante un enfoque de instalación no invasiva, permitiendo automatizar puertas existentes mediante abrazaderas y soportes sin necesidad de perforar o reemplazar la infraestructura de la universidad.

El repositorio contiene el código, la documentación técnica y los diagramas de hardware de nuestro **Prototipo Alpha IoT Funcional**.

##  Estructura del Repositorio

El proyecto está organizado en los siguientes directorios:

*  **`/software`**: Código fuente para el microcontrolador ESP32, librerías dependientes (ESP32Servo) y documentación lógica del sistema (incluyendo mitigación de rebotes y gestión de consumo eléctrico).
*  **`/hardware`**: Lista de materiales (BOM), diagramas de conexión, justificación de componentes y archivos base para la conceptualización 3D del encapsulado.
*  **`/docs`**: Material de apoyo de presentaciones, guiones y manuales de operación (incluyendo el Avance #2).

## Estado del Proyecto
* [x] **Avance 1:** Definición del problema e ideación.
* [x] **Avance 2:** Prototipo Alpha IoT Funcional (Validación de control ESP32, estabilidad eléctrica con fuente externa y mitigación de ruido térmico mediante software).
* [ ] **Avance 3:** Escalabilidad a prototipo final (Implementación de actuador lineal de 12V y driver DC).

## 🛠️ Tecnologías Utilizadas
* **Hardware:** Microcontrolador ESP32, Servomotor MG996R (Fase Alpha).
* **Software:** C/C++ (Arduino IDE), ESP32Servo.
* **Modelado 3D:** Tinkercad (Diseño conceptual del encapsulado).
