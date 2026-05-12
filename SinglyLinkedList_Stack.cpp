#include <iostream>
using namespace std;

// Node cho Kho hàng
struct Product {
    int id;
    Product* next;
};

// Node cho Stack Undo
struct Action {
    string type; // "THEM" hoac "XOA"
    int productID;
    Action* next;
};

Product* khoHang = NULL;
Action* undoStack = NULL;

// Lưu thao tác vào Stack - Slide Chương 2 trang 110
void Luu_thao_tac(string type, int id) {
    Action* newAction = new Action;
    newAction->type = type;
    newAction->productID = id;
    newAction->next = undoStack;
    undoStack = newAction;
}

void Them_san_pham(int id, bool isUndo = false) {
    Product* p = new Product;
    p->id = id;
    p->next = khoHang;
    khoHang = p;
    cout << "Da them san pham: " << id << endl;
    if (!isUndo) Luu_thao_tac("THEM", id);
}

void Xoa_san_pham(int id, bool isUndo = false) {
    // Logic xoa node bat ky trong DSLK - Slide Chuong 2 trang 54
    Product *curr = khoHang, *prev = NULL;
    while (curr != NULL && curr->id != id) {
        prev = curr;
        curr = curr->next;
    }
    if (curr != NULL) {
        if (prev == NULL) khoHang = curr->next;
        else prev->next = curr->next;
        delete curr;
        cout << "Da xoa san pham: " << id << endl;
        if (!isUndo) Luu_thao_tac("XOA", id);
    }
}

void Undo() {
    if (undoStack == NULL) {
        cout << "Khong co gi de hoan tac!" << endl;
        return;
    }
    Action* last = undoStack;
    undoStack = undoStack->next;

    cout << "DANG HOAN TAC: ";
    if (last->type == "THEM") Xoa_san_pham(last->productID, true); // Undo cua Them la Xoa
    else Them_san_pham(last->productID, true); // Undo cua Xoa la Them

    delete last;
}

int main() {
    Them_san_pham(101);
    Them_san_pham(102);
    Xoa_san_pham(101);
    cout << "--- Nhan nut Undo ---" << endl;
    Undo(); // Se hoan tac viec xoa san pham 101
    return 0;
}