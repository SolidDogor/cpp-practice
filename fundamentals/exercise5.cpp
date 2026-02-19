/*
 * EJERCICIO 5 – Eliminar duplicados preservando el orden
 *
 * Objetivo:
 * Implementar una función que reciba un std::vector<int> y retorne
 * un nuevo vector sin elementos repetidos, manteniendo el orden de
 * primera aparición.
 *
 * Firma requerida:
 *
 *      std::vector<int> remove_duplicates(const std::vector<int>& v);
 *
 * Requisitos:
 * 1) El resultado NO debe contener duplicados.
 * 2) Debe preservarse el orden original de primera aparición.
 * 3) NO usar std::set (ni std::unordered_set).
 * 4) Se permite usar std::map para registrar qué valores ya aparecieron.
 * 5) Complejidad esperada: O(n log n) usando std::map.
 *
 * Ejemplo:
 *      Entrada:  {4, 2, 4, 3, 2, 1}
 *      Salida:   {4, 2, 3, 1}
 *
 * Casos borde:
 *  - Vector vacío -> retorna vector vacío
 *  - Vector con un solo elemento -> retorna el mismo vector
 */

#include <iostream>
#include <vector>
#include <map>

void print_vector(const std::vector<int>& v);
std::vector<int> remove_duplicates(const std::vector<int>& v);

int main ()
{
	int q = 0;
	std::cout << "Ingrese la cantidad de elementos del vector: ";
	std::cin >> q;
	if (q < 0)
    {
        std::cout << "La cantidad de elementos no puede ser negativa.\n";
        return 1;
    }
	std::vector<int> v(q);
    for (int i = 0; i < q; i++)
    {
        std::cout << "Ingrese el elemento #" << (i + 1) << ": ";
        std::cin >> v[i];
    }
	std::cout << "Arreglo original:\n";
	print_vector(v);	
    v = remove_duplicates(v);
	std::cout << "Arreglo sin duplicados:\n";
	print_vector(v);
	return 0;
}

void print_vector(const std::vector<int>& v)
{
	std::cout << "{";
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
        if (i < v.size() - 1) std::cout << ", ";
	}
	std::cout << "}\n";
}

std::vector<int> remove_duplicates(const std::vector<int>& v) {
    std::map<int, int> count;
    std::vector<int> out;
    out.reserve(v.size());

    for (std::size_t i = 0; i < v.size(); ++i)
	{
        int x = v[i];
        if (count[x] == 0) out.push_back(x);
        count[x]++;
    }
    return out;
}
