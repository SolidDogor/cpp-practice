/*
 * EJERCICIO 3 – Invertir vector in-place
 *
 * Objetivo:
 * Implementar una función que invierta el orden de los elementos
 * de un std::vector<int> SIN usar std::reverse().
 *
 * Requisitos:
 *
 * 1. Implementar la función:
 *
 *      void reverse_vector(std::vector<int>& v);
 *
 * 2. La inversión debe hacerse:
 *      - In-place (sin crear otro vector auxiliar).
 *      - Con complejidad O(n).
 *
 * 3. No usar funciones de la STL que ya resuelvan el problema.
 *
 * Pista:
 *      Intercambiar el primer elemento con el último,
 *      el segundo con el penúltimo, etc.
 *
 *      Solo es necesario iterar hasta la mitad del vector.
 *
 * Ejemplo:
 *
 *      Entrada:  {1, 2, 3, 4, 5}
 *      Salida:   {5, 4, 3, 2, 1}
 *
 *      Entrada:  {10, 20, 30}
 *      Salida:   {30, 20, 10}
 *
 * Casos borde:
 *      - Vector vacío
 *      - Vector con un solo elemento
 */

#include <iostream>
#include <vector>

void print_vector(const std::vector<int>& v);
void reverse_vector(std::vector<int>& v);

int main() {
    int q = 0;
    std::cout << "Ingrese la cantidad de elementos en el vector: ";
    std::cin >> q;

    if (q < 0) {
        std::cout << "La cantidad de elementos no puede ser negativa.\n";
        return 1;
    }

    std::vector<int> v(static_cast<std::size_t>(q));

    for (std::size_t i = 0; i < v.size(); ++i) {
        std::cout << "Ingrese el elemento " << (i + 1) << ": ";
        std::cin >> v[i];
    }

    std::cout << "Vector original:\n";
    print_vector(v);

    reverse_vector(v);

    std::cout << "Vector a la reversa:\n";
    print_vector(v);
}

void print_vector(const std::vector<int>& v) {
    std::cout << "{";
    for (std::size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i + 1 != v.size()) std::cout << ", ";
    }
    std::cout << "}\n";
}

void reverse_vector(std::vector<int>& v) {
    for (std::size_t i = 0; i < v.size() / 2; ++i) {
        int aux = v[i];
        v[i] = v[v.size() - 1 - i];
        v[v.size() - 1 - i] = aux;
    }
}
