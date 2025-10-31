#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, t_inicio, t_final;
    cin >> n >> m;
    vector<pair<int,int>> researchers;
    priority_queue<int, vector<int>, greater<int>> computadores;
    int desbloqueos_totales = 0;

    for(int i = 0; i<n; i++){
        cin>> t_inicio>> t_final;
        t_final += t_inicio;
        researchers.push_back({t_inicio, t_final});
    }
    sort(researchers.begin(), researchers.end());
    


    for(int i = 0; i<n; i++){
        bool flag = true;

        while(flag){
            if(computadores.empty()){
                //Aqui se crea un computador, con el valor en el que se empieza a usar
                //Se suma uno a desbloqueos totales
                computadores.push(researchers.at(i).second);
                desbloqueos_totales++;
                flag = false;
            }else{
                if(computadores.top()<= researchers.at(i).first){
                    //Este es el caso donde el computador top ya se libero
                    if(computadores.top() + m < researchers.at(i).first){
                        //Caso en el que ya se bloqueo de vuelta
                        //se elimina y asi entra de nuevo en el bucle
                        computadores.pop();
                    }else{
                        //caso en el que se libero pero todavia no se bloquea
                        //Se borra el registro y se inserta el nuevo pc, pero no cuenta como desbloqueo
                        computadores.pop();
                        computadores.push(researchers.at(i).second);
                        flag = false; //Asi sale del bucle
                    }
                }else{
                    //Caso en el que aun no se libera, se inserta pc nuevo nomas
                    //Se sale del bucle
                    computadores.push(researchers.at(i).second);
                    desbloqueos_totales++;
                    flag = false;//Asi sale del bucle. 

                }
            }          

           
        } 
    }

    cout<<n - desbloqueos_totales <<"\n";
    return 0;
}