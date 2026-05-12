#include <iostream>
#include <ctime>

using namespace std;

#define MAX 10005

// Bubble Sort - Slide Chương 4 trang 17
void BubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j - 1] > a[j]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}
// Counting Sort - Slide Chương 4 (Nâng cao) trang 46
void CountingSort(int a[], int n) {
    // Tìm giá trị lớn nhất trong mảng
    int max_val = a[0];
    for (int i = 1; i < n; i++) if (a[i] > max_val) max_val = a[i];

    // Khởi tạo mảng đếm (cấp phát động cho kích thước linh hoạt)
    int *cntArr = new int[max_val + 1]{0};
    int *ans = new int[n];

    // Bước 3: Đếm số lần xuất hiện
    for (int i = 0; i < n; i++) cntArr[a[i]]++;

    // Bước 4: Tính mảng tích lũy (prefix sum)
    for (int i = 1; i <= max_val; i++) cntArr[i] += cntArr[i - 1];

    // Bước 5: Tạo mảng kết quả (duyệt ngược để giữ tính ổn định)
    for (int i = n - 1; i >= 0; i--) {
        ans[cntArr[a[i]] - 1] = a[i];
        cntArr[a[i]]--;
    }

    // Bước 6: Sao chép về mảng ban đầu
    for (int i = 0; i < n; i++) a[i] = ans[i];

    delete[] cntArr; delete[] ans;
}
int main() {
    int choice, n;
    static int a[MAX];

    cin >> choice >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    clock_t start = clock();
    if (choice == 1) BubbleSort(a, n);
    else if (choice == 2) CountingSort(a, n);
    clock_t end = clock();

    for (int i = 0; i < n; i++) cout << a[i] << " ";

    double duration = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    cout << "\n[Phan tich] Thoi gian chay: " << duration << " ms" << endl;

    return 0;
}