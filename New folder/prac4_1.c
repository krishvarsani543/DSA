#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int val)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

void insertFront(struct Node **head, int val)
{
    struct Node *newNode = createNode(val);

    newNode->next = *head;
    *head = newNode;
}

void insertEnd(struct Node **head, int val)
{
    struct Node *newNode = createNode(val);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertAtPosition(struct Node **head, int val, int pos)
{
    if (pos < 1)
    {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1)
    {
        insertFront(head, val);
        return;
    }

    struct Node *newNode = createNode(val);
    struct Node *temp = *head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid Position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteval(struct Node **head,int val){
    struct Node* temp;
    struct Node* prev;

    if(*head==NULL){
        printf("Queue is empty");
       return; 
    }
    temp=*head;
    prev=NULL;

    if(temp->data==val){
        *head=temp->next;
        free(temp);
        printf("Patient token deleted");
        return;
    }

    while(temp!=NULL &&temp->data!=val){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("patient token not found");
        return;
    }
    prev->next=temp->next;
    free(temp);
    printf("patient token deleted");
}
void reverse(struct Node *head)
{
    if (head == NULL)
    {
        return;
    }

    reverse(head->next);
    printf("%d -> ", head->data);
}

void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Current List : ");

    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    int choise,token,pos;
    while(1){
        printf("1.Inseart Critical Position At Front\n");
        printf("2.Inseart Routine Patient At End\n");
         printf("3.Inseart Priority Patient At Position\n");
         printf("4.Deletion Queue\n");
         printf("5.Reverse Queue\n");
          printf("6.Display Queue\n");
           printf("7.Exists\n");

           printf ("Enter Your Choise :");
           scanf("%d",&choise);

           switch(choise){
            case 1:
            printf("Enter Patient Token : ");
            scanf("%d",&token);
            insertFront(&head,token);
            display(head);
            break;

             case 2:
            printf("Enter Patient Token : ");
            scanf("%d",&token);
            insertEnd(&head,token);
            display(head);
            break;

             case 3:
            printf("Enter Patient Token : ");
            scanf("%d",&token);
            printf("Enter Position : ");
            scanf("%d",pos);
            insertAtPosition(&head,token,pos);
            display(head);
            break;

            case 4:
              printf("Enter Patient Token : ");
            scanf("%d",&token);
            deleteval(&head,token);
            display(head);
            break;

           

              case 5:
               printf("Reverse Queue : ");
                 reverse(head);
                printf("NULL\n");
                  break;
             

            case 6:
            display(head);
            break;

            case 7:
            return 0;

            default:
            printf("inavalid choise");
           }
        

    }

  

    return 0;
}