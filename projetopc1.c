#include <stdio.h>

int oum(long long int a,long long int b){
    return a + b;
}
int odois(long long int a,long long int b){
    return a - b;

}
int otres(long long int a,long long int b){
    return a * b;
}

int main(){
    int i, n;

    scanf("%d", &n);
    long long int v[n][3], result;
    int o[n];
    for (i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            scanf("%lld", &v[i][j]);

            }
        scanf("%d", &o[i]);
        }
        printf("\n");
    for(i = 0; i < n; i++){
            if(o[i]==1){
               result = oum(v[i][0], v[i][1]);
            }
            if(o[i]==2){
                result = odois(v[i][0], v[i][1]);
            }
            if(o[i]==3){
                result = otres(v[i][0], v[i][1]);

            }
        printf("%lld\n", result);
    }
    return 0;
}
