#ifndef CWavelet_h
#define CWavelet_h

#include <vector>

/* Esta classe � a classe Base das classes CWaveletMorlet e CWaveletCM,
 nela todos os atributos est�o declarados onde as respectivas classes ir�o herdar e 
 implementar de acordo com a particularidade de cada uma.
**/
class CWavelet
{
protected:
	
	//Declara��o dos Atributos
	double intervaloamostragem;      // Atributo Intervalo de amostragem
	double frequencia;         		// Atributo frequ�ncia
	std::vector<double> amostras;   // Atributo Amostra
    
public:
	
    CWavelet() {} //construtor
    CWavelet( double _intervaloamostragem, double _frequencia )
	: intervaloamostragem( _intervaloamostragem ), frequencia( _frequencia ) {}  //Construtor sobrecarregado	
    virtual ~CWavelet() {} // destrutor 
    
    int GetTamanho() const  { return amostras.size(); }   // M�todo que retorna o tamanho o vetor amostra
    std::vector<double> GetAmostras() const { return amostras; } // M�todo que retorna o vetor amostra
    virtual double GetIntervaloAmostragem() const { return intervaloamostragem; } // retorna o atributo intervalo amostragem
    virtual double GetFrequencia() const          { return frequencia; }         // retorna o atributo frequencia
};

#endif
