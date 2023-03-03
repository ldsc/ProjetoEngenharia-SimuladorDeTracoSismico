#ifndef CWaveletMorlet_h
#define CWaveletMorlet_h

#include "CWavelet.h"

class CWaveletMorlet: public CWavelet
{

public:
	
	CWaveletMorlet() {}                         // Construtor default
    CWaveletMorlet(int n, double dt, double f); // construtor sobrecarregado
    virtual ~CWaveletMorlet() {}    // destrutor

};

#endif
