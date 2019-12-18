/*
  Archivo: Jugador.h
  Autor: Juan Marcos Caicedo Mejía, Santiago Mejía Martínez, Kevin David Loaiza Giraldo
  Email: juan.marcos.caicedo@correounivalle.edu.co, mejia.santiago@correounivalle.edu.co, kevin.loaiza@correounivalle.edu.co
  Fecha creación: 2017-10-26
  Fecha última modificación: 2017-10-26
  Versión: 0.1
  Licencia: GPL
*/

// Clase: Jugador
// Responsabilidad: Representa un jugador abstracto que tiene una jugada en X y una jugada en Y, de la cual se infiere su proximo movimiento.
// Colaboración: (es la clase padre de JugadorComputador & JugadorHumano).

#ifndef HH_Jugador
#define HH_Jugador

#include<stdlib.h>
#include<iostream>
using namespace std;

class Jugador
{
  protected:
  int jugadaenX;
  int jugadaenY;
  
  public:
  Jugador();
  virtual void dimeTuJugada(int &jugadaenX,int &jugadaenY);

};

#endif