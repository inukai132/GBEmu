#include "Screen.h"

Screen::Screen(int sizeX, int sizeY, int setMult)
{
	int totalPix = sizeX * sizeY;
	rawScreen = new std::vector<pixel>(totalPix);
}

Screen::~Screen()
{
}

void Screen::setPixel(int x, int y, pixel newPix)
{
}

std::vector<pixel>* Screen::getPixels()
{
	return rawScreen;
}
