
#ifndef LTEXTURA_H_INCLUDED
#define LTEXTURA_H_INCLUDED

class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path, SDL_Renderer* Renderer);

		//Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor, SDL_Renderer* Renderer);

        bool loadFromRenderedNunber(SDL_Color textColor, SDL_Renderer* gRenderer, const char *format, ...);


        void print(int x,int y,const char *format, ...);

		//Deallocates texture
		void free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );

		//Renders texture at given point
		void render( int x, int y, SDL_Renderer* Renderer, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
};

#endif // LTEXTURA_H_INCLUDED
