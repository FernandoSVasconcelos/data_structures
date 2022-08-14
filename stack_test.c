#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

void insert_stack(int *stack, int value){
    for(int i=0; i < STACK_SIZE; i++){
        if(stack[i] == NULL){
            printf("Insert {%d} in {%d} slot\n", value, i);
            stack[i] = value;
            break;
        }
    }
}

void pop_stack(int *stack){
    int i=0;
    while(stack[i] != NULL){
        i++;
    }
    printf("Pop {%d} from {%d} slot\n", stack[i-1], i-1);
    stack[i-1] = NULL;
}

void print_stack(int *stack){
    printf("-----BEGIN-------\n");
    for(int i=0; i < STACK_SIZE; i++){
        printf("%d ", stack[i]);
    }
    printf("\n-----END------\n");
}

void init_stack(int *stack){
    for(int i=0; i < STACK_SIZE; i++){
        stack[i] = NULL;
    }
}

int main(){
    int *stack;
    stack = (int*) malloc(sizeof(int) * STACK_SIZE);
    init_stack(&stack);
    insert_stack(&stack, 33);
    insert_stack(&stack, 1);
    insert_stack(&stack, 2);
    insert_stack(&stack, 4);
    insert_stack(&stack, 5);
    insert_stack(&stack, 7);
    insert_stack(&stack, 83);
    insert_stack(&stack, 6);
    insert_stack(&stack, 21);
    print_stack(&stack);
    pop_stack(&stack);
    print_stack(&stack);
    pop_stack(&stack);
    print_stack(&stack);
    
    free(stack); 
    return 0;
}