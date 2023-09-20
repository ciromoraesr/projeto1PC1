#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int chartoint(char num) {
    return num - '0';
}

char intochar(int num) {
    return num + '0';
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
    int lena = strlen(a), lenb = strlen(b);
    char temp[1002], sub[1002];
    int resulnegativo = 0;
    int maior = 0;
    int carry = 0;
    
    if (lena > lenb) {
        maior = 1;
    } else if (lenb > lena) {
        maior = 2;
    } else {
        for (int i = 0; i < lena; i++) {
            if (a[i] > b[i]) {
                maior = 1;
                break;
            } else if (a[i] < b[i]) {
                maior = 2;
                break;
            }
        }
    }
    
    if (maior == 2) {
        resulnegativo = 1;
    } else if (maior == 1) {
        resulnegativo = 0;
    }
    
    if (lena > lenb) {
        int diffe = lena - lenb;
        for (int i = 0; i < diffe; i++) {
            temp[i] = '0';
        }
        for (int i = diffe; i < lena; i++) {
            temp[i] = b[i - diffe];
        }
        temp[lena] = '\0';

        int sum = 0;
        for (int i = 0; i < lena - 1; i++) {
            sum = chartoint(a[i]) + sum;
        }
        if (sum == 0) {
            for (int i = 0; i < lena - 1; i++) {
                sub[i] = temp[i];
                resulnegativo = 1;
            }
        } else {
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
        }
    } else if (lenb > lena) {
        int diffe = lenb - lena;
        for (int i = 0; i < diffe; i++) {
            temp[i] = '0';
        }
        for (int i = diffe; i < lenb; i++) {
            temp[i] = a[i - diffe];
        }
        temp[lenb] = '\0';

        int sum = 0;
        for (int i = 0; i < lenb - 1; i++) {
            sum = chartoint(a[i]) + sum;
        }
        if (sum == 0) {
            for (int i = 0; i < lenb - 1; i++) {
                sub[i] = temp[i];
                resulnegativo = 1;
            }
        } else {
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
        }
    } else {
        int sum = 0;
        for (int i = 0; i < lena - 1; i++) {
            sum = chartoint(a[i]) + sum;
        }
        if (sum == 0) {
            for (int i = 0; i < lena - 1; i++) {
                sub[i] = b[i];
                resulnegativo = 1;
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

    if (atoi(sub) == 0) {
        printf("0");
    } else {
        if (resulnegativo == 1) {
            printf("-");
        }
        int start = 0;
        while (sub[start] == '0' && start < strlen(sub)) {
            start++;
        }
        for (int i = start; i < strlen(sub) - 1; i++) {
            if (chartoint(sub[i]) >= -9 && chartoint(sub[i]) <= 9) {
                printf("%c", sub[i]);
            }
        }
    }
    printf("\n");
}

int main() {
    char a[501] = "0";
    char b[501] = "1";
    subr(a, b);
    return 0;
}
