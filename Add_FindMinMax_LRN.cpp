#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *left, *right;
};

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

// Tìm Node có giá trị nhỏ nhất (cực trái)
int findMin(Node* p) {
    Node* curr = p;
    while (curr && curr->left != NULL) curr = curr->left;
    return curr->info;
}

// Tìm Node có giá trị lớn nhất (cực phải)
int findMax(Node* p) {
    Node* curr = p;
    while (curr && curr->right != NULL) curr = curr->right;
    return curr->info;
}

// Duyệt LRN (Post-order) - Slide Chương 5 trang 37
void duyetLRN(Node *p) {
    if (p != NULL) {
        duyetLRN(p->left);
        duyetLRN(p->right);
        cout << p->info << " ";
    }
}

int main() {
    Node* root = NULL;
    int n, x;
    cout << "Nhap so luong phan tu: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x; InsertNode(root, x);
    }

    if (root != NULL) {
        cout << "Gia tri nho nhat: " << findMin(root) << endl;
        cout << "Gia tri lon nhat: " << findMax(root) << endl;
        cout << "Duyet LRN: "; duyetLRN(root); cout << endl;
    }
    return 0;
}