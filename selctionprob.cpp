#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quickSelect(vector<int>& arr, int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivotIndex = partition(arr, low, high);

    if (k == pivotIndex) {
        return arr[pivotIndex];
    } else if (k < pivotIndex) {
        return quickSelect(arr, low, pivotIndex - 1, k);
    } else {
        return quickSelect(arr, pivotIndex + 1, high, k);
    }
}

int findKthSmallest(vector<int>& arr, int k) {
    if (k <= 0 || k > arr.size()) {
        cout << "Invalid value of k." << endl;
        return -1;
    }

    return quickSelect(arr, 0, arr.size() - 1, k - 1);
}

int main() {
    vector<int> arr = {12, 3, 14, 5, 7, 1, 9, 10, 2};
    int k = 4; // Find the 4th smallest element

    int kthSmallest = findKthSmallest(arr, k);
    if (kthSmallest != -1) {
        cout << "The " << k << "-th smallest element is: " << kthSmallest << endl;
    }

    return 0;
}
