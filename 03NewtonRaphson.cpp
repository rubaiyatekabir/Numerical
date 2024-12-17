#include<bits/stdc++.h>
using namespace std ;

const double dif = 0.0001 ;

class newtonRaphson
{
public :
    double f(double x)
    {
        return (x*x*x) - (3*x) + 1;
    }
    double ddxf(double x)
    {
        return 3*x*x - 3 ;
    }

    double NewtonRaphson(double x)
    {
        double h = f(x)/ddxf(x);
        while( abs(h)> dif)
        {
            x=x-h;
            h = f(x)/ddxf(x);
        }
        return x;
    }
};
int main()
{
    cout<< fixed << setprecision(10);
    srand(time(0));
    newtonRaphson raphson;
    for(int i=0 ; i<10 ; i++)
    {
        double root = rand();
        cout << "assumption : " << root << " ";
        root= raphson.NewtonRaphson(root);
        cout << "final root : " << root << endl;
    }
    return 0;
}
