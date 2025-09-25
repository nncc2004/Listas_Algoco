#include <iostream>
#include<list>
#include<string>
#include<sstream>

//R da vuelta el arreglo
//D Elimina el elemento en la posicion cero. Arroja error si esta vacio

//Mi estrategia sera llevar cuenta de si borrar al inicio o al final, en base 
// a la cantidad de veces que se DEBERIA haber dado vuelta el string. 
//No voy a dar vuelta el string, voy a ver si la cantidad de Rluego fue par o inpar
// Y con eso dare vuelta el string resultante una sola vez para entregarlo.
using namespace std;

int main(){
    int qtty;
    cin >>qtty;
    cin.ignore();
    list<string> resultado;
    int n, R;
    string bapc;
    bool raise_error;
    for(int i = 0; i < qtty; i++){
        //Limpieza de variables/estructuras
        n = 0;
        bapc = "";
        R = 0;
        string linea = "";
        string caracter = "";
        raise_error = false;

        //recoger inputs de la iteracion
        getline(cin, bapc);
        cin >> n;
        cin.ignore();
        getline(cin, linea);
        linea.erase(0, 1);               
        linea.erase(linea.size() - 1);
        stringstream ss_linea(linea);
        ostringstream oss;

        while (getline(ss_linea, caracter, ','))
        {
            resultado.push_back(caracter);
        } 

        for (int j = 0; j<bapc.size(); j++){
            switch (bapc[j])
            {
            case 'R':
                if(R){
                    R = 0;
                }else{
                    R = 1;
                }
                break;
            case 'D':
                if(!resultado.size())
                    raise_error = true;
                
                if(!raise_error){
                    if(!R){
                    //numero par de reverse
                    resultado.pop_front();
                    }else{
                        //numero impar de reverse
                        resultado.pop_back();
                    }
                }
                
            default:
                break;
            }
        }
        if(!raise_error){
            cout<<'[';
            while (!resultado.empty()) {
                if (!R) {
                    cout << resultado.front();
                    resultado.pop_front();
                } else {
                    cout << resultado.back();
                    resultado.pop_back();
                }

                if (!resultado.empty()) {
                    cout << ',';
                }
            }
            cout<<"]\n";
        }else{
            cout<<"error"<<endl;
        }
               

    }
    return 0;

}