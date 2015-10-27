/*Univarsidad del valle de Guatemala
 *Algoritmos y estruxturas de datos
 *Seccion 10
 *Christopher Antonio Chiroy Miranda, 14411
 *Pedro Joaquin Castillo Coronado, 14224
 *Boris Ramiro Cifuentes de Leon, 14150
 *Freddy Jose Ruiz Gatica, 14592
 */


#include "simpletools.h"                      // Include simpletools header
#include "ping.h"                             // Include ping header
#include "abdrive.h"

int distance1;                                 //Se declara distancia que mide el sensor 1
int distance2;                                 //Se declara distancia que mide el sensor 2

int main(){
  while(1){                                   //Ciclo infinito
    distance1 = ping_cm(8);                   //Distancia sensor 1 (Enfrente)conectado al pin 8                
    distance2 = ping_cm(4);                   //Distancia sensor 2 (Derecha) conectado al pin 4
    
    if(distance2<10){                         //Distancia derecha < 10:           
      if(distance1<13){                       //      Si disntacia de enfrente < 13 
        drive_speed(0, 0);                    //            Frenar el carrito
        drive_goto(0, 50);                    //            girar 90 grados a la izquierda
        pause(200);                           //            tiempo de giro
      }
      else{                                   //      Si distancia de enfrente > 13
        drive_speed(64, 64);                  //            Avanzar hacia adelante
        pause(100);                           //            tiempo en volver a analizar la distancia
      }                
    }
    
    else{                                     //Distancia derecha > 10:
     drive_speed(0, 0);                       //      Frenar el carrito
     drive_goto(25, 25);                      //      Avanzar hacia adelante para girar
     pause(200);                              //      pausa para avanzar 
     drive_goto(26, -25);                     //      Giro derecha
     pause(200);                              //      Pausa para girar
     drive_goto(35, 35);                      //      Avanza hacia enfrente
     pause(200);                              //      Pausa para avanzar
    }             
  } 
}
