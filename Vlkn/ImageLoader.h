#ifndef __IMAGE_LOADER_H__
#define __IMAGE_LOADER_H__

struct ImageLoader
{
public:
	unsigned char* pixels;
	int texWidth = 0;
	int texHeight = 0;
	int texChannels = 0;

public:
	bool LoadImage(const char* filename);
	//bool GetPixels(const char* filename, int& texWidth, int& texHeight, int& texChannels, unsigned char*& pixels);
	void DestroyImage();
};

#endif