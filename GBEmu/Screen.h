#pragma once
#include <vector>
struct pixel {
	char red;
	char green;
	char blue;
};

class Screen
{
private:
	std::vector<pixel>* rawScreen;
public:
	Screen(int sizeX, int sizeY, int setMult);
	~Screen();
	void setPixel(int x, int y, pixel newPix);
	std::vector<pixel>* getPixels();

};

