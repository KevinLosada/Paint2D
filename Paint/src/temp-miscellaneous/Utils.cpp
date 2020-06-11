#include "Utils.h"
#include "Cleanup.h"

/**
* Log an SDL error with some error message to the output stream of our choice
* @param os The output stream to write the message to
* @param msg The error message to write, format will be msg error: SDL_GetError()
*/
void Utils::logSDLError(std::ostream& os, const std::string& msg) {
	os << msg << " error: " << SDL_GetError() << std::endl;
}

/**
* Loads a BMP image into a texture on the rendering device
* @param file The BMP image file to load
* @param ren The renderer to load the texture onto
* @return the loaded texture, or nullptr if something went wrong.
*/
// TODO: Finish writing function
//SDL_Texture* loadTexture(const std::string& file, SDL_Renderer* ren) {
//	//initialize to nullptr to avoid dangling pointers
//	SDL_Texture* texture = nullptr;
//	//load bmp
//	SDL_Surface* loadedImage = SDL_LoadBMP(file.c_str());
//	//if success convert to texture and return it
//	if (loadedImage != nullptr) {
//		texture = SDL_CreateTextureFromSurface(ren, loadedImage);
//		SDL_FreeSurface(loadedImage);
//	}
//	
//	//Cleanup::cleanup()
//}
