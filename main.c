#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"linkedLinearLists.h"
#include "bidirectionalLinkedLists.h"
#include "circularLinkedLists.h"
#include"trees.h"

int main() {
	LogEntry* head = NULL;
   	DLogEntry* dhead = NULL;
    int choice = -1;
    int id, severity, position;
    char message[256];
    char timestamp[20];
    char keyword[30];
    LogEntry* result = NULL;
    LogEntry* newEntry = NULL;
    DLogEntry* newEntryD = NULL;
    
    while (choice != 0) {
        printf("\n--- Log Entry Manager ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete by ID\n");
        printf("5. Delete by timestamp\n");
        printf("6. Delete first\n");
        printf("7. Delete last\n");
        printf("8. Search by ID\n");
        printf("9. Search by keyword\n");
        printf("10. Search by timestamp\n");
        printf("11. Sort by timestamp\n");
        printf("12. Sort by severity\n");
        printf("13. Reverse list\n");
        printf("14. Count logs\n");
        printf("15. Print all logs\n");
        printf("\n--- Doubly Linked List Log Menu ---\n");
        printf("16. Insert at Beginning\n");
        printf("17. Insert at End\n");
        printf("18. Insert at Position\n");
        printf("19. Delete by ID\n");
        printf("20. Delete by Timestamp\n");
        printf("21. Delete First\n");
        printf("22. Delete Last\n");
        printf("23. Delete at Position\n");
        printf("24. Search by ID\n");
        printf("25. Search by Keyword\n");
        printf("26. Search by Timestamp\n");
        printf("27. Sort by Date\n");
        printf("28. Sort by Severity\n");
        printf("29. Reverse List\n");
        printf("30. Display Forward\n");
        printf("31. Display Backward\n");
        printf("32. Count Logs\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        if (choice == 1 || choice == 2 || choice == 3) {
            printf("Enter ID: ");
            scanf("%d", &id);
            getchar();
            printf("Enter message: ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';
            printf("Enter timestamp (YYYY-MM-DD HH:MM:SS): ");
            fgets(timestamp, sizeof(timestamp), stdin);
            timestamp[strcspn(timestamp, "\n")] = '\0';
            printf("Enter severity (0-10): ");
            scanf("%d", &severity);
            getchar();

            newEntry = createLogEntry(id, message, timestamp, severity);

            if (choice == 1) insertAtBeginning(&head, newEntry);
            else if (choice == 2) insertAtEnd(&head, newEntry);
            else {
                printf("Enter position: ");
                scanf("%d", &position);
                getchar();
                insertAtPosition(&head, newEntry, position);
            }
        }

        if (choice == 4) {
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            deleteById(&head, id);
        }

        if (choice == 5) {
            printf("Enter timestamp to delete: ");
            fgets(timestamp, sizeof(timestamp), stdin);
            timestamp[strcspn(timestamp, "\n")] = '\0';
            deleteByTimestamp(&head, timestamp);
        }

        if (choice == 6) {
            deleteFirst(&head);
        }

        if (choice == 7) {
            deleteLast(&head);
        }

        if (choice == 8) {
            printf("Enter ID to search: ");
            scanf("%d", &id);
            result = searchById(head, id);
            if (result)
                printf("Found: ID: %d | Time: %s | Severity: %d | Message: %s\n",
                       result->id, result->timestamp, result->severity, result->message);
            else
                printf("Log with ID %d not found.\n", id);
        }

        if (choice == 9) {
            printf("Enter keyword to search: ");
            fgets(keyword, sizeof(keyword), stdin);
            keyword[strcspn(keyword, "\n")] = '\0';
            result = searchByKeyword(head, keyword);
            if (result)
                printf("Found: ID: %d | Time: %s | Severity: %d | Message: %s\n",
                       result->id, result->timestamp, result->severity, result->message);
            else
                printf("No log containing keyword '%s' found.\n", keyword);
        }

        if (choice == 10) {
            printf("Enter timestamp to search: ");
            fgets(timestamp, sizeof(timestamp), stdin);
            timestamp[strcspn(timestamp, "\n")] = '\0';
            result = searchByTimestamp(head, timestamp);
            if (result)
                printf("Found: ID: %d | Time: %s | Severity: %d | Message: %s\n",
                       result->id, result->timestamp, result->severity, result->message);
            else
                printf("Log with timestamp '%s' not found.\n", timestamp);
        }

        if (choice == 11) {
            sortByTimestamp(&head);
            printf("List sorted by timestamp.\n");
        }

        if (choice == 12) {
            sortBySeverity(&head);
            printf("List sorted by severity.\n");
        }

        if (choice == 13) {
            reverseList(&head);
            printf("List reversed.\n");
        }

        if (choice == 14) {
            printf("Total log entries: %d\n", countLogs(head));
        }

        if (choice == 15) {
            printLogList(head);
        
        if (choice == 16 || choice == 17 || choice == 18) {
            printf("Enter ID: ");
            scanf("%d", &id);
            getchar();
            printf("Enter message: ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';
            printf("Enter timestamp (YYYY-MM-DD HH:MM:SS): ");
            fgets(timestamp, sizeof(timestamp), stdin);
            timestamp[strcspn(timestamp, "\n")] = '\0';
            printf("Enter severity (0-10): ");
            scanf("%d", &severity);
            getchar();
            
            newEntryD = createDLogEntry(id, message, timestamp, severity);
         if (choice == 16) {
            printf("Enter ID, Message, Timestamp, Severity: ");
            scanf("%d %s %d", &id, message, timestamp, &severity);
          dhead = insertAtBeginningD(dhead, createDLogEntry(id, message, timestamp, severity));
        } else if (choice == 17) {
            printf("Enter ID, Message, Timestamp, Severity: ");
            scanf("%d %s %d", &id, message, timestamp, &severity);
           dhead = insertAtEndD(dhead, createDLogEntry(id, message, timestamp, severity));
        } else if (choice == 18) {
            printf("Enter Position, then ID, Message, Timestamp, Severity: ");
            scanf("%d %d %s %d", &position, &id, message, timestamp, &severity);
            dhead = insertAtPositionD(dhead, createDLogEntry(id, message, timestamp, severity), position);
        } else if (choice == 19) {
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            dhead = deleteByIdD(dhead, id);
        } else if (choice == 20) {
            printf("Enter Timestamp to delete: ");
            scanf("%s", timestamp);
            dhead = deleteByTimestampD(dhead, timestamp);
        } else if (choice == 21) {
            dhead = deleteFirstD(dhead);
        } else if (choice == 22) {
            dhead = deleteLastD(dhead);
        } else if (choice == 23) {
            printf("Enter Position to delete: ");
            scanf("%d", &position);
            dhead = deleteMiddleD(dhead, position);
        } else if (choice == 24) {
            printf("Enter ID to search: ");
            scanf("%d", &id);
            DLogEntry* foundById = searchByIdD(dhead, id);
            if (foundById) printf("Found: %s\n", foundById->message);
            else printf("Not Found\n");
        } else if (choice == 25) {
            printf("Enter keyword: ");
            scanf("%s", keyword);
            DLogEntry* foundByKeyword = searchByKeywordD(dhead, keyword);
            if (foundByKeyword) printf("Found: %s\n", foundByKeyword->message);
            else printf("Not Found\n");
        } else if (choice == 26) {
            printf("Enter timestamp: ");
            scanf("%s", timestamp);
            DLogEntry* foundByTime = searchByTimestampD(dhead, timestamp);
            if (foundByTime) printf("Found: %s\n", foundByTime->message);
            else printf("Not Found\n");
        } else if (choice == 27) {
            dhead = sortByDateD(dhead);
        } else if (choice == 28) {
            dhead = sortBySeverityD(dhead);
        } else if (choice == 29) {
            dhead = reverseListD(dhead);
        } else if (choice == 30) {
            displayForward(dhead);
        } else if (choice == 31) {
            DLogEntry* temp = dhead;
            while (temp && temp->next) temp = temp->next;
            if (temp) displayBackward(temp);
        } else if (choice == 32) {
            printf("Total Logs: %d\n", countLogsD(dhead));
        } else {
            printf("Invalid choice\n");
        }
        if (choice == 0) {
            printf("Exiting...\n");
            while (head != NULL) deleteFirst(&head);
        }
    }
        }
    }
}
/*
CLog newLog() {
    CLog log;
    printf("Enter ID: ");
    scanf("%d", &log.id);
    getchar();
    printf("Enter message: ");
    fgets(log.message, sizeof(log.message), stdin);
    log.message[strcspn(log.message, "\n")] = '\0';
    printf("Enter timestamp (e.g., 2025-05-19): ");
    fgets(log.timestamp, sizeof(log.timestamp), stdin);
    log.timestamp[strcspn(log.timestamp, "\n")] = '\0';
    printf("Enter severity (1 to 5): ");
    scanf("%d", &log.severity);
    getchar();
    return log;
}

    CLog* tail = NULL;
    int size = 0, maxSize = 5; // For fixed-size buffer
    while (choice != 0) {
        printf("\n=== Circular Linked List Menu ===\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete by ID\n");
        printf("5. Delete by timestamp\n");
        printf("6. Delete first log\n");
        printf("7. Delete last log\n");
        printf("8. Search by ID\n");
        printf("9. Search by keyword\n");
        printf("10. Search by timestamp\n");
        printf("11. Count logs\n");
        printf("12. Display logs\n");
        printf("13. Sort by date\n");
        printf("14. Sort by severity\n");
        printf("15. Reverse list\n");
        printf("16. Insert to fixed-size buffer\n");
        printf("17. Detect cycle\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
            tail = insertAtBeginningC(tail, newLog());
        else if (choice == 2)
            tail = insertAtEndC(tail, newLog());
        else if (choice == 3) {
            CLog log = newLog();
            printf("Enter position: ");
            scanf("%d", &position);
            tail = insertAtPositionC(tail, log, position);
        }
        else if (choice == 4) {
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            tail = deleteByIdC(tail, id);
        }
        else if (choice == 5) {
            printf("Enter timestamp to delete: ");
            fgets(timestamp, sizeof(timestamp), stdin);
            timestamp[strcspn(timestamp, "\n")] = '\0';
            tail = deleteByTimestampC(tail, timestamp);
        }
        else if (choice == 6)
            tail = deleteFirstC(tail);
        else if (choice == 7)
            tail = deleteLastC(tail);
        else if (choice == 8) {
            printf("Enter ID to search: ");
            scanf("%d", &id);
            CLog* result = searchByIdC(tail, id);
            if (result)
                printf("Found: %s\n", result->message);
            else
                printf("Log not found.\n");
        }
        else if (choice == 9) {
            printf("Enter keyword to search: ");
            fgets(keyword, sizeof(keyword), stdin);
            keyword[strcspn(keyword, "\n")] = '\0';
            CLog* result = searchByKeywordC(tail, keyword);
            if (result)
                printf("Found: %s\n", result->message);
            else
                printf("Log not found.\n");
        }
        else if (choice == 10) {
            printf("Enter timestamp to search: ");
            fgets(timestamp, sizeof(timestamp), stdin);
            timestamp[strcspn(timestamp, "\n")] = '\0';
            CLog* result = searchByTimestampC(tail, timestamp);
            if (result)
                printf("Found: %s\n", result->message);
            else
                printf("Log not found.\n");
        }
        else if (choice == 11)
            printf("Total logs: %d\n", countLogsC(tail));
        else if (choice == 12)
            displayCircular(tail);
        else if (choice == 13)
            tail = sortByDateC(tail);
        else if (choice == 14)
            tail = sortBySeverityC(tail);
        else if (choice == 15)
            tail = reverseListC(tail);
        //else if (choice == 16)
            //tail = insertFixedSizeBufferC(tail, newLog, &size, maxSize);
        else if (choice == 17)
            printf("Cycle detected: %s\n", detectCycleC(tail) ? "Yes" : "No");
        else if (choice == 0) {
            printf("Exiting...\n");
            return 0;
        }
        else
            printf("Invalid option.\n");
    }

    TLog* root = NULL;
    LogHeap heap;
    initHeap(&heap);

    while (choice != 0) {
        printf("\n=== LOG SYSTEM MENU ===\n");
        printf("1. Insert log entry\n");
        printf("2. Delete log entry by timestamp\n");
        printf("3. Search log by timestamp\n");
        printf("4. Inorder traversal (BST)\n");
        printf("5. Preorder traversal (BST)\n");
        printf("6. Postorder traversal (BST)\n");
        printf("7. Insert into heap (by severity)\n");
        printf("8. Remove max severity log from heap\n");
        printf("9. Display heap (array format)\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline

        if (choice == 1) {
            int id, severity;
            char msg[100], ts[50];

            printf("Enter ID: ");
            scanf("%d", &id);
            getchar();

            printf("Enter Message: ");
            fgets(msg, sizeof(msg), stdin);
            msg[strcspn(msg, "\n")] = '\0';

            printf("Enter Timestamp: ");
            fgets(ts, sizeof(ts), stdin);
            ts[strcspn(ts, "\n")] = '\0';

            printf("Enter Severity (0-10): ");
            scanf("%d", &severity);

            TLog* newNode = createNode(id, msg, ts, severity);
            root = insertNode(root, newNode);
            printf("Inserted.\n");
        }

        else if (choice == 2) {
            char ts[50];
            printf("Enter Timestamp to delete: ");
            fgets(ts, sizeof(ts), stdin);
            ts[strcspn(ts, "\n")] = '\0';

            root = deleteNode(root, ts);
            printf("Deleted (if existed).\n");
        }

        else if (choice == 3) {
            char ts[50];
            printf("Enter Timestamp to search: ");
            fgets(ts, sizeof(ts), stdin);
            ts[strcspn(ts, "\n")] = '\0';

            TLog* found = searchByTimestampT(root, ts);
            if (found)
                printf("Found: ID %d | Time: %s | Severity: %d | Msg: %s\n", found->id, found->timestamp, found->severity, found->message);
            else
                printf("Log not found.\n");
        }

        else if (choice == 4) {
            printf("Inorder Traversal:\n");
            inorderTraversal(root);
        }

        else if (choice == 5) {
            printf("Preorder Traversal:\n");
            preorderTraversal(root);
        }

        else if (choice == 6) {
            printf("Postorder Traversal:\n");
            postorderTraversal(root);
        }

        else if (choice == 7) {
            int id, severity;
            char msg[100], ts[50];

            printf("Enter ID: ");
            scanf("%d", &id);
            getchar();

            printf("Enter Message: ");
            fgets(msg, sizeof(msg), stdin);
            msg[strcspn(msg, "\n")] = '\0';

            printf("Enter Timestamp: ");
            fgets(ts, sizeof(ts), stdin);
            ts[strcspn(ts, "\n")] = '\0';

            printf("Enter Severity (0-10): ");
            scanf("%d", &severity);

            TLog* newNode = createNode(id, msg, ts, severity);
            insertToHeap(&heap, newNode);
            printf("Inserted into heap.\n");
        }

        else if (choice == 8) {
            TLog* max = removeMax(&heap);
            if (max)
                printf("Removed Max Severity: ID %d | Severity %d | Msg: %s\n", max->id, max->severity, max->message);
            else
                printf("Heap is empty.\n");
        }

        else if (choice == 9) {
        	int i;
            printf("Heap contents (unsorted array view):\n");
            for ( i = 0; i < heap.size; ++i) {
                printf("ID: %d | Severity: %d | Msg: %s\n",
                       heap.entries[i]->id,
                       heap.entries[i]->severity,
                       heap.entries[i]->message);
            }
        }

        else if (choice == 0) {
            printf("Exiting...\n");
        }

        else {
            printf("Invalid choice.\n");
        }

void LinkedLinearListMenu() {
    LogEntry* head = NULL;
    int choice = -1, id, severity, position;
    char message[256], timestamp[50], keyword[50];
    LogEntry* result = NULL;
    LogEntry* newEntry = NULL;

    while (choice != 0) {
        printf("\n--- Linear Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete by ID\n");
        printf("5. Delete by timestamp\n");
        printf("6. Delete first\n");
        printf("7. Delete last\n");
        printf("8. Search by ID\n");
        printf("9. Search by keyword\n");
        printf("10. Search by timestamp\n");
        printf("11. Sort by timestamp\n");
        printf("12. Sort by severity\n");
        printf("13. Reverse list\n");
        printf("14. Count logs\n");
        printf("15. Print all logs\n");
        printf("0. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice >= 1 && choice <= 3) {
            printf("Enter ID: ");
            scanf("%d", &id); getchar();
            printf("Enter message: ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';
            printf("Enter timestamp: ");
            fgets(timestamp, sizeof(timestamp), stdin);
            timestamp[strcspn(timestamp, "\n")] = '\0';
            printf("Enter severity (0-10): ");
            scanf("%d", &severity); getchar();
            newEntry = createLogEntry(id, message, timestamp, severity);

            if (choice == 1) insertAtBeginning(&head, newEntry);
            else if (choice == 2) insertAtEnd(&head, newEntry);
            else if (choice == 3) {
                printf("Enter position: ");
                scanf("%d", &position); getchar();
                insertAtPosition(&head, newEntry, position);
            }
        } else if (choice == 4) {
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            deleteById(&head, id);
        } else if (choice == 5) {
            printf("Enter timestamp to delete: ");
            fgets(timestamp, sizeof(timestamp), stdin);
            timestamp[strcspn(timestamp, "\n")] = '\0';
            deleteByTimestamp(&head, timestamp);
        } else if (choice == 6) deleteFirst(&head);
        else if (choice == 7) deleteLast(&head);
        else if (choice == 8) {
            printf("Enter ID to search: ");
            scanf("%d", &id);
            result = searchById(head, id);
            if (result)
                printf("Found: %d %s %s %d\n", result->id, result->timestamp, result->message, result->severity);
            else printf("Not found\n");
        } else if (choice == 9) {
            printf("Enter keyword: ");
            fgets(keyword, sizeof(keyword), stdin);
            keyword[strcspn(keyword, "\n")] = '\0';
            result = searchByKeyword(head, keyword);
            if (result)
                printf("Found: %s\n", result->message);
            else printf("Not found\n");
        } else if (choice == 10) {
            printf("Enter timestamp: ");
            fgets(timestamp, sizeof(timestamp), stdin);
            timestamp[strcspn(timestamp, "\n")] = '\0';
            result = searchByTimestamp(head, timestamp);
            if (result)
                printf("Found: %s\n", result->message);
            else printf("Not found\n");
        } else if (choice == 11) {
            sortByTimestamp(&head);
        } else if (choice == 12) {
            sortBySeverity(&head);
        } else if (choice == 13) {
            reverseList(&head);
        } else if (choice == 14) {
            printf("Total logs: %d\n", countLogs(head));
        } else if (choice == 15) {
            printLogList(head);
        } else if (choice == 0) {
            printf("Returning to Main Menu...\n");
        } else {
            printf("Invalid option.\n");
        }
    }
}
void doublyLinkedListMenu() {
    DLogEntry* head = NULL;
    int choice = -1, id, severity, position;
    char message[256], timestamp[50], keyword[50];
    DLogEntry* result = NULL;
    DLogEntry* newEntry = NULL;

    while (choice != 0) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete by ID\n");
        printf("5. Delete first\n");
        printf("6. Delete last\n");
        printf("7. Search by ID\n");
        printf("8. Search by keyword\n");
        printf("9. Sort by severity\n");
        printf("10. Reverse list\n");
        printf("11. Count logs\n");
        printf("12. Print all logs\n");
        printf("0. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice); getchar();

        if (choice >= 1 && choice <= 3) {
            printf("Enter ID: ");
            scanf("%d", &id); getchar();
            printf("Enter message: ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';
            printf("Enter timestamp: ");
            fgets(timestamp, sizeof(timestamp), stdin);
            timestamp[strcspn(timestamp, "\n")] = '\0';
            printf("Enter severity (0-10): ");
            scanf("%d", &severity); getchar();
            newEntry = createDLogEntry(id, message, timestamp, severity);

            if (choice == 1) insertAtBeginningD(head, newEntry);
            else if (choice == 2) insertAtEndD(head, newEntry);
            else if (choice == 3) {
                printf("Enter position: ");
                scanf("%d", &position); getchar();
                insertAtPositionD(head, newEntry, position);
            }
        } else if (choice == 4) {
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            doublyDeleteById(&head, id);
        } else if (choice == 5) deleteFirstD(head);
        else if (choice == 6) deleteLastD(head);
        else if (choice == 7) {
            printf("Enter ID to search: ");
            scanf("%d", &id);
           result = searchByIdD(head, id);
            if (result)
                printf("Found: %d %s %s %d\n", result->id, result->timestamp, result->message, result->severity);
            else printf("Not found\n");
        } else if (choice == 8) {
            printf("Enter keyword: ");
            fgets(keyword, sizeof(keyword), stdin);
            keyword[strcspn(keyword, "\n")] = '\0';
            result = searchByKeywordD(head, keyword);
            if (result)
                printf("Found: %s\n", result->message);
            else printf("Not found\n");
        } else if (choice == 9) doublySortBySeverity(&head);
        else if (choice == 10) doublyReverseList(&head);
        else if (choice == 11) printf("Total logs: %d\n", doublyCountLogs(head));
        else if (choice == 12) doublyPrintLogList(head);
        else if (choice == 0) printf("Returning to Main Menu...\n");
        else printf("Invalid option.\n");
    }
}
void circularLinkedListMenu() {
    CLog* tail = NULL;
    int choice = -1;
    int id, severity, position;
    int size = 0, maxSize = 5;
    char message[100], timestamp[20], keyword[50];
    CLog newLog;
    CLog* result = NULL;

    while (choice != 0) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Insert into fixed size buffer (max %d)\n", maxSize);
        printf("5. Delete by ID\n");
        printf("6. Delete by timestamp\n");
        printf("7. Delete first\n");
        printf("8. Delete last\n");
        printf("9. Search by ID\n");
        printf("10. Search by keyword\n");
        printf("11. Search by timestamp\n");
        printf("12. Count logs\n");
        printf("13. Sort by date\n");
        printf("14. Sort by severity\n");
        printf("15. Reverse list\n");
        printf("16. Detect cycle\n");
        printf("17. Display list\n");
        printf("0. Return to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); getchar();

        if (choice >= 1 && choice <= 4) {
            printf("Enter ID: ");
            scanf("%d", &newLog.id); getchar();
            printf("Enter timestamp: ");
            fgets(newLog.timestamp, sizeof(newLog.timestamp), stdin);
            newLog.timestamp[strcspn(newLog.timestamp, "\n")] = '\0';
            printf("Enter message: ");
            fgets(newLog.message, sizeof(newLog.message), stdin);
            newLog.message[strcspn(newLog.message, "\n")] = '\0';
            printf("Enter severity (0?10): ");
            scanf("%d", &newLog.severity); getchar();

            if (choice == 1) {
                tail = insertAtBeginningC(tail, newLog);
            } else if (choice == 2) {
                tail = insertAtEndC(tail, newLog);
            } else if (choice == 3) {
                printf("Enter position: ");
                scanf("%d", &position); getchar();
                tail = insertAtPositionC(tail, newLog, position);
            } //else if (choice == 4) {
               // tail = insertFixedSizeBufferC(tail, newLog, &size, maxSize);
            //}
            choice = -1;
        } else if (choice == 5) {
            printf("Enter ID to delete: ");
            scanf("%d", &id); getchar();
            tail = deleteByIdC(tail, id);
            choice = -1;
        } else if (choice == 6) {
            printf("Enter timestamp to delete: ");
            fgets(timestamp, sizeof(timestamp), stdin);
            timestamp[strcspn(timestamp, "\n")] = '\0';
            tail = deleteByTimestampC(tail, timestamp);
            choice = -1;
        } else if (choice == 7) {
            tail = deleteFirstC(tail);
            choice = -1;
        } else if (choice == 8) {
            tail = deleteLastC(tail);
            choice = -1;
        } else if (choice == 9) {
            printf("Enter ID to search: ");
            scanf("%d", &id); getchar();
            result = searchByIdC(tail, id);
            if (result)
                printf("Found: %d | %s | %d\n%s\n", result->id, result->timestamp, result->severity, result->message);
            else
                printf("Not found.\n");
            choice = -1;
        } else if (choice == 10) {
            printf("Enter keyword to search: ");
            fgets(keyword, sizeof(keyword), stdin);
            keyword[strcspn(keyword, "\n")] = '\0';
            result = searchByKeywordC(tail, keyword);
            if (result)
                printf("Found: %d | %s | %d\n%s\n", result->id, result->timestamp, result->severity, result->message);
            else
                printf("Not found.\n");
            choice = -1;
        } else if (choice == 11) {
            printf("Enter timestamp to search: ");
            fgets(timestamp, sizeof(timestamp), stdin);
            timestamp[strcspn(timestamp, "\n")] = '\0';
            result = searchByTimestampC(tail, timestamp);
            if (result)
                printf("Found: %d | %s | %d\n%s\n", result->id, result->timestamp, result->severity, result->message);
            else
                printf("Not found.\n");
            choice = -1;
        } else if (choice == 12) {
            printf("Log count: %d\n", countLogsC(tail));
            choice = -1;
        } else if (choice == 13) {
            tail = sortByDateC(tail);
            printf("List sorted by date.\n");
            choice = -1;
        } else if (choice == 14) {
            tail = sortBySeverityC(tail);
            printf("List sorted by severity.\n");
            choice = -1;
        } else if (choice == 15) {
            tail = reverseListC(tail);
            printf("List reversed.\n");
            choice = -1;
        } else if (choice == 16) {
            if (detectCycleC(tail))
                printf("Cycle detected.\n");
            else
                printf("No cycle found.\n");
            choice = -1;
        } else if (choice == 17) {
            displayCircular(tail);
            choice = -1;
        } else if (choice == 0) {
            printf("Returning to main menu...\n");
        } else {
            printf("Invalid choice. Try again.\n");
            choice = -1;
        }
    }
}
    }
/*
int main() {
    int mainChoice = -1;

    while (mainChoice != 0) {
        printf("\n=== MAIN MENU ===\n");
        printf("1. Singly Linked List Menu\n");
        printf("2. Doubly Linked List Menu\n");
        printf("3. Circular Linked List Menu\n");
        printf("4. Binary Search Tree & Heap Menu\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &mainChoice);
        getchar(); // consume newline

        if (mainChoice == 1) {
            LinkedLinearListMenu();
        } else if (mainChoice == 2) {
            doublyLinkedListMenu();
        } else if (mainChoice == 3) {
            circularLinkedListMenu();
        } else if (mainChoice == 4) {
            bstAndHeapMenu();
        } else if (mainChoice == 0) {
            printf("Exiting main program...\n");
        } else {
            printf("Invalid main menu choice.\n");
        }
    }*/






