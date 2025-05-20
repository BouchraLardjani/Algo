#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct TLog {
    int id;
    char message[256];
    char timestamp[20]; // ?????? ??????? ???
    int severity;
    struct TLog* left;
    struct TLog* right;
} TLog;

// ????? Heap ?????? ??????? ??? ???????
typedef struct {
    TLog* entries[100]; // ?????? ???? Heap
    int size;
} LogHeap;

// BST Functions
TLog* createNode(int id, const char* msg, const char* ts, int severity);
TLog* insertNode(TLog* root, TLog* node);
TLog* deleteNode(TLog* root, const char* timestamp);
TLog* searchByTimestampT(TLog* root, const char* timestamp);

void inorderTraversal(TLog* root);
void preorderTraversal(TLog* root);
void postorderTraversal(TLog* root);

TLog* findMin(TLog* root);
TLog* linkedListToBST( TLog* head); 
int countListNodes(TLog* head);

// Heap Functions
void initHeap(LogHeap* heap);
void insertToHeap(LogHeap* heap, TLog* log);
TLog* removeMax(LogHeap* heap); // log with highest severity
void heapifyDown(LogHeap* heap, int index);



   
