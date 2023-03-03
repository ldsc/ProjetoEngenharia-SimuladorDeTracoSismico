#include "CWaveletMorlet.h"
#include "CWaveletCM.h"
#include "CMeioAcustico.h"
#include "CTracoSismico.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

//Este é o programa principal

using namespace std;

int main()
{
   
    cout << "---------------------Geração de Traço Sísmico------------------\n" ;
    cout << "\n\n Autores: Ramon Diogo e Sávio Januario \n Disciplina: Programação Prática em C++ \n" ;
    cout << "\n\n-----------------------------------------------------------\n" ;
    
    
    cout << "Você deseja carregar os dados manualmente ou ler do arquivo? \n(1)Carregar Manualmente \n(2)Ler do arquivo\n";
    int escolha; //cria variável inteira
    cin >> escolha; //armazena o valor digitado na variável
    cin.get();
    cout << "\n\a-------------------------------------------------------------\n"; 
    CMeioAcustico meio; //cria objeto do tipo CMeioAcustico
    switch (escolha) //cria uma função condicional
	{
    	case 1:
    		meio.Ler(); //executa a função Ler() da classe CMeioAcustico
    		break;
    		
    	case 2:
    		string nomearquivo1; //cria variável do tipo string
		cout << "Qual o nome do arquivo com as propriedades do meio acústico? \n";
    		cin >> nomearquivo1; //armazena nome digitado na variável
    	        ifstream fin(nomearquivo1.c_str());
			fin >> meio; //Lê arquivo
   			fin.close();
    		cin.get();
    		break;
	}
        CWavelet* wav; //cria ponteiro da classe CWavelet
   	int escolha1;
   	cout << "\n-----------------------------------------------------------------\n"; 
	cout << "Qual tipo de wavelet deseja utilizar?\n(1) Chapéu Mexicano\n(2) Morlet\n" ;
   	cin >> escolha1;
   	cin.get();

   	int n;
   	cout << "Qual o número de amostras da wavelet? \n";
   	cin >> n;
   	cin.get();
    
	double dt;
	cout << "Qual o intervalo em segundos de amostragem da wavelet? \n";
   	cin >> dt;
   	cin.get();
    
	double f;
	cout << "Qual a frequência em Hertz de pico da wavelet? \n";
   	cin >> f;
   	cin.get();
    		
switch (escolha1)
{
	case 1:
		 wav = new CWaveletCM( n, dt, f );
		 break;
	case 2:
		 wav = new CWaveletMorlet( n, dt, f );
		 break;
}
   
    
	CTracoSismico traco(meio, wav); //cria objeto do tipo CtracoSismico inicializando-o com o objeto do tipo CMeioAcustico e o ponteiro da classe CWavelet como parâmetos 
    
    string nomearquivo2;  //cria variável string
    cout << "\n\a----------------------------------------------------------------\n";    
    cout << "Qual o nome do arquivo de saída do traço sísmico? \n";
    cin >> nomearquivo2; //armazena o nome digitado na varável
    cin.get();
    ofstream fout(nomearquivo2.c_str());
    vector<double> tr = traco.GetTraco(); //armazena a convolução no vetor 'tr'
    for (int i=0; i<tr.size(); i++)
        fout << tr[i] << 	endl;
    fout.close();
    


CGnuplot plot = CGnuplot ("lines");      
plot.plotfile_x(nomearquivo2.c_str());  //plota utilizando o gnuplot

cin.get();
cin.get();

    return 0;

};
