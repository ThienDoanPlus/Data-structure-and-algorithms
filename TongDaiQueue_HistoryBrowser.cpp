#include <iostream>
using namespace std;

#define MAX 100

// --- MODULE 1: QUEUE TONG DAI (Hàng đợi vòng đơn giản) ---
int queue_calls[MAX];
int f = -1, r = -1;

void Nhan_cuoc_goi(int phoneNumber) {
    if (r == MAX - 1) { cout << "Tong dai ban!" << endl; return; }
    if (f == -1) f = 0;
    queue_calls[++r] = phoneNumber;
    cout << "Cuoc goi tu " << phoneNumber << " dang cho..." << endl;
}

void Pop_cuoc_goi() {
    if (f == -1 || f > r) { cout << "Khong co cuoc goi nao." << endl; return; }
    cout << "Dang ket noi voi: " << queue_calls[f++] << endl;
    if (f > r) f = r = -1; // Reset khi trống
}

// --- MODULE 2: STACK LICH SU WEB ---
int stack_history[MAX];
int sp = -1;

void Truy_cap_web(int pageID) {
    if (sp == MAX - 1) return;
    stack_history[++sp] = pageID;
    cout << "Da truy cap trang: " << pageID << endl;
}

void Quay_lai_trang() {
    if (sp <= 0) { // sp = 0 là trang hiện tại, dưới đó mới là quay lại
        cout << "Khong the quay lai nua." << endl;
        return;
    }
    sp--; // Lùi lại trang trước đó
    cout << "Da quay lai trang: " << stack_history[sp] << endl;
}

int main() {
    // Demo Queue
    cout << "--- TONG DAI ---" << endl;
    Nhan_cuoc_goi(911);
    Nhan_cuoc_goi(113);
    Pop_cuoc_goi();

    // Demo Stack
    cout << "\n--- TRINH DUYET ---" << endl;
    Truy_cap_web(1); // Google
    Truy_cap_web(2); // Facebook
    Truy_cap_web(3); // Youtube
    Quay_lai_trang(); // Ve Facebook
    return 0;
}