#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

template <typename T>
std::istream& operator >> (std::istream& in, std::vector<T>& v) {
    if (v.size() == 0) {
        T temp;
        while (in >> temp) {
            v.push_back(temp);
        }
    }
    else {
        for (size_t i = 0; i != v.size(); ++i) {
            in >> v[i];
        }
    }
    return in;
}

template <typename T>
std::ostream& operator << (std::ostream& out, std::vector<T>& v) {
    for (size_t i = 0; i != v.size(); ++i) {
        if (i != 0) {
            out << '\n'; // вывод разделителя, можно заменить на '\n'
        }               // или любой другой нужный
        out << v[i];
    }
    return out;
}

#define ll long long
#define ld long double

int main()
{
    ll n, m; cin >> n >> m;
    vector<vector<ll>> v(n);
    vector<vector<ll>> ans(n + 1);
    ans[0].resize(m + 1);
    for (ll i = 0; i != n; ++i) {
        v[i].resize(m);
        cin >> v[i];
        ans[i + 1].resize(m + 1);
        for (ll j = 0; j != m; ++j) {
            ans[i + 1][j + 1] = ans[i + 1][j] + ans[i][j + 1] + v[i][j] - ans[i][j];
        }
    }
    ll t; cin >> t;
    vector<ll> a(t);
    for (int i = 0; i != t; ++i) {
        ll x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--; x2--; y1--; y2--;
        a[i] = ans[x2 + 1][y2 + 1] - ans[x1][y2 + 1] - ans[x2 + 1][y1] + ans[x1][y1];
    }
    //cout << a;
    /*for (int i = 0; i != n + 1; ++i) {
        cout << ans[i] << endl;
    }*/
    cout << a;
}