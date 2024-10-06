#include <iostream>
#include <vector>

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