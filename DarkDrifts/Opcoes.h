#ifndef OPCOES_H_INCLUDED
#define OPCOES_H_INCLUDED
#include"SDL_image.h"
class Opcoes
{
public:
void Iniciajogo();
void Configuracoes();
void Ajuda();

bool Carregamenu(SDL_Renderer* Janela );
void Fecharmenu();
void Startmenu(SDL_Renderer* Janela);
};

#endif // OPCOES_H_INCLUDED
