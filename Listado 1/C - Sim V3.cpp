#include<list>
#include<string>
#include <iostream>

using namespace std;
// Esta version si funciona
int main(){
    int cursor_position, n;
    string nueva_linea;
    cin >> n;
    cin.ignore();
    char caracter_actual;

    list<char> L;
    list<char> R;

    for (int i = 0; i < n; i++){
        nueva_linea = "";
        caracter_actual = '\0';

        cin.get(caracter_actual);

        while(caracter_actual != '\n'){
            switch (caracter_actual){
                case '[':
                    //logica de ir al inicio
                    //Se mueve todo lo que haya en L al inicio de R
                    R.splice(R.begin(), L);


                    break;
                case ']':
                    //logica de ir al final
                    //Se mueve todo lo que hay al final al final de L
                    L.splice(L.end(), R);
                    break;
                case '<':
                    //logica del borrado
                    //Se borra el ultimo elemento de L nada mas. 
                    if (L.empty()) break;
                    L.pop_back();
                    break;
                default:
                    //logica general, agregar el caracter al final de L
                    L.push_back(caracter_actual);
                    break;
            }
            cin.get(caracter_actual);


        }

        L.splice(L.end(), R);
        for (char c : L) {
        nueva_linea += c;
        }
        cout << nueva_linea <<endl;
        L.clear();
        R.clear();

    }

        
        
    return 0;
}