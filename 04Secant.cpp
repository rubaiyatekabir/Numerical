#include<bits/stdc++.h>
using namespace std;

const double dif = 1e-6;

class Secant
{
public:
    double f(double x)
    {
        return x*x*x + x - 1;
    }

    double secant(double x1, double x2)
    {
        cout << x1 << " " << x2 << endl;
        double root;
        while (abs(x1 - x2) > dif)
        {
            root = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
            cout << root << endl;
            x1 = x2;
            x2 = root;
        }
        return root;
    }
};

int main()
{
    cout << fixed << setprecision(6);
    srand(time(0));

    Secant secant;
    double x1 = rand(), x2 = rand();
    //cin >> x1 >> x2;
    double ans = secant.secant(x1, x2);
    //cout << ans << endl;

    return 0;
}
