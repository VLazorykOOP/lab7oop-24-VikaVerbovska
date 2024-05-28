#include <iostream>

template<typename T>
void findMaxAndCount(T arr[], int size, T& maxVal, int& count) {
    if (size == 0) {
        std::cerr << "Error: Array is empty\n";
        return;
    }

    maxVal = arr[0
    count = 1;

    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            count = 1;
        }
        else if (arr[i] == maxVal) {
            count++;
        }
    }
}

// Specialization for const charr*
void findMaxAndCount(const char* arr[], int size, const char*& maxVal, int& count) {
    if (size == 0) {
        std::cerr << "Error: Array is empty\n";
        return;
    }

    maxVal = arr[0];
    count = 1;

    for (int i = 1; i < size; ++i) {
        if (strcmp(arr[i], maxVal) > 0) {
            maxVal = arr[i];
            count = 1;
        }
        else if (strcmp(arr[i], maxVal) == 0) {
            count++;
        }
    }
}


template<typename T>
void shellSort(T arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Specialization for char*
void shellSort(char* arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            char* temp = arr[i];
            int j;
            for (j = i; j >= gap && strcmp(arr[j - gap], temp) > 0; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int choice;
    std::cout << "Choose the operation: \n1. Find max value and count\n2. Shell sort\n";
    std::cin >> choice;

    if (choice == 1) {
       const char* strings[] = { "apple", "banana", "apple", "orange", "banana" };
        const char* maxStr;
        int count;

        findMaxAndCount(strings, 5, maxStr, count);

        std::cout << "Max string: " << maxStr << ", Count: " << count << std::endl;
    }
    if (choice == 2) {
        const char* strings[] = { "banana", "apple", "orange", "grape", "pear" };
        int size = sizeof(strings) / sizeof(strings[0]);

        shellSort(const_cast<char**>(strings), size);

        std::cout << "Sorted strings:\n";
        for (int i = 0; i < size; ++i) {
            std::cout << strings[i] << std::endl;
        }
    }

    return 0;
}