#include "CWaveletMorlet.h"
#include "CWaveletCM.h"
#include "CMeioAcustico.h"
#include "CTracoSismico.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

//Este � o programa principal

using namespace std;

int main()
{
   
    cout << "---------------------Gera��o de Tra�o S�smico------------------\n" ;
    cout << "\n\n Autores: Ramon Diogo e S�vio Januario \n Disciplina: Programa��o Pr�tica em C++ \n" ;
    cout << "\n\n-----------------------------------------------------------\n" ;
    
    
    cout << "Voc� deseja carregar os dados manualmente ou ler do arquivo? \n(1)Carregar Manualmente \n(2)Ler do arquivo\n";
    int escolha; //cria vari�vel inteira
    cin >> escolha; //armazena o valor digitado na vari�vel
    cin.get();
    cout << "\n\a-------------------------------------------------------------\n"; 
    CMeioAcustico meio; //cria objeto do tipo CMeioAcustico
    switch (escolha) //cria uma fun��o condicional
	{
    	case 1:
    		meio.Ler(); //executa a fun��o Ler() da classe CMeioAcustico
    		break;
    		
    	case 2:
    		string nomearquivo1; //cria vari�vel do tipo string
		cout << "Qual o nome do arquivo com as propriedades do meio ac�stico? \n";
    		cin >> nomearquivo1; //armazena nome digitado na vari�vel
    	        ifstream fin(nomearquivo1.c_str());
			fin >> meio; //L� arquivo
   			fin.close();
    		cin.get();
    		break;
	}
        CWavelet* wav; //cria ponteiro da classe CWavelet
   	int escolha1;
   	cout << "\n-----------------------------------------------------------------\n"; 
	cout << "Qual tipo de wavelet deseja utilizar?\n(1) Chap�u Mexicano\n(2) Morlet\n" ;
   	cin >> escolha1;
   	cin.get();

   	int n;
   	cout << "Qual o n�mero de amostras da wavelet? \n";
   	cin >> n;
   	cin.get();
    
	double dt;
	cout << "Qual o intervalo em segundos de amostragem da wavelet? \n";
   	cin >> dt;
   	cin.get();
    
	double f;
	cout << "Qual a frequ�ncia em Hertz de pico da wavelet? \n";
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
   
    
	CTracoSismico traco(meio, wav); //cria objeto do tipo CtracoSismico inicializando-o com o objeto do tipo CMeioAcustico e o ponteiro da classe CWavelet como par�metos 
    
    string nomearquivo2;  //cria vari�vel string
    cout << "\n\a----------------------------------------------------------------\n";    
    cout << "Qual o nome do arquivo de sa�da do tra�o s�smico? \n";
    cin >> nomearquivo2; //armazena o nome digitado na var�vel
    cin.get();
    ofstream fout(nomearquivo2.c_str());
    vector<double> tr = traco.GetTraco(); //armazena a convolu��o no vetor 'tr'
    for (int i=0; i<tr.size(); i++)
        fout << tr[i] << 	endl;
    fout.close();
    


CGnuplot plot = CGnuplot ("lines");      
plot.plotfile_x(nomearquivo2.c_str());  //plota utilizando o gnuplot

cin.get();
cin.get();

    return 0;

};
