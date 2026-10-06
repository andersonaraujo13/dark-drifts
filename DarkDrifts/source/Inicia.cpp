#include<iostream>
#include<cstdio>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "Textura.h"
#include "Inicia.h"
#include "Jogo.h"

int PAGINA = 0;

//CONSTANTES DE ALTURA E LARGURA
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
//CONSTANTES DE ALTURA E LARGURA DE BOTÕES
const int BUTTON_WIDTH = 254;
const int BUTTON_HEIGHT = 57;
const int TOTAL_BUTTONS = 4;
const int BUTTON_WIDTH_BACK = 85;
const int BUTTON_HEIGHT_BACK = 24;

enum Button_Estado
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4,
};Button_Estado Mouse_CurrentSprite;

//Carregando Texture
Texture Recordes;
Texture Como_Jogar;
Texture Creditos;
Texture Inicia_Jogo;
Texture Tela_Fundo;
Texture TelaJogo;
Texture TelaGuia;
Texture Volta;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
//Icone Janela
SDL_Surface* Icone_Janela;
//Rendered texture



bool Inicia::IniciaSDL()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{

		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Dark Drifts", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
		    //Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
                Icone_Janela=IMG_Load("imagens/ICONE.png");
                if (!Icone_Janela)
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                   success = false;
                }
                else
                    {
                    SDL_SetWindowIcon(gWindow,Icone_Janela);
                    }
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                //Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;
	//Carrega Botões/Tela inicial/Estaticos.
	if( !TelaGuia.loadFromFile( "imagens/Como jogar.jpg",gRenderer ))
	{
		printf( "Failed to load button sprite texture!\n" );
		success = false;
	}
	if( !Volta.loadFromFile( "imagens/voltar_sem_textura.jpg",gRenderer ))
	{
		printf( "Failed to load button sprite texture!\n" );
		success = false;
	}
    if( !Recordes.loadFromFile( "imagens/recordes sem textura.jpg",gRenderer ))
	{
		printf( "Failed to load button sprite texture!\n" );
		success = false;
	}
	if( !Como_Jogar.loadFromFile( "imagens/como jogar sem textura.jpg",gRenderer ))
	{
		printf( "Failed to load button sprite texture!\n" );
		success = false;
	}
	if( !Creditos.loadFromFile( "imagens/creditos sem textura.jpg",gRenderer ))
	{
		printf( "Failed to load button sprite texture!\n" );
		success = false;
	}
	if( !Tela_Fundo.loadFromFile( "imagens/teladefundo.jpg",gRenderer ))
	{
		printf( "Failed to load button sprite texture!\n" );
		success = false;
	}
	if( !TelaJogo.loadFromFile( "imagens/imagem de fundo sem logo.jpg",gRenderer ))
	{
		printf( "Failed to load button sprite texture!\n" );
		success = false;
	}
	if( !Inicia_Jogo.loadFromFile( "imagens/iniciar jogo sem textura.jpg",gRenderer ))
	{
		printf( "Failed to load button sprite texture!\n" );
		success = false;
	}

	return success;
}

