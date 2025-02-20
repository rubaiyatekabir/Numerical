#include <bits/stdc++.h>
using namespace std;

struct Point
{
    double x, y;
};

class NewtonDivided
{
public:
    double newtonDivided(vector<Point> points, double value)
    {
        int n = points.size();
        double f[n][n];
        for (int i = 0; i < n; i++)
            f[i][0] = points[i].y;
        // calculating tabular value
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j + i < n; j++)
                f[j][i] = (f[j + 1][i - 1] - f[j][i - 1]) / (points[i + j].x - points[j].x);
        }
        double res = f[0][0];
        double x = 1;
        for (int i = 1; i < n; i++)
        {
            x = x * (value - points[i - 1].x);
            res = res + x * f[0][i];
        }
        // displaying the table
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
                cout << f[i][j] << "\t";
            cout << endl;
        }

        return res;
    }
};

int main()
{
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    NewtonDivided formula;
    vector<Point> points;
    double x, y, value;
    cin >> value;
    while (cin >> x >> y)
    {
        points.push_back({x, y});
    }
    double ans = formula.newtonDivided(points, value);
    cout << ans << endl;
    return 0;
}
/*
2.8
2.0 0.85467
2.3 0.75682
2.6 0.43126
2.9 0.22364
3.2 0.08567
ans -> 0.274617
*/

/*
7
5 12
6 13
9 14
11 16
ans 13.4667
*/
