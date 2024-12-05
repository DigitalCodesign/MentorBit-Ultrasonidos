/*


          ██████╗    ██╗    ██████╗    ██╗   ████████╗    █████╗    ██╗
          ██╔══██╗   ██║   ██╔════╝    ██║   ╚══██╔══╝   ██╔══██╗   ██║
          ██║  ██║   ██║   ██║  ███╗   ██║      ██║      ███████║   ██║
          ██║  ██║   ██║   ██║   ██║   ██║      ██║      ██╔══██║   ██║
          ██████╔╝   ██║   ╚██████╔╝   ██║      ██║      ██║  ██║   ███████╗
          ╚═════╝    ╚═╝    ╚═════╝    ╚═╝      ╚═╝      ╚═╝  ╚═╝   ╚══════╝

   ██████╗    ██████╗    ██████╗    ███████╗   ███████╗   ██╗    ██████╗    ███╗   ██╗
  ██╔════╝   ██╔═══██╗   ██╔══██╗   ██╔════╝   ██╔════╝   ██║   ██╔════╝    ████╗  ██║
  ██║        ██║   ██║   ██║  ██║   █████╗     ███████╗   ██║   ██║  ███╗   ██╔██╗ ██║
  ██║        ██║   ██║   ██║  ██║   ██╔══╝     ╚════██║   ██║   ██║   ██║   ██║╚██╗██║
  ╚██████╗   ╚██████╔╝   ██████╔╝   ███████╗   ███████║   ██║   ╚██████╔╝   ██║ ╚████║
   ╚═════╝    ╚═════╝    ╚═════╝    ╚══════╝   ╚══════╝   ╚═╝    ╚═════╝    ╚═╝  ╚═══╝


  Autor: Digital Codesign
  Version: 1.0.0
  Fecha de creación: Septiembre de 2024
  Fecha de version: Septiembre de 2024
  Repositorio: 
  Descripcion:
    Esta libreria esta especificamente diseñada para ser utilizada junto con
    el modulo ultrasonidos de MentorBit
  Metodos principales:
    obtenerDistancia() - > devuelve el valor de la distancia a la cual hay un objeto frontal en cm

*/

#include "MentorBitUltrasonidos.h"
#include <arduino.h>

/*
    Constructor, se dben indiar el pin de echo y de trigger
*/
MentorBitUltrasonidos::MentorBitUltrasonidos(uint8_t trigger, uint8_t echo){
    _trigger = trigger;
    _echo = echo;
    pinMode(_trigger,INPUT);
    pinMode(_echo,INPUT);
}

/*
    Función que obtiene el valor de la posicion marcada por el encoder
*/
long MentorBitUltrasonidos::obtenerDistancia(){
    long time_in;
    long distance; // cm

    digitalWrite(_trigger,LOW);
    delayMicroseconds(4);
    digitalWrite(_trigger,HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigger,LOW);

    time_in = pulseIn(_echo,HIGH);

    distance = (time_in * 10 )/( 292 * 2);
    return distance;
}