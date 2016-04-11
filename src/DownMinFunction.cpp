#include "DownMinFunction.h"

uchar DownMinFunction::Execute (uchar* input)
{
	return std::min (std::min (input [0], input [1]), std::min (input [2], input [3]));
}