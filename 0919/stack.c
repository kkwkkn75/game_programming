#include <stdio.h>
#include <stdlib.h>

void push(char data);
char pop(void);
struct stack_node{
    char data;
    struct stack_node *link;
};

struct stack_node *top = NULL;

int main(void){

    push('A');
    push('B');
    printf("%c\n", pop()); 
    printf("%c\n", pop());

    return 0;
}

void push(char data){
    struct stack_node *new_node;
    new_node = (struct stack_node*)malloc(sizeof(struct stack_node));
    new_node -> data = data;
    new_node -> link = top;
    top = new_node;
}

char pop(void){
    struct stack_node *temp;
    char data;
    if(top == NULL) {
        printf("empty\n");
        return '\0';
    }
    data = top -> data;
    temp = top;
    top = top -> link;
    free(temp);
    return data;
}