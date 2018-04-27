#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

//used from standard library
using std::cout;
using std::endl;
using std::string;

class Texture {
public:
	//initialize the texture's memory and size
	Texture();
	//get rid of everything
	~Texture();

	//take a renderer and a path to a png image and create a texture from it
	bool loadImageFromFile(SDL_Renderer* renderer, string path);

	//copy the texture to the renderer at the given coordinates
	void render(SDL_Renderer* renderer, int xpos, int ypos);

	//return a pointer to the texture
	SDL_Texture* getTexture();

	//returns the dimensions of the texture
	int getWidth();
	int getHeight();

	//destroys the texture and frees memory of it
	void free();

private:
	//the texture itself
	SDL_Texture* tTexture;

	//a surface for the text or image so it doesn't have to be created and destroyed every time you render text
	SDL_Surface* textSurface;
	SDL_Surface* loadedImage;

	//texture's dimensions
	int tWidth;
	int tHeight;
};
#endif /* TEXTURE_H_ */
