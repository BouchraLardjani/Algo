#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct DLogEntry {
    int id;
    char message[256];
    char timestamp[20];
    int severity;
    struct DLogEntry* next;
    struct DLogEntry* prev;
} DLogEntry;
// createDLogEntry function: this function create a new entry in the double list.
DLogEntry* createDLogEntry(int id, const char* message, const char* timestamp, int severity) {
    DLogEntry* newEntry = (DLogEntry*)malloc(sizeof(DLogEntry));
    if (!newEntry) return NULL;
    newEntry->id = id;
    strncpy(newEntry->message, message, 255);
    newEntry->message[255] = '\0';
    strncpy(newEntry->timestamp, timestamp, 19);
    newEntry->timestamp[19] = '\0';
    newEntry->severity = severity;
    newEntry->next = NULL;
    newEntry->prev = NULL;
    return newEntry;
}
// insertAtBeginningD function: this function insert newEntry at the beginning of double list.

DLogEntry* insertAtBeginningD(DLogEntry* dhead, DLogEntry* newEntry) {
    newEntry->prev = NULL;          // New first node's prev is NULL
    if (dhead != NULL) {
        newEntry->next = dhead;
        dhead->prev = newEntry;     // Fix here: use dhead, not head, and assign pointer directly
    } else {
        newEntry->next = NULL;      // If list empty, next is NULL
    }
    return newEntry;                // Return new head pointer
}
// insertAtEndD function: this function insert newEntry at tle last of double list.
DLogEntry* insertAtEndD(DLogEntry* dhead, DLogEntry* newEntry) {
    if (!dhead) return newEntry;
    DLogEntry* temp = dhead;
    while (temp->next)
        temp = temp->next;
    temp->next = newEntry;
    newEntry->prev = temp;
    return dhead;
}
// insertAtPoition function: this function insert newEntry at specific position.
DLogEntry* insertAtPositionD(DLogEntry* dhead, DLogEntry* newEntry, int position) {
    if (position <= 0 || !dhead)
        return insertAtBeginningD(dhead, newEntry);
    DLogEntry* temp = dhead;
    int index = 0;
    while (temp->next && index < position - 1) {
        temp = temp->next;
        index++;
    }
    newEntry->next = temp->next;
    newEntry->prev = temp;
    if (temp->next)
        temp->next->prev = newEntry;
    temp->next = newEntry;
    return dhead;
}
// deleteByIdD function : this function delete log by specific ID.
DLogEntry* deleteByIdD(DLogEntry* dhead, int id) {
    DLogEntry* temp = dhead;
    while (temp && temp->id != id)
        temp = temp->next;
    if (!temp) return dhead;
    if (temp->prev)
        temp->prev->next = temp->next;
    else
        dhead = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    free(temp);
    return dhead;
}
// deleteByTimestampD function : this function delete log by specific timestamp.
DLogEntry* deleteByTimestampD(DLogEntry* dhead, const char* timestamp) {
    DLogEntry* temp = dhead;
    while (temp && strcmp(temp->timestamp, timestamp) != 0)
        temp = temp->next;
    if (!temp) return dhead;
    if (temp->prev)
        temp->prev->next = temp->next;
    else
        dhead = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    free(temp);
    return dhead;
}
// deleteFirstD function: this function delete the first log in the double list.
DLogEntry* deleteFirstD(DLogEntry* dhead) {
    if (!dhead) return NULL;
    DLogEntry* temp = dhead;
    dhead = dhead->next;
    if (dhead)
        dhead->prev = NULL;
    free(temp);
    return dhead;
}
// deleteLastD function : this function delete log at the last double list.
DLogEntry* deleteLastD(DLogEntry* dhead) {
    if (!dhead) return NULL;
    if (!dhead->next) {
        free(dhead);
        return NULL;
    }
    DLogEntry* temp = dhead;
    while (temp->next)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    return dhead;
}
// deleteMiddleD function : this function delete log in specific position.
DLogEntry* deleteMiddleD(DLogEntry* dhead, int position) {
    if (!dhead || position < 0) return dhead;
    DLogEntry* temp = dhead;
    int i = 0;
    while (temp && i < position) {
        temp = temp->next;
        i++;
    }
    if (!temp) return dhead;
    if (temp->prev)
        temp->prev->next = temp->next;
    else
        dhead = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    free(temp);
    return dhead;
}
// searchByIdD function : this function find the log by Id.
DLogEntry* searchByIdD(DLogEntry* dhead, int id) {
    while (dhead) {
        if (dhead->id == id) return dhead;
        dhead = dhead->next;
    }
    return NULL;
}
// searchByKeywordD function : this function find the log that contain specific keyword.
DLogEntry* searchByKeywordD(DLogEntry* dhead, const char* keyword) {
    while (dhead) {
        if (strstr(dhead->message, keyword)) return dhead;
        dhead = dhead->next;
    }
    return NULL;
}
// searchByTimestamp function: this function find the log that contain a specific timestamp.
DLogEntry* searchByTimestampD(DLogEntry* dhead, const char* timestamp) {
    while (dhead) {
        if (strcmp(dhead->timestamp, timestamp) == 0) return dhead;
        dhead = dhead->next;
    }
    return NULL;
}
// sortByDateD function : this function sort the list by date.
DLogEntry* sortByDateD(DLogEntry* dhead) {
	char msg[256], ts[20];
	int severity;
	int id;
	
    if (!dhead) return NULL;
    DLogEntry* i, *j;
    for (i = dhead; i; i = i->next) {
        for (j = i->next; j; j = j->next) {
            if (strcmp(i->timestamp, j->timestamp) > 0) {
                // Swap values
                ts[20]= i->id; i->id = j->id; j->id = id;
                int severity = i->severity; i->severity = j->severity; j->severity = severity;
                char msg[256], ts[20];
                strcpy(msg, i->message); strcpy(i->message, j->message); strcpy(j->message, msg);
                strcpy(ts, i->timestamp); strcpy(i->timestamp, j->timestamp); strcpy(j->timestamp, ts);
            }
        }
    }
    return dhead;
}
// sortBySeverityD function: this function sort logs by severity.
DLogEntry* sortBySeverityD(DLogEntry* dhead) {
    if (!dhead) return NULL;
    DLogEntry* i, *j;
    for (i = dhead; i; i = i->next) {
        for (j = i->next; j; j = j->next) {
            if (i->severity > j->severity) {
                int id = i->id; i->id = j->id; j->id = id;
                char msg[256], ts[20];
                strcpy(msg, i->message); strcpy(i->message, j->message); strcpy(j->message, msg);
                strcpy(ts, i->timestamp); strcpy(i->timestamp, j->timestamp); strcpy(j->timestamp, ts);
                int severity = i->severity; i->severity = j->severity; j->severity = severity;
            }
        }
    }
    return dhead;
}
// reverseListD function : this function reverse the double list.
DLogEntry* reverseListD(DLogEntry* dhead) {
    DLogEntry* current = dhead;
    DLogEntry* temp = NULL;
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp)
        dhead = temp->prev;
    return dhead;
}
// displayForward function : this function display the list .
void displayForward(DLogEntry* dhead) {
    while (dhead) {
        printf("ID: %d | Time: %s | Severity: %d\nMessage: %s\n---\n",
               dhead->id, dhead->timestamp, dhead->severity, dhead->message);
        dhead = dhead->next;
    }
}
// displayBackward function : this function display the list.
void displayBackward(DLogEntry* tail) {
    while (tail) {
        printf("ID: %d | Time: %s | Severity: %d\nMessage: %s\n---\n",
               tail->id, tail->timestamp, tail->severity, tail->message);
        tail = tail->prev;
    }
}
// mergeListsD function : this function merge the list.
DLogEntry* mergeListsD(DLogEntry* dhead1, DLogEntry* dhead2) {
    if (!dhead1) return dhead2;
    if (!dhead2) return dhead1;
    DLogEntry* temp = dhead1;
    while (temp->next)
        temp = temp->next;
    temp->next = dhead2;
    dhead2->prev = temp;
    return dhead1;
}
// countLogsD function: this function calculate the number of logs in the double list.
int countLogsD(DLogEntry* dhead) {
    int count = 0;
    while (dhead) {
        count++;
        dhead = dhead->next;
    }
    return count;
}
