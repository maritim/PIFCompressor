#include "Compressor.h"

#include "zlib.h"

Compressor::Compressor ()
{

}

Compressor::~Compressor ()
{

}

void Compressor::Compress (uchar* input, std::size_t isize, uchar*& output, std::size_t& osize)
{
    osize = compressBound (isize);

    output = new uchar [osize];

    compress ((Bytef *)output, &osize, (Bytef *)input, isize);

    // TODO: Choose between these too: Delete this at a later commit

	// output = new uchar [isize];

	// z_stream defstream;
	//    defstream.zalloc = Z_NULL;
	//    defstream.zfree = Z_NULL;
	//    defstream.opaque = Z_NULL;

	//    // setup "a" as the input and "b" as the compressed output
	//    defstream.avail_in = (uInt)isize; // size of input, string + terminator
	//    defstream.next_in = (Bytef *)input; // input char array
	//    defstream.avail_out = (uInt)isize; // size of output
	//    defstream.next_out = (Bytef *)output; // output char array

	//    deflateInit(&defstream, Z_BEST_COMPRESSION);
	//    deflate(&defstream, Z_FINISH);
	//    deflateEnd(&defstream);

	//    osize = defstream.total_out;
}

void Compressor::Uncompress (uchar* input, std::size_t isize, uchar*& output, std::size_t& osize)
{
	osize = isize * 3;

	output = new uchar [osize];

	uncompress((Bytef *)output, &osize, (Bytef *)input, isize);
}