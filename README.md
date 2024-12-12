# MentorBit-Ultrasonidos
Esta librería está construida por Digital Codesign para utilizar el módulo de Ultrasonidos, principalmente diseñado para el kit educacional "MentorBit".

Puedes encontrar nuestro MentorBit y mucho más material de electrónica y robótica en nuestra tienda oficial:  [https://digitalcodesign.com/shop](https://digitalcodesign.com/shop)

# Modo de empleo

Una vez tengamos la librería instalada desde el Arduino IDE, tenemos que incluir la librería con la siguiente línea:

``#include <MentorBitUltrasonidos.h>``

Este sensor necesita de dos pines para funcionar: "Trigger", que cuando se activa manda una señal de una frecuencia alta hacia delante; y "Echo", que recive esta señal y manda el tiempo en ms que tardó la señal en llegar al receptor.


Para usar el sensor, efinimos los puertos por los que vamos a mandar y recivir la señal al sensor de ultrasonidos:

``#define PIN_ECHO A4
#define PIN_TRIGGER 24``


### Constructor

Una vez incluida la librería y definido el pin dl zumbador, usamos el constructor para crear el objeto del zumbador, y empleamos el pin del zumbador que definimos anteriormente:

``MentorBitUltrasonidos Ultrasonidos(PIN_TRIGGER,PIN_ECHO);``


### Uso

Con nuestro sensor de ultrasonidos ya definido, ya podemos emplear la función "obtenerDistancia()" para obtener la distancia del objeto más cercano. 

``Ultrasonidos.obtenerdistancia()``

A partir de aquí, podemos usar el código de ejemplo para crear alguna melodía, o el uso que se le quiera dar. 
