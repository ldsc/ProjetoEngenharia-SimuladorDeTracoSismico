#ifndef CWavelet_h
#define CWavelet_h

#include <vector>

/* Esta classe é a classe Base das classes CWaveletMorlet e CWaveletCM,
 nela todos os atributos estão declarados onde as respectivas classes irão herdar e 
 implementar de acordo com a particularidade de cada uma.
**/
class CWavelet
{
protected:
	
	//Declaração dos Atributos
	double intervaloamostragem;      // Atributo Intervalo de amostragem
	double frequencia;         		// Atributo frequência
	std::vector<double> amostras;   // Atributo Amostra
    
public:
	
    CWavelet() {} //construtor
    CWavelet( double _intervaloamostragem, double _frequencia )
	: intervaloamostragem( _intervaloamostragem ), frequencia( _frequencia ) {}  //Construtor sobrecarregado	
    virtual ~CWavelet() {} // destrutor 
    
    int GetTamanho() const  { return amostras.size(); }   // Método que retorna o tamanho o vetor amostra
    std::vector<double> GetAmostras() const { return amostras; } // Método que retorna o vetor amostra
    virtual double GetIntervaloAmostragem() const { return intervaloamostragem; } // retorna o atributo intervalo amostragem
    virtual double GetFrequencia() const          { return frequencia; }         // retorna o atributo frequencia
};

#endif
