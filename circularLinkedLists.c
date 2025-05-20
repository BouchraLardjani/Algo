#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct CLog {
    int id;
    char timestamp[20];
    char message[100];
    int severity;
    struct CLog* next;
} CLog;
// createCNode function: this function create node in the circular list.
CLog* createCNode(int id, const char* message, const char* timestamp, int severity) {
    CLog* node = (CLog*)malloc(sizeof(CLog));
    if (!node) return NULL;
    node->id = id;
    strncpy(node->message, message, sizeof(node->message) - 1);
    node->message[sizeof(node->message) - 1] = '\0';
    strncpy(node->timestamp, timestamp, sizeof(node->timestamp) - 1);
    node->timestamp[sizeof(node->timestamp) - 1] = '\0';
    node->severity = severity;
    node->next = NULL;
    return node;
}
// insertAtBeginningC function : this function insert newLog at the beginning of circular list.
CLog* insertAtBeginningC(CLog* tail, CLog newLog) {
    CLog* node = createCNode(newLog.id, newLog.message, newLog.timestamp, newLog.severity);
    if (!tail) {
        node->next = node;
        return node;
    }
    node->next = tail->next;
    tail->next = node;
    return tail;
}
// insertAtEndC function : this function insert newLog at the enf of circular list.
CLog* insertAtEndC(CLog* tail, CLog newLog) {
    tail = insertAtBeginningC(tail, newLog);
    return tail ? tail->next : NULL;
}
// insertAtPositionC function : this function insert newLog at specific position.
CLog* insertAtPositionC(CLog* tail, CLog newLog, int position) {
    if (!tail || position <= 0)
        return insertAtBeginningC(tail, newLog);
    CLog* temp = tail->next;
    int i = 1;
    while (i < position && temp != tail) {
        temp = temp->next;
        i++;
    }
    CLog* node = createCNode(newLog.id, newLog.message, newLog.timestamp, newLog.severity);
    node->next = temp->next;
    temp->next = node;
    if (temp == tail)
        tail = node;
    return tail;
}
// deleteByIdC function : this function delete the log by ID.
CLog* deleteByIdC(CLog* tail, int id) {
    if (!tail) return NULL;
    CLog* curr = tail->next;
    CLog* prev = tail;
    do {
        if (curr->id == id) {
            if (curr == tail && curr->next == tail) {
                free(curr);
                return NULL;
            }
            if (curr == tail) tail = prev;
            prev->next = curr->next;
            free(curr);
            return tail;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);
    return tail;
}
// deleteByTimestamp function: this function delete log by timestamp.
CLog* deleteByTimestampC(CLog* tail, const char* timestamp) {
    if (!tail) return NULL;
    CLog* curr = tail->next;
    CLog* prev = tail;
    do {
        if (strcmp(curr->timestamp, timestamp) == 0) {
            if (curr == tail && curr->next == tail) {
                free(curr);
                return NULL;
            }
            if (curr == tail) tail = prev;
            prev->next = curr->next;
            free(curr);
            return tail;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);
    return tail;
}
// deleteFirstC function: this function delete the log at the first of the circular list.
CLog* deleteFirstC(CLog* tail) {
    if (!tail) return NULL;
    CLog* head = tail->next;
    if (head == tail) {
        free(head);
        return NULL;
    }
    tail->next = head->next;
    free(head);
    return tail;
}
// deleteLastC function : this function delete log at the last circular list.
CLog* deleteLastC(CLog* tail) {
    if (!tail) return NULL;
    CLog* curr = tail->next;
    if (curr == tail) {
        free(tail);
        return NULL;
    }
    while (curr->next != tail)
        curr = curr->next;
    curr->next = tail->next;
    free(tail);
    return curr;
}
// searchByIdC function : this function find the log that contain specific Id.
CLog* searchByIdC(CLog* tail, int id) {
    if (!tail) return NULL;
    CLog* temp = tail->next;
    do {
        if (temp->id == id) return temp;
        temp = temp->next;
    } while (temp != tail->next);
    return NULL;
}
// searchByKeywordC function : this function find log that contain a specific keyword.
CLog* searchByKeywordC(CLog* tail, const char* keyword) {
    if (!tail) return NULL;
    CLog* temp = tail->next;
    do {
        if (strstr(temp->message, keyword)) return temp;
        temp = temp->next;
    } while (temp != tail->next);
    return NULL;
}
// searchByTimestampC function: this function find log that contain a specific timestamp.
CLog* searchByTimestampC(CLog* tail, const char* timestamp) {
    if (!tail) return NULL;
    CLog* temp = tail->next;
    do {
        if (strcmp(temp->timestamp, timestamp) == 0) return temp;
        temp = temp->next;
    } while (temp != tail->next);
    return NULL;
}
// countLogsC function: this function calculate the number of circular list.
int countLogsC(CLog* tail) {
    if (!tail) return 0;
    int count = 0;
    CLog* temp = tail->next;
    do {
        count++;
        temp = temp->next;
    } while (temp != tail->next);
    return count;
}
// displayCircular function : this function display circular list.
void displayCircular(CLog* tail) {
    if (!tail) {
        printf("List is empty.\n");
        return;
    }
    CLog* temp = tail->next;
    do {
        printf("ID: %d | Time: %s | Severity: %d\nMessage: %s\n---\n",
               temp->id, temp->timestamp, temp->severity, temp->message);
        temp = temp->next;
    } while (temp != tail->next);
}
// sortByDateC function : this function sort the circular list.
CLog* sortByDateC(CLog* tail) {
	char tmpMsg[100];
	char tmpTime[20];
	int tmpId ;
	int tmpSeverity;
    if (!tail) return NULL;
    CLog* i = tail->next;
    do {
        CLog* j = i->next;
        while (j != tail->next) {
            if (strcmp(i->timestamp, j->timestamp) > 0) {
                tmpId = i->id;
                 strcpy(tmpMsg, i->message);
                 strcpy(tmpTime, i->timestamp);
                tmpSeverity = i->severity;
                i->id = j->id;
                strcpy(i->message, j->message);
                strcpy(i->timestamp, j->timestamp);
                i->severity = j->severity;
                j->id = tmpId;
                strcpy(j->message, tmpMsg);
                strcpy(j->timestamp, tmpTime);
                j->severity = tmpSeverity;
            }
            j = j->next;
        }
        i = i->next;
    } while (i != tail->next);
    return tail;
}
// sortBySeverityC function : this function sort the circular list.
CLog* sortBySeverityC(CLog* tail) {
	char tmpMsg[100];
	char tmpTime[20];
	int tmpSeverity;
	int tmpId ;
    if (!tail) return NULL;
    CLog* i = tail->next;
    do {
        CLog* j = i->next;
        while (j != tail->next) {
            if (i->severity > j->severity) {
                tmpId = i->id;
                strcpy(tmpMsg, i->message);
                strcpy(tmpTime, i->timestamp);
                tmpSeverity = i->severity;
                i->id = j->id;
                strcpy(i->message, j->message);
                strcpy(i->timestamp, j->timestamp);
                i->severity = j->severity;
                j->id = tmpId;
                strcpy(j->message, tmpMsg);
                strcpy(j->timestamp, tmpTime);
                j->severity = tmpSeverity;
            }
            j = j->next;
        }
        i = i->next;
    } while (i != tail->next);
    return tail;
}
// reverseListC function : this function reverse the circular list.
CLog* reverseListC(CLog* tail) {
    if (!tail || tail->next == tail) return tail;
    CLog *prev = NULL, *curr = tail->next, *start = tail->next;
    CLog* next;
    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != start);
    start->next = prev;
    tail = start;
    return tail;
}

// dtectCycleC function : this function check if list contain cycle or not.
bool detectCycleC(CLog* tail) {
	CLog* slow;
	 CLog* fast;
    if (!tail || !tail->next) return false;// if the list is empty or contain one element.
     slow = tail->next;// initialise two pointers sarting from the head.
     fast = tail->next;
    while (fast && fast->next && fast!= tail && fast->next!=tail) {
        slow = slow->next;// slow moves one step.
        fast = fast->next->next;// fast moves two step.
        if (slow == fast) return true;// if slow and fast meet , a cycle exists.
    }
    return false;
}



