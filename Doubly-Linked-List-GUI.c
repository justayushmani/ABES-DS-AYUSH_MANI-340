#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;
HWND hwndInsertValue, hwndDisplay, hwndMain;
HWND hwndInsertBegin, hwndInsertEnd, hwndDeleteBegin, hwndDeleteEnd;

// Function declarations
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void AddMenus(HWND);
void AddControls(HWND);

void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
    updateDisplay();
}

void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
    updateDisplay();
}

void deleteAtBeginning() {
    if (head == NULL) {
        MessageBox(hwndMain, "List is empty", "Error", MB_OK | MB_ICONERROR);
        return;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
    updateDisplay();
}

void deleteAtEnd() {
    if (head == NULL) {
        MessageBox(hwndMain, "List is empty", "Error", MB_OK | MB_ICONERROR);
        return;
    }

    struct Node* temp = head;

    if (temp->next == NULL) {
        head = NULL;
        free(temp);
        updateDisplay();
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
    updateDisplay();
}

void updateDisplay() {
    char displayText[1024] = "Doubly Linked List: ";
    
    if (head == NULL) {
        strcat(displayText, "Empty");
    } else {
        struct Node* temp = head;
        char numStr[16];
        while (temp != NULL) {
            sprintf(numStr, "%d ", temp->data);
            strcat(displayText, numStr);
            temp = temp->next;
        }
    }
    
    SetWindowText(hwndDisplay, displayText);
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = WindowProcedure;

    if(!RegisterClassW(&wc))
        return -1;

    hwndMain = CreateWindowW(L"myWindowClass", L"Doubly Linked List GUI",
                         WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                         100, 100, 500, 400,
                         NULL, NULL, hInst, NULL);

    MSG msg = {0};
    while(GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch(msg) {
        case WM_CREATE:
            AddControls(hwnd);
            break;
        case WM_COMMAND:
            switch(wp) {
                case 1: { // Insert at Beginning
                    char value[256];
                    GetWindowText(hwndInsertValue, value, 256);
                    insertAtBeginning(atoi(value));
                    SetWindowText(hwndInsertValue, "");
                    break;
                }
                case 2: { // Insert at End
                    char value[256];
                    GetWindowText(hwndInsertValue, value, 256);
                    insertAtEnd(atoi(value));
                    SetWindowText(hwndInsertValue, "");
                    break;
                }
                case 3: // Delete at Beginning
                    deleteAtBeginning();
                    break;
                case 4: // Delete at End
                    deleteAtEnd();
                    break;
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcW(hwnd, msg, wp, lp);
    }
    return 0;
}

void AddControls(HWND hwnd) {
    // Create input field
    CreateWindowW(L"static", L"Enter Value:", WS_VISIBLE | WS_CHILD,
                 20, 20, 100, 20, hwnd, NULL, NULL, NULL);
    
    hwndInsertValue = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER,
                                  120, 20, 100, 20, hwnd, NULL, NULL, NULL);

    // Create buttons
    hwndInsertBegin = CreateWindowW(L"button", L"Insert at Beginning", 
                                  WS_VISIBLE | WS_CHILD,
                                  20, 60, 150, 30, hwnd, (HMENU)1, NULL, NULL);

    hwndInsertEnd = CreateWindowW(L"button", L"Insert at End", 
                               WS_VISIBLE | WS_CHILD,
                               180, 60, 150, 30, hwnd, (HMENU)2, NULL, NULL);

    hwndDeleteBegin = CreateWindowW(L"button", L"Delete at Beginning", 
                                 WS_VISIBLE | WS_CHILD,
                                 20, 100, 150, 30, hwnd, (HMENU)3, NULL, NULL);

    hwndDeleteEnd = CreateWindowW(L"button", L"Delete at End", 
                               WS_VISIBLE | WS_CHILD,
                               180, 100, 150, 30, hwnd, (HMENU)4, NULL, NULL);

    // Create display area
    hwndDisplay = CreateWindowW(L"static", L"Doubly Linked List: Empty", 
                              WS_VISIBLE | WS_CHILD | SS_LEFT,
                              20, 150, 440, 200, hwnd, NULL, NULL, NULL);
}