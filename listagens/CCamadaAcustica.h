#ifndef CCamadaAcustica_h
#define CCamadaAcustica_h

#include "CCamada.h"

/* Esta classe recebe os atributos e os métodos 
da classe CCamada e calcula a impedância
**/

class CCamadaAcustica: public CCamada //herança
{
public:
    
    CCamadaAcustica(){}                 // Construtor default
    CCamadaAcustica(double _rho, double _v, double _t):CCamada(_rho, _v, _t){}
    virtual ~CCamadaAcustica() {}       // Destrutor 
    virtual double Z() const;			// Método para Cálculo de impedância
};

#endif

