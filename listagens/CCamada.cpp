#include "CCamada.h"

	
std::ofstream& operator<<(std::ofstream& fout, const CCamada& c)
{
    fout << c.rho << " " << c.v << " " << c.t;
    return fout;
};

std::ifstream& operator>>(std::ifstream& fin, CCamada& c)
{
    fin >> c.rho >> c.v >> c.t;
    return fin;
};

