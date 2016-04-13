#ifndef PIFFILE_H
#define PIFFILE_H

struct PIFFile
{
	unsigned char id[4] = { 'P', 'I', 'F', 0x0 };
	unsigned short int width;
	unsigned short int height;
	unsigned short int levels;
	unsigned int dataSize;

	unsigned char* data;
};

#endif