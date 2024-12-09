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


/*
    Constructor, se dben indiar el pin de echo y de trigger
*/
MentorBitUltrasonidos::MentorBitUltrasonidos(uint8_t trigger = 0, uint8_t echo = 0){
    _port.gpios[0] = trigger;
    _port.gpios[1] = echo;
    pinMode(_port.gpios[0],OUTPUT);
    pinMode(_port.gpios[1],INPUT);
}

/*
    Función que obtiene el valor de la posicion marcada por el encoder
*/
long MentorBitUltrasonidos::obtenerDistancia(){
    long time_in;
    long distance; // cm

    digitalWrite(_port.gpios[0],LOW);
    delayMicroseconds(4);
    digitalWrite(_port.gpios[0],HIGH);
    delayMicroseconds(10);
    digitalWrite(_port.gpios[0],LOW);

    time_in = pulseIn(_port.gpios[1],HIGH);

    distance = (time_in * 10 )/( 292 * 2);
    return distance;
}

void MentorBitUltrasonidos::configPort(const Port& port) {

    _port.type = port.type;
    _port.location = port.location;
    _port.gpios[0] = port.gpios[0];
    _port.gpios[1] = port.gpios[1];

}
