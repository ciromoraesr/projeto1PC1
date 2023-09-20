#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int chartoint(char num) {
    return num - '0';
}
//função pra checar se os valor da string são todos zeros ou não
int checkzer(char s[501]){
    int zero = 0;
    for(int i  = 0; i < strlen(s)-1; i++){
        if(s[i] != '0'){
            zero = 1;
            break;
        }
        
    }
    return zero;
}
char intochar(int num) {
    return num + '0';
}
void post(char x[501], char y[501], char tempo[501]) {
    int lena = strlen(x), lenb = strlen(y);
    int diffe = abs(lena - lenb);
    for (int i = 0; i < diffe; i++) {
        tempo[i] = '0';
    }
    for (int i = diffe; i < lena; i++) {
        tempo[i] = y[i - diffe];
    }
    tempo[lena] = '\0';
}
void subr(char a[501], char b[501]) {
    //declarando as variáveis usadas
    int lena = strlen(a), lenb = strlen(b);
    char temp[1002], sub[1002];
    int resulnegativo = 0;
    //int maior = 0;
    int carry = 0;
    int um = checkzer(a);
    int dois = checkzer(b); 
    //definindo um número para caso uma string seja maior q a outra: 1-string A ; 2- string B
        if (lena > lenb) {
            resulnegativo = 0;
        } else if (lenb > lena) {
            resulnegativo = 1;
        } else {
            for (int i = 0; i < lena; i++) {
                if (a[i] > b[i]) {
                    resulnegativo = 0;
                    break;
                } else if (a[i] < b[i]) {
                    resulnegativo = 1;
                    break;
                }
            }
        }
    if (lena > lenb){
        post(a, b, temp);
        for(int i = lena -1; i>= 0; i -- ){
                int x = chartoint(a[i]);
                int y = chartoint(temp[i]);
                int diff = x - y - carry;
            
            if (diff < 0){
                diff = diff + 10;
                carry = 1;
            }else{
                carry = 0;
            }
            sub[i] = intochar(diff);
       } 
    }
    else if(lenb > lena){
       post(b, a, temp);
     
    //if (resulnegativo == 1){
        for(int i = lenb  - 1 ; i>= 0; i -- ){
                int x = chartoint(b[i]);
                int y = chartoint(temp[i]);
                int diff = x - y - carry;
            
            if (diff < 0){
                diff = diff + 10;
                carry = 1;
            }else{
                carry = 0;
            }
            sub[i] = intochar(diff);
    }

    }else{
       if (resulnegativo == 1){
        for(int i = lena -1; i>= 0; i -- ){
                int x = chartoint(b[i]);
                int y = chartoint(a[i]);
                int diff = x - y - carry;
            
            if (diff < 0){
                diff = diff + 10;
                carry = 1;
            }else{
                carry = 0;
            }
            sub[i] = intochar(diff);

       }}else{
        for(int i = lena -1; i>= 0; i -- ){
                int x = chartoint(a[i]);
                int y = chartoint(b[i]);
                int diff = x - y - carry;
            
            if (diff < 0){
                diff = diff + 10;
                carry = 1;
            }else{
                carry = 0;
            }
            sub[i] = intochar(diff);
       } 
    }
}

if (atoi(sub) == 0) {
        printf("0");
} else {
    if (resulnegativo == 1) {
            printf("-");
        }
        int start = 0;
    if (strlen(sub) > 1){
        while (sub[start] == '0' && start < strlen(sub)) {
            start++;
        }
    }else{
            start = 0;
        }

for (int i = start; i < strlen(sub); i++) {
    if (chartoint(sub[i]) >= -9 && chartoint(sub[i]) <= 9) {
            printf("%c", sub[i]);
        }
    }
}
printf("\n");
}
void mult(char a[501], char b[501]){
    int lena = strlen(a), lenb = strlen(b);
    char temp[501], resultado[1002];
    int carry = 0;
    if (lena > lenb){
        post(a, b, temp);




    }else if(lenb > lena){
        post(b, a, temp);




   }else{
    
   }
}
int main(){
    char a[501] = "10000";
    char b[501] = "1000";

    subr(a, b);
    return 0;
}
