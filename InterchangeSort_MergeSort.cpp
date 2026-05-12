#include <iostream>
#include <ctime> // Thư viện đo thời gian thực thi

using namespace std;
#define MAX 10005

// --- INTERCHANGE SORT - Slide Chương 4 trang 53 ---
// Độ phức tạp: O(n^2)
void InterchangeSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                // Hoán vị trực tiếp tại chỗ
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

// --- MERGE SORT - Slide Chương 4 trang 62, 63, 64 ---
// Độ phức tạp: O(n log n)
void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tạo mảng phụ bằng con trỏ như slide
    int *leftArr = new int[n1];
    int *rightArr = new int[n2];

    for (int i = 0; i < n1; i++) leftArr[i] = array[left + i];
    for (int j = 0; j < n2; j++) rightArr[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            array[k++] = leftArr[i++];
        } else {
            array[k++] = rightArr[j++];
        }
    }

    while (i < n1) array[k++] = leftArr[i++];
    while (j < n2) array[k++] = rightArr[j++];

    // Giải phóng bộ nhớ mảng phụ
    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int main() {
    int choice, n;
    static int a[MAX]; // Dùng static để tránh tràn bộ nhớ Stack

    // (1) Nhập số đại diện thuật toán (1: Interchange, 2: Merge)
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
        InterchangeSort(a, n);
    } else if (choice == 2) {
        mergeSort(a, 0, n - 1);
    }

    clock_t end = clock(); 
    // --- KẾT THÚC ĐO THỜI GIAN ---

    // Xuất mảng đã sắp xếp
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    // Tính toán thời gian thực thi (miligiây)
    double duration = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    
    cout << "\n\n--------------------------------------" << endl;
    cout << "Thuat toan: " << (choice == 1 ? "Interchange Sort" : "Merge Sort") << endl;
    cout << "Thoi gian thuc thi: " << duration << " ms" << endl;
    cout << "--------------------------------------" << endl;
    return 0;
}