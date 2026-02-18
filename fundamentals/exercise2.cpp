/*
 * EJERCICIO 2 – Verificación de número primo
 *
 * Objetivo:
 * Implementar una función que determine si un número entero es primo.
 *
 * Definición:
 * Un número primo es un número entero mayor que 1 que solo es divisible
 * por 1 y por sí mismo.
 *
 * Requisitos:
 * 1. Implementar la función:
 *      bool is_prime(int n);
 *
 * 2. La función debe:
 *    - Retornar false si n <= 1.
 *    - Verificar si existe algún divisor entre 2 y n-1.
 *    - Retornar true únicamente si no se encuentra ningún divisor.
 *
 * Nota:
 * En esta primera versión NO optimizar.
 * La optimización (hasta sqrt(n) y saltando pares) se hará después.
 *
 * Ejemplos:
 *    is_prime(2)  -> true
 *    is_prime(7)  -> true
 *    is_prime(9)  -> false
 *    is_prime(-5) -> false
 */

#include <iostream>
#include <vector>

bool is_prime(int n)
{
    if (n <= 1)  return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i== 0) return false;
    }
    return true;
}

int main()
{
    std::vector<int> test_numbers = {2, 7, 9, -5};
    for (int num : test_numbers)
    {
        if (is_prime(num)) std::cout << num << " es primo\n";
        else std::cout << num << " no es primo\n";
    }
    return 0;
}