#ifndef BOLA_JOGADOR_H_INCLUDED
#define BOLA_JOGADOR_H_INCLUDED

class Bola_Jogador
{

private:

    int  Raio;
    int  Position_x;
    int  Position_y;

    SDL_Texture *Imagem;
    int Width;
    int Height;


public:

    Bola_Jogador(SDL_Renderer *Janelarenderizada);
    bool Load_Imagem(SDL_Renderer *Janelarenderizada);
    void Render_Imagem(SDL_Renderer* Janelarenderizada);
    void Set_Position(int x ,int y);
    void Get_Position(int *x,int *y);
    void Free();

};

#endif // BOLA_JOGADOR_H_INCLUDED
