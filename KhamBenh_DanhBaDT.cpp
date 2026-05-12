#include <iostream>
#include <string>
using namespace std;
// --- MODULE 1: QUEUE BENH NHAN ---
struct Patient {
    string name;
    Patient* next;
};
Patient *front = NULL, *rear = NULL;

void Dang_ky_kham(string name) {
    Patient* p = new Patient;
    p->name = name; p->next = NULL;
    if (rear == NULL) front = rear = p;
    else { rear->next = p; rear = p; }
    cout << "Da dang ky: " << name << endl;
}

void Goi_ten_kham() {
    if (front == NULL) return;
    Patient* temp = front;
    cout << "Moi benh nhan: " << temp->name << " vao kham." << endl;
    front = front->next;
    if (front == NULL) rear = NULL;
    delete temp;
}

// --- MODULE 2: BINARY SEARCH DANH BA ---
struct Contact {
    string name;
    string phone;
};

int Tim_danh_ba(Contact db[], int n, string target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (db[mid].name == target) return mid;
        if (target < db[mid].name) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int main() {
    // Demo Queue
    Dang_ky_kham("Nguyen Van A");
    Dang_ky_kham("Tran Thi B");
    Goi_ten_kham();

    // Demo Binary Search
    Contact danhBa[3] = {{"An", "01"}, {"Binh", "02"}, {"Cuong", "03"}};
    int idx = Tim_danh_ba(danhBa, 3, "Binh");
    if (idx != -1) cout << "Tim thay so: " << danhBa[idx].phone << endl;

    return 0;
}