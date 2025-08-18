#include<vector>
#include <iostream>
#include <climits>
using namespace std;


int main(){

    int n, mayor_altura;
    cin >> n;
    vector<int> mountains;    
    for (int i = 0; i < n; i++){
        int input;
        cin >> input;
        mountains.push_back(input);
    }

    

    mayor_altura = 0;

    
    for(int i = 0; i <n-2; i++){


        for(int j = i+1; j< n; j++){


            int puente;
            if (mountains.at(i) > mountains.at(j)){
                puente = mountains.at(j);
            }else{
                puente = mountains.at(i);
            }

            int k = i+1,  menor, mayor;

            menor = INT_MAX;
            mayor = 0;

            while(k < j){
                if(mountains.at(k) < menor){
                    menor = mountains.at(k);
                } 
                if(mountains.at(k) > mayor){
                    mayor = mountains.at(k);
                }
                k++;
            }
            if (mayor < puente){
                int altura;
                altura = puente - menor;
                if (altura > mayor_altura){
                    mayor_altura = altura;                 
                }
            } 
            

        }
    }


    cout << mayor_altura<< endl;
    
    return 0;
}