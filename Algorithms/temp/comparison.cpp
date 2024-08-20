#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

void quicksort1(int*, int, int);
int partition1(int*, int, int);

void quicksort2(int*, int, int);
int partition2(int*, int, int);

void generateRandomArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int size = 10000;
    int arr1[size], arr2[size];
    
    // Test with multiple data types
    for (int test = 0; test < 10; test++) {
        generateRandomArray(arr1, size);
        copy(arr1, arr1 + size, arr2); // Copy arr1 to arr2

        auto start1 = high_resolution_clock::now();
        quicksort1(arr1, 0, size - 1);
        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stop1 - start1);
        cout << "Time taken by partition1: " << duration1.count() << " microseconds" << endl;

        auto start2 = high_resolution_clock::now();
        quicksort2(arr2, 0, size - 1);
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop2 - start2);
        cout << "Time taken by partition2: " << duration2.count() << " microseconds" << endl;

        // Validate the sorted arrays
        if (!is_sorted(arr1, arr1 + size)) {
            cout << "Error: partition1 did not sort the array correctly!" << endl;
        }
        if (!is_sorted(arr2, arr2 + size)) {
            cout << "Error: partition2 did not sort the array correctly!" << endl;
        }
    }

    return 0;
}

void quicksort1(int* arr, int left, int right) {
    if (left >= right)
        return;
    int p = partition1(arr, left, right);
    quicksort1(arr, left, p - 1);
    quicksort1(arr, p + 1, right);
}

int partition1(int* arr, int left, int right) {
    int p = right;
    while (left != right) {
        if (p == right && arr[left] > arr[p]) {
            swap(arr[left], arr[p]);
            right--;
            p = left;
        } else if (p == right && arr[left] <= arr[p]) {
            left++;
        } else if (p == left && arr[right] < arr[p]) {
            swap(arr[right], arr[p]);
            left++;
            p = right;
        } else if (p == left && arr[right] >= arr[p]) {
            right--;
        }
    }
    return p;
}

void quicksort2(int* arr, int left, int right) {
    if (left >= right)
        return;
    int p = partition2(arr, left, right);
    quicksort2(arr, left, p - 1);
    quicksort2(arr, p + 1, right);
}

int partition2(int* arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}
