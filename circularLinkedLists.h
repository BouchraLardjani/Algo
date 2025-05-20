
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct CLog {
    int id;
    char timestamp[20];
    char message[100];
    int severity;
    struct CLog* next;
} CLog;
CLog* createCNode(int id, const char* message, const char* timestamp, int severity);
CLog* insertAtBeginningC(CLog* tail, CLog newLog);
CLog* insertAtEndC(CLog* tail, CLog newLog);
CLog* insertAtPositionC(CLog* tail, CLog newLog, int position);
CLog* insertFixedSizeBufferC(CLog* tail, CLog newLog, int* size);
CLog* deleteByIdC(CLog* tail, int id);
CLog* deleteByTimestampC(CLog* tail, const char* timestamp);
CLog* deleteFirstC(CLog* tail);
CLog* deleteLastC(CLog* tail);
CLog* searchByIdC(CLog* tail, int id);
CLog* searchByKeywordC(CLog* tail, const char* keyword);
CLog* searchByTimestampC(CLog* tail, const char* timestamp);
int countLogsC(CLog* tail);
void displayCircular(CLog* tail);
CLog* sortByDateC(CLog* tail);
CLog* sortBySeverityC(CLog* tail);
CLog* reverseListC(CLog* tail);

bool detectCycleC(CLog* tail);


