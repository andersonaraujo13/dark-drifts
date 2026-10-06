#include <cmath>
#include "Circulo.h"
#include<iostream>

Circulo::Circulo( int x, int y, int raio ) : X(x),Y(y), Raio( raio ) {}

int Circulo::Get_Raio()
{
    return Raio;
}

void Circulo::Set_X_Y(int x,int y)
{
    X = x;
    Y = y;
}
bool Circulo::Checar_Colisao( Circulo &A, Circulo &B )
{


    int Raiototal = A.Raio + B.Raio;
    Raiototal = Raiototal * Raiototal;
    int Dx = A.X - B.X;
    int Dy = A.Y - B.Y;
    int distanciatotal = Dx * Dx + Dy * Dy ;


    if( distanciatotal < Raiototal )
    {
        return true;
    }


    return false;
}


void Circulo::Set_Raio(int raio)
{
    Raio = raio;
}
