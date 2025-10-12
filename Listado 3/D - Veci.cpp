#include <bits/stdc++.h>
using namespace std;

int main() {
    string numero;
    cin >> numero;

    // Paso 1: convertir el número en vector de dígitos
    vector<int> digitos;
    for (char c : numero)
        digitos.push_back(c - '0');

    // Paso 2: buscar el primer índice "i" desde el final
    // tal que digitos[i] < digitos[i + 1]
    int i = digitos.size() - 2;
    while (i >= 0 && digitos[i] >= digitos[i + 1])
        i--;

    // Si no hay tal índice, significa que los dígitos están en orden descendente
    if (i < 0) {
        cout << 0 << "\n"; // ya es la mayor permutación posible
        return 0;
    }

    // Paso 3: buscar el índice "j" (también desde el final)
    // tal que digitos[j] > digitos[i]
    int j = digitos.size() - 1;
    while (digitos[j] <= digitos[i])
        j--;

    // Paso 4: intercambiar los elementos i y j
    swap(digitos[i], digitos[j]);

    // Paso 5: ordenar (o invertir, que es más rápido) el segmento a la derecha de i
    reverse(digitos.begin() + i + 1, digitos.end());

    // Paso 6: reconstruir el número en string y mostrarlo
    for (int d : digitos)
        cout << d;
    cout << "\n";

    return 0;
}
