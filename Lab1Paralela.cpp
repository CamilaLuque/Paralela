#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int MAX = 10000;

double A[MAX][MAX], x[MAX], y[MAX];

void pair1() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

void pair2() {
    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

int main()
{
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            A[i][j] = i;
        }
        x[i] = i;
        y[i] = 0;
    }
    auto start = high_resolution_clock::now();
    pair1();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Duracion utilizando i primero: " << duration.count() << endl;
    y[0] = 0;
    start = high_resolution_clock::now();
    pair2();
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Duracion utilizando j primero: " << duration.count() << endl;

}
