#ifndef __IMAGE_LOADER_H__
#define __IMAGE_LOADER_H__

struct ImageLoader
{
private:
	unsigned char* pixels;

public:
	bool GetPixels(const char* filename, int& texWidth, int& texHeight, int& texChannels, unsigned char*& pixels);
	void DestroyPixels();
};

#endif