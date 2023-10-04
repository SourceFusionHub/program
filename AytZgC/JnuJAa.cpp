#include <iostream>
#include <vector>
#include <cmath>
#include <complex>

using namespace std;

// Utility function to compute the FFT
void fft(vector<complex<double>>& a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<complex<double>> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }

    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * M_PI / n * (invert ? -1 : 1);
    complex<double> w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

int main() {
    vector<complex<double>> data = {{1, 0}, {2, 0}, {3, 0}, {4, 0}};
    
    fft(data, false);
    for (const auto& val : data) {
        cout << val << " ";
    }
    cout << endl;

    fft(data, true);  // Inverse FFT
    for (const auto& val : data) {
        cout << val << " ";
    }

    return 0;
}
