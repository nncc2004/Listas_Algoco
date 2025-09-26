#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n, h, valor;
    cin >> n;
    cin >> h;

    int cueva[h];
    for(int i = 0; i<h; i++){
        cueva[i] = 0;
    }

    for(int i = 0; i<n; i++){
        cin >>valor;
        if(i%2 == 0){
            //par: estalagmita (abajo hacia arriba)
            for(int j = 0; j<valor; j++){
                cueva[j]+=1;
            }
        }else{
            //impar: estalactita (arriba hacia abajo)
            for(int j = h-valor; j < h; j++){
                cueva[j]+=1;
            }
        }
    }
    int menor = INT_MAX;
    int cant = 0;
    for(int p : cueva){
        if(p< menor){
            cant = 1;
            menor = p;
        }else if(p == menor){
            cant++;
        }
    }

    cout<<menor<<" "<<cant<<endl;

    
    return 0;
}