#include <iostream>
using namespace std;

// Định nghĩa cấu trúc Node theo chuẩn Slide
struct Node {
    int info;
    Node *left, *right;
};

// Hàm khởi tạo cây rỗng
void Init(Node* &root) {
    root = NULL;
}

// 1. Hàm Thêm (Insert) - Bám sát logic BST
void Insert(Node* &root, int x) {
    if (root == NULL) {
        root = new Node;
        root->info = x;
        root->left = root->right = NULL;
    } else {
        if (x < root->info) Insert(root->left, x);
        else if (x > root->info) Insert(root->right, x);
        // Nếu bằng thì không thêm (vì BST thường không chứa giá trị trùng)
    }
}

// Hàm bổ trợ tìm nút thế mạng cho trường hợp xóa nút có 2 con
// q là nút bắt đầu tìm (thường là con phải của p), p là nút cần xóa
void SearchStandFor(Node* &p, Node* &q) {
    if (q->left != NULL) {
        SearchStandFor(p, q->left);
    } else {
        p->info = q->info; // Chép giá trị nút thế mạng lên nút cần xóa
        p = q;             // Cho p trỏ vào nút thế mạng để chuẩn bị delete
        q = q->right;      // Nối con phải của nút thế mạng vào vị trí của nó
    }
}

// 2. Hàm Xóa (Delete) - Chuẩn logic 3 trường hợp
int Delete(Node* &root, int x) {
    if (root == NULL) return 0; // Không tìm thấy x để xóa

    if (x < root->info) return Delete(root->left, x);
    if (x > root->info) return Delete(root->right, x);

    // Đã tìm thấy nút có giá trị x
    Node* p = root;
    if (root->left == NULL) {
        root = root->right; // Trường hợp 1 con phải hoặc nút lá
    } else if (root->right == NULL) {
        root = root->left;  // Trường hợp 1 con trái
    } else {
        // Trường hợp nút có 2 con: Tìm nút thế mạng trái nhất của cây bên phải
        SearchStandFor(p, root->right);
    }
    delete p;
    return 1;
}

// 3. Duyệt LRN (Post-order: Left-Right-Node)
void LRN(Node* root) {
    if (root != NULL) {
        LRN(root->left);
        LRN(root->right);
        cout << root->info << " ";
    }
}

// Hàm hủy cây để giải phóng bộ nhớ (Senior Tip)
void ClearTree(Node* &root) {
    if (root != NULL) {
        ClearTree(root->left);
        ClearTree(root->right);
        delete root;
        root = NULL;
    }
}

int main() {
    Node* root;
    Init(root);
    int choice, val;

    while (true) {
        cout << "\n--- CÂU 2: CÂY NHỊ PHÂN TÌM KIẾM ---" << endl;
        cout << "1. Them nut vao cay" << endl;
        cout << "2. Xoa nut khoi cay" << endl;
        cout << "3. Duyet LRN" << endl;
        cout << "0. Quay lai Menu chinh" << endl;
        cout << "Chon thao tac: "; cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap gia tri can them: "; cin >> val;
                Insert(root, val);
                break;
            case 2:
                cout << "Nhap gia tri can xoa: "; cin >> val;
                if (Delete(root, val)) cout << "Xoa thanh cong." << endl;
                else cout << "Khong tim thay gia tri!" << endl;
                break;
            case 3:
                cout << "Duyet LRN: ";
                LRN(root);
                cout << endl;
                break;
            case 0:
                ClearTree(root);
                return 0;
            default:
                cout << "Chon sai!" << endl;
        }
    }
    return 0;
}