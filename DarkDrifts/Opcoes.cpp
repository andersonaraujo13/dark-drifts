#include<iostream>
#include<cstdio>
#include "SDL.h"
#include "SDL_image.h"
#include "Textura.h"
#include "Opcoes.h"


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;





Texture Telamenu;
Texture Botao;

bool Opcoes::Carregamenu(SDL_Renderer* Janela )
{
    //Loading success flag
    bool sucesso = true;

   if( !Telamenu.loadFromFile( "imagens/teladefundo.png",Janela ) )
	{
		printf( "Failed to load Foo' texture image!\n" );
		sucesso = false;
	}

	//Load background texture
	if( !Botao.loadFromFile( "imagens/BOTAO.png",Janela ) )
	{
		printf( "Failed to load background texture image!\n" );
		sucesso = false;
	}
    return sucesso;
}


void Opcoes::Fecharmenu()
{
	//DESALOCA IMAGEM
	Telamenu.free();
	Botao.free();

}


void Opcoes::Startmenu(SDL_Renderer* Janela)
{


		if( !Carregamenu(Janela) )
		{
			printf( "FALHA NA INICIALIZACAO!\n" );
		}
		else
		{

			bool quit = false;

                // CRIA UM EVENTO (NO CASO PARA FECHAR A JANELA)
                SDL_Event Fechar;


			while( !quit )
			{

				while( SDL_PollEvent( &Fechar ) != 0 )
				{

					if( Fechar.type == SDL_QUIT )
					{
						quit = true;
					}
				}

                //Render background texture to screen
				Telamenu.render( 0, 0 , Janela);

				//Render Foo' to the screen
				Botao.render( 240, 190 , Janela );

				//Update screen
				SDL_RenderPresent( Janela );
			}
		}



	Fecharmenu();

}



