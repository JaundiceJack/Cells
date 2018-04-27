/*
 * Texture.cpp
 *
 *  Created on: Feb 2, 2017
 *      Author: jmcneilan
 */

#include "Texture.h"

//initialize the texture and it's size
Texture::Texture() {
	tTexture = NULL;
	textSurface = NULL;
	loadedImage = NULL;

	tWidth = 0;
	tHeight = 0;
}

//free memory of the texture
Texture::~Texture() {
	free();
}

//loadImageFromFile: converts an image at the given path to a texture
bool Texture::loadImageFromFile(SDL_Renderer* renderer, string path){
	//create a surface to load the image onto
	loadedImage = IMG_Load(path.c_str());
	if(loadedImage == NULL){
		cout << "IMG: Failed to load image from " << path.c_str() << endl;
		cout << "IMG Error: " << IMG_GetError() << endl;
		return false;
	}

	//convert the surface to a texture
	tTexture = SDL_CreateTextureFromSurface(renderer, loadedImage);
	if(tTexture == NULL){
		cout << "SDL: Failed to convert image surface to texture." << endl;
		cout << "SDL Error: " << SDL_GetError() << endl;
		return false;
	}

	//assign image dimensions
	else{
		tWidth = loadedImage->w;
		tHeight = loadedImage->h;
	}

	//get rid of surface
	SDL_FreeSurface(loadedImage);

	//return true if everything went well
	return true;
}

//getTexture: returns a pointer to the object's texture
SDL_Texture* Texture::getTexture(){
	return tTexture;
}

//returns the dimensions of the texture
int Texture::getWidth(){
	return tWidth;
}
int Texture::getHeight(){
	return tHeight;
}

//render: copies the texture to the renderer at the coordinate given
void Texture::render(SDL_Renderer* renderer, int xpos, int ypos){
	//where and how big the texture will be rendered
	SDL_Rect renderQuad  = {xpos, ypos, tWidth, tHeight};
	//renderQuad = new SDL_Rect(xpos, ypos, tWidth, tHeight);
	SDL_RenderCopy(renderer, tTexture, NULL, &renderQuad);
}

//free:  destroys the texture if it exists
void Texture::free(){
	if(tTexture != NULL){
		SDL_DestroyTexture(tTexture);
		tTexture = NULL;
		tWidth = 0;
		tHeight = 0;
	}
}
