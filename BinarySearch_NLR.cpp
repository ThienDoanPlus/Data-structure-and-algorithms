#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *left, *right;
};

// Thêm node - Slide Chương 5 trang 49
void InsertNode(Node *&p, int x) {
    if (p == NULL) {
        p = new Node;
        p->info = x;
        p->left = p->right = NULL;
    } else {
        if (x < p->info) InsertNode(p->left, x);
        else if (x > p->info) InsertNode(p->right, x);
    }
}

// Tìm kiếm x - Slide Chương 5 trang 30 (Đệ quy)
Node* Search(Node* p, int x) {
    if (p == NULL || p->info == x) return p;
    if (x < p->info) return Search(p->left, x);
    return Search(p->right, x);
}

// Duyệt NLR - Slide Chương 5 trang 35
void duyetNLR(Node *p) {
    if (p != NULL) {
        cout << p->info << " "; // Node
        duyetNLR(p->left);      // Left
        duyetNLR(p->right);     // Right
    }
}

int main() {
    Node* root = NULL;
    int n, x, target;

    cout << "Nhap so luong node: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap gia tri: "; cin >> x;
        InsertNode(root, x);
    }

    cout << "Duyet cay NLR: "; duyetNLR(root); cout << endl;

    cout << "Nhap gia tri can tim: "; cin >> target;
    if (Search(root, target)) cout << "Tim thay " << target << " tren cay." << endl;
    else cout << "Khong tim thay." << endl;

    return 0;
}