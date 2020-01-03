#include <stdio.h>

int hermite(int n,int x){
    if(n==0) return 1;
    else {
        if(n==1) return 2*x;
        else return 2*x*hermite(n-1,x)-2*(n-1)*hermite(n-2,x);
    }
}
int main() {
    int n, Hx, x;
    printf("Write the values for n:\n");
    scanf("%d",&n);
    printf("Write the values for x:\n");
    scanf("%d",&x);
    Hx = hermite(n,x);
    printf("%d",Hx);
    return 0;
}