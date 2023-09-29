#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//função que transforma um char em um inteiro
int chartoint(char num) {
    return num - '0';
}
//função que transforma um inteiro em um char
char intochar(int num) {
    return num + '0';
}
/*função que checa se a função é composta somente de zeros, ou não.
caso seja só 0 ela retorna 0, e caso tenha algum número diferente de zero ela retorna 1.*/
int checkzer(char s[501]) {
    int zero = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] != '0' && s[i] != '\0') {
            zero = 1;
            break;
        }
    }
    return zero;
}
//função que deixa as strings a e b com o mesmo tamanho, colocando zeros a esquerda na menor string
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
//função soma entre strings a e b
void soma(char a[501], char b[501]) {
    char temp[502], soma[1002];
    int lena = strlen(a), lenb = strlen(b);
    //caso a string a seja maior que a string b
    if (lena > lenb) {
         post(a, b, temp);
        int carry = 0;
        //adiciona o caracter \0 no final da string 
        soma[lena + 1] = '\0';
        //realiza a soma entre a maior string e a string temp de mesmo tamanho
        for (int i = lena - 1; i >= 0; i--) {
            int sum = chartoint(temp[i]) + chartoint(a[i]) + carry;
            carry = sum / 10;
            soma[i + 1] = intochar(sum % 10);
        }
        soma[0] = intochar(carry);
        
    } else if (lenb > lena) {
        post(b, a, temp);
        int carry = 0;
        //colocando o digito \0 no final da string resultado
        soma[lenb + 1] = '\0';
        for (int i = lenb - 1; i >= 0; i--) {
            int sum = chartoint(temp[i]) + chartoint(b[i]) + carry;
            carry = sum / 10;

            soma[i + 1] = intochar(sum % 10);
        }
        soma[0] = intochar(carry);
    } else {
        int carry = 0;
        //colocando o digito \0 no final da string resultado
        soma[lenb + 1] = '\0';
        for (int i = lena - 1; i >= 0; i--) {
            int sum = chartoint(a[i]) + chartoint(b[i]) + carry;
            carry = sum / 10;
            soma[i + 1] = intochar(sum % 10);
        }
        soma[0] = intochar(carry);
    }
    //Checando se a string é composta somente de zeros.
    if (checkzer(soma) == 0) {
        printf("0");
    } else {
         //pulando os zeros à esquerda na impressão final.
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
    int lena = strlen(a), lenb = strlen(b);
    char temp[1002], sub[1002];
    int resulnegativo = 0;
    int carry = 0;
    // Definindo se o resultado vai ser negativo ou positivo
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
    // Começando a subtração. Separando em três casos variáveis caso o tamanho das string sejam diferentes
    if (lena > lenb) {
        post(a, b, temp);
        //colocando o digito \0 no final da string resultado
        sub[lena] = '\0';
        for (int i = lena - 1; i >= 0; i--) {
            int x = chartoint(a[i]);
            int y = chartoint(temp[i]);
            int diff = x - y - carry;
            
            if (diff < 0) {
                diff = diff + 10;
                carry = 1;
            } else {
                carry = 0;
            }
            sub[i] = intochar(diff);
        }
    } else if (lenb > lena) {
        post(b, a, temp);
        //colocando o digito \0 no final da string resultado
        sub[lenb] = '\0';
        for (int i = lenb - 1; i >= 0; i--) {
            int x = chartoint(b[i]);
            int y = chartoint(temp[i]);
            int diff = x - y - carry;

            if (diff < 0) {
                diff = diff + 10;
                carry = 1;
            } else {
                carry = 0;
            }
            sub[i] = intochar(diff);
        }
    } else {
        //colocando o digito \0 no final da string resultado
        sub[lena] = '\0';
        if (resulnegativo == 1) {
            for (int i = lena - 1; i >= 0; i--) {
                int x = chartoint(b[i]);
                int y = chartoint(a[i]);
                int diff = x - y - carry;

                if (diff < 0) {
                    diff = diff + 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                sub[i] = intochar(diff);
            }
        } else {
            for (int i = lena - 1; i >= 0; i--) {
                int x = chartoint(a[i]);
                int y = chartoint(b[i]);
                int diff = x - y - carry;

                if (diff < 0) {
                    diff = diff + 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                sub[i] = intochar(diff);
            }
        }
    }
    //Checando se a string é composta somente de zeros
    if (checkzer(sub) == 0) {
        printf("0");
    } else{
        //Imprimindo o sinal caso o resultado seja negativo
        if (resulnegativo == 1) {
            printf("-");
        }
        //pulando os zeros à esquerda na impressão final
        int start = 0;
        if (strlen(sub) > 1) {
            while (sub[start] == '0' && start < strlen(sub)) {
                start++;
            }
        } else {
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

void mult(char a[501], char b[501]) {
    int lena = strlen(a), lenb = strlen(b);
    char resultado[1002];
    resultado[lena + lenb] = '\0';
    //preenchendo o resultado com 0's antes dos produtos
    for (int i = 0; i < lena + lenb; i++) {
        resultado[i] = '0';
    }
    //colocando o digito \0 no final da string resultado
    resultado[lena + lenb] = '\0';
    //Começando a multiplicação
    for (int i = lenb - 1; i >= 0; i--) {
        int carry = 0;  
        for (int j = lena - 1; j >= 0; j--) {
            int multi = (chartoint(b[i]) * chartoint(a[j]) + chartoint(resultado[i + j + 1]) + carry);
            resultado[j + i + 1] = intochar(multi % 10);
            carry = multi / 10;
        }
        resultado[i] = intochar(carry);
    }
    //Checando se a string é composta somente de zeros e pulando os digitos à esquerda.
    int h = checkzer(resultado);
    int start = 0;
    while (resultado[start] == '0' && start < strlen(resultado)) {
        start++;
    }
    if (h == 0) {
        printf("0");
    } else {
        for (int i = start; i < strlen(resultado); i++) {
            if (chartoint(resultado[i]) >= 0 && chartoint(resultado[i]) <= 9) {
                printf("%c", resultado[i]);
            }
        }
    }
    printf("\n");
}

int main() {
    char a[501];
    char b[501];
    int n, o;
    scanf("%d", &n);
    //Impressão final em loop que se repete n vezez.
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d", a, b, &o);
        if (o == 1) {
            soma(a, b);
        } else if (o == 2) {
            subr(a, b);
        } else {
            mult(a, b);
        }
    }
    return 0;
}
