#include <bits/stdc++.h>
using namespace std;

struct figura{
    int lado1;
    int lado2;
};


int main() {
    figura figuras[3];

    int area = 0;
    for(int i = 0; i<3; i++){
        cin >> figuras[i].lado1;
        cin >> figuras[i].lado2;
        area += figuras[i].lado1*figuras[i].lado2;
    }
    int lado_buscado = sqrt(area);
    if(lado_buscado * lado_buscado != area){
        cout<<"NO\n";
        return 0;
    }

    int ord[3] = {0,1,2};
    do {
        // mask: bit p -> rotación de la pieza en la posición p de la permutación
        for (int mask = 0; mask < 8; ++mask) {
            int w[3], h[3];
            for (int p = 0; p < 3; ++p) {
                int id = ord[p];
                if (mask & (1 << p)) { // rotada
                    w[p] = figuras[id].lado2;
                    h[p] = figuras[id].lado1;
                } else {
                    w[p] = figuras[id].lado1;
                    h[p] = figuras[id].lado2;
                }
            }

            // 1) fila horizontal: alturas iguales a lado_buscado y anchos suman lado_buscado
            if (h[0]==lado_buscado && h[1]==lado_buscado && h[2]==lado_buscado && (w[0]+w[1]+w[2])==lado_buscado) {
                cout << "YES\n"; return 0;
            }

            // 2) columna vertical: anchos iguales a lado_buscado y alturas suman lado_buscado
            if (w[0]==lado_buscado && w[1]==lado_buscado && w[2]==lado_buscado && (h[0]+h[1]+h[2])==lado_buscado) {
                cout << "YES\n"; return 0;
            }

            // 3) lado_buscado: pieza 0 ocupa altura completa; piezas 1+2 apiladas a la derecha
            //    (h[0]==lado_buscado) && (h[1]+h[2]==lado_buscado) && mismas anchuras para 1 y 2 && ancho total == lado_buscado
            if (h[0]==lado_buscado && (h[1]+h[2])==lado_buscado && (w[1]==w[2]) && (w[0]+w[1])==lado_buscado) {
                cout << "YES\n"; return 0;
            }

            // 4) lado_buscado simétrico: pieza 0 ocupa ancho completo; piezas 1+2 lado a lado abajo
            if (w[0]==lado_buscado && (w[1]+w[2])==lado_buscado && (h[1]==h[2]) && (h[0]+h[1])==lado_buscado) {
                cout << "YES\n"; return 0;
            }
        }
    } while (next_permutation(ord, ord+3));

    cout << "NO\n";
    return 0;

}