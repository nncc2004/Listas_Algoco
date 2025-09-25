#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

int main() {
    int n, mayor_altura;
    cin >> n;
    vector<int> mountains;    

    mayor_altura = 0; 
    for (int i = 0; i < n; i++){
        int input;
        cin >> input;
        mountains.push_back(input);
    }

    int pivote1 = 0; //Con esta buscaremos constantemente el 'pivote 1' del puente, mientras que con el for buscaremos el pivote 2.
    int menor_intermedio = mountains[0]; //Con esta se ira gurdando el valor de la montania menor entre el pivote1 y la posicion i actual.

    for(int i = 1; i<n; i++){
        if(mountains[i] < menor_intermedio) menor_intermedio = mountains[i];

        if(mountains[i] >= mountains[pivote1]){
            int salto = mountains[pivote1] - menor_intermedio;
            mayor_altura = max(salto, mayor_altura);

            pivote1 = i;
            menor_intermedio = mountains[i];
        }

    }

    pivote1 = n - 1;
    menor_intermedio = mountains[n-1];

    for(int i = n-2; i>=0; i--){
        if(mountains[i] < menor_intermedio) menor_intermedio = mountains[i];

        if(mountains[i] >= mountains[pivote1]){
            int salto = mountains[pivote1] - menor_intermedio;
            mayor_altura = max(salto, mayor_altura);

            pivote1 = i;
            menor_intermedio = mountains[i];
        }
    }

    cout<< mayor_altura <<endl;

    return 0;
}
