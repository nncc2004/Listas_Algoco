#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
//Una tarea por intervalo de tiempo
//Una tarea no puede durar mas que un intervalo de tiempo

int main(){
    int n, m;
    cin>> n >> m;
    vector<int> tareas;
    vector<int> intervalos;

    int x;
    for (int i = 0; i<n;i++){
        cin>>x;
        tareas.push_back(x);
    }

    for (int i = 0; i<m;i++){
        cin>>x;
        intervalos.push_back(x);
    }

    stable_sort(tareas.begin(), tareas.end());
    stable_sort(intervalos.begin(), intervalos.end());

    int menor = (n < m) ? n : m;
    int total = 0;

    while(!tareas.empty() && !intervalos.empty()){
        if(tareas.back() <= intervalos.back()){
            total++;
            tareas.pop_back();
            intervalos.pop_back();
        }else{
            tareas.pop_back();
        }
    }
    cout<<total;
    return 0;
}

