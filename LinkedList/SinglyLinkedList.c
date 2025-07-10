#include <stdio.h>
#include <stdlib.h>

struct Node
{
    void *data;
    struct Node *next;
};

struct Node* node_constructor(void *data)
{
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
};

struct LinkedList
{
    struct Node *head;
    int size;
};

struct LinkedList* linked_list_constructor()
{
    struct LinkedList *list = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
};

void add_item(struct LinkedList *list, void *data)
{
    struct Node *new_node = node_constructor(data);
    if(list->size == 0)
    {
        list->head = new_node;
        list->size++;
        return;
    }
    
    struct Node *temp = list->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    list->size++;
};

void traverse_list(struct LinkedList *list)
{
    if(list->size == 0)
    {
        printf("List is empty!\n");
        return;
    }
    
    struct Node *temp = list->head;
    int i = 1;
    while(temp != NULL)
    {
        printf("Node %d address: %p\n", i, temp);
        printf("Node %d value: %d\n", i, *(int*)temp->data);
        temp = temp->next;
        i++;
    }
};

int main() {
    int value = 1;
    int value2 = 2;
    struct LinkedList *list = linked_list_constructor();
    add_item(list, &value);
    add_item(list, &value2);
    traverse_list(list);
    free(list);
    return 0;
}
