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

// Xóa Node - Tập trung vào Case 1 (Node lá) - Slide Chương 5 trang 51
Node* deleteLeaf(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->info) root->left = deleteLeaf(root->left, key);
    else if (key > root->info) root->right = deleteLeaf(root->right, key);
    else {
        // Kiểm tra xem có đúng là node lá không
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL; // Trả về NULL để node cha cập nhật lại liên kết
        } else {
            cout << "Day khong phai la node la, khong thuc hien xoa!" << endl;
        }
    }
    return root;
}

void duyetNLR(Node *p) {
    if (p != NULL) {
        cout << p->info << " ";
        duyetNLR(p->left);
        duyetNLR(p->right);
    }
}

int main() {
    Node* root = NULL;
    int n, x, del;
    cout << "Nhap n: "; cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; InsertNode(root, x); }

    cout << "Cay NLR: "; duyetNLR(root); cout << endl;
    cout << "Nhap gia tri node la can xoa: "; cin >> del;
    root = deleteLeaf(root, del);

    cout << "Sau khi xoa: "; duyetNLR(root); cout << endl;
    return 0;
}