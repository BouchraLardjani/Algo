
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct LogEntry {
    int id;
    char message[256];
    char timestamp[20]; 
    int severity;
    struct LogEntry* next;
} LogEntry;

LogEntry* createLogEntry(int id, const char* message, const char* timestamp, int severity);
void insertAtBeginning(LogEntry** head, LogEntry* newEntry);
void insertAtEnd(LogEntry** head, LogEntry* newEntry);
void insertAtPosition(LogEntry** head, LogEntry* newEntry, int position);
void deleteById(LogEntry** head, int id);
void deleteByTimestamp(LogEntry** head, const char* timestamp);
void deleteFirst(LogEntry** head);
void deleteLast(LogEntry** head);
LogEntry* searchById(LogEntry* head, int id);
LogEntry* searchByKeyword(LogEntry* head, const char* keyword);
LogEntry* searchByTimestamp(LogEntry* head, const char* timestamp);
void sortByTimestamp(LogEntry** head);
void sortBySeverity(LogEntry** head);
void reverseList(LogEntry** head);
int countLogs(LogEntry* head);
void printLogList(LogEntry* head);


