#include <SDL.h>
#include <SDL_image.h>
#include <cstdio>
#include <string>
#include "Textura.h"

Texture::Texture()
{
	//Initialize
	Textura = NULL;
	Width = 0;
	Height = 0;
}

Texture::~Texture()
{
	//Deallocate
	free();
}

bool Texture::loadFromFile( std::string path , SDL_Renderer* gRenderer )
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format,0 ,0xFF,0XFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
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
	Textura = newTexture;
	return Textura != NULL;
}

void Texture::free()
{
	//Free texture if it exists
	if( Textura != NULL )
	{
		SDL_DestroyTexture( Textura );
		Textura = NULL;
		Width = 0;
		Height = 0;
	}
}

void Texture::render( int x, int y , SDL_Renderer* gRenderer)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, Width, Height };
	SDL_RenderCopy( gRenderer, Textura, NULL, &renderQuad );

}

int Texture::getWidth()
{
	return Width;
}

int Texture::getHeight()
{
	return Height;
}
