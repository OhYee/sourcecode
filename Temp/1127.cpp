#include <complex>
#include <cstdio>
#include <iostream>
using namespace std;

#define Log(format, ...) printf(format, ##__VA_ARGS__)

/* 向量模板 */
const double eps = 1e-10;
typedef complex<double> Vector;

int sgn(double x) {
    if (fabs(x) <= eps)
        return 0;
    return x > 0 ? 1 : -1;
}
double Cross(auto a, auto b) {
    return a.real() * b.imag() - a.imag() * b.real();
}
double Dot(auto a, auto b) { return a.real() * b.real() + a.imag() * b.imag(); }
double Mixed(auto a, auto b, auto c) {
    return (b.real() - a.real()) * (c.imag() - a.imag()) -
           (b.imag() - a.imag()) * (c.real() - a.real());
}

void print(auto mycomplex) {
    cout << "complex: " << mycomplex << endl
         << "real: " << mycomplex.real() << endl // 实部
         << "imag: " << mycomplex.imag() << endl // 虚部
         << "abs: " << abs(mycomplex) << endl    // 模
         << "arg: " << arg(mycomplex) << endl    // 幅角
         << "norm: " << norm(mycomplex) << endl
         << "conj: " << conj(mycomplex) << endl
         << "polar: " << polar(mycomplex) << endl
         << "proj: " << proj(mycomplex) << endl;
}

int main() {
    complex<double> vec1(3, 4), vec2(1, 1);
    
    print(vec1);
    print(vec2);
    print(vec1 + vec2);
    print(vec1 * vec2);

    cout << Dot(vec1, vec2) << " " << Cross(vec1, vec2) << endl;

    return 0;
}