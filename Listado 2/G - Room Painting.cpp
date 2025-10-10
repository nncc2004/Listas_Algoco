#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long n, m, x; 
    cin >>n;
    cin >>m;

    long diferencia = 0;
    vector<long> cans;
    vector<long> paint_needed;

    for(int i = 0; i<n; i++){
        cin >> x;
        cans.push_back(x);
    }
    for(int i = 0; i<m; i++){
        cin >> x;
        paint_needed.push_back(x);
    }
    sort(cans.begin(), cans.end());
    sort(paint_needed.begin(), paint_needed.end());

    int inicio = 0;
    for(int i = 0; i<m; i++){
        for(int j = inicio; j<n; j++){
            if(cans.at(j) >= paint_needed.at(i)){
                diferencia += cans.at(j) - paint_needed.at(i);
                inicio = j;
                break;
            }
        }
    }

    cout<<diferencia<<endl;
    return 0;
}
