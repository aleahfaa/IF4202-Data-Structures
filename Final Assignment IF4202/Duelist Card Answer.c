/*077's notes:
a problem about stack
stack:dynamic data structure that adheres to the lifo
push:add new data to the top of the list
pop:remove the data on the lowest of the list
top:the data at the peak
min:the smallest data
max:the biggest data
duelist card (c version)*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define max 10

struct Stack {
    int* elements;
    int top;
    int capacity;
};

//function to create a stack with a given capacity
struct Stack* createStack(int capacity) {
    //allocate memory for the stack structure
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    //allocate memory for the elements array
    stack->elements = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

//function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top==-1;
}

//function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top==stack->capacity - 1;
}

//function to push an element onto the stack
void push(struct Stack* stack, int x) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->elements[++stack->top] = x;
}

//function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    return stack->elements[stack->top--];
}

//function to get the top element of the stack
int top(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->elements[stack->top];
}

//function to find the minimum value in the stack
int findMin(struct Stack* stack) {
    int min_val = INT_MAX;
    for (int i = 0; i <= stack->top; i++) {
        if (stack->elements[i] < min_val) {
            min_val = stack->elements[i];
        }
    }
    return min_val;
}

//function to find the maximum value in the stack
int findMax(struct Stack* stack) {
    int max_val = INT_MIN;
    for (int i = 0; i <= stack->top; i++) {
        if (stack->elements[i] > max_val) {
            max_val = stack->elements[i];
        }
    }
    return max_val;
}

int main() {
    int rounds;
    scanf("%d", &rounds);
    //create a stack named "cards" using the createStack function
    struct Stack* cards = createStack(rounds);
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    while (rounds--) {
        char command[max];
        scanf("%s", command);
        //check the command and perform the corresponding operation
        if (strcmp(command, "push") == 0) {
            int x;
            scanf("%d", &x);
            push(cards, x);
            //update min_val and max_val if necessary
            min_val = (x < min_val) ? x : min_val;
            max_val = (x > max_val) ? x : max_val;
        } else if (strcmp(command, "pop") == 0) {
            if (!isEmpty(cards)) {
                int top_val = pop(cards);
                //update min_val and max_val if necessary
                if (top_val == min_val) {
                    min_val = findMin(cards);
                }
                if (top_val == max_val) {
                    max_val = findMax(cards);
                }
            }
        } else if (strcmp(command, "top") == 0) {
            if (!isEmpty(cards)) {
                //print the top element of the stack
                printf("%d\n", top(cards));
            }
        } else if (strcmp(command, "min") == 0) {
            //print the minimum value in the stack
            printf("%d\n", min_val);
        } else if (strcmp(command, "max") == 0) {
            //print the maximum value in the stack
            printf("%d\n", max_val);
        }
    }
    //free the memory allocated for the elements array and the stack itself
    free(cards->elements);
    free(cards);
    return 0;
}
