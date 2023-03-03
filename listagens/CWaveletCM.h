#ifndef CWaveletCM_h
#define CWaveletCM_h

#include "CWavelet.h"

/*Esta classe herda os atributos e métodos da classe CWavelet e inicializa os atributos por um construtor sobrecarregado
**/

class CWaveletCM: public CWavelet
{	

public:
	
   CWaveletCM() {}  // construtor default
    CWaveletCM ( int n, double dt, double f ); // construtor sobrecarregado
    virtual ~CWaveletCM() {} // destrutor
    
};

#endif
