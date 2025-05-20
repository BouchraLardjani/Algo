#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include"trees.h"
#include "linkedLinearLists.h"
TLog* createNode(int id, const char* msg, const char* ts, int severity) {
    TLog* node = (TLog*)malloc(sizeof(TLog));
    node->id = id;
    strcpy(node->message, msg);
    strcpy(node->timestamp, ts);
    node->severity = severity;
    node->left = node->right = NULL;
    return node;
}

TLog* insertNode(TLog* root, TLog* node) {
    if (!root) return node;
    if (strcmp(node->timestamp, root->timestamp) < 0)
        root->left = insertNode(root->left, node);
    else
        root->right = insertNode(root->right, node);
    return root;
}

TLog* searchByTimestampT(TLog* root, const char* timestamp) {
    if (!root || strcmp(root->timestamp, timestamp) == 0)
        return root;
    if (strcmp(timestamp, root->timestamp) < 0)
        return searchByTimestampT(root->left, timestamp);
    else
        return searchByTimestampT(root->right, timestamp);
}

TLog* findMin(TLog* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

TLog* deleteNode(TLog* root, const char* timestamp) {
    if (!root) return NULL;

    int cmp = strcmp(timestamp, root->timestamp);
    if (cmp < 0)
        root->left = deleteNode(root->left, timestamp);
    else if (cmp > 0)
        root->right = deleteNode(root->right, timestamp);
    else {
        // found node
        if (!root->left) {
            TLog* tmp = root->right;
            free(root);
            return tmp;
        } else if (!root->right) {
            TLog* tmp = root->left;
            free(root);
            return tmp;
        } else {
            TLog* temp = findMin(root->right);
            *root = *temp;
            root->right = deleteNode(root->right, temp->timestamp);
        }
    }

    return root;
}

void inorderTraversal(TLog* root) {
    if (!root) return;
    inorderTraversal(root->left);
    printf("ID: %d | Time: %s | Severity: %d | Msg: %s\n", root->id, root->timestamp, root->severity, root->message);
    inorderTraversal(root->right);
}

void preorderTraversal(TLog* root) {
    if (!root) return;
    printf("ID: %d | Time: %s | Severity: %d | Msg: %s\n", root->id, root->timestamp, root->severity, root->message);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(TLog* root) {
    if (!root) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("ID: %d | Time: %s | Severity: %d | Msg: %s\n", root->id, root->timestamp, root->severity, root->message);
}

// ========== Convert Linked List to BST ==========

// Count nodes in linked list

int countListNodes(TLog* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->left;
    }
    return count;
}


// Helper to convert sorted linked list to BST
/*
TLog* sortedListToBSTUtil(struct LogEntry** headRef, int n) {
    if (n <= 0) return NULL;

    // build left subtree
    TLog* left = sortedListToBSTUtil(headRef, n / 2);

    TLog* root = createNode((*headRef)->id, (*headRef)->message, (*headRef)->timestamp, (*headRef)->severity);
    root->left = left;

    *headRef = (*headRef)->next;

    root->right = sortedListToBSTUtil(headRef, n - n / 2 - 1);

    return root;
}

TLog* linkedListToBST(TLog* head) {
    int n = countListNodes(head);
    return sortedListToBSTUtil(&head, n);
}
*/
TLog* sortedListToBSTUtil(TLog** headRef, int n) {
    if (n <= 0) return NULL;

    // build left subtree
    TLog* left = sortedListToBSTUtil(headRef, n / 2);

    TLog* root = createNode((*headRef)->id, (*headRef)->message, (*headRef)->timestamp, (*headRef)->severity);
    root->left = left;

    *headRef = (*headRef)->left;

    root->right = sortedListToBSTUtil(headRef, n - n / 2 - 1);

    return root;
}

TLog* linkedListToBST(TLog* head) {
    int n = countListNodes(head);
    return sortedListToBSTUtil(&head, n);
}


// ========== HEAP FOR SEVERITY ==========

void initHeap(LogHeap* heap) {
    heap->size = 0;
}

void swap(TLog** a, TLog** b) {
    TLog* temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(LogHeap* heap, int idx) {
    int parent = (idx - 1) / 2;
    while (idx > 0 && heap->entries[idx]->severity > heap->entries[parent]->severity) {
        swap(&heap->entries[idx], &heap->entries[parent]);
        idx = parent;
        parent = (idx - 1) / 2;
    }
}

void heapifyDown(LogHeap* heap, int idx) {
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->entries[left]->severity > heap->entries[largest]->severity)
        largest = left;
    if (right < heap->size && heap->entries[right]->severity > heap->entries[largest]->severity)
        largest = right;

    if (largest != idx) {
        swap(&heap->entries[idx], &heap->entries[largest]);
        heapifyDown(heap, largest);
    }
}

void insertToHeap(LogHeap* heap, TLog* log) {
    if (heap->size >= 100) {
        printf("Heap full!\n");
        return;
    }
    heap->entries[heap->size] = log;
    heapifyUp(heap, heap->size);
    heap->size++;
}

TLog* removeMax(LogHeap* heap) {
    if (heap->size == 0) return NULL;
    TLog* max = heap->entries[0];
    heap->entries[0] = heap->entries[--heap->size];
    heapifyDown(heap, 0);
    return max;
}

