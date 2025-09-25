#include <iostream>
#include<string>
#include<queue>
#include <vector>
#include <unordered_set>

using namespace std;

int main(){

    int n, m, k;
    cin >> n;
    cin >> m;

    unordered_set<int>registro;

    for(int i = 0; i < m; i++){
        cin >> k;
        if(registro.find(k) == registro.end()){
            registro.insert(k);
        }
        
    }

    for(int i = 0; i<n; i++){
        if(registro.find(i) == registro.end()){
            cout<<i<<endl;
        }
    }
    cout<<"Mario got " <<registro.size()<< " of the dangerous obstacles.\n";
    return 0;
}