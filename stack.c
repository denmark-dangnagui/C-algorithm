//스택 응용으로, 키보드로부터 입력된 한 라인의 수식 문장 내 괄호 쌍의 대칭성을 검사하는 프로그램을 작성하세요. 괄호 쌍은 { }, [ ] , ( ), 세 종류가 있다.
//입력 : (3+40*(2+(30-7)*2133)
//출력 : Wrong_5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *x;
int top;

char pop(void){
    if(top <= -1){
        printf("Stack Empty\n");
        return 0;
    }
    return x[(top)--];
}
void push(char data) {
    if (top >= 1000 - 1) {
        printf("Stack FULL\n");
        return;
    }
    x[++(top)] = data;
}
int isEmpty(void) {
    if ((top) == -1) {
        return 1;
    }
    else {
        return 0;
    }
}



int isBalanced(char *string_) {
    char temp;
    for (int i = 0; i < strlen(string_); i++) {
        if ((string_[i] == '(') || (string_[i] == '{') || (string_[i] == '[')) {
            push(string_[i]);
        }

        else if ((string_[i] == ')') || (string_[i] == '}') || (string_[i] == ']')) {
            if (isEmpty()) {
                return 0;
            }
            temp = pop();
            if (string_[i] == ')') {
                if (temp != '(') {
                    return 0;
                }
            }
            else if (string_[i] == '}') {
                 if (temp != '{') {
                     return 0;
                 }
             }
             else if (string_[i] == ']') {
                 if (temp != '[') {

                }
            }
        }
    }
    return isEmpty();
}

int main() {
    int cnt = 0;
    char *string_ = (char*)malloc(sizeof(char) * 1000);
    x = (char*)malloc(sizeof(char) * 1000);
    top = -1;
    scanf("%[^\n]s", string_);
    getchar();
    int i;
    for (i = 0; i < strlen(string_) ; i++) {
        if ((string_[i] == '(') || (string_[i] == '{') || (string_[i] == '[') || (string_[i] == ')') || (string_[i] == '}') || (string_[i] == ']')) {
                cnt++;
            }
    }

    if(isBalanced(string_) == 1) {
        printf("OK_%d\n", cnt);
    }
    else {
        printf("Wrong_%d\n", cnt);
    }
    free(string_);
    free(x);
}
