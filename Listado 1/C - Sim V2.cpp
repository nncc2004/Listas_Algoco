#include<vector>
#include<string>
#include <iostream>

using namespace std;

int main(){
    int cursor_position, n;
    string nueva_linea;
    cin >> n;
    cin.ignore();
    char caracter_actual;

    for (int i = 0; i < n; i++){
        nueva_linea = "";
        cursor_position = 0;
        caracter_actual = '\0';

        cin.get(caracter_actual);

        while(caracter_actual != '\n'){
            switch (caracter_actual){
                case '[':
                    //logica de ir al inicio
                    cursor_position = 0;
                    break;
                case ']':
                    //logica de ir al final
                    cursor_position = nueva_linea.length();

                    break;
                case '<':
                    //logica del borrado. Tner ojo con como se trasladan desde la posicion en adelante todos una posicion hacia atras. 
                    if(!cursor_position) break;
                    cursor_position--;
                    nueva_linea.erase(cursor_position, 1);
                    //cursor_position--;
                    
                    break;
                default:
                    //logica general, solo agregar elementos en la pos del cursor y sumar una a la pos
                    nueva_linea.insert(cursor_position, string(1, caracter_actual));
                    cursor_position++;
                    break;
            }
            cin.get(caracter_actual);


        }
        cout << nueva_linea <<endl;
    }

        
        
    return 0;
}