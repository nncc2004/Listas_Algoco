#include <iostream>
#include<string>
#include<queue>
#include <sstream>


using namespace std;

int main() {
    priority_queue<pair<int, int>> bid_price;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> ask_price;
    int n, orders;
    string instruccion[5];
    cin >> n;

    for(int i = 0; i <n; i++){
        //reiniciar EDD y vartiables
        string linea = "";
        orders = 0;
        bid_price = priority_queue<pair<int, int>>();
        ask_price = priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<>
        >();
        int stock_price = -1;

        //recoger inputs
        cin>>orders;
        cin.ignore();

        for(int j = 0; j <orders; j++){
            getline(cin, linea);
            istringstream iss_linea(linea);
            for (int i = 0; i < 5; ++i) {
                iss_linea >> instruccion[i];
            }
            string opreacion = instruccion[0];
            int precio = stoi(instruccion[4]);
            int cantidad = stoi(instruccion[1]);
            int mejor_venta, mejor_compra, cantidad_mejor_venta, cantidad_mejor_compra;



            if(opreacion == "buy"){
                bid_price.push({precio, cantidad});
            }else{
                ask_price.push({precio, cantidad});
            }
            if(!(ask_price.empty()|| bid_price.empty())){
                mejor_venta = ask_price.top().first;
                mejor_compra = bid_price.top().first;
                cantidad_mejor_venta = ask_price.top().second;
                cantidad_mejor_compra = bid_price.top().second;
            }
            

            //caso de stock
            while(mejor_venta <= mejor_compra && !(ask_price.empty()|| bid_price.empty())){
                int dif = cantidad_mejor_venta - cantidad_mejor_compra;
                ask_price.pop();
                bid_price.pop();
                stock_price = mejor_venta;
                if(dif> 0){ 
                    ask_price.push({mejor_venta, dif});
                }

                if(dif < 0){
                    bid_price.push({mejor_compra, abs(dif)});
                }

                mejor_venta = ask_price.top().first;
                mejor_compra = bid_price.top().first;
                cantidad_mejor_venta = ask_price.top().second;
                cantidad_mejor_compra = bid_price.top().second;
                
            }




            int show[3] ={
                ask_price.empty() ? -1 : ask_price.top().first,
                bid_price.empty() ? -1 :bid_price.top().first,
                stock_price
            };
            for(int k = 0; k<3; k++){
                if(show[k] != -1){
                    cout <<show[k]<< ' ';
                }else{
                    cout <<"- ";
                }
            }
            cout<<"\n";


        }


    }

    return 0;
}