
#include <iostream>
#include<vector>

using namespace std;
/*
este funciona, pero no me lo acepta el juez virtual. Debe haber algun caso que no pero no logro averiguar cual es. 
*/
int main(){
    int n, k, x, anterior, contador_swap;
    cin >> n;
    vector<int> numeros;
    int tamano = 20;
    for(int i = 0; i<n; i++){
        k = 0, contador_swap = 0;
        numeros.clear();
        cin >> k;
        for(int j = 0; j < tamano; j++){
            cin >> x;
            numeros.push_back(x);
        }
        //Aqui ya tengo el k y el vector desordenado 'numeros'
        //la logica seria implementar el sort mencionado, y aplicarlo al vector, aumentando un contador por cada swap que se haga.

        //para ver numros desordenados deberia ir comparando la posicion j con j-1 (anterior), si en algun momento anterior es mayor que j, hay desorden
        for(int j = 0; j<tamano; j++){
            int actual = numeros.at(j);
            if(j ==0){
                anterior = actual;
                continue;
            }
            if(anterior > actual){
                //aqui hacer que el numero avance a la posicion que corresponde
                int m = j;
                do{
                    swap(numeros[m], numeros[m-1]);
                    contador_swap += 1;
                    m--;
                }while ( m-1 >= 0 && numeros.at(m-1) > numeros.at(m) );  
            }

            anterior = actual;

        }
        cout << k << " " << contador_swap <<endl;

    } 

    return 0;
}   