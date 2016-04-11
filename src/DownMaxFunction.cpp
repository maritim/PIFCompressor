#include "DownMaxFunction.h"

uchar DownMaxFunction::Execute (uchar* input)
{
	return std::max (std::max (input [0], input [1]), std::max (input[2], input [3]));
}