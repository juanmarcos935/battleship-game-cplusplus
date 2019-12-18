/*
  Archivo: JugadorHumano.h
  Autor: Juan Marcos Caicedo Mejía, Santiago Mejía Martínez, Kevin David Loaiza Giraldo
  Email: juan.marcos.caicedo@correounivalle.edu.co, mejia.santiago@correounivalle.edu.co, kevin.loaiza@correounivalle.edu.co
  Fecha creación: 2017-10-26
  Fecha última modificación: 2017-10-26
  Versión: 0.1
  Licencia: GPL
*/

// Clase: JugadorHumano
// Responsabilidad: Representa esta vez un jugador Humano, con la misma interfase y metodos que un Jugador abstracto. 
// Funciona con polimorfismo ya que posee la misma función jugar() de Jugador Abstracto pero jugar() de Humano 
// responde de manera distinta al pedir la jugada por teclado.
// Colaboración: es un jugador. 

#ifndef HH_JugadorHumano
#define HH_JugadorHumano

#include<stdlib.h>
#include<iostream>
#include"Jugador.h"

class JugadorHumano : public Jugador
{
    public:
    JugadorHumano();
    void dimeTuJugada(int &jugadaenX,int &jugadaenY);


};

#endif