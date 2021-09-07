#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
}s;
int flag;
void push(int);
void take_element(){
    printf("Enter the element in the stack\n");
    for (int i = 0; i < flag; i++)
    {
        int temp;
        scanf("%d", &temp);
        push(temp);
    }
}
void display_element()
{
    for (int i = 0; i <= s.top; i++)
    {
        printf("%d\n",s.arr[i]);
    }
}
int isfull(){
    if(s.top == s.size-1){
        return 1;
    }
    return 0;
}
int isempty(){
    if (s.top == -1)
    {
        return 1;
    }
    return 0;
}
void push(int num){
    s.size++;
    if (isfull())
    {
        printf("Stack Overflow\n");
    }
    else{
        s.top++;
        s.arr=(int *)realloc(s.arr,s.size*sizeof(int));
        s.arr[s.top]=num;
    }
}
int pop(){
    if (isempty())
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        int val = s.arr[s.top];
        s.top--;
        s.size--;
        s.arr=(int *)realloc(s.arr,s.size*sizeof(int));
        return val;
    }
    
}
int peek(){
    if (isempty())
    {
        printf("stack underflow\n");
        return -1;
    }
    else{
        int val = s.arr[s.top];
        return val;
    }
    
}
int main(){
    printf("Enter the size of the stack\n");
    scanf("%d",&flag);
    s.top=-1;
    s.size=0;
    s.arr=(int *)malloc(sizeof(int));
    char ch;
    int num,choice;
    take_element(flag);
    do
    {
        printf("Enter 1 to display the element\nEnter 2 to perform the push\nEnter 3 to perform the pop\nEnter 4 to Perform the peek\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display_element();
            break;
        case 2:
            printf("Enter the number\n");
            scanf("%d", &num);
            push(num);
            break;
        case 3:
            printf("Element POP is %d\n", pop());
            break;
        case 4:
            printf("Peek Element is %d\n", peek());
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
