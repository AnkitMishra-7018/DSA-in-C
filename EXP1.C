#include <stdio.h>

#define MAX 100

void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// ---------------- INSERTION ----------------

int insertAtBeginning(int arr[], int n, int value) {
    if (n >= MAX) {
        printf("Array is full. Cannot insert.\n");
        return n;
    }
    for (int i = n; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = value;
    return n + 1;
}

int insertAtEnd(int arr[], int n, int value) {
    if (n >= MAX) {
        printf("Array is full. Cannot insert.\n");
        return n;
    }
    arr[n] = value;
    return n + 1;
}

int insertAtPosition(int arr[], int n, int value, int pos) {
    // pos is 1-based index
    if (n >= MAX) {
        printf("Array is full. Cannot insert.\n");
        return n;
    }
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position.\n");
        return n;
    }
    for (int i = n; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = value;
    return n + 1;
}

// ---------------- DELETION ----------------

int deleteFromBeginning(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty. Cannot delete.\n");
        return n;
    }
    for (int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
    return n - 1;
}

int deleteFromEnd(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty. Cannot delete.\n");
        return n;
    }
    return n - 1; // simply reduce size
}

int deleteFromPosition(int arr[], int n, int pos) {
    // pos is 1-based index
    if (n == 0) {
        printf("Array is empty. Cannot delete.\n");
        return n;
    }
    if (pos < 1 || pos > n) {
        printf("Invalid position.\n");
        return n;
    }
    for (int i = pos - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];
    return n - 1;
}

// ---------------- MAIN MENU ----------------

int main() {
    int arr[MAX];
    int n = 0, choice, value, pos;

    printf("Enter initial number of elements: ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Enter %d elements:\n", n);
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\n----- ARRAY OPERATIONS MENU -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Given Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Given Position\n");
        printf("7. Display Array\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                n = insertAtBeginning(arr, n, value);
                display(arr, n);
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                n = insertAtEnd(arr, n, value);
                display(arr, n);
                break;

            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position (1 to %d): ", n + 1);
                scanf("%d", &pos);
                n = insertAtPosition(arr, n, value, pos);
                display(arr, n);
                break;

            case 4:
                n = deleteFromBeginning(arr, n);
                display(arr, n);
                break;

            case 5:
                n = deleteFromEnd(arr, n);
                display(arr, n);
                break;

            case 6:
                printf("Enter position (1 to %d): ", n);
                scanf("%d", &pos);
                n = deleteFromPosition(arr, n, pos);
                display(arr, n);
                break;

            case 7:
                display(arr, n);
                break;

            case 8:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}