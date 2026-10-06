#ifndef BOLA_VERMELHA_H_INCLUDED
#define BOLA_VERMELHA_H_INCLUDED

class Bola_Vermelha
{

private:

    char Flag;
    char Flag_Direcao;
    int  Raio;
    int  Position_x;
    int  Position_y;
    int  Position_Initial;
    double  Deslocamento_x;
    double  Deslocamento_y;
    int Caminho;

    SDL_Texture *Imagem;
    int Width;
    int Height;


public:

    Bola_Vermelha(SDL_Renderer *Janelarenderizada);
    bool Load_Imagem(SDL_Renderer *Janelarenderizada);
    void Render_Imagem(SDL_Renderer* Janelarenderizada);
    char Get_Flag();
    char Escolhe_Direcao();
    void Set_Flag(char Novo_Estado);
    void Set_Position(int x ,int y);
    void Get_Position(int *x,int *y);
    void Movimento(double *velocidade_x , double *velocidade_y);
    void Set_Caminho();
    void Free();
    double Escolhe_Velocidade();
};

#endif // BOLA_VERMELHA_H_INCLUDED