void Inicia::Fechar()
{
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void Inicia::StartSDL()
{

	//Start up SDL and create window
	if( !IniciaSDL() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
    //Load media
        if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
        else
		{
			//Main loop flag
			bool quit = false;
			//Event handler
			SDL_Event e;
			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}
                //Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );
                Jogo *Play = new Jogo;
				//Render current frame

    switch(PAGINA)
    {
    case 0:
    SDL_ShowCursor( SDL_ENABLE);

    SDL_Point Mouse_Position;
    Mouse_Position.x=268;
    Mouse_Position.y=314;
    Tela_Fundo.render(0,0,gRenderer);
	if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if( x < Mouse_Position.x || x > Mouse_Position.x + BUTTON_WIDTH )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < Mouse_Position.y || y > Mouse_Position.y + BUTTON_HEIGHT)
		{
			inside = false;
		}

		//Mouse is outside button
		if( !inside )
		{
			Mouse_CurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e.type )
			{
				case SDL_MOUSEMOTION:
				Mouse_CurrentSprite= BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;

				case SDL_MOUSEBUTTONDOWN:
				Mouse_CurrentSprite= BUTTON_SPRITE_MOUSE_DOWN;
				break;

				case SDL_MOUSEBUTTONUP:
				Mouse_CurrentSprite = BUTTON_SPRITE_MOUSE_UP;
				break;
			}
		}
	}

    switch (Mouse_CurrentSprite)
            {
    case BUTTON_SPRITE_MOUSE_OVER_MOTION:
	     Inicia_Jogo.render(268,314,gRenderer);
	     break;

	case BUTTON_SPRITE_MOUSE_DOWN:
         break;

	case BUTTON_SPRITE_MOUSE_UP:

         PAGINA = 1;
         Inicia_Jogo.render(268,314,gRenderer);
	     break;

	default:
	     break;
			}
    Mouse_Position.x=268;
    Mouse_Position.y=383;
	if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if( x < Mouse_Position.x || x > Mouse_Position.x + BUTTON_WIDTH )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < Mouse_Position.y || y > Mouse_Position.y + BUTTON_HEIGHT)
		{
			inside = false;
		}

		//Mouse is outside button
		if( !inside )
		{
			Mouse_CurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e.type )
			{
				case SDL_MOUSEMOTION:
				Mouse_CurrentSprite= BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;

				case SDL_MOUSEBUTTONDOWN:
				Mouse_CurrentSprite= BUTTON_SPRITE_MOUSE_DOWN;
				break;

				case SDL_MOUSEBUTTONUP:
				Mouse_CurrentSprite = BUTTON_SPRITE_MOUSE_UP;
				break;
			}
		}
	}

    switch (Mouse_CurrentSprite)
            {
    case BUTTON_SPRITE_MOUSE_OVER_MOTION:
	     Como_Jogar.render(268,382,gRenderer);
	     break;

	case BUTTON_SPRITE_MOUSE_DOWN:
         break;

	case BUTTON_SPRITE_MOUSE_UP:
         PAGINA = 2;
         Como_Jogar.render(268,382,gRenderer);
	     break;

	default:
	     break;
			}
    Mouse_Position.x=268;
    Mouse_Position.y=452;
	if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if( x < Mouse_Position.x || x > Mouse_Position.x + BUTTON_WIDTH )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < Mouse_Position.y || y > Mouse_Position.y + BUTTON_HEIGHT)
		{
			inside = false;
		}

		//Mouse is outside button
		if( !inside )
		{
			Mouse_CurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e.type )
			{
				case SDL_MOUSEMOTION:
				Mouse_CurrentSprite= BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;

				case SDL_MOUSEBUTTONDOWN:
				Mouse_CurrentSprite= BUTTON_SPRITE_MOUSE_DOWN;
				break;

				case SDL_MOUSEBUTTONUP:
				Mouse_CurrentSprite = BUTTON_SPRITE_MOUSE_UP;
				break;
			}
		}
	}

    switch (Mouse_CurrentSprite)
            {
    case BUTTON_SPRITE_MOUSE_OVER_MOTION:
	     Recordes.render(268,452,gRenderer);
	     break;

	case BUTTON_SPRITE_MOUSE_DOWN:
         break;

	case BUTTON_SPRITE_MOUSE_UP:
         Recordes.render(268,452,gRenderer);
	     break;

	default:
	     break;
			}
    Mouse_Position.x=268;
    Mouse_Position.y=518;
	if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if( x < Mouse_Position.x || x > Mouse_Position.x + BUTTON_WIDTH )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < Mouse_Position.y || y > Mouse_Position.y + BUTTON_HEIGHT)
		{
			inside = false;
		}

		//Mouse is outside button
		if( !inside )
		{
			Mouse_CurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e.type )
			{
				case SDL_MOUSEMOTION:
				Mouse_CurrentSprite= BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;

				case SDL_MOUSEBUTTONDOWN:
				Mouse_CurrentSprite= BUTTON_SPRITE_MOUSE_DOWN;
				break;

				case SDL_MOUSEBUTTONUP:
				Mouse_CurrentSprite = BUTTON_SPRITE_MOUSE_UP;
				break;
			}
		}
	}

    switch (Mouse_CurrentSprite)
            {
    case BUTTON_SPRITE_MOUSE_OVER_MOTION:
	     Creditos.render(268,518,gRenderer);
	     break;

	case BUTTON_SPRITE_MOUSE_DOWN:
         break;

	case BUTTON_SPRITE_MOUSE_UP:
         Creditos.render(268,518,gRenderer);
	     break;

	default:
	     break;
			}
            break;
				//Update screen
        case 1:
				SDL_RenderClear( gRenderer );
                Play->Iniciar_Jogo(gWindow,gRenderer);
                PAGINA = 0 ;
                delete Play;
                Play = NULL;
            break;
        case 2:
                SDL_RenderClear(gRenderer);
                Mouse_Position.x=693;
                Mouse_Position.y=556;
                TelaGuia.render(0,0,gRenderer);
                if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
                {
                    //Get mouse position
                    int x, y;
                    SDL_GetMouseState( &x, &y );

                    //Check if mouse is in button
                    bool inside = true;

                    //Mouse is left of the button
                    if( x < Mouse_Position.x || x > Mouse_Position.x + BUTTON_WIDTH_BACK )
                    {
                        inside = false;
                    }
                    //Mouse above the button
                    else if( y < Mouse_Position.y || y > Mouse_Position.y + BUTTON_HEIGHT_BACK)
                    {
                        inside = false;
                    }

                    //Mouse is outside button
                    if( !inside )
                    {
                        Mouse_CurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
                    }
                    //Mouse is inside button
                    else
                    {
                        //Set mouse over sprite
                        switch( e.type )
                        {
                            case SDL_MOUSEMOTION:
                            Mouse_CurrentSprite= BUTTON_SPRITE_MOUSE_OVER_MOTION;
                            break;

                            case SDL_MOUSEBUTTONDOWN:
                            Mouse_CurrentSprite= BUTTON_SPRITE_MOUSE_DOWN;
                            break;

                            case SDL_MOUSEBUTTONUP:
                            Mouse_CurrentSprite = BUTTON_SPRITE_MOUSE_UP;
                            break;
                        }
                    }
                }

                switch (Mouse_CurrentSprite)
                        {
                case BUTTON_SPRITE_MOUSE_OVER_MOTION:
                     Volta.render(693,556,gRenderer);
                     break;

                case BUTTON_SPRITE_MOUSE_DOWN:
                     break;

                case BUTTON_SPRITE_MOUSE_UP:
                     PAGINA = 0;
                     Volta.render(693,556,gRenderer);
                     break;
                default:
                     break;
                        }
            break;
        case 3:

            break;
        case 4:

            break;
        }

				SDL_RenderPresent( gRenderer );
			}
		}

	}

	//Free resources and close SDL
	Fechar();
}
//Clear screen


