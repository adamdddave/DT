#ifndef DataPoint_h
#define DataPoint_h
#include <Riostream.h>
#include <vector>
#include <cmath>

using namespace std;
// data point
class DataPoint {
public:
	DataPoint() : i(0), t(0.), t2(0.), nRS(0.), nWS(0.), sRS(0.), sWS(0.) {;}

	double r() const { return nWS/nRS; }
	double sr() const {
		double rWS  = sWS/nWS;
		double rRS  = sRS/nRS;
		return r()*sqrt(rWS*rWS+rRS*rRS);
	}

	static std::ostream &PrintTitle(std::ostream &out=std::cout) {
		out << setw(2) << "i" << "\t";
		out << setw(10) << "t(i)" << "\t" << setw(10) << "t2(i)" << "\t";
		out << setw(28) << "N_RS(i)" << "\t";
		out << setw(28) << "N_WS(i)" << "\t";
		out << setw(28) << "R(i)" << std::endl;
		return out;
	}

	std::ostream &Print(std::ostream &out=std::cout) {
		out << setw(2) << i << "\t";
		out << setw(10) << t << "\t" << setw(10) << t2 << "\t";
		out << setw(12) << nRS << " +/-" << setw(12) << sRS << "\t";
		out << setw(12) << nWS << " +/-" << setw(12) << sWS << "\t";
		out << setw(12) << r() << " +/-" << setw(12) << sr() << std::endl;
		return out;
	}

	std::istream &Read(std::istream &in) {
		return in >> i >> t >> t2 >> nRS >> sRS >> nWS >> sWS;
	}

	int i;
	double t, t2, nRS, nWS, sRS, sWS;
};

typedef std::vector<DataPoint> DataPoints;

bool CompareDataPoints(DataPoint a, DataPoint b);

DataPoints MergeDatasets(DataPoints a, DataPoints b);

#endif
