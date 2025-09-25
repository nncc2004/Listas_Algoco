#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; 
    cin >> n;
    int tamano = 20;
    for (int i = 0; i < n; i++) {
        int k, x;
        cin >> k;
        vector<int> numeros;
        numeros.reserve(tamano);

        for (int j = 0; j < tamano; j++) {
            cin >> x;
            numeros.push_back(x);
        }

        int contador_mov = 0;

        // simulación de inserción uno por uno
        for (int j = 1; j < tamano; j++) {
            int actual = numeros[j];
            int m = j;

            // buscar dónde insertar
            while (m > 0 && numeros[m - 1] > actual) {
                m--;
            }

            // alumnos desplazados = cuantos moví hacia atrás
            contador_mov += (j - m);

            // insertar en la posición m
            int temp = numeros[j];
            for (int k2 = j; k2 > m; k2--) {
                numeros[k2] = numeros[k2 - 1];
            }
            numeros[m] = temp;
        }

        cout << k << " " << contador_mov << endl;
    }

    return 0;
}
