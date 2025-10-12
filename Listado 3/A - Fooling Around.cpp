#include<iostream>
#include <vector>
#include <unordered_map>


using namespace std;

vector<int> generar_primos(int n) {
    vector<bool> es_primo(n + 1, true);
    es_primo[0] = es_primo[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (es_primo[i]) {
            for (int j = i * i; j <= n; j += i) {
                es_primo[j] = false;
            }
        }
    }
    vector<int> primos;
    for (int i = 2; i <= n; ++i) {
        if (es_primo[i]) primos.push_back(i);
    }

    return primos;
}


bool recursive_function(int n, vector<int> & primos, unordered_map<int, bool> &memoria){
    //Si está en memoria:
    if (memoria.find(n) != memoria.end()) return memoria[n];

    //Casos base:
    if (n == 0){
        memoria[n] = false;
        return false; //Alice pierde
    }

    if  (n == 1){
        memoria[n] = true;
        return true; //Alice gana
    }

    //Backtracking:
    for(int p : primos){
        int valor_restado = p-1;
        
        if(valor_restado > n) break;

        bool resultado = recursive_function(n - valor_restado, primos, memoria);
        
        if (!resultado){
            memoria[n] = true;
            return true;
        } 
    }
    memoria[n] = false;
    return false;
}

int main(){
    int q;
    long n;
    unordered_map<int, bool> memoria;
    cin>>q;

    for(int i = 0; i<q; i++){
        cin>>n;
        auto primos = generar_primos(n+1);
        if(recursive_function(n, primos, memoria)){
            cout<<"Alice\n";
        }else{
            cout<<"Bob\n";
        }
    }



    return 0;
}