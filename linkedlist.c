//입력에 대한 설명
//첫 번째 다항식의 항의 개수가 입력되고, 이후에 다항식의 각 항의 (계수, 지수) 쌍이 지수의 내림차순으로 입력됨
//동일한 방식으로 두 번째 다항식의 정보가 입력됨
//출력에 대한 설명
//결과 다항식의 각 항의 (계수, 지수) 쌍을 지수의 내림차순으로 출력
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

typedef struct node{
    struct node *next;
    int coef;
    int exp;
} node;

typedef struct head {
    node *head;
} head;

head * createlist(void){
    head *l;
    l = (head *)malloc(sizeof(head));
    l->head = NULL;
    return l;
}

void addTerm(head *l,int coef, int exp){
    node *temp;
    node *p;
    temp = (node *)malloc(sizeof(node));
    temp->coef = coef;
    temp->exp = exp;
    temp->next = NULL;
    if(l->head == NULL){
        l->head = temp;
        return;
    }
    else {
        p = l->head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
}

void addPoly(head *a,head *b,head *c){
    node *x = a->head;
    node *y = b->head;
    int sum;

    while (x != 0 && y != 0) {
        if(x->exp == y->exp){
            sum = x->coef + y->coef;
            addTerm(c, sum, x->exp);
            x = x->next;
            y = y->next;
        }
        else if(x->exp > y->exp){
            addTerm(c, x->coef, x->exp);
            x=x->next;
        }
        else {
            addTerm(c, y->coef, y->exp);
            y = y->next;
        }
    }
    for(; x!=NULL;x = x->next)
        addTerm(c, x->coef, x->exp);
    for(; y!=NULL;y = y->next)
        addTerm(c, y->coef, y->exp);
}

void print(head *l){
    node *p = l->head;
    for(;p;p = p->next){
        if(p->coef != 0)
            printf("%d %d ",p->coef,p->exp);
        else if(p->coef == 0)
            printf(" ");
    }
    printf("\n");
}

int main(void){
    int n, i, x, y;


    head *a,*b,*c;
    a = createlist();
    b = createlist();
    c = createlist();

    scanf("%d",&n);


    for(i = 0 ; i < n ; i++){
        scanf("%d %d",&x,&y);
        addTerm(a, x, y);
    }

    scanf("%d", &n);

    for(i = 0 ; i < n  ; i++){
        scanf("%d %d",&x,&y);
        addTerm(b, x, y);
    }
    addPoly(a, b, c);
    print(c);
}
