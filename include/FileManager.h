#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Singleton.h"

#include <string>

#include "Image.h"

class FileManager : public Singleton<FileManager>
{
	friend Singleton<FileManager>;

public:
	Image* LoadImage (const std::string& name);
	void SaveImage (Image* image, const std::string& name);
private:
	FileManager ();
	~FileManager ();
	FileManager (const FileManager&);
	FileManager& operator=(const FileManager&);
};

#endif