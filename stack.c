#include "stdio.h"
#include "stdlib.h"

#define MAX 50

int a[MAX];
int top;

//definitions
void initializeStack();
int isEmpty();
int isFull();
int size();
int peek();
void push(int x);
int pop();
void display();

//entry point
int main(){
    //initialization.
    int choice, data;
    initializeStack();
    
    //UI loop.
    while(1){
        printf("1. push an element onto the stack.\n");
        printf("2. pop an element from the stack.\n");
        printf("3. peek top\n");
        printf("4. display stack\n");
        printf("5. Check the size of the stack\n");
        printf("6. quit the program.\n");
        
        //get user choice.
        scanf("%d", &choice);

        //catch quit case.
        if(choice == 6){
            break;
        }

        //process other cases.
        switch(choice){
            case 1: printf("Enter the data for the element\n");
                    scanf("%d", &data);
                    push(data);
                    break;

            case 2: data = pop();
                    printf("%d\n", data);
                    break;

            case 3: data = peek();
                    printf("%d\n", data);
                    break;

            case 4: display();
                    break;

            case 5: data = size();
                    printf("size: %d\n", data);
                    break;
        }

    }
    return 0;
}

//implimentations
void initializeStack(){
    top = -1;
}

int isEmpty(){
    if(top == 0 || top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if(top == MAX){
        return 1;
    }
    else{
        return 0;
    }
}

int size(){
    return top + 1;
}

int peek(){
    return a[top];
}

void push(int x){
    if(!isFull()){
        top++;
        a[top] = x;
    }
    else{
        printf("The stack is full\n");
        return;
    }
}

int pop(){
    if(!isEmpty()){
        top--;
        return a[top + 1];
    }
    else{
        printf("The stack is empty\n");
        return -1;
    }
}

void display(){
    if(!isEmpty()){
        for(int i = 0; i < size(); i++){
            printf("%d | ", a[i]);
        }
        printf("\n");
        return;
    }
    else{
        printf("The list is empty");
        return;
    }
}


