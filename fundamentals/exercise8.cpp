/*
 * EJERCICIO 8 – Contar frecuencias SIN operator[]
 *
 * Objetivo:
 * Implementar un contador de frecuencias usando std::map<int,int>,
 * pero SIN usar operator[] para insertar claves nuevas.
 *
 * Firma requerida:
 *
 *      std::map<int,int> count_frequencies_with_find(const std::vector<int>& v);
 *
 * Requisitos:
 * 1) Recorrer el vector y contar apariciones.
 * 2) No usar freq[x]++ directamente.
 * 3) Usar find() para buscar la clave:
 *      - Si NO existe: insertar {x, 1}
 *      - Si existe: incrementar el valor existente
 * 4) Complejidad esperada: O(n log k).
 *
 * Ejemplo:
 *  Entrada: {4, 4, 2, 4, 2, -1}
 *  Salida:
 *      -1 : 1
 *       2 : 2
 *       4 : 3
 *
 * Pistas:
 *  - it = m.find(x)
 *  - if (it == m.end()) insert(...)
 *  - else it->second++
 */

#include <iostream>
#include <map>
#include <vector>

std::map<int,int> count_frequencies_with_find(const std::vector<int>& v);

int main ()
{
	int q = 0;
	std::cout << "Ingrese la cantidad de elementos del vector: ";
	std::cin >> q;
	if (q < 0)
	{
		std::cout << "No puede ingresar uan cantidad negativa.\n";
		return 1;
	}
	std::vector<int> v(q);
	for (std::size_t i = 0; i < v.size(); i++)
	{
		std::cout << "Ingrese el elemento #" << (i + 1) << ": ";
		std::cin >> v[i];
	}
	std::map<int,int> m = count_frequencies_with_find(v);
	std::cout << "Numero\t: Frecuencia\n";
	for (std::map<int,int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		std::cout << it->first << "\t: " << it->second << "\n";
	}
	return 0;
}

std::map<int,int> count_frequencies_with_find(const std::vector<int>& v)
{
    std::map<int,int> m;

    for (std::size_t i = 0; i < v.size(); ++i)
    {
        int x = v[i];
        std::map<int,int>::iterator it = m.find(x);

        if (it == m.end()) m.insert(std::make_pair(x, 1));
        else it->second++;
    }

    return m;
}