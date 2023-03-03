#include "CMeioAcustico.h"
#include <iostream>

using namespace std;


//Método para preencher o vetor de tempo
vector<double> CMeioAcustico::Tempos() const
{
    vector<double> tempos;
    for (int i=0; i<camadas.size(); i++)
        tempos.push_back(camadas[i].GetT());
    return tempos;
};

//Método para preencher o vetor de impedância
vector<double> CMeioAcustico::Impedancias() const
{
    vector<double> impedancias;
    for (int i=0; i<camadas.size(); i++)
        impedancias.push_back(camadas[i].Z());
    return impedancias;
};

//Calculo da Refletividade  (z2-z1)/(z2+z1)
vector<double> CMeioAcustico::Refletividades(double dt) const 
{
    	vector<double> refletividades; 
    double t = 0.0;
    for (int i=1; i<camadas.size(); i++)
    {   
        t += camadas[i-1].GetT();
        for (int j=0; j<t/dt; j++)
            refletividades.push_back(0);
        double r = (camadas[i].Z() - camadas[i-1].Z())/(camadas[i].Z() + camadas[i-1].Z());
        refletividades.push_back(r);
    };
    t += camadas[camadas.size()-1].GetT();
    for (int j=0; j<t/dt; j++)
        refletividades.push_back(0);
    
    return refletividades;
};

ofstream& operator<<(ofstream& fout, const CMeioAcustico& m)
{
    for (int i=0; i<m.camadas.size(); i++)
        fout << m.camadas[i] << 	endl;
    return fout;
};

ifstream& operator>>(ifstream& fin, CMeioAcustico& m)
{
    while (true) 
    {
        CCamadaAcustica camada;
        fin >> camada;
        if (!fin.good())
            break;
        m.camadas.push_back(camada);
    };
    return fin;
};

void CMeioAcustico::Ler()

{

int n;

cout << "Quantas camadas você quer criar?\n";

cin >> n;

cin.get();


for (int i = 0; i < n; i++)

{

double rho;
double v;
double t;

cout << "Entre com o valor de densidade da camada " << i+1 << "\n";

cin >> rho;

cin.get();

cout << "Entre com o valor de velocidade na camada " << i+1 << "\n";

cin >> v;

cin.get();

cout << "Entre com o tempo de trânsito da onda na camada " << i+1 << "\n";

cin >> t;

cin.get();

CCamadaAcustica camada(rho, v, t);
camadas.push_back(camada);

}

}

