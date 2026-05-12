#include <iostream>
#include <ctime> // Thư viện đo thời gian
using namespace std;
#define MAX 10005
// Hàm hoán vị 
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
// Hàm BubbleSort
void BubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j - 1] > a[j]) {
                swap(a[j], a[j - 1]);
            }
        }
    }
}
// Hàm merge (trộn) 
void merge(int array[], int left, int mid, int right) {
    int subArr1 = mid - left + 1;
    int subArr2 = right - mid;

    int *leftArr = new int[subArr1];
    int *rightArr = new int[subArr2];

    for (int i = 0; i < subArr1; i++)
        leftArr[i] = array[left + i];
    for (int j = 0; j < subArr2; j++)
        rightArr[j] = array[mid + 1 + j];

    int idxArr1 = 0, idxArr2 = 0;
    int idxMerged = left;

    while (idxArr1 < subArr1 && idxArr2 < subArr2) {
        if (leftArr[idxArr1] <= rightArr[idxArr2]) {
            array[idxMerged] = leftArr[idxArr1];
            idxArr1++;
        } else {
            array[idxMerged] = rightArr[idxArr2];
            idxArr2++;
        }
        idxMerged++;
    }

    while (idxArr1 < subArr1) {
        array[idxMerged] = leftArr[idxArr1];
        idxArr1++;
        idxMerged++;
    }
    while (idxArr2 < subArr2) {
        array[idxMerged] = rightArr[idxArr2];
        idxArr2++;
        idxMerged++;
    }
    delete[] leftArr;
    delete[] rightArr;
}

// Hàm mergeSort - Slide Chương 4 trang 62
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
    static int a[MAX]; // Dùng static để tránh tràn bộ nhớ stack với n=10.000

    // (1) Nhập số đại diện thuật toán
    cin >> choice;
    // (2) Nhập số lượng phần tử n
    cin >> n;
    // (3) Nhập n số nguyên
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Bắt đầu đo thời gian
    clock_t start = clock(); 

    if (choice == 1) {
        BubbleSort(a, n);
    } else if (choice == 2) {
        mergeSort(a, 0, n - 1);
    }

    // Kết thúc đo thời gian
    clock_t end = clock(); 

    // Xuất mảng đã sắp xếp
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    // Tính toán thời gian chạy (miligiây)
    double duration = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    cout << "\n\nThoi gian chay: " << duration << " ms" << endl;

    return 0;
}