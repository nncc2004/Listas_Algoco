#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main() {
    int n, h, valor;
    cin >> n >> h;

    vector<int> estalacticas(h+2, 0);
    vector<int> estalagmitas(h+2, 0);

    for (int i = 0; i < n; i++) {
        cin >> valor;
        if (i % 2 == 0) {
            estalagmitas[valor]++;
        } else {
            estalacticas[valor]++;
        }
    }

    // acumulados hacia atrás
    for (int i = h-1; i >= 1; i--) {
        estalagmitas[i] += estalagmitas[i+1];
        estalacticas[i] += estalacticas[i+1];
    }

    int menor = INT_MAX, cant = 0;

    for (int altura = 1; altura <= h; altura++) {
        int atraviesa = estalagmitas[altura] + estalacticas[h - altura + 1];
        if (atraviesa < menor) {
            menor = atraviesa;
            cant = 1;
        } else if (atraviesa == menor) {
            cant++;
        }
    }

    cout << menor << " " << cant << "\n";
    return 0;
}
