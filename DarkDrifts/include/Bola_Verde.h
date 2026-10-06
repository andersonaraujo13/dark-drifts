#ifndef BOLA_VERDE_H_INCLUDED
#define BOLA_VERDE_H_INCLUDED

class Bola_Verde
{

private:

    char Flag;
    char Flag_Direcao;
    int  Raio;
    int  Position_x;
    int  Position_y;
    int  Position_Initial;
    int  Colisao_x;
    int  Colisao_y;
    double  Deslocamento_x;
    double  Deslocamento_y;
    int Caminho;

    SDL_Texture *Imagem;
    int Width;
    int Height;


public:

    Bola_Verde(SDL_Renderer *Janelarenderizada);
    bool Load_Imagem(SDL_Renderer *Janelarenderizada);
    void Render_Imagem(SDL_Renderer* Janelarenderizada);
    void Render_Imagem_Manual(SDL_Renderer* Janelarenderizada,int x , int y);
    char Get_Flag();
    char Escolhe_Direcao();
    void Set_Flag(char Novo_Estado);
    void Set_Flag_Direcao(char Novo_Estado);
    void Set_Position(int x ,int y);
    void Set_Colisao(int x,int y);
    void Get_Position(int *x,int *y);
    void Get_Colisao(int *x,int *y);
    void Movimento(double *velocidade_x , double *velocidade_y);
    void Set_Caminho();
    void Free();
    double Escolhe_Velocidade();
};

#endif // BOLA_VERDE_H_INCLUDED
