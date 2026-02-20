/*
 * EJERCICIO 7 – Map + Vector: construir un índice sin insertar “accidentalmente”
 *
 * Objetivo:
 * Dado un std::vector<int> con números (posiblemente repetidos), construir un índice
 * que guarde, para cada número, las posiciones (índices) donde aparece.
 *
 * Firma requerida:
 *
 *      std::map<int, std::vector<std::size_t>>
 *      build_index(const std::vector<int>& v);
 *
 * Requisitos:
 * 1) Para cada valor x en el vector, almacenar en el map un vector con todos los
 *    índices i donde v[i] == x.
 *
 * 2) Imprimir el resultado ordenado (std::map ya lo hace) en el formato:
 *
 *      valor : [i1, i2, i3, ...]
 *
 *    Ejemplo:
 *      Entrada:  {4, 2, 4, 3, 2, 4}
 *      Salida:
 *        2 : [1, 4]
 *        3 : [3]
 *        4 : [0, 2, 5]
 *
 * 3) IMPORTANTE (para practicar bien map):
 *    Implementar DOS versiones:
 *
 *    A) build_index_with_brackets:
 *       Usa operator[] (permitido) para crear/obtener la lista y hacer push_back.
 *
 *    B) build_index_with_find:
 *       NO usar operator[] para insertar.
 *       Usar find() para comprobar si la clave existe.
 *       - Si no existe: insertar un vector nuevo con el índice actual.
 *       - Si existe: hacer push_back al vector existente.
 *
 * 4) Complejidad esperada:
 *    O(n log k), donde k es el número de claves distintas.
 *
 * Casos borde:
 *  - Vector vacío => map vacío
 */

#include <iostream>
#include <vector>
#include <map>

std::map<int, std::vector<std::size_t>> build_index_with_find(const std::vector<int>& v);

int main ()
{
	int q = 0;
	std::cout << "Ingrese la cantidad de elementos en el vector: ";
	std::cin >> q;
	if (q < 0)
	{
		std::cout << "No puede haber cantidad negativa.\n";
		return 1;
	}
	std::vector<int> v(q);
    for (std::size_t i = 0; i < v.size(); i++)
    {
        std::cout << "Ingrese el elemento #" << (i + 1) << ": ";
        std::cin >> v[i];
    }
	std::map<int, std::vector<std::size_t>> m = build_index_with_find(v);
    std::cout << "Numero\t: Posicion(es)\n";
	for (std::map<int,std::vector<std::size_t>>::const_iterator i = m.begin(); i != m.end(); i++)
	{
		std::cout << i->first << "\t: [";
		for (std::size_t j = 0; j < i->second.size(); j++)
		{
			std::cout << i->second[j];
			if (j + 1 < i->second.size()) std::cout << ", ";
		}
		std::cout << "]\n";
	}
	return 0;
}

std::map<int, std::vector<std::size_t>> build_index_with_find(const std::vector<int>& v)
{
    std::map<int, std::vector<std::size_t>> m;

    for (std::size_t i = 0; i < v.size(); ++i)
    {
        int key = v[i];
        std::map<int, std::vector<std::size_t>>::iterator it = m.find(key);

        if (it == m.end())
        {
            std::vector<std::size_t> positions;
            positions.push_back(i);
            m.insert(std::make_pair(key, positions));
        }
        else
        {
            it->second.push_back(i);
        }
    }

    return m;
}

/*
std::map<int, std::vector<std::size_t>> build_index(const std::vector<int>& v)
{
	std::map<int, std::vector<std::size_t>> m;
	for (std::size_t i = 0; i < v.size(); i++)
	{
		m[v[i]].push_back(i);
	}
	return m;
}
*/