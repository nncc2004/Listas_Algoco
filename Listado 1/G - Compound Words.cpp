#include <iostream>
#include<string>
#include<queue>
#include <vector>
#include <unordered_set>

using namespace std;

int main(){
    vector<string> palabras;
    priority_queue<string, vector<string>, greater<string>> ordenado;
    unordered_set<string>registro;
    string palabra;

    while(cin>> palabra){
        palabras.push_back(palabra);
    }   


    

    for(int i = 0; i < palabras.size(); i++){
        for(int j = 0; j< palabras.size(); j++){
            if(i ==j) continue;
            string juntar = palabras.at(i) + palabras.at(j);

            if(registro.find(juntar) == registro.end()){
                ordenado.push(juntar);
                registro.insert(juntar);
            }
            
        }
    }
    int tamanio = ordenado.size();
    for(int i = 0; i< tamanio; i++){
        cout<<ordenado.top()<<endl;
        ordenado.pop();
    }

    return 0;
}