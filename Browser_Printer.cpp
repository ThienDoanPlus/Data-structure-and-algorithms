#include <iostream>
#include <string>

using namespace std;

// Cấu trúc Node chung để lưu trữ chuỗi (URL hoặc tên tài liệu)
struct Node {
    string data;
    Node* next;
};

// ==========================================
// 1. QUẢN LÝ LỊCH SỬ (STACK)
// ==========================================
Node* historyStack = NULL; // top của Stack

void View_page(string url) {
    Node* newNode = new Node;
    newNode->data = url;
    newNode->next = historyStack;
    historyStack = newNode;
    cout << "[Browser] Dang xem trang: " << url << endl;
}

void Click_back() {
    if (historyStack == NULL) {
        cout << "[Browser] Khong co lich su de quay lai!" << endl;
        return;
    }
    Node* temp = historyStack;
    cout << "[Browser] Da thoat khoi trang: " << temp->data << endl;
    historyStack = historyStack->next;
    delete temp; // Giai phong bo nho

    if (historyStack != NULL) {
        cout << "[Browser] Trang hien tai sau khi Back: " << historyStack->data << endl;
    } else {
        cout << "[Browser] Trinh duyet dang o trang trong." << endl;
    }
}

// ==========================================
// 2. QUẢN LÝ IN ẤN (QUEUE)
// ==========================================
Node *frontP = NULL, *rearP = NULL;

void Send_to_printer(string docName) {
    Node* newNode = new Node;
    newNode->data = docName;
    newNode->next = NULL;
    
    if (rearP == NULL) { // Queue dang rong
        frontP = rearP = newNode;
    } else {
        rearP->next = newNode;
        rearP = newNode;
    }
    cout << "[Printer] Da nhan tai lieu: " << docName << " (Vao hang cho)" << endl;
}

void Process_print() {
    if (frontP == NULL) {
        cout << "[Printer] Hang cho trong, khong co gi de in!" << endl;
        return;
    }
    Node* temp = frontP;
    cout << "[Printer] Dang thuc hien in tai lieu: " << temp->data << endl;
    
    frontP = frontP->next;
    if (frontP == NULL) {
        rearP = NULL;
    }
    delete temp;
}

// ==========================================
// MENU ĐIỀU KHIỂN
// ==========================================
int main() {
    int choice;
    string input;

    while (true) {
        cout << "\n========= CÂU 3: QUẢN LÝ VĂN PHÒNG =========" << endl;
        cout << "1. Xem trang web moi (View Page)" << endl;
        cout << "2. Nhan nut Quay lai (Click Back)" << endl;
        cout << "3. Gui file di in (Send to Printer)" << endl;
        cout << "4. Thuc hien in (Process Print)" << endl;
        cout << "0. Thoat" << endl;
        cout << "Chon chuc nang: "; cin >> choice;
        cin.ignore(); // Xoa bo nho dem de dung getline

        switch (choice) {
            case 1:
                cout << "Nhap URL trang web: ";
                getline(cin, input);
                View_page(input);
                break;
            case 2:
                Click_back();
                break;
            case 3:
                cout << "Nhap ten tai lieu: ";
                getline(cin, input);
                Send_to_printer(input);
                break;
            case 4:
                Process_print();
                break;
            case 0:
                // Giai phong bo nho truoc khi thoat (Senior tip)
                while(historyStack) Click_back();
                while(frontP) Process_print();
                return 0;
            default:
                cout << "Lua chon khong hop le!" << endl;
        }
    }
    return 0;
}