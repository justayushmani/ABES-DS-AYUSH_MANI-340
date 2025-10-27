#include<stdio.h>
#define SIZE 5
int queue[SIZE];
int front=-1,rear=-1;

void enqueue(int queue[],int ele)
{
    if((front==0 && rear==SIZE-1) || (rear+1)%SIZE==front)
        printf("Queue Overflow\n");
    else
    {
        if(front==-1)
            front=0;
        rear=(rear+1)%SIZE;
        queue[rear]=ele;
        printf("Inserted %d\n",ele);
    }
}

void dequeue(int queue[])
{
    if(front==-1)
        printf("Queue Underflow\n");
    else
    {
        printf("Deleted %d\n",queue[front]);
        if(front==rear)
            front=rear=-1;
        else
            front=(front+1)%SIZE;
    }
}

void display(int queue[])
{
    if(front==-1)
        printf("Queue Empty\n");
    else
    {
        int i=front;
        printf("Queue elements: ");
        while(1)
        {
            printf("%d ",queue[i]);
            if(i==rear)
                break;
            i=(i+1)%SIZE;
        }
        printf("\n");
    }
}

int main()
{
    int choice,ele;
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice: ");
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