#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Heap Sort
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Randomized Quick Sort
int randomPartition(vector<int>& arr, int low, int high) {
    int random = low + rand() % (high - low);
    swap(arr[random], arr[high]);
    return partition(arr, low, high);
}

void randomizedQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    vector<int> mergeArr = {64, 34, 25, 12, 22, 11, 90};
    vector<int> heapArr = {64, 34, 25, 12, 22, 11, 90};
    vector<int> quickArr = {64, 34, 25, 12, 22, 11, 90};
    vector<int> randomizedQuickArr = {64, 34, 25, 12, 22, 11, 90};

    int n = mergeArr.size();

    // Merge Sort
    mergeSort(mergeArr, 0, n - 1);
    cout << "Sorted array using Merge Sort: ";
    for (int i = 0; i < n; i++) {
        cout << mergeArr[i] << " ";
    }
    cout << endl;

    // Heap Sort
    heapSort(heapArr);
    cout << "Sorted array using Heap Sort: ";
    for (int i = 0; i < n; i++) {
        cout << heapArr[i] << " ";
    }
    cout << endl;

    // Quick Sort
    quickSort(quickArr, 0, n - 1);
    cout << "Sorted array using Quick Sort: ";
    for (int i = 0; i < n; i++) {
        cout << quickArr[i] << " ";
    }
    cout << endl;

    // Randomized Quick Sort
    randomizedQuickSort(randomizedQuickArr, 0, n - 1);
    cout << "Sorted array using Randomized Quick Sort: ";
    for (int i = 0; i < n; i++) {
        cout << randomizedQuickArr[i] << " ";
    }
    cout << endl;

    return 0;
}

