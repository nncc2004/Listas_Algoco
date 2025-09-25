#include<vector>
#include<string>
#include <iostream>

using namespace std;

int main(){
    int cursor_position, n;
    string input_line, nueva_linea;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++){
        nueva_linea = "";
        cursor_position = 0;
        getline(cin, input_line);

        //aqui la logica sobre la nueva linea
        for (int j = 0; j <input_line.length(); j++){

            char caracter_actual = input_line[j];

            switch (caracter_actual)
            {
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


        }

        cout << nueva_linea <<endl;
    }
    return 0;
}