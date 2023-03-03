#include "CTracoSismico.h"

using namespace std;

//implementação da convolução
vector< double > CTracoSismico::Convolucao( vector<double> x, vector<double> y)
{
    	vector< double > z( x.size(), 0.0 );
    int d = ( y.size() - 1 )/2;

    for (int i=d; i<y.size()-1; i++)
        for (int j=0; j<i+1; j++)
            z[i-d] += x[j]*y[i-j];

    for (int i=y.size()-1; i<x.size(); i++)
        for (int j=i+1-y.size(); j<i+1; j++)
            z[i-d] += x[j]*y[i-j];

    for ( int i=x.size(); i<x.size()+d; i++ )
        for ( int j=i+1-y.size(); j<x.size(); j++ )
            z[i-d] += x[j]*y[i-j];

    return z;
};
//implmentação da convolução entre a wavelet e a refletividade, sendo armazenado em um vetor 'traco' 
vector< double > CTracoSismico::GetTraco() const
{
    double dt = wavelet->GetIntervaloAmostragem();
    vector< double > refl = meio.Refletividades(dt);
    vector< double > wlet = wavelet->GetAmostras();
    vector< double > traco = Convolucao(refl, wlet);
    return traco;

};





