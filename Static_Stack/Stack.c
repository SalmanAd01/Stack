#include <stdio.h>
#define MAX_SIZE 100
int size;
int top=-1;
int arr[MAX_SIZE];
void push();
void take_element()
{
    printf("Enter the element in the stack\n");
    for (int i = 0; i < size; i++)
    {
        int temp;
        scanf("%d", &temp);
        push(temp);
    }
}
void display_element(){
    printf("Element in the stack is given by\n");
    for (int i = 0; i <= top; i++)
    {
        printf("Element is : %d\n", arr[i]);
    }   
}
int isfull(){
    if(top == MAX_SIZE -1){
        return 1;
    }
    return 0;
}
int isempty(){
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
void push(int num){
    if(isfull()){
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        arr[top] = num;
    }
}
int pop(){
    if (isempty())
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        int val = arr[top];
        top--;
        return val;
    }
}
int peek(){
    if (isempty())
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return arr[top];
}
int main(){
    int choice,num;
    char ch;
    printf("Enter the size of the stack\n");
    scanf("%d",&size);
    take_element();
    do
    {
        printf("Enter 1 to display the element\nEnter 2 to perform the push\nEnter 3 to perform the pop\nEnter 4 to Perform the peek\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            display_element();
            break;
        case 2:
            printf("Enter the number\n");
            scanf("%d",&num);
            push(num);
            break;
        case 3:
            printf("Element POP is %d\n",pop());
            break;
        case 4:
            printf("Peek Element is %d\n",peek());
            break;
        default:
            printf("Enter the valid number\n");
            break;
        }
    printf("Enter S to stop\n");
    scanf(" %c",&ch);
    } while (ch != 'S');
    return 0;
}
