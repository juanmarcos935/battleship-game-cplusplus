/*
  Archivo: Tablero.h
  Autor: Juan Marcos Caicedo Mejía, Santiago Mejía Martínez, Kevin David Loaiza Giraldo
  Email: juan.marcos.caicedo@correounivalle.edu.co, mejia.santiago@correounivalle.edu.co, kevin.loaiza@correounivalle.edu.co
  Fecha creación: 2017-10-26
  Fecha última modificación: 2017-10-26
  Versión: 0.1
  Licencia: GPL
*/

// Clase: Tablero
// Responsabilidad: Mantiene los datos de un tablero de barquitos de 10x10 casillas, con el siguiente código en cada casilla:
//          0=AGUA, 1=BARCO, 2=TOCADO, 3=HUNDIDO, 4=ALREDEDORES
// Colaboración: ninguna.


#ifndef HH_Tablero
#define HH_Tablero

#include<stdlib.h>
#include<iostream>


class Tablero
{
  private:
    int tablero[10][10];

  public:
    /** Construye el tablero de 10 x 10 casillas colocando al azar:
        - 3 barcos de 2 casillas
        - 2 barcos de 3 casillas
        - 1 barcos de 4 casillas
    */
    Tablero();
    void imprimir();
    void limpiarCuatros();
    bool haHabidoImpacto(int x, int y);
    void marcarImpacto(int x, int y);
    bool estaElBarcoHundido(int x, int y);
    void marcarHundimiento(int x, int y);
    bool todosImpactados();
    
    
  protected:
    void ponerBarcoAlAzar(int tamano);
    bool intentarPonerBarco(int vertical, int horizontal, int orientacion,int tamano);
    bool revisarSiEstaLibre(int vertical, int horizontal, int orientacion, int tamano);
    void ponerBarco(int vertical, int horizontal, int orientacion, int tamano);
};

#endif