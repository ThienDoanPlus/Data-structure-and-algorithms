#include <iostream>
#include <ctime> // Thư viện đo thời gian

using namespace std;

// (2) n <= 10.000 nên MAX là 10005 để an toàn
#define MAX 10005

// Hàm hoán vị - Slide Chương 4 trang 31
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Selection Sort - Slide Chương 4 trang 31
void SelectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_pos = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_pos]) {
                min_pos = j;
            }
        }
        if (min_pos != i) {
            swap(a[min_pos], a[i]);
        }
    }
}

// Quick Sort - Slide Chương 4 (Nâng cao) trang 11/76
// Sử dụng phân hoạch với chốt (pivot) ở giữa
void QuickSort(int a[], int left, int right) {
    int x = a[(left + right) / 2]; // Pivot
    int i = left, j = right;
    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++; 
            j--;
        }
    }
    if (left < j) QuickSort(a, left, j);
    if (i < right) QuickSort(a, i, right);
}

int main() {
    int choice, n;
    // Dùng static để mảng lớn được cấp phát ở phân vùng Data, tránh tràn bộ nhớ Stack
    static int a[MAX]; 

    // (1) Nhập số đại diện thuật toán (1: Selection, 2: Quick)
    cin >> choice;
    
    // (2) Nhập số lượng phần tử n
    cin >> n;

    // (3) Nhập n số nguyên
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // --- BẮT ĐẦU ĐO THỜI GIAN ---
    clock_t start = clock(); 

    if (choice == 1) {
        SelectionSort(a, n);
    } else if (choice == 2) {
        QuickSort(a, 0, n - 1);
    }

    clock_t end = clock(); 
    // --- KẾT THÚC ĐO THỜI GIAN ---

    // Xuất mảng đã sắp xếp
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    // Tính toán thời gian chạy ra miligiây (ms)
    double duration = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    
    cout << "\n\n--------------------------------------" << endl;
    cout << "Thuat toan: " << (choice == 1 ? "Selection Sort" : "Quick Sort") << endl;
    cout << "Thoi gian thuc thi: " << duration << " ms" << endl;
    cout << "--------------------------------------" << endl;

    return 0;
}