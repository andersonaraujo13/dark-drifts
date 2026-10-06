#include "SDL.h"
#include "SDL_image.h"
#include "Bola_Jogador.h"
#include  <iostream>
#include  <ctime>
#include  <cstdlib>
#include  <ctime>


Bola_Jogador::Bola_Jogador(SDL_Renderer *Janelarenderizada)
{

    Raio = 19 ;

    if ( !Load_Imagem( Janelarenderizada ) )
    {

    std::cout<<"Failed to load sprite texture";

    }


}


bool Bola_Jogador::Load_Imagem(SDL_Renderer *Janelarenderizada)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( "imagens/bolinha azul - jogador.png" );
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

void Bola_Jogador::Render_Imagem( SDL_Renderer* Janelarenderizada )
{
     SDL_ShowCursor(SDL_DISABLE);
     int  x , y ;
     SDL_GetMouseState(&x,&y);

     int x_real,y_real;
     x_real = x - 40;
     y_real = y - 29;

    Set_Position(x,y);

	SDL_Rect renderQuad = { x_real ,y_real, Width, Height };
	SDL_RenderCopy( Janelarenderizada, Imagem, NULL, &renderQuad );


}

void Bola_Jogador::Set_Position(int x , int y)
{
    Position_x = x;
    Position_y = y;
}

void Bola_Jogador::Get_Position(int *x, int *y)
{

    *x = Position_x;
    *y = Position_y;

}

void Bola_Jogador::Free()
{
    SDL_DestroyTexture(Imagem);
    Imagem = NULL;
}







