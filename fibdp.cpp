#include <iostream>
#include <vector>

using namespace std;

// Function to generate the Fibonacci series up to the nth term
vector<long long> generateFibonacci(int n) {
    vector<long long> fib(n + 1);

    // Base cases
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib;
}

int main() {
    int n;
    cout << "Enter the value of n for Fibonacci series: ";
    cin >> n;

    vector<long long> fibonacciSeries = generateFibonacci(n);

    cout << "Fibonacci Series up to the " << n << "th term: ";
    for (int i = 0; i <= n; i++) {
        cout << fibonacciSeries[i];
        if (i < n) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}
