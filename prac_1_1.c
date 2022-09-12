#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable:4996)

typedef struct node{
    struct node *prev;
    struct node *next;
    char data;
} node;

int size;
node *h;
node *t;
void init(){
    h = (node *)malloc(sizeof(node));
    t = (node *)malloc(sizeof(node));
    h->prev = NULL;
    h->next = t;
    t->next = NULL;
    t->prev = h;
    size = 0;
}

void add(int idx, char data){
    if (idx > size + 1 || idx < 0 ){
        printf("invalid position\n");
    }
    else{
        node *temp = (node *)malloc(sizeof(node));
        temp->data = data;
        int i = 0;
        if(size >= idx){
            temp->next = h->next;
            for(i = 0; i < idx - 1 ; i++){
                temp->next = temp->next->next;
            }
            temp->prev = temp->next->prev;
            temp->prev->next = temp;
            temp->next->prev = temp;
        }
        else{
            temp->next = t;
            temp->prev = t->prev;
            t->prev->next = temp;
            t->prev = temp;
        }
        size++;
    }
}

void delete(int idx){
    if(idx > size || idx <= 0){
        printf("invalid position\n");
    }
    else{
        node *temp = h->next;
        for(int i = 0 ; i < idx -1 ; i++){
            temp = temp->next;
        }
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        free(temp);
        size--;
    }
}

void get(int idx){
    if(idx > size || idx < 0){
        printf("invalid position\n");
    }
    else{
        node *temp;
        int i = 0;
        temp = h->next;
        for(i = 0 ; i < idx - 1; i++){
            temp = temp->next;
        }
        printf("%c\n", temp->data);
    }
}

void _print(){
    for(node *temp = h->next ; temp != t; temp = temp->next){
        printf("%c",temp->data);
    }
    printf("\n");
}

int main (void){
    int i,n,idx;
    char order,word;
    init();
    scanf("%d",&n);
    getchar();
    for(i = 0 ; i < n ; i++){
        scanf("%c",&order);
        getchar();
        if(order == 'A'){
            scanf("%d %c",&idx,&word);
            getchar();
            add(idx,word);
        }
        else if(order == 'D'){
            scanf("%d",&idx);
            getchar();
            delete(idx);
        }
        else if(order == 'G'){
            scanf("%d",&idx);
            getchar();
            get(idx);
        }
        else if(order == 'P'){
            _print();
        }
    }
}
