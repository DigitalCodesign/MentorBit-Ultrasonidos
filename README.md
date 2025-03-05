# MentorBitUltrasonidos

Librería para la medición de distancias mediante un sensor ultrasónico en módulos compatibles con MentorBit.

## Descripción

La librería `MentorBitUltrasonidos` facilita la medición de distancias utilizando un sensor ultrasónico HC-SR04 en módulos compatibles con MentorBit. Permite obtener la distancia a objetos en centímetros, ideal para proyectos de robótica, evitación de obstáculos y medición de distancias.

## Modo de Empleo

1.  **Instalación:**
    * Abre el IDE compatible con MentorBit.
    * Ve a "Herramientas" -> "Gestionar librerías..."
    * Busca "MentorBitUltrasonidos" e instálala.

2.  **Ejemplo básico:**

    ```c++
    #include <MentorBitUltrasonidos.h>

    MentorBitUltrasonidos ultrasonidos(7, 6); // Trigger en pin 7, Echo en pin 6

    void setup() {
      Serial.begin(9600);
      Serial.println("Sensor ultrasónico inicializado.");
    }

    void loop() {
      long distancia = ultrasonidos.obtenerDistancia();
      Serial.print("Distancia: ");
      Serial.print(distancia);
      Serial.println(" cm");
      delay(100);
    }
    ```

## Constructor y Métodos Públicos

### Constructor

* `MentorBitUltrasonidos(uint8_t trigger = 0, uint8_t echo = 0)`: Crea un objeto `MentorBitUltrasonidos`.
    * `trigger`: Pin digital al que está conectado el pin Trigger del sensor.
    * `echo`: Pin digital al que está conectado el pin Echo del sensor.

### Métodos

* `long obtenerDistancia()`: Obtiene la distancia al objeto más cercano en centímetros.
