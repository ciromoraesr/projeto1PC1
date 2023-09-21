#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int chartoint(char num) {
    return num - '0';
}
//função pra checar se os valor da string são todos zeros ou não
int checkzer(char s[501]){
    int zero = 0;
    for(int i  = 0; i < strlen(s); i++){
        if(s[i] != '0' && s[i] != '\0'){
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
void soma(char a[501], char b[501]) {
    char temp[502], soma[1002];
    int lena = strlen(a), lenb = strlen(b);
    if (lena > lenb) {
        int diff = lena - lenb;
        for (int i = 0; i < diff; i++) {
            temp[i] = '0';
        }
        for (int i = diff; i < lena; i++) {
            temp[i] = b[i - diff];
        }
        temp[lena] = '\0';
        int carry = 0;
        for (int i = strlen(temp) - 1; i >= 0; i--) {
            int sum = chartoint(temp[i]) + chartoint(a[i]) + carry;
            carry = sum / 10;
            soma[i + 1] = intochar(sum % 10);
        }
        soma[0] = intochar(carry);
    } else if (lenb > lena) {
        int diff = lenb - lena;
        for (int i = 0; i < diff; i++) {
            temp[i] = '0';
        }
        for (int i = diff; i < lenb; i++) {
            temp[i] = a[i - diff];
        }
        temp[lenb] = '\0';
        int carry = 0;
        for (int i = strlen(temp) - 1; i >= 0; i--) {
            int sum = chartoint(temp[i]) + chartoint(b[i]) + carry;
            carry = sum / 10;
            soma[i + 1] = intochar(sum % 10);
        }
        soma[0] = intochar(carry);
    } else {
        int carry = 0;
        for (int i = lena - 1; i >= 0; i--) {
            int sum = chartoint(a[i]) + chartoint(b[i]) + carry;
            carry = sum / 10;
            soma[i + 1] = intochar(sum % 10);
        }
        soma[0] = intochar(carry);
    }
    if (atoi(soma) == 0) {
        printf("0");
    } else {
        int start = 0;
        while (soma[start] == '0' && start < strlen(soma)) {
            start++;
        }
        for (int i = start; i < strlen(soma); i++) {
            if (chartoint(soma[i]) >= 0 && chartoint(soma[i]) <= 9) {
                printf("%c", soma[i]);
            }
        }
    }
    printf("\n");
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
}else if(um == 0 && dois != 0){
    printf("-");
    for(int i =0; i < lenb ; i++){
        printf("%c", b[i]);
    }
}else if(atoi(b) == 0){
    for(int i = 0; i < lena; i++){
        printf("%c", a[i]);
    } 
}else {
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
        for (int i = 0; i < lena + lenb; i++) {
        resultado[i] = '0';
        }
        resultado[lena + lenb] = '\0';
        for(int i = lenb-1; i >= 0; i--){
        int carry = 0;
            for(int j = lena -1; j >= 0; j--){
                int multi = (chartoint(b[i]) * chartoint(a[j]) + chartoint(resultado[i+j+1])+ carry);
                resultado[j+ i +1] = intochar(multi%10);
                carry = multi/ 10;   
            }
        resultado[i] = intochar(carry);
        }
    int h = checkzer(resultado);
    int start  = 0;
    while (resultado[start] == '0' && start < strlen(resultado)) {
            start++;
    }
    if (h == 0){
        printf("0");
    }else{
    
    for (int i = start; i < strlen(resultado); i++){
         if (chartoint(resultado[i]) >= 0 && chartoint(resultado[i]) <= 9) {
                printf("%c", resultado[i]);
            }
    }
    }
    printf("\n");
}
int main(){
    char a[501];
    char b[501];
    int n, o;
    scanf("%d", &n);
    for(int i =0; i < n; i++){
        scanf("%s %s %d", a, b, &o);
        if (o == 1){
            soma(a, b);
        }else if(o == 2){
            subr(a, b);
        }else{
            mult(a, b);
        }
    }
    return 0;
}
