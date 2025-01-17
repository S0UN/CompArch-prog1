#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int value;
    struct ListNode *next;
} ListNode;

ListNode *CreateNode(int value)
{
    ListNode *ln = malloc(sizeof(ListNode));
    if (ln == NULL)
    {
        printf("Failed to allocate memory\n");
        exit(-1);
    }
    else
    {
        ln->value = value;
        ln->next = NULL;
    }
    return ln;
}

void add(ListNode **head, int value)
{
    ListNode *newNode = CreateNode(value);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        ListNode *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void prepend(ListNode **head, int value)
{
    ListNode *newNode = CreateNode(value);
    newNode->next = *head;
    *head = newNode;
}
void delete(ListNode **head, int value)
{
    ListNode *current = *head, *prev = NULL;
    if (current != NULL && current->value == value)
    {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->value != value)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
        return;

    prev->next = current->next;
    free(current);
}

void fibonacci(ListNode **head, int value) {
    if (value <= 0) {
        printf("The number of Fibonacci terms must be positive.\n");
        return;
    }

    ListNode *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    if (value >= 1) {
        *head = CreateNode(0); 
        if (value == 1) return;
    }

    ListNode *current = CreateNode(1);
    (*head)->next = current;

    int first = 0, second = 1, sum;
    for (int i = 2; i < value; i++) {
        sum = first + second;
        current->next = CreateNode(sum);
        current = current->next;
        first = second;
        second = sum;
    }
}


int get(ListNode *head, int index)
{
    int count = 0;
    ListNode *current = head;
    while (current != NULL)
    {
        if (count == index)
        {
            return current->value;
        }
        current = current->next;
        count++;
    }
    printf("Index out of bounds\n");
    return -1; 
}

void set(ListNode** head, int index, int newValue) {
    int count = 0;
    ListNode* current = *head;
    while (current != NULL) {
        if (count == index) {
            current->value = newValue;
            return;
        }
        current = current->next;
        count++;
    }
    printf("Index %d out of bounds\n", index);
}


void insertAt(ListNode **head, int index, int value)
{
    ListNode *newNode = CreateNode(value);
    ListNode *current = *head;
    ListNode *prev = NULL;
    int i = 0;

    if (index == 0)
    {
        prepend(head, value);
        return;
    }

    while (i < index && current != NULL)
    {
        prev = current;
        current = current->next;
        i++;
    }

    if (i != index)
    {
        printf("Index out of bounds\n");
        free(newNode);
        return;
    }

    prev->next = newNode;
    newNode->next = current;
}

void printList(ListNode *head)
{
    ListNode *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main(int argc, const char *argv[]) {
    ListNode *head = NULL;

    // Append elements
    add(&head, 1);
    add(&head, 2);
    add(&head, 3);
    printf("After adding 1, 2, 3: ");
    printList(head);

    // Test get
    int getIndex = 1;
    int getValue = get(head, getIndex);
    printf("Value at index %d: %d\n", getIndex, getValue);

    // Test set
    set(&head, 1, 20);
    printf("List after setting index 1 to 20: ");
    printList(head);

    // Test insert at index
    insertAt(&head, 2, 25);
    printf("After inserting 25 at index 2: ");
    printList(head);

    // Test delete
    delete(&head, 1);
    printf("After deleting value 1: ");
    printList(head);

    // Test prepend
    prepend(&head, 0);
    printf("After prepending 0: ");
    printList(head);

    // Generate and test Fibonacci sequence
    fibonacci(&head, 10);
    printf("Fibonacci sequence with 10 terms: ");
    printList(head);

    // Cleanup: Free all nodes
    ListNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}


