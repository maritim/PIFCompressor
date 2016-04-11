#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include "Singleton.h"

#define uchar unsigned char

class Compressor : public Singleton<Compressor>
{
	friend Singleton<Compressor>;

public:
	void Compress (uchar*, std::size_t, uchar*&, std::size_t&);
	void Uncompress (uchar*, std::size_t, uchar*&, std::size_t&);
private:
	Compressor ();
	~Compressor ();
	Compressor (const Compressor&);
	Compressor& operator=(const Compressor&);
};

#endif