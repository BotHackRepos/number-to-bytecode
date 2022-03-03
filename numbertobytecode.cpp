#include <iostream>

bool* ByteCode(int number, int& size, bool& pos) {
    int i = 0;
    int nn = number;
    while (true) {
        nn /= 2;
        if (nn == 1)
            break;
        ++i;
    }
    size = i + 1;
    bool* arr = new bool[size + 1];
    int n = number;
    for (int j = 0; j < size; ++j) {
        if (n - (n / 2 * 2) > 0) {
            arr[j] = true;
        }
        else {
            arr[j] = false;
        }
        n /= 2;
    }
    bool* arr2 = new bool[size];
    int d = 0;
    int y = arr[size - 1] % 10;
    int arrr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    bool marrr[10] = { false, true, false, true, false, true, false, true, false, true };
    for (int i = 0; i < 10; ++i) {
        if (y == arrr[i]) {
            pos = marrr[i];
            break;
        }
    }
    for (int k = size; k > 0; --k) {
        arr2[d] = arr[k];
        ++d;
    }
    delete[] arr;
    return arr2;
}

int main() {
    int num;
    std::cin >> num;
    int size;
    bool n;
    bool* bytecode = ByteCode(num, size, n);
    for (int i = 0; i < size; ++i) {
        if (bytecode[i]) {
            std::cout << "1";
        }
        else {
            std::cout << "0";
        }
    }
    delete[] bytecode;
    std::cout << n << "\n";
    return 0;
}