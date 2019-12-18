/*
  Archivo: JugadorComputador.h
  Autor: Juan Marcos Caicedo Mejía, Santiago Mejía Martínez, Kevin David Loaiza Giraldo
  Email: juan.marcos.caicedo@correounivalle.edu.co, mejia.santiago@correounivalle.edu.co, kevin.loaiza@correounivalle.edu.co
  Fecha creación: 2017-10-26
  Fecha última modificación: 2017-10-26
  Versión: 0.1
  Licencia: GPL
*/

// Clase: JugadorComputador
// Responsabilidad: En este caso representa un Jugador Computador (máquina) con la misma interfase
// y metodos de Jugador abstracto. Funciona con polimorfismo ya que hereda de Jugador abstracto
// el metodo jugar() pero responde de manera distinta ante el, dando sus jugadas en X y Y
// de manera random.
// Colaboración: es un jugador. 

#ifndef HH_JugadorComputador
#define HH_JugadorComputador

#include<stdlib.h>
#include<iostream>
#include"Jugador.h"

class JugadorComputador : public Jugador
{
    public:
    JugadorComputador();
    void dimeTuJugada(int &jugadaenX,int &jugadaenY);


};

#endif