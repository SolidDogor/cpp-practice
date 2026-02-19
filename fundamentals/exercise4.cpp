/*
 * EJERCICIO 4 – Conteo de frecuencias con std::map
 *
 * Objetivo:
 * Leer una lista de enteros y contar cuántas veces aparece cada valor.
 *
 * Requisitos:
 *
 * 1. Implementar una función que reciba un vector de enteros y retorne
 *    un std::map<int, int> donde:
 *      - key   = número
 *      - value = frecuencia (cantidad de apariciones)
 *
 *      std::map<int, int> count_frequencies(const std::vector<int>& v);
 *
 * 2. Luego, imprimir el resultado en formato:
 *
 *      Numero : Frecuencia
 *      3      : 5
 *      10     : 2
 *      -1     : 1
 *
 * 3. No usar unordered_map en este ejercicio.
 *    Queremos que la salida salga ordenada automáticamente.
 *
 * Casos borde:
 *  - vector vacío (debe imprimir "sin datos" o simplemente no imprimir pares)
 *
 * Ejemplo:
 *  Entrada:  {4, 4, 2, 4, 2, -1}
 *  Salida:
 *      -1 : 1
 *       2 : 2
 *       4 : 3
 */

#include <iostream>
#include <vector>
#include <map>

std::map<int, int> count_frequencies(const std::vector<int>& v);

int main() {
    int q = 0;
    std::cout << "Ingrese la cantidad de elementos en el vector: ";
    std::cin >> q;

    if (q < 0) {
        std::cout << "No se puede ingresar una cantidad negativa.\n";
        return 1;
    }

    std::vector<int> v(static_cast<std::size_t>(q));
    for (std::size_t i = 0; i < v.size(); ++i) {
        std::cout << "Ingrese el valor #" << (i + 1) << ": ";
        std::cin >> v[i];
    }

    std::map<int, int> f = count_frequencies(v);

    std::cout << "Numero\t: Frecuencia\n";
    for (const auto& [num, freq] : f) {
        std::cout << num << "\t: " << freq << "\n";
    }

    return 0;
}

std::map<int, int> count_frequencies(const std::vector<int>& v) {
    std::map<int, int> m;
    for (int x : v) {
        m[x]++;
    }
    return m;
}
