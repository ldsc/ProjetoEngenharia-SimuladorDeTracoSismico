#include "CWaveletCM.h"
#include <math.h>


CWaveletCM::CWaveletCM (int n, double dt, double f )
: CWavelet(dt,f) 
{
    double aux = pow( M_PI*f, 2 );
    double t0 = -dt*( n/2 );
    for ( int i=0; i<n; i++ )
    {
        double t = t0 + i*dt;
        amostras.push_back(( 1.0 - 2.0*aux*t*t )*exp( -aux*t*t ));
    };
};
