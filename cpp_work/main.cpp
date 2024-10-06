#include <iostream>
//#include "useful.cpp"
#include <vector>
#include <algorithm>
#include <string>
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
            out << ' '; // вывод разделителя, можно заменить на '\n'
        }               // или любой другой нужный
        out << v[i];
    }
    return out;
}

bool operator < (const pair<int, int>& a, const pair<int, int>& b) {
    return tie(a.second, a.first) < tie(b.second, b.first);
}

int main() {
    int m, n;
    cin >> m;
    vector<int> q(m);
    cin >> q;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    sort(q.begin(), q.end());
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int ptr = 0;
    int s = 0, ln = 0;
    while (ptr != n) {
        if (ln < q[0]) {
            s += a[ptr];
            ln++;
        }
        else if (ln == q[0] + 1) {
            ln = 0;
        }
        else {
            ln++;
        }
        ptr++;
    }
    cout << s;

}


