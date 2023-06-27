#include <stdio.h>
#define MAX_SIZE 100

int arr[MAX_SIZE];
int size = 0;

void insert() {
    int item, index;
    printf("Enter item to insert: ");
    scanf("%d", &item);
    printf("Enter index to insert at: ");
    scanf("%d", &index);
    if (size >= MAX_SIZE) {
        printf("Array is full\n");
        return;
    }
    if (index < 0 || index > size) {
        printf("Invalid index\n");
        return;
    }
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = item;
    size++;
    printf("Inserted %d at index %d\n", item, index);
}

void delete() {
    int index;
    printf("Enter index to delete at: ");
    scanf("%d", &index);
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }
    if (index < 0 || index >= size) {
        printf("Invalid index\n");
        return;
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("Deleted item at index %d\n", index);
}

void search() {
    int item;
    printf("Enter item to search for: ");
    scanf("%d", &item);
    for (int i = 0; i < size; i++) {
        if (arr[i] == item) {
            printf("%d found at index %d\n", item, i);
            return;
        }
    }
    printf("%d not found in array\n", item);
}

int main() {
    int choice;
    while (1) {
        printf("Enter choice:\n1. Insert\n2. Delete\n3. Search\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                search();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
