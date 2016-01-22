#ifndef DataPoint_cxx
#define DataPoint_cxx
#include "DataPoint.h"

bool CompareDataPoints(DataPoint a, DataPoint b)
{
	return (a.i < b.i);
}

DataPoints MergeDatasets(DataPoints a, DataPoints b)
{
	DataPoints sum;
	sum.reserve( a.size() + b.size() );
	sum.insert( sum.end(), a.begin(), a.end() );
	sum.insert( sum.end(), b.begin(), b.end() );
	return sum;
}

#endif
