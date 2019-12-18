/*
  Archivo: Arbitro.h
  Autor: Juan Marcos Caicedo Mejía, Santiago Mejía Martínez, Kevin David Loaiza Giraldo
  Email: juan.marcos.caicedo@correounivalle.edu.co, mejia.santiago@correounivalle.edu.co, kevin.loaiza@correounivalle.edu.co
  Fecha creación: 2017-10-26
  Fecha última modificación: 2017-10-26
  Versión: 0.1
  Licencia: GPL
*/

// Clase: Arbitro
// Responsabilidad: Darle un flujo al juego y poder desde su conocimiento ser 
// quien tenga la batuta de la partida. Decide quien juega y dice cuando el juego ha terminado. A su vez, anuncia las jugadas/movimientos.
// Colaboración: Conoce ambos tableros (tableroHumano y tableroComputador). Conoce ambos jugadores (jugadorHumano y jugadorComputador)

#ifndef HH_Arbitro
#define HH_Arbitro

#include<stdlib.h>
#include<iostream>
#include"Jugador.h"
#include"JugadorHumano.h"
#include"JugadorComputador.h"
#include"Tablero.h"


class Arbitro
{
  protected:
  Tablero tableroHumano;
  Tablero tableroComputador;
  JugadorHumano jugadorHumano;
  JugadorComputador jugadorComputador;
  
  public:
  Arbitro(Tablero &tableroHumano,Tablero &tableroComputador,JugadorHumano &jugadorHumano,JugadorComputador &jugadorComputador);
  void comenzarAJugar();
  bool gameOver();
  
};

#endif