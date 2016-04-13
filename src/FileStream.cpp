#include "FileStream.h"

#include <cstdio>

FileStream::FileStream ()
{

}

FileStream::~FileStream ()
{

}

void FileStream::SavePIFFile (PIFFile* file, const std::string& name)
{
	FILE* outputFile = fopen (name.c_str (), "wb");

	fwrite (file, sizeof (PIFFile) - sizeof (unsigned int*), 1, outputFile);
	fwrite (file->data, sizeof (unsigned char), file->dataSize, outputFile);

	fclose (outputFile);
}

void FileStream::LoadPIFFile (PIFFile* file, const std::string& name)
{
	FILE* inputFile = fopen (name.c_str (), "rb");

	if (fread (file, sizeof (PIFFile) - sizeof (unsigned int*), 1, inputFile) == 0);

	file->data = new unsigned char [file->dataSize];

	if (fread (file->data, sizeof (unsigned char), file->dataSize, inputFile) == 0);

	fclose (inputFile);
}