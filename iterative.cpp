#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void fibonacci(int n) {
    int a = 0, b = 1;
    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

int sequentialSearch(vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    // GCD calculation
    int a = 48;
    int b = 18;
    int result = gcd(a, b);
    cout << "GCD of " << a << " and " << b << " is: " << result << endl;

    // Fibonacci series generation
    int n = 10;
    fibonacci(n);

    // Sequential Search
    vector<int> seqArr = {10, 20, 30, 40, 50, 60};
    int seqKey = 30;
    int seqResult = sequentialSearch(seqArr, seqKey);
    if (seqResult != -1) {
        cout << "Element " << seqKey << " found at index " << seqResult << endl;
    } else {
        cout << "Element " << seqKey << " not found in the array." << endl;
    }

    // Binary Search
    vector<int> binArr = {10, 20, 30, 40, 50, 60};
    int binKey = 30;
    int binResult = binarySearch(binArr, binKey);
    if (binResult != -1) {
        cout << "Element " << binKey << " found at index " << binResult << endl;
    } else {
        cout << "Element " << binKey << " not found in the array." << endl;
    }

    return 0;
}

