#include <iostream>
#include <cstring> 

template<typename T>
void findMaxAndCount(const T* array, int size, T& maxVal, int& count) {
    if (size == 0) {
        count = 0;
        return;
    }

    maxVal = array[0];
    count = 1;

    for (int i = 1; i < size; ++i) {
        if (array[i] > maxVal) {
            maxVal = array[i];
            count = 1;
        }
        else if (array[i] == maxVal) {
            count++;
        }
    }
}

template<typename T>
void shellSort(T arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            T temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Вибір функції залежно від шаблону
template<typename T>
void performTask(T arr[], int n, bool useFindMaxAndCount) {
    if (useFindMaxAndCount) {
        T maxVal;
        int count;
        findMaxAndCount(arr, n, maxVal, count);
        std::cout << "Max value: " << maxVal << ", Count: " << count << std::endl;
    }
    else {
        shellSort(arr, n);
        std::cout << "Array sorted." << std::endl;
    }
}

int main() {
    int choice;
    std::cout << "Choose the operation: \n1. Find max value and count\n2. Shell sort\n";
    std::cin >> choice;

    if (choice == 1) {
        int intArray[] = { 1, 2, 3, 4, 5, 5, 4, 3, 2, 1 };
        int maxInt, intCount;
        performTask(intArray, 10, true);
    }
    else if (choice == 2) {
        const char* arr[] = { "banana", "apple", "orange", "grape", "kiwi" };
        int n = sizeof(arr) / sizeof(arr[0]);

        std::cout << "Before sorting:" << std::endl;
        for (int i = 0; i < n; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        performTask(arr, n, false);

        std::cout << "After sorting:" << std::endl;
        for (int i = 0; i < n; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}
