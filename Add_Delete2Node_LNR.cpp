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

// Tìm node nhỏ nhất bên phải - Slide Chương 5 trang 66
Node* findMin(Node* node) {
    Node* curr = node;
    while (curr && curr->left != NULL) curr = curr->left;
    return curr;
}

// Xóa Node - Tập trung vào Case 3 (2 con) - Slide Chương 5 trang 66
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->info) root->left = deleteNode(root->left, key);
    else if (key > root->info) root->right = deleteNode(root->right, key);
    else {
        // Case 1 & 2: 0 hoặc 1 con
        if (root->left == NULL) {
            Node* temp = root->right; delete root; return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left; delete root; return temp;
        }
        // Case 3: 2 con (Yêu cầu đề bài)
        Node* temp = findMin(root->right); // Tìm node thế mạng
        root->info = temp->info;           // Chép giá trị
        root->right = deleteNode(root->right, temp->info); // Xóa node thế mạng
    }
    return root;
}

// Duyệt LNR (Tăng dần) - Slide Chương 5 trang 33
void duyetLNR(Node *p) {
    if (p != NULL) {
        duyetLNR(p->left);
        cout << p->info << " ";
        duyetLNR(p->right);
    }
}

int main() {
    Node* root = NULL;
    int n, x;
    cout << "Nhap n: "; cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; InsertNode(root, x); }
    
    cout << "Truoc khi xoa (LNR): "; duyetLNR(root); cout << endl;
    
    int del; cout << "Nhap node 2 con can xoa: "; cin >> del;
    root = deleteNode(root, del);
    
    cout << "Sau khi xoa (LNR): "; duyetLNR(root); cout << endl;
    return 0;
}