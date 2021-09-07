#include <stdio.h>
#include <stdlib.h>
int size=0;
int flag;
int top = -1;
void push();
void take_element(int *arr)
{
    printf("Enter the element in the stack\n");
    for (int i = 0; i < flag; i++)
    {
        int temp;
        scanf("%d", &temp);
        push(arr,temp);
    }
}
void display_element(int *arr)
{
    printf("Element in the stack is given by\n");
    for (int i = 0; i <= top; i++)
    {
        printf("Element is : %d\n", arr[i]);
    }
}
int isfull()
{
    if (top == size - 1)
    {
        return 1;
    }
    return 0;
}
int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
void push(int *arr,int num)
{
    size++;
    if (isfull())
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        arr=(int*)realloc(arr,size*sizeof(int));
        arr[top] = num;
    }
}
int pop(int *arr)
{
    if (isempty())
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        int val = arr[top];
        top--;
        arr=(int *)realloc(arr,size*sizeof(int));
        size--;
        return val;
    }
}
int peek(int *arr)
{
    if (isempty())
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return arr[top];
}
int main()
{
    int choice, num;
    char ch;
    int *arr;
    arr=(int*)malloc(sizeof(int));
    printf("Enter the size of the stack\n");
    scanf("%d", &flag);
    take_element(arr);
    do
    {
        printf("Enter 1 to display the element\nEnter 2 to perform the push\nEnter 3 to perform the pop\nEnter 4 to Perform the peek\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display_element(arr);
            break;
        case 2:
            printf("Enter the number\n");
            scanf("%d", &num);
            push(arr,num);
            break;
        case 3:
            printf("Element POP is %d\n", pop(arr));
            break;
        case 4:
            printf("Peek Element is %d\n", peek(arr));
            break;
        default:
            printf("Enter the valid number\n");
            break;
        }
        printf("Enter S to stop\n");
        scanf(" %c", &ch);
    } while (ch != 'S');
    return 0;
}
