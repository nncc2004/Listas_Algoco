/*
Ask price: Precio menor al que alguien quiere vender su share
Bid price: Precio mayor que alguien esta dispuesto a pagar por una share
Stock price: Precio al que se llega para la transaccion

Task: Mantener actualizado el precio de ask, bid y stock. 

output: Tras cada linea de oferta, se debe imprimir tres enteros con
los precios de cada cosa en el orden descrito arriba. 

basdicamente, si al hacer una nueva oferta de compra, es mayor o igual que
la ultima de venta, se actualiza el stock.  (pq se llega a acuerdo)

De forma naloga, si al hacer una oferta de venta, mas barata o igual que laultima 
ofera de compra, se actualiza el stock. (pq se llega a acuerdo)

nota: usar max y min heap. 
*/


//No funciona bien , falto ir actualizando hacia atras en los registro sde los heap
//En caso de que una nueva oferta pueda usar mas que solo el top de algun heap
// por ejemplo una oferta de compra a un precio muy alto que pueda satisfacer mas de 
//solo el mejor precio, sino que varios hacia atras


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
            int mejor_precio;
            int curr_qtty;



            if(opreacion == "buy"){
                //logica bid_price
                if(!ask_price.empty()){


                    mejor_precio = ask_price.top().first;
                    curr_qtty  = ask_price.top().second;


                    if (precio >= mejor_precio){
                        //logica de stockprice
                        stock_price = ask_price.top().first;
                        curr_qtty = curr_qtty - cantidad;
                        ask_price.pop();
                        if (curr_qtty > 0){
                            ask_price.push({precio, curr_qtty});
                        }else if(curr_qtty < 0){
                            
                            bid_price.push({precio, abs(curr_qtty)});
                        }
                    }else{
                        bid_price.push({precio, cantidad});
                    }
                }else{
                    bid_price.push({precio, cantidad});
                }
                

                

            }else{
                //logica ask_price
                if(!bid_price.empty()){
                    mejor_precio = bid_price.top().first;
                    curr_qtty  = bid_price.top().second;
                    if(precio <= mejor_precio){
                        stock_price = ask_price.top().first;
                        curr_qtty = curr_qtty - cantidad;
                        bid_price.pop();
                        if (curr_qtty > 0){
                            bid_price.push({precio, curr_qtty});
                        }else if(curr_qtty < 0){
                            ask_price.push({precio, abs(curr_qtty)});
                        }
                    }else{
                        ask_price.push({precio, cantidad});
                    }
                }else{
                    ask_price.push({precio, cantidad});
                }

                
            }

            int show[3] ={
                ask_price.empty() ? -1 : ask_price.top().first,
                bid_price.empty() ? -1 :bid_price.top().first,
                stock_price
            };
            cout<< "RESULTADO LINEA: ";
            for(int k = 0; k<3; k++){
                if(show[k] != -1){
                    cout <<show[k]<< ' ';
                }else{
                    cout <<"- ";
                }
            }
            cout<<endl;


        }


    }

    return 0;
}