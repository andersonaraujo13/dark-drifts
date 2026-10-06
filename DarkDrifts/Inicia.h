#ifndef INICIA_H_INCLUDED
#define INICIA_H_INCLUDED

class Inicia
{

// inicio do video sdl, prepara o video para as funçoes sdl

//**********************************************************************//

private:

bool IniciaSDL();   //inicia sytema de video , retorna um booleano com o estatus
bool CarregaSDL(); //carrega a primeira imagem , e possiveis sons inicias....
void Fechar();    //fecha todos os subsstemas do sdl, destroy janela.

public:

void StartSDL();//executa todos os sistemas acima

//**********************************************************************//

};

#endif // INICIA_H_INCLUDED
