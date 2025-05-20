#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct DLogEntry {
    int id;
    char message[256];
    int severity;
    char timestamp[20];
    struct DLogEntry* next;
    struct DLogEntry* prev;
} DLogEntry;

DLogEntry* createDLogEntry(int id, const char* message, const char* timestamp, int severity);
DLogEntry* insertAtBeginningD(DLogEntry* dhead, DLogEntry* newEntry);
DLogEntry* insertAtEndD(DLogEntry* dhead, DLogEntry* newEntry);
DLogEntry* insertAtPositionD(DLogEntry* dhead, DLogEntry* newEntry, int position);
DLogEntry* deleteByIdD(DLogEntry* dhead, int id);
DLogEntry* deleteByTimestampD(DLogEntry* dhead, const char* timestamp);
DLogEntry* deleteFirstD(DLogEntry* dhead);
DLogEntry* deleteLastD(DLogEntry* dhead);
DLogEntry* deleteMiddleD(DLogEntry* dhead, int position);
DLogEntry* searchByIdD(DLogEntry* dhead, int id);
DLogEntry* searchByKeywordD(DLogEntry* dhead, const char* keyword);
DLogEntry* searchByTimestampD(DLogEntry* head, const char* timestamp);
DLogEntry* sortByDateD(DLogEntry* dhead);
DLogEntry* sortBySeverityD(DLogEntry* dhead);
DLogEntry* reverseListD(DLogEntry* dhead);
void displayForward(DLogEntry* dhead);
void displayBackward(DLogEntry* dtail);
DLogEntry* mergeListsD(DLogEntry* dhead1, DLogEntry* head2);
int countLogsD(DLogEntry* dhead);

