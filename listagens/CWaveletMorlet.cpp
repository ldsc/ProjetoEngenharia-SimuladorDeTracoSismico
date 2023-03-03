#include "CWaveletMorlet.h"
#include <math.h>


CWaveletMorlet::CWaveletMorlet( int n, double dt, double f )
: CWavelet(dt, f) 
{
    double aux = pow(2.0*M_PI*f, 2);
    double t0 = -dt*(n/2);
    for (int i=0; i<n; i++)
    {
        double t = t0 + i*dt;
        amostras.push_back(( cos( 2.0*M_PI*f*t ) - exp( -0.5*aux ))*exp( -M_PI*f*t*t ));
    };
};
