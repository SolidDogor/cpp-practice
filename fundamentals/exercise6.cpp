    /*
    * EJERCICIO 6 – Número más frecuente (con desempate)
    *
    * Objetivo:
    * Dado un std::vector<int>, encontrar el número que aparece más veces.
    *
    * Firma requerida:
    *
    *      int most_frequent(const std::vector<int>& v);
    *
    * Requisitos:
    * 1) Usar std::map<int,int> para contar frecuencias.
    * 2) Retornar el número con mayor frecuencia.
    * 3) Si hay empate en frecuencia, retornar el MENOR número.
    * 4) Complejidad esperada: O(n log n).
    *
    * Casos borde:
    *  - Si el vector está vacío, puedes:
    *      a) lanzar una excepción (std::invalid_argument), o
    *      b) retornar 0 (pero debes documentarlo).
    *    (Elige una opción y sé consistente.)
    *
    * Ejemplos:
    *
    *  Entrada: {1, 2, 2, 3, 3, 3, 1}
    *  Frec:   1->2, 2->2, 3->3
    *  Salida: 3
    *
    *  Entrada: {4, 4, 2, 2}
    *  Frec:   2->2, 4->2   (empate)
    *  Salida: 2            (porque es el menor)
    *
    *  Entrada: {-1, -1, -2, -2, -2, 10}
    *  Salida: -2
    */

#include <iostream>
#include <map>
#include <vector>

int most_frequent(const std::vector<int>& v);

int main ()
{
    int q = 0;
    std::cout << "Ingrese la cantidad de elementos del vector: ";
    std::cin >> q;
    if (q < 0)
    {
        std::cout << "No se puede tener una cantidad negativa.\n";
        return 1;
    }
    std::vector<int> v(q);
    for (int i = 0; i < q; i++)
    {
        std::cout << "Ingrese el elemento #" << (i + 1) << ": ";
        std::cin >> v[i];
    }
    int f = most_frequent(v);
    std::cout << "Numero con mayor frecuencia: " << f << ".\n";
    return 0;
}

int most_frequent(const std::vector<int>& v)
{
    if (v.empty())
    {
        std::cout << "El vector está vacío. Retornando 0 por convención.\n";
        return 0;
    }

    std::map<int,int> freq;
    for (int x : v)
    {
        freq[x]++;
    }

    int best_number = 0;
    int best_count = -1;

    for (const auto& [number, count] : freq)
    {
        if (count > best_count)
        {
            best_count = count;
            best_number = number;
        }
    }

    return best_number;
}
