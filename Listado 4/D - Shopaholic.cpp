#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main(){
    long n, total = 0;
    long gratis = 0;
    cin >> n;
    vector<int>precios;
    int precio;
    for(int i = 0; i < n; i++){
        cin >> precio;
        total += precio;
        precios.push_back(precio);
    }

    if(n<3){
        cout<<total;
        return 0;
    }
    sort(precios.begin(), precios.end(), greater<int>());
    while(precios.size() % 3 != 0){
        precios.pop_back();
    }

    //Ahora tenemos un vector que es multiplo de tres en cantidad y ordenada de mayor a menor
    int sem = 0;
    while(!precios.empty()){
        if(sem == 0){
            sem = 2;
            gratis += precios.back();
            precios.pop_back();
            continue;
        }
        sem--;
        precios.pop_back();
    }

    cout<<gratis<<"\n";

    return 0;
}



//100 150 200 250 300 350 400
//150 200 250 300 350 400