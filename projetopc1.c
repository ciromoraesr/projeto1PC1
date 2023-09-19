#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int chartoint(int num){
    return num - '0';
}
char intochar(int num){
    return num + '0';
}
void soma(char a[501], char b[501]){
    char temp[502], soma[1002];
    if (strlen(a) > strlen(b)){
        int diff = strlen(a) - strlen(b);
        for (int i = 0; i < diff; i++){
            temp[i] = '0';
        }
        for(int i = diff; i < strlen(a); i++){
            temp[i] = b[i - diff];
        }
        temp[strlen(a)] = '\0';

        int carry = 0;
        for (int i = strlen(temp) - 1; i >= 0; i--){
            int sum = chartoint(temp[i]) + chartoint(a[i]) + carry;
            carry = sum / 10;
            soma[i+1] = intochar(sum % 10);
        }
        soma[0] = intochar(carry);
    }
    else if(strlen(b) > strlen(a)){
        int diff = strlen(b) - strlen(a);
        for (int i = 0; i < diff; i++){
            temp[i] = '0';
        }
        for(int i = diff; i < strlen(b); i++){
            temp[i] = a[i - diff];
        }
        temp[strlen(b)] = '\0';

        int carry = 0;
        for (int i = strlen(temp) - 1; i >= 0; i--){
            int sum = chartoint(temp[i]) + chartoint(b[i]) + carry;
            carry = sum / 10;
            soma[i+1] = intochar(sum % 10);
        }
        soma[0] = intochar(carry);
    }
    else {

        int carry = 0;
        for (int i = strlen(a) - 1; i >= 0; i--){
            int sum = chartoint(a[i]) + chartoint(b[i]) + carry;
            carry = sum / 10;
            soma[i+1] = intochar(sum % 10);
        }
        soma[0] = intochar(carry);
    }
    if (atoi(soma) == 0){
        printf("0");
    }else{
    int start = 0;
    while (soma[start] == '0' && start < strlen(soma)) {
        start++;
    }

    for (int i = start; i < strlen(soma); i++){
        if (chartoint(soma[i])>= 0 && chartoint(soma[i])<= 9){
        printf("%c", soma[i]);
            }
        }
    }
}
void sub(char a[501], char b[501]){
    int lena = strlen(a), lenb = strlen(b);
    char temp[1002], sub[1002];
    int resulnegativo = 0;
    int maior = 0;

    if (lena > lenb){
        maior = 1;

    }else if(lenb > lena){
        maior = 2;
    }else{
        for (int i = 0; i < lena; i++){
            if (a[i] > b[i]){
                maior = 1;
                break;

            }else{
                maior = 2;
                break;
            }
        }
    }
    if (maior == 2){
        resulnegativo = 1;
    }
    else if(maior == 1){
        resulnegativo = 0;
    }

}

int main(){
    char a[501] = "127349847218943757471829";
    char b[501] = "9942174127482147421798427421";

    soma(a, b);
    return 0;
}
