#include<stdio.h>
#define SIZE 5
int queue[SIZE];
int front=-1,rear=-1;

void enqueue(int queue[],int ele)
{
    if(rear==SIZE-1)
        printf("Queue Overflow\n");
    else
    {
        if(front==-1)
            front=0;
        rear++;
        queue[rear]=ele;
        printf("Inserted %d\n",ele);
    }
}

void dequeue(int queue[])
{
    if(front==-1 || front>rear)
        printf("Queue Underflow\n");
    else
    {
        printf("Deleted %d\n",queue[front]);
        front++;
    }
}

void display(int queue[])
{
    if(front==-1 || front>rear)
        printf("Queue Empty\n");
    else
    {
        printf("Queue elements: ");
        for(int i=front;i<=rear;i++)
            printf("%d ",queue[i]);
        printf("\n");
    }
}

int main()
{
    int choice,ele;
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d",&ele);
                enqueue(queue,ele);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}