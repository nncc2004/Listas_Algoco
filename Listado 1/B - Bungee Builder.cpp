#include<vector>
#include <iostream>
#include <climits>
using namespace std;

// este codigo aun tira time exceeded

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

        int menor, mayor, puente;
        menor = INT_MAX;
        mayor = 0;
        
        for(int j = i+2; j< n; j++){
       


            if (mountains.at(i) > mountains.at(j)){
                puente = mountains.at(j);
            }else{
                puente = mountains.at(i);
            }

            if(mountains.at(j-1) > mayor){
                mayor = mountains.at(j-1);
            }
            if(mountains.at(j-1) < menor){
                menor = mountains.at(j-1);
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