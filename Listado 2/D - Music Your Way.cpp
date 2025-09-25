#include <iostream>
#include<algorithm>
#include <vector>
#include <string>
#include <sstream>
#include<map>
using namespace std;

void print_canciones(vector<vector<string>> canciones){
    for(vector<string>p : canciones){
        for(string s : p){
            cout<<s<<" ";
        }
        cout<<endl;
    }

}

void print_vector_inline(vector<string> &v){
    for(string s : v){
        cout<<s<<" ";
    }
    cout<<endl;
}

int main() {
    map<string, int> atr;
    vector<vector<string>> canciones;
    vector<string> cancion_particular, atributos;
    int i = 0, n, n_atributos, n_instrucciones;
    string linea, valor, atr_key;

    getline(cin, linea);
    stringstream ss(linea);
    while (ss >> valor) { 
        atributos.push_back(valor);
        atr[valor] = i;
        i++;
    }
    n_atributos = atr.size();

    cin >> n;
    for(int i = 0; i< n; i++){
        cancion_particular.clear();
        for(int j = 0; j< n_atributos; j++){
            cin >> valor;
            cancion_particular.push_back(valor);
        }
        canciones.push_back(cancion_particular);
    }

    cin>> n_instrucciones;
    for(int i = 0; i<n_instrucciones; i++){
        cin>>atr_key;
        int pos = atr.at(atr_key);
        stable_sort(canciones.begin(), canciones.end(),
            [pos](const vector<string> &a, const vector<string> &b){
                return a.at(pos) < b.at(pos);
            });
        print_vector_inline(atributos);
        print_canciones(canciones);
        cout<<endl;
    }

}






