#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person*)(0xFFFFFFFFFFFFFFFFUL)

typedef struct{
    char name[MAX_NAME];
    int age;
} person;

person * hash_table[TABLE_SIZE];

unsigned int hash(char *name){
    int length = strlen(name);
    unsigned int hash_value  = 0;

    for(int i=0; i < length; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table(){
    for(int i=0; i < TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
}

void print_table(){
    printf("START\n");
    for(int i=0; i < TABLE_SIZE; i++){
        if(hash_table[i] == NULL){
            printf("\t%i\t-----\n", i);
        }
        else if(hash_table[i] == DELETED_NODE){
            printf("\t%i\t-----<deleted>\n", i);
        }
        else{
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
    printf("END\n");
}

bool hash_table_insert(person *p){
    if(p == NULL) return false;
    int index = hash(p->name);
    for(int i=0; i < TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE;
        if(hash_table[try] == NULL || hash_table[try] == DELETED_NODE){
            hash_table[try] = p;
            return true;
        }
    }
    return false;
}

person *hash_table_lookup(char *name){
    int index = hash(name);
    for(int i=0; i < TABLE_SIZE; i++){
        int try = (index + i) % TABLE_SIZE;
        if(hash_table[try] == NULL){
            return false;
        }
        if(hash_table[try] == DELETED_NODE) continue;
        if((strncmp(hash_table[try]->name, name, TABLE_SIZE)) == 0){
            return hash_table[try];
        }
    }
    return NULL;
}

person *hash_table_delete(char *name){
    int index = hash(name);
    for(int i=0; i < TABLE_SIZE; i++){
        int try = (index + i) % TABLE_SIZE;
        if(hash_table[try] == NULL) return NULL;
        if(hash_table[try] == DELETED_NODE) continue;
        if((strncmp(hash_table[try]->name, name, TABLE_SIZE)) == 0){
            person *tmp = hash_table[try];
            hash_table[try] = NULL;
            printf("Removendo %s da tabela.\n", name);
            return tmp;
        }
    }
    return DELETED_NODE;
}

int main(){
    init_hash_table();

    person billy = {.name="Billy", .age=2};
    person fernando = {.name="Fernando", .age=25};
    person souza = {.name="Souza", .age=200};

    hash_table_insert(&billy);
    hash_table_insert(&fernando);
    hash_table_insert(&souza);
    print_table();

    person *tmp = hash_table_lookup("Matias");
    if(tmp == NULL){
        printf("NOT FOUND!\n");
    }
    else{
        printf("Found %s.\n", tmp->name);
    }
    
    tmp = hash_table_lookup("Billy");
    if(tmp == NULL){
        printf("NOT FOUND!\n");
    }
    else{
        printf("Found %s.\n", tmp->name);
    }

    hash_table_delete("Fernando");
    print_table();

    return 0;
}