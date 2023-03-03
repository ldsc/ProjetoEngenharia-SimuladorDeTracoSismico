#ifndef CCamadaAcustica_h
#define CCamadaAcustica_h

#include "CCamada.h"

/* Esta classe recebe os atributos e os m�todos 
da classe CCamada e calcula a imped�ncia
**/

class CCamadaAcustica: public CCamada //heran�a
{
public:
    
    CCamadaAcustica(){}                 // Construtor default
    CCamadaAcustica(double _rho, double _v, double _t):CCamada(_rho, _v, _t){}
    virtual ~CCamadaAcustica() {}       // Destrutor 
    virtual double Z() const;			// M�todo para C�lculo de imped�ncia
};

#endif

