#include<bits/stdc++.h>
using namespace std;

struct Point
{
    double x, y;
};

class NewtonForward
{
public :

    double cal_u(double u, int n)
    {
        double temp = u;
        for (int i = 1; i < n; i++)
            temp =temp * (u - i);
        return temp;
    }

    long long int fact(int x)
    {
        long long int fac= 1;
        for (long long int i = 2; i <= x; i++)
            fac = fac * i;
        return fac;
    }

    double newtonforward(vector<Point>points, double value)
    {
        int n = points.size();
        double y[n][n];
        for (int i = 0; i < n; i++)
            y[i][0] = points[i].y;
        // calculating tabular value
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j + i < n; j++)
                y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
        double res = y[0][0];
        double u = (value - points[0].x)/(points[1].x - points[0].x);
        for (int i = 1; i < n; i++)
        {
            res += cal_u(u, i)*y[0][i]/(double)fact(i);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
                cout << setw(4) << y[i][j] << "\t";
            cout << endl;
        }
        return res;
    }
};

int main()
{

    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    NewtonForward formula;
    vector<Point>points;
    double x, y, value;
    cin >> value;
    while (cin >> x >> y)
    {
        points.push_back({x, y});
    }
    double ans = formula.newtonforward(points, value);
    cout << ans << endl;
    return 0;
}
/*
0.12
0.10 0.1003
0.15 0.1511
0.20 0.2027
0.25 0.2553
0.30 0.3093
ans -> 0.120528
*/
// 1925
// 1891 46
// 1901 66
// 1911 81
// 1921 93
// 1931 101
//ans 96.8368
