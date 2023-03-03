#ifndef CCamada_h
#define CCamada_h

#include <fstream>

/*Esta classe representa as caractéristicas da camada. 
Recebe de um arquivo de entrada com os atributos densidade, 
velocidade e duplo tempo (assim sabe-se a profundidade da camada)
**/

class CCamada{

protected:
//atributos
	double rho;  // densidade
	double v;   // velocidade da onda cisalhante
    double t;   // duplo tempo 
    

public:	

	CCamada(): rho(0.0), v(0.0), t(0.0) {}                                                 //Construtor
	CCamada( double _rho, double _v, double _t ): rho( _rho ), v( _v ), t( _t ) {}  //Construtor sobrecarregado	
	CCamada( const CCamada &obj ): rho( obj.rho ), v( obj.v) , t( obj.t ) {}       //Construtror de cópia
	
//Destrutor
	virtual ~CCamada() {}
	
//Métodos
	void   SetRho( double _rho ) { rho = _rho; } // seta o atributo densidade
	double GetRho() const      { return rho; }  // retorna o atributo densidade
	void   SetV( double _v )     { v = _v; }    // seta o atributo velocidade 
	double GetV() const        { return v; }    // seta o atributo velocidade
    void   SetT(double _t)     { t = _t; }      // seta o atributo tempo
    double GetT() const        { return t; }    // seta o atributo tempo 
    
	 

//sobrecarga de operador
	friend std::ofstream& operator<<(std::ofstream&, const CCamada&); //Ler do arquivo de entrada
    friend std::ifstream& operator>>(std::ifstream&, CCamada&);   // salva no arquivo de saída
    
};

#endif
