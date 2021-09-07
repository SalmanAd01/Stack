#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    int *arr;
};
int flag;
void push(struct Stack *stack, int);
void take_element(struct Stack *stack)
{
    for (int i = 0; i < flag; i++)
    {
        int temp;
        scanf("%d", &temp);
        push(stack, temp);
    }
}
void display_element(struct Stack *stack)
{
    printf("Element in the stack is given by\n");
    for (int i = 0; i <= stack->top; i++)
    {
        printf("Element is : %d\n", stack->arr[i]);
    }
}
int isfull(struct Stack *stack)
{
    if (stack->top == stack->size - 1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}
int isempty(struct Stack *stack) {
    if(stack->top == -1){
        return 1;
    }
    else
    {
        return 0;
    }
    
}
void push(struct Stack *stack, int num)
{
    stack->size++;
    if (isfull(stack))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack->top++;
        stack->arr = (int *)realloc(stack->arr, stack->size * sizeof(int));
        stack->arr[stack->top] = num;
    }
}
int pop(struct Stack *stack) {
    if (isempty(stack))
    {
        printf("Stack Overflow\n");
        return -1;
    }
    else
    {
        int val = stack->arr[stack->top];
        stack->top--;
        stack->size--;
        stack->arr = (int *)realloc(stack->arr, stack->size * sizeof(int));
        return val;
    }
}
int peek(struct Stack *stack){
    if (isempty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        return stack->arr[stack->top];
    }
    
    
}
int main()
{
    struct Stack *stack;
    stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->arr = (int *)malloc(sizeof(int));
    stack->size = 0;
    stack->top = -1;
    printf("Enter the Size of the array\n");
    scanf("%d", &flag);
    take_element(stack);
    char ch;
    int num, choice;
    do
    {
        printf("Enter 1 to display the element\nEnter 2 to perform the push\nEnter 3 to perform the pop\nEnter 4 to Perform the peek\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display_element(stack);
            break;
        case 2:
            printf("Enter the number\n");
            scanf("%d", &num);
            push(stack, num);
            break;
        case 3:
            printf("Element POP is %d\n", pop(stack));
            break;
        case 4:
            printf("Peek Element is %d\n", peek(stack));
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
