#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n, mayor_altura;
    cin >> n;
    vector<int> mountains;

    mayor_altura = 0;
    for (int i = 0; i < n; i++) {
        int input; cin >> input;
        mountains.push_back(input);
    }

    // estados para ambos recorridos
    int pivote_izq = 0;
    int menor_intermedio_izq = mountains[0];

    int pivote_der = n - 1;
    int menor_intermedio_der = mountains[n - 1];

    int i = 1, j = n - 2;
    while (i < n || j >= 0) {
        // izquierda -> derecha
        if (i < n) {
            if (mountains[i] < menor_intermedio_izq) menor_intermedio_izq = mountains[i];
            if (mountains[i] >= mountains[pivote_izq]) {
                int salto = mountains[pivote_izq] - menor_intermedio_izq;
                if (salto > mayor_altura) mayor_altura = salto;
                pivote_izq = i;
                menor_intermedio_izq = mountains[i];
            }
            ++i;
        }

        // derecha -> izquierda
        if (j >= 0) {
            if (mountains[j] < menor_intermedio_der) menor_intermedio_der = mountains[j];
            if (mountains[j] >= mountains[pivote_der]) {
                int salto = mountains[pivote_der] - menor_intermedio_der;
                if (salto > mayor_altura) mayor_altura = salto;
                pivote_der = j;
                menor_intermedio_der = mountains[j];
            }
            --j;
        }
    }

    cout << mayor_altura << "\n";
    return 0;
}
