#include <bits/stdc++.h>
#include <cmath>
using namespace std;
double coefficient[100];
int N;
double funValue(double x)
{
    double result = 0;
    for (int i = N, j = 0; i >= 0; i--, j++)
    {
        result += pow(x, i) * coefficient[j];
    }
    return result;
}

double trapezoidal(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = 0.5 * (funValue(a) + funValue(b));

    for (int i = 1; i < n; i++)
    {
        sum += funValue(a + i * h);
    }

    return h * sum;
}

int main()
{
    cout << "enter max power:";
    cin >> N;
    for (int i = 0; i < N + 1; i++)
    {
        cout << "Coefficient of x^" << (N - i) << " : ";
        cin >> coefficient[i];
    }

    double a, b;
    int subInterval;
    cout << "Enter the lower limit (a): ";
    cin >> a;

    cout << "Enter the upper limit (b): ";
    cin >> b;

    cout << "Enter the number of subintervals (n): ";
    cin >> subInterval;

    double integral = trapezoidal(a, b, subInterval);

    cout << "The approximate value of the integral using the Trapezoidal rule is: "
         << integral << endl;

    return 0;
}
