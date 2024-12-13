

# MentorBit-Ultrasonidos

Esta librería está construida por Digital Codesign para utilizar el módulo de Ultrasonidos, principalmente diseñado para el kit educacional "MentorBit".

Puedes encontrar nuestro MentorBit y mucho más material de electrónica y robótica en nuestra tienda oficial: [https://digitalcodesign.com/shop](https://digitalcodesign.com/shop)

# Modo de empleo

Una vez tengamos la librería instalada desde el Arduino IDE, tenemos que incluirla con la siguiente línea:

```cpp
#include <MentorBitUltrasonidos.h>
```

Este sensor utiliza dos pines para funcionar correctamente:

- **Trigger (o disparo)**: Este pin emite una señal de alta frecuencia cuando se activa, que se envía hacia adelante para detectar un objeto.
- **Echo (o eco)**: Este pin recibe la señal reflejada por el objeto y mide el tiempo que tarda en regresar, lo que nos permite calcular la distancia.

Para usar el sensor, definimos los puertos para el **Trigger** y **Echo**:

```cpp
#define PIN_ECHO A4
#define PIN_TRIGGER 24
```

### Constructor

Una vez incluida la librería y definidos los pines, usamos el constructor para crear el objeto del sensor de ultrasonidos, pasando los pines de **Trigger** y **Echo** como parámetros:

```cpp
MentorBitUltrasonidos Ultrasonidos(PIN_TRIGGER, PIN_ECHO);
```

### Uso

Con nuestro sensor de ultrasonidos definido, podemos utilizar la función `obtenerDistancia()` para obtener la distancia al objeto más cercano en centímetros. La función devolverá el valor en tipo `float`.

```cpp
float distancia = Ultrasonidos.obtenerDistancia();
```

A partir de aquí, puedes utilizar el valor de distancia para realizar cualquier operación o acción en tu proyecto, como activar otros dispositivos según la proximidad del objeto.

