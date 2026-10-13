#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double z(const double x);

int main()
{
    double kp, kk;
    int n;

    cout << "kp = ";
    cin >> kp;

    cout << "kk = ";
    cin >> kk;

    cout << "n = ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Error: n must be greater than 0!" << endl;
        return 1;
    }

    double dk = (kk - kp) / n;

    
    cout << "-----------------------------------" << endl;
    cout << setw(12) << "k"
        << setw(20) << "Expression" << endl;
    cout << "-----------------------------------" << endl;

    for (int i = 0; i <= n; i++)
    {
        double k = kp + i * dk;

        double f = z(2 * k + 1)
            - pow(z(2 * k - 1), 2)
            + sqrt(z(k));

        cout << fixed << setprecision(6)
            << setw(12) << k
            << setw(20) << f << endl;
    }

    return 0;
}

double z(const double x)
{
    if (fabs(x) >= 1)
    {
        return (cos(x) + 1)
            / (sin(x) * sin(x) + exp(x));
    }
    else
    {
        double S = 1.0;
        double a = 1.0;

        for (int j = 1; j <= 7; j++)
        {
            a *= -x / j;
            S += a;
        }

        return exp(-x) * S;
    }
}