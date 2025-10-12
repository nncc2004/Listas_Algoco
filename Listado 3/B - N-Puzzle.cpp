#include<iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;

//scatter: suma de todas las distancias
//Cada dsitancia se mide como la suma de los valores absolutos de las diferencias entre ambas columnas y ambas filas.

int calculo_distancia(int i_oficial, int j_oficial, int i, int j){
    int distancia = 0;
    distancia += (abs(i_oficial - i));
    distancia += (abs(j_oficial - j));
    return distancia;
}

int main(){
    char letras[15] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O'};

    map<char, pair<int, int>> posiciones;

    
    int i = 0, j = 0;
    for(char l : letras){
        posiciones[l] = {i, j};
        (i == 3) ? (j++, i = 0) : i++;
    }

    string linea;
    int scatter = 0;
    j = 0;
    for (int k = 0; k < 4; k++){
        getline(cin, linea);
        int i = 0;
        for(auto letra:linea){
            if(letra == '.'){
                (i == 3) ? (j++, i = 0) : i++;
                continue;
            }
        
            if(posiciones[letra].first != i || posiciones[letra].second != j){
                scatter += calculo_distancia(posiciones[letra].first, posiciones[letra].second, i ,j);
            } 


            (i == 3) ? (j++, i = 0) : i++;
        }

    }
    cout<<scatter<<endl;



    return 0;
}