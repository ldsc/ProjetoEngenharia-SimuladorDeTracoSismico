#ifndef CTracoSismico_h
#define CTracoSismico_h

#include <vector>
#include "CMeioAcustico.h"
#include "CWavelet.h"
#include "CGnuplot.h"

///Esta classe executa a convolu��o entre o veotr de refletividades e a fun��o wavelet escolhida


class CTracoSismico
{
protected:
	///atributos
    CMeioAcustico meio;
    CWavelet* wavelet;

public:
    CTracoSismico() {}///construtor default
    CTracoSismico( CMeioAcustico meio_, CWavelet* wavelet_ ): meio( meio_ ), wavelet( wavelet_ ) {} ///contrutor sobrecarregado
    CTracoSismico( const CTracoSismico &obj ): meio( obj.meio ), wavelet( obj.wavelet) {} ///construtor de c�pia 
    ~CTracoSismico() {} ///destrutor

	///m�todos
    CMeioAcustico GetMeio()    { return meio; }
    CWavelet* GetWavelet() { return wavelet; }
    std::vector< double > GetTraco() const;
    static std::vector<double> Convolucao(std::vector< double >, std::vector< double > );

};

#endif

