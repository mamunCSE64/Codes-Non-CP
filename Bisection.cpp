#include <bits/stdc++.h>
using namespace std;
const double tolarance = (double)0.000001;
double cof[100];
int N;
double RootValu(double x)
{
    double root = 0;
    for (int i = N, j = 0; i >= 0; i--, j++)
    {
        root += pow(x, i) * cof[j];
    }
    return root;
}

double bisection()
{
    double a, b;
    cin >> a >> b;
    if (RootValu(a) * RootValu(b) >= 0)
    {
        cout << "You have not assumed right a and b" << endl;
        return -999;
    }
    double c;
    int i = 0;
    while ((b - a) >= tolarance)    
    {
        c = (a + b) / 2;
        if (RootValu(c) == tolarance) break;
        else if (RootValu(c) * RootValu(a) < 0)
            b = c;
        else a = c;
        i++;
        cout << "iteration " << i << " root " << c << endl;
    }
    return c;
}

int main()
{
    cout << "Enter the max-power :";
    cin >> N;
    for (int i = 0; i < N + 1; i++)
    {
        cout << "(x^" << (N - i) << ")*";
        cin >> cof[i];
    }
    for (int i = 0; i < N + 1; i++)
    {
        cout << cof[i] << " ";
    }
    double a, b;
    cout << "guess the vaue a and b: ";
    while (1)
    {
        double root = bisection();
        if (root != -999)
        {
            cout << "The value of root is : " << root << endl;
        }
    }
    return 0;
}
