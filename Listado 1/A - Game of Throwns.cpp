
#include<vector>
#include<string>
#include <iostream>
#include <sstream> // StringStream

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int pos = 0;
    vector <int> historial;
    historial.push_back(pos);
    cin.ignore(); //IMPORTANTE: Usar cuando se necesite limpiar el bufer del CIN
    string input_line;
    getline(cin, input_line); //Almacenar una linea completa de input como string
    stringstream linea(input_line); //Convertir la linea a stringsream (trabajar mejor los inputs) (ayuda montones con la conversion de datos)


    for(int i = 0; i < k; i++){
        int instruction;
        string info;
        linea >> info;
        stringstream info_stream(info);

        if (info_stream >> instruction){
            //Caso en el que si es un numero
            //Logica de mover el huevo en 'instruccion posiciones'
            // notar que si pos > n-1, pos = pos - n - 1
            pos += instruction;
            while(pos > n-1){
                pos = pos - n;
            } 
         
            while(pos < 0){
                pos = pos + n;
            }
            
            historial.push_back(pos);


        }else{
            //Logica del undo aca, ya que no se pudo hacer la transformacion
            //Hasta el momento pienso agarrar el siguiente numero ya que es la cantidad
            //de instrucciones a retroceder (eliminar de historial)
            linea >> instruction;


            for(int m = 0; m< instruction; m++){
                historial.pop_back();

            }
            
        }
        pos = historial.back();
    }

    cout << historial.back();
    
    return 0;
}