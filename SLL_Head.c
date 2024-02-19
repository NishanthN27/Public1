#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node * NODE;

NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if(x == NULL)
    {
        printf("Memory not allocated");
        exit(0);
    }
    return x;
}

void insert_front(NODE head, int item)
{
    NODE temp, next;
    temp = getnode();
    next = head->link;
    temp->info = item;
    head->link = temp;
    temp->link = next;
}

void insert_rear(NODE head, int item)
{
    NODE temp, cur;
    temp = getnode();
    temp->info = item;
    temp->link = NULL;
    cur = head;
    while(cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
}

void delete_front(NODE head)
{
    NODE first, sec;
    if(head->link == NULL)
    {
        printf("There are no elements\n");
        return;
    }
    first = head->link;
    sec = first->link;
    head->link = sec;
    printf("Deleted element is %d\n", first->info);
    free(first);
}

void delete_rear(NODE head)
{
    NODE cur, prev;
    
    if(head->link == NULL)
    {
        printf("There are no elements\n");
        return;
    }
    cur = head->link;
    prev = head;
    while(cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    printf("Deleted element is %d\n", cur->info);
    prev->link = NULL;
    free(cur);
}

void display(NODE head)
{
    NODE cur;
    if(head->link == NULL)
    {
        printf("There are no elements\n");
        return;
    }
    cur = head->link;
    while(cur != NULL)
    {
        printf("%d ", cur->info);
        cur = cur->link;
    }
    printf("\n"); 
}

int main()
{
    NODE head; 
    head = getnode();
    head->link = NULL;
    int choice, item;

    while(1)
    {
        printf("\n1. Insert at front");
        printf("\n2. Insert at rear");
        printf("\n3. Delete from front");
        printf("\n4. Delete from rear");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the element to insert at front: ");
                scanf("%d", &item);
                insert_front(head, item);
                break;
            case 2:
                printf("Enter the element to insert at rear: ");
                scanf("%d", &item);
                insert_rear(head, item);
                break;
            case 3:
                delete_front(head);
                break;
            case 4:
                delete_rear(head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
