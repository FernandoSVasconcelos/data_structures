#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

void insert_queue(int *queue, int value){
    for(int i=0; i < QUEUE_SIZE; i++){
        if(queue[i] == NULL){
            queue[i] = value;
            printf("Insert {%d} in {%d} slot\n", value, i);
            break;
        }
    }
}

void pop_queue(int *queue){
    for(int i=0; i < QUEUE_SIZE; i++){
        if(queue[i] != NULL){
            printf("Poping {%d] from {%d} slot\n", queue[i], i);
            queue[i] = NULL;
            break;
        }
    }

}

void init_queue(int *queue){
    for(int i=0; i < QUEUE_SIZE; i++){
        queue[i] = NULL;
    }
}

void print_queue(int *queue){
    for(int i=0; i < QUEUE_SIZE; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){
    int *queue;
    queue = malloc(sizeof(int) * QUEUE_SIZE);
    init_queue(&queue);
    insert_queue(&queue, 6);
    insert_queue(&queue, 7);
    insert_queue(&queue, 8);
    insert_queue(&queue, 2);
    pop_queue(&queue);
    print_queue(&queue);
    pop_queue(&queue);
    print_queue(&queue);

    return 0;
}