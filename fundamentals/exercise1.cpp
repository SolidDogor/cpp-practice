#include <vector>
#include <iostream>

double compute_mean(const std::vector<double>& v);
double compute_variance(const std::vector<double>& v);
double compute_min(const std::vector<double>& v);
double compute_max(const std::vector<double>& v);

int main()
{
    int n = 0;
    std::cout << "Ingrese la cantidad de elementos: ";
    std::cin >> n;
    std::vector<double> v(n);
    std::cout << "Ingrese los " << n << " elementos:\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << "Elemento " << i + 1 << ": ";
        std::cin >> v[i];
    }
    std::cout << "Varianza: " << compute_variance(v) << "\n";
    std::cout << "Media: " << compute_mean(v) << "\n";
    std::cout << "Maximo: " << compute_max(v) << "\n";
    std::cout << "Minimo: " << compute_min(v) << "\n";
    return 0;
}

double compute_mean(const std::vector<double>& v)
{
    double sum = 0;
    for (double x : v) sum += x;
    return sum / v.size();
}

double compute_variance(const std::vector<double>& v)
{
    double mean = compute_mean(v);
    double sum = 0;
    std::vector<double> w = v;
    for (double& x : w)
    {
        x = (x - mean) * (x - mean);
        sum += x;
    }
    return sum / w.size();
}

double compute_min(const std::vector<double>& v)
{
    double min = v[0];
    for (double x : v) if (x < min) min = x;
    return min;
}

double compute_max(const std::vector<double>& v)
{
    double max = v[0];
    for (double x : v) if (x > max) max = x;
    return max;
}