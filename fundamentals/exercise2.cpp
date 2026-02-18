/*
 * EJERCICIO 2 – Parte 2 (Versión Optimizada)
 *
 * Objetivo:
 * Mejorar la implementación anterior de is_prime(int n)
 * para que sea más eficiente.
 *
 * Fundamento matemático:
 * Si un número n tiene un divisor mayor que sqrt(n),
 * entonces necesariamente tiene otro divisor menor que sqrt(n).
 *
 * Por lo tanto, solo es necesario comprobar divisores hasta que:
 *
 *      d * d <= n
 *
 * Requisitos:
 *
 * 1. La función debe mantener:
 *      - Retornar false si n <= 1.
 *      - Retornar true si n es primo.
 *
 * 2. Optimizar la búsqueda de divisores:
 *      - Si n == 2 → true.
 *      - Si n es par (n % 2 == 0) → false.
 *      - Solo comprobar divisores impares.
 *      - Iterar mientras d * d <= n.
 *
 * 3. NO usar std::sqrt().
 *    Usar la condición:
 *
 *          d * d <= n
 *
 *    para evitar costos adicionales y problemas de precisión.
 *
 * Complejidad:
 *    La versión anterior tenía complejidad O(n).
 *    Esta versión debe reducirse aproximadamente a O(√n).
 *
 * Ejemplos:
 *    is_prime(29)  -> true
 *    is_prime(49)  -> false
 *    is_prime(97)  -> true
 *    is_prime(100) -> false
 */

#include <iostream>
#include <vector>

bool is_prime(int n)
{
    if (n <= 1)  return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i*i <= n; i += 2)
    {
        std::cout << "Probando divisor: " << i << "\n";
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    std::vector<int> test_numbers = {29, 49, 97, 100};
    for (int num : test_numbers)
    {
        if (is_prime(num)) std::cout << num << " es primo\n";
        else std::cout << num << " no es primo\n";
    }
    return 0;
}