#ifndef TEXTURA_H_INCLUDED
#define TEXTURA_H_INCLUDED

class Texture
{
	public:
		//Initializes variables
		Texture();

		//Deallocates memory
		~Texture();

		//Loads image at specified path
		bool loadFromFile( std::string path,SDL_Renderer* Renderer );

		//Deallocates texture
		void free();

		//Renders texture at given point
		void render( int x, int y ,SDL_Renderer* Renderer );

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* Textura;

		//Image dimensions
		int Width;
		int Height;
};

#endif // TEXTURA_H_INCLUDED
