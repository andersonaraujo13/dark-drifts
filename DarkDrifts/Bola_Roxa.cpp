#include "SDL.h"
#include "SDL_image.h"
#include "Bola_Roxa.h"
#include  <iostream>
#include  <ctime>
#include  <cstdlib>
#include  <ctime>


Bola_Roxa::Bola_Roxa(SDL_Renderer *Janelarenderizada)
{

    Flag_Direcao =  Escolhe_Direcao() ;
    Flag = 'P';
    Raio = 19 ;
    Deslocamento_x = Escolhe_Velocidade() / 15;
    Deslocamento_y = Escolhe_Velocidade() / 10;
    Caminho = 0;
    Position_Initial = rand() % 600;


    if ( !Load_Imagem( Janelarenderizada ) )
    {

    std::cout<<"Failed to load sprite texture";

    }


}


bool Bola_Roxa::Load_Imagem(SDL_Renderer *Janelarenderizada)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( "imagens/bolinha rosa.png" );
	if( loadedSurface == NULL )
	{
		std::cout<< "Unable to load image %s! SDL_image Error: %s\n"<<  IMG_GetError() ;
	}
	else
	{
	    SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format,0 ,0xFF,0XFF ) );
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( Janelarenderizada, loadedSurface );
		if( newTexture == NULL )
		{
			std::cout<< "Unable to load image %s! SDL_image Error: %s\n"<<  IMG_GetError() ;
		}
		else
		{
			//Get image dimensions
			Width = loadedSurface->w;
			Height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	Imagem = newTexture;
	return Imagem != NULL;



}

void Bola_Roxa::Render_Imagem( SDL_Renderer* Janelarenderizada )
{
     double velocidade_x , velocidade_y;
     int  x , y ;
     int  x_real,y_real;

     Movimento(&velocidade_x,&velocidade_y);



     switch(Flag_Direcao)
     {
        case 'D' :
            {
                x = Position_Initial + (Caminho * velocidade_x) ;
                y =                (Caminho * velocidade_y) - 10;

                Set_Position(x,y);
                break;
            }
        case 'E' :
            {
                x = Position_Initial - (Caminho * velocidade_x) ;
                y =               (Caminho * velocidade_y) - 10 ;

                Set_Position(x,y);
                break;
            }
        default :
              break;
     }

     if (x < -50 || x > 850 || y > 650)
     {

         Set_Flag('F');
     }


     x_real = x - 31 ;
     y_real = y - 35;


	SDL_Rect renderQuad = { x_real, y_real, Width, Height };
	SDL_RenderCopy( Janelarenderizada, Imagem, NULL, &renderQuad );


}



char Bola_Roxa::Get_Flag()
{

    return Flag;

}
char Bola_Roxa::Escolhe_Direcao()
{

    switch (rand() % 2)
    {
       case 0 :

            return 'D';
            break;
       case 1:

            return 'E';
            break;
    }

}

void Bola_Roxa::Set_Position(int x , int y)
{
    Position_x = x;
    Position_y = y;
}

void Bola_Roxa::Get_Position(int *x, int *y)
{

    *x = Position_x;
    *y = Position_y;

}

void Bola_Roxa::Movimento(double *velocidade_x , double *velocidade_y)
{
    *velocidade_x = Deslocamento_x;
    *velocidade_y = Deslocamento_y;

}
void Bola_Roxa::Set_Caminho()
{
    Caminho = Caminho + 1;
}

void Bola_Roxa::Set_Flag(char Novo_Estado)
{
    Flag = Novo_Estado;

}

void Bola_Roxa::Free()
{
    SDL_DestroyTexture(Imagem);
    Imagem = NULL;
}

double Bola_Roxa::Escolhe_Velocidade()
{

 double Numero =(rand() % 3 ) + 1;
 return Numero;


}
