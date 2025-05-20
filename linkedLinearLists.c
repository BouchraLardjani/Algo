 
// This is for implementation of all declared function.
                                                                             
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include <stdio.h>
typedef struct LogEntry {
    int id;
    char message[256];
    char timestamp[20];
    int severity;
    struct LogEntry* next;
} LogEntry;
//createLogEntry function: this function create new LogEntry in the list.
LogEntry* createLogEntry(int id, const char* message, const char* timestamp, int severity) {
    LogEntry* newEntry = (LogEntry*)malloc(sizeof(LogEntry));
    newEntry->id = id;
    strncpy(newEntry->message, message, 255);
    newEntry->message[255] = '\0';
    strncpy(newEntry->timestamp, timestamp, 19);
    newEntry->timestamp[19] = '\0';
    newEntry->severity = severity;
    newEntry->next = NULL;
    return newEntry;
}
// insertAtBeginning function: this function insert at the beginning newEntry at the list.
void insertAtBeginning(LogEntry** head, LogEntry* newEntry) {
    newEntry->next = *head;
    *head = newEntry;
}
// insertAtEnd function: this function insert at newEntry at the end of list.
void insertAtEnd(LogEntry** head, LogEntry* newEntry) {
    if (*head == NULL) {
        *head = newEntry;
        return;
    }
    LogEntry* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newEntry;
}
// insertAtPosition function :this function insert a newEntry in specific position.
void insertAtPosition(LogEntry** head, LogEntry* newEntry, int position) {
	int i;
    if (position <= 0 || *head == NULL) {
        insertAtBeginning(head, newEntry);
        return;
    }
    LogEntry* temp = *head;
    for ( i = 0; i < position - 1 && temp->next != NULL; i++)
        temp = temp->next;
    newEntry->next = temp->next;
    temp->next = newEntry;
}
// deleteById function: this function delete the log by the ID.
void deleteById(LogEntry** head, int id) {
    LogEntry* temp = *head;
    LogEntry* prev = NULL;
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (prev == NULL)
        *head = temp->next;
    else
        prev->next = temp->next;
    free(temp);
}
// deleteByTimestamp function: this function delete the log by timestamp .
void deleteByTimestamp(LogEntry** head, const char* timestamp) {
    LogEntry* temp = *head;
    LogEntry* prev = NULL;
    while (temp != NULL && strcmp(temp->timestamp, timestamp) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (prev == NULL)
        *head = temp->next;
    else
        prev->next = temp->next;
    free(temp);
}
// deleteFirst function : this function delete the log at  the first list.
void deleteFirst(LogEntry** head) {
    if (*head == NULL) return;
    LogEntry* temp = *head;
    *head = (*head)->next;
    free(temp);
}
// deleteLast function: this function delete the log at the end of list.
void deleteLast(LogEntry** head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    LogEntry* temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}
// searchById function: this function find the log by specific Id. 
LogEntry* searchById(LogEntry* head, int id) {
    while (head != NULL) {
        if (head->id == id) return head;
        head = head->next;
    }
    return NULL;
}
// searchByKeyword function: this function find the log by specific keyword.
LogEntry* searchByKeyword(LogEntry* head, const char* keyword) {
    while (head != NULL) {
        if (strstr(head->message, keyword)) return head;
        head = head->next;
    }
    return NULL;
}
// searchByTimestamp function: this function find the log by specific timestamp.
LogEntry* searchByTimestamp(LogEntry* head, const char* timestamp) {
    while (head != NULL) {
        if (strcmp(head->timestamp, timestamp) == 0) return head;
        head = head->next;
    }
    return NULL;
}
// sortByTimestamp function: this function sort the logs by timestamp.
void sortByTimestamp(LogEntry** head) {
    if (*head == NULL || (*head)->next == NULL) return;
    LogEntry *i, *j;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->timestamp, j->timestamp) > 0) {
                LogEntry temp = *i;
                *i = *j;
                *j = temp;

                LogEntry* tmp = i->next;
                i->next = j->next;
                j->next = tmp;
            }
        }
    }
}
// sortBySeverity function: this function sort the logs by severity.
void sortBySeverity(LogEntry** head) {
    if (*head == NULL || (*head)->next == NULL) return;
    LogEntry *i, *j;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->severity > j->severity) {
                LogEntry temp = *i;
                *i = *j;
                *j = temp;
                LogEntry* tmp = i->next;
                i->next = j->next;
                j->next = tmp;
            }
        }
    }
}
// reverseList function : this function reverse the list .
void reverseList(LogEntry** head) {
    LogEntry* prev = NULL;
    LogEntry* current = *head;
    LogEntry* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
// countLogs function : this function calculate the number of logs.
int countLogs(LogEntry* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}
// printLogList function: this function display the list.
void printLogList(LogEntry* head) {
    while (head != NULL) {
        printf("ID: %d | Time: %s | Severity: %d | Message: %s\n",
               head->id, head->timestamp, head->severity, head->message);
        head = head->next;
    }
}

