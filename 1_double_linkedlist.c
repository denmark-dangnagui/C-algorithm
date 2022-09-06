#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node{
    struct node *next;
    struct node *prev;
    char data;
}node;
int size;
node *h;
node *t;

void init(){
    h = (node *)malloc(sizeof(node));
    t = (node *)malloc(sizeof(node));
    h->next = t;
    h->prev = NULL;
    t->next = NULL;
    t->prev = h;
    size = 0;
}

void add(int index, char word){
    if(index > size + 1 || index < 0){
        printf("invalid position\n");
    }
    else{
        node *temp = (node *)malloc(sizeof(node));
        temp->data = word;
        int i = 0;
        if(size >= index){
            temp->next = h->next;
            for(i = 0 ; i < index - 1; i++){
                temp->next = temp->next->next;
            }
            temp->prev = temp->next->prev;
            temp->prev->next = temp;
            temp->next->prev = temp;
        }
        else{
            temp->next = t;
            temp->prev = t->prev;
            t->prev = temp;
            t->prev->next = temp;
        }
        size++;
    }
}

void delete(int index){
    if(index > size || index < 0){
        printf("invalid position\n");
    }
    else{
        node *temp = h->next;
        for(int i = 0 ; i < index -1 ; i++){
            temp = temp->next;
        }
        temp->next->prev = temp;
        temp->prev->next = temp;
        free(temp);
        size--;
    }
}

void get(int index){
    int i;
    node *temp = h->next;
    for(i = 0 ; i < index - 1; i++){
        temp = temp->next;
    }
    printf("%c\n",temp->data);
}

void print_(){
    for(node *temp = h->next ; temp != t; temp = temp->next){
        printf("%c",temp->data);
    }
}

int main(void){
    int n,i,index;
    char a, word;

    init();
    scanf("%d",&n);
    getchar();
    for(i = 0 ; i < n ; i++){
        scanf("%c",&a);
        getchar();
        if(a == 'A'){
            scanf("%d %c",&index,&word);
            getchar();
            add(index,word);
        }
        else if(a == 'D'){
            scanf("%d",&index);
            getchar();
            delete(index);
        }
        else if(a == 'G'){
            scanf("%d",&index);
            getchar();
            get(index);
            
        }
        else if(a == 'P'){
            print_();
        }
    }
}