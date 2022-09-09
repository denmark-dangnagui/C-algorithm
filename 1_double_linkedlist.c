#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

typedef struct node{
    struct node *next;
    struct node *prev;
    char data;
} node;
node *h;
node *t;
int size;
void init(){
    h = (node *)malloc(sizeof(node));
    t = (node *)malloc(sizeof(node));
    h->prev = NULL;
    h->next = t;
    t->next = NULL;
    t->prev = h;
    size = 0;
}

void add(int x, char data){
    if(x > size + 1 || x < 0){
        printf("invalid position\n");
    }
    else{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    int i = 0;
    if(size >= x){ // 앞에 추가
        temp->next = h->next;
        for( i = 0 ; i < x - 1 ; i++){
                    temp->next = temp->next->next;
                }
                temp->prev = temp->next->prev;
                temp->prev->next = temp;
                temp->next->prev = temp;
    }
    else {   // 뒤에 추가
        temp->next = t;
        temp->prev = t->prev;
        t->prev->next = temp;
        t->prev = temp;
    }

    size++;
    }
}
void delete(int x){
    if(x < 0 || x > size){
        printf("invalid position\n");
    }
    else{
    x = x - 1;
    node *temp = h->next;
    for(int i = 0 ; i < x ; i++){
        temp = temp->next;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(temp);
    size--;
    }
}
void get(int x){
    if(x < 0 || x > size){
        printf("invalid position\n");
    }
    else{
        x = x - 1;
    node *temp = h->next;
        for(int i = 0 ; i < x ; i++){
            temp = temp->next;
        }
    printf("%c\n",temp->data);
    }
}
void print_(){
    for(node *temp = h->next ; temp != t ; temp = temp->next){
        printf("%c",temp->data);
    }
    printf("\n");
}
int main(void){
    int n, i, b;
    char a,c;
    
    init();
    
    scanf("%d",&n);
    getchar();
    
    for(i = 0 ; i < n ; i++){
        
        scanf("%c",&a);
        getchar();
        if(a == 'A'){
            scanf("%d %c",&b,&c);
            getchar();
            add(b,c);
        }
        else if( a == 'D'){
            scanf("%d",&b);
            getchar();
            delete(b);
        }
        else if( a == 'G'){
            scanf("%d",&b);
            getchar();
            get(b);
        }
        else if( a == 'P'){
            print_();
        }
    }
    for(i = 0 ; i < size ; i++){
        delete(1);
        i--;
    }
    printf("123\n");
    print_();
    printf("456\n");
    free(h);
    free(t);

}

