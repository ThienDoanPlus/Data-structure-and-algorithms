#include <iostream>
#include <ctime>

using namespace std;

#define MAX 10005

// --- INSERTION SORT - Slide Chương 4 trang 40 ---
void InsertionSort(int a[], int n) {
    int x, i, j;
    for (i = 1; i < n; i++) {
        x = a[i]; 
        j = i - 1;
        while (0 <= j && x < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

// --- HEAP SORT - Slide Chương 4 (Nâng cao) trang 26, 27 ---
void shift(int a[], int i, int n) {
    int j = 2 * i + 1;
    if (j >= n) return;
    if (j + 1 < n && a[j] < a[j + 1]) j++;
    if (a[i] >= a[j]) return;
    else {
        int temp = a[i]; a[i] = a[j]; a[j] = temp; // Swap
        shift(a, j, n);
    }
}

void HeapSort(int a[], int n) {
    // Bước 1: Tạo Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        shift(a, i, n);
    
    // Bước 2: Hoán đổi pt đầu với pt cuối và tạo lại heap
    for (int i = n - 1; i > 0; i--) {
        int temp = a[0]; a[0] = a[i]; a[i] = temp;
        shift(a, 0, i);
    }
}

int main() {
    int choice, n;
    static int a[MAX];

    cin >> choice >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    clock_t start = clock();
    if (choice == 1) InsertionSort(a, n);
    else if (choice == 2) HeapSort(a, n);
    clock_t end = clock();

    for (int i = 0; i < n; i++) cout << a[i] << " ";
    
    double duration = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    cout << "\n[Phan tich] Thoi gian chay: " << duration << " ms" << endl;

    return 0;
}