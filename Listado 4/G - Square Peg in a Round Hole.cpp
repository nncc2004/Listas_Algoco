#include <algorithm>
#include <bits/stdc++.h>

using namespace std;


int main(){
    int n, m, k, total = 0;
    float input;
    cin>> n >> m >> k;
    vector<int> plots;
    vector<float> radios;
    for(int i = 0; i<n; i++){
        cin >> input;
        plots.push_back(2*input);
    }
    sort(plots.begin(), plots.end());

    for(int i = 0; i<m; i++){
        cin >> input;
        radios.push_back(2*input);
    }

    for(int i = 0; i<k; i++){
        cin >> input;
        radios.push_back(sqrt(2)*input);
    }
    sort(radios.begin(), radios.end());
    //Aqui ya tengo los tres vectores ordenados.
    //El tamano maximo del lado de una casa de (2/sqrt(2))*r, con r radio del plot.
    //Para una casa redonda basta con que el radio sea igual o menor.


    while(!plots.empty() && !radios.empty()){
        if(radios.back() < plots.back()){
            //La casa si cabe

            radios.pop_back();
            plots.pop_back();
            total++;
        }else{

            radios.pop_back();
        }
    }
    cout<<total<<"\n";



    return 0;
}