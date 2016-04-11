#ifndef PIFCOMPRESSOR_H
#define PIFCOMPRESSOR_H

#include "Singleton.h"

#include <string>

class PIFCompressor : public Singleton<PIFCompressor>
{
	friend Singleton<PIFCompressor>;

public:
	void Compress (const std::string& filename, const std::string& ofilename);
	void Decompress (const std::string& filename, const std::string& ofilename);

private:
	PIFCompressor ();
	~PIFCompressor ();
	PIFCompressor (const PIFCompressor&);
	PIFCompressor& operator=(const PIFCompressor&);
};

#endif