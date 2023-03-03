#ifndef CMeioAcustico_h
#define CMeioAcustico_h

#include <vector>
#include <fstream>
#include "CCamadaAcustica.h"
#include <iostream>

/* Esta classe representa um conjunto de camadas ordenadas em um vetor onde sua principal fun��o � o calculo do vetor Refletividade
**/

class CMeioAcustico
{
protected:
    	std::vector<CCamadaAcustica> camadas; // Atributo 

public:
    CMeioAcustico() {} //construtor default  
    ~CMeioAcustico() {} // destrutor 
    
    // M�todos
   int Tamanho() const { return camadas.size(); }        
   std::vector<double> Tempos() const;    
   std::vector<double> Impedancias() const;
   std::vector<double> Refletividades(double) const;
   void Ler();

//Sobrecarga de Operador
    CCamadaAcustica& operator[](int i) { return camadas[i]; } 
    friend 	std::ofstream& operator<<( std::ofstream&, const CMeioAcustico& ); // Ler 
    friend 	std::ifstream& operator>>( std::ifstream&, CMeioAcustico& );      // Salvar

};

#endif
    
