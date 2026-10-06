#ifndef CIRCULO_H_INCLUDED
#define CIRCULO_H_INCLUDED

class Circulo
{
private :
    int X , Y , Raio;

public:
    Circulo( int x, int y, int raio );
    Circulo(){};
    int Get_Raio();
    void Set_Raio(int raio);
    void Set_X_Y (int x , int y);
    bool Checar_Colisao(Circulo &A, Circulo &B);

};

#endif // CIRCULO_H_INCLUDED
