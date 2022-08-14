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
    printf("Poping {%d] from {%d} slot\n", queue[0], 0);
    queue[0] = NULL;
    for(int i=0; i < QUEUE_SIZE-1; i++){
        queue[i] = queue[i+1];
    }
    queue[QUEUE_SIZE-1] = NULL;

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
    queue = (int*) malloc(sizeof(int) * QUEUE_SIZE);
    init_queue(&queue);
    insert_queue(&queue, 6);
    insert_queue(&queue, 7);
    insert_queue(&queue, 8);
    insert_queue(&queue, 2);
    insert_queue(&queue, 1);
    insert_queue(&queue, 3);
    insert_queue(&queue, 14);
    insert_queue(&queue, 5);
    insert_queue(&queue, 22);
    insert_queue(&queue, 12);
    print_queue(&queue);
    pop_queue(&queue);
    print_queue(&queue);
    pop_queue(&queue);
    print_queue(&queue);

    free(queue);
    return 0;
}