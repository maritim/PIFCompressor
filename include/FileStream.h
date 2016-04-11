#ifndef FILESTREAM_H
#define FILESTREAM_H

#include "Singleton.h"

#include <string>

#include "PIFFile.h"

class FileStream : public Singleton<FileStream>
{
	friend Singleton<FileStream>;

public:
	void LoadPIFFile (PIFFile* file, const std::string& name);
	void SavePIFFile (PIFFile* file, const std::string& name);
private:
	FileStream ();
	~FileStream ();
	FileStream (const FileStream&);
	FileStream& operator=(const FileStream&);
};

#endif