#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void heapify_up(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapify_down(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapify_down(smallest);
        }
    }

public:
    void push(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;
        heapify_up(index);
    }

    void pop() {
        if (heap.empty()) {
            cout << "Heap is empty. Cannot pop." << endl;
            return;
        }
        // Move the last element to the root and then heapify down
        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);
    }

    int peek() {
        if (!heap.empty()) {
            return heap[0];
        }
        cout << "Heap is empty." << endl;
        return INT_MAX; // Return a placeholder value when the heap is empty
    }

    int size() {
        return heap.size();
    }
};

int main() {
    MinHeap minHeap;
    
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(4);
    minHeap.push(1);
    
    cout << "Current Min Heap: ";
    while (minHeap.size() > 0) {
        cout << minHeap.peek() << " ";
        minHeap.pop();
    }
    cout << endl;

    return 0;
}
