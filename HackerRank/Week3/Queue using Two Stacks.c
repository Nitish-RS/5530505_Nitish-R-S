#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define N 100000
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int a[N], b[N];
    int t1=0, t2=0;
    int q, c, v;
    
    scanf("%d",&q);
    while(q--){
        scanf("%d",&c);
        if(c==1){
            scanf("%d",&v);
            a[t1++] = v;
        }
        else{
            if(c==2){
                if(t2==0){
                    while(t1>0){
                        b[t2++] = a[--t1];
                    }
                }
                if(t2>0) t2--;
            }
            else if(c==3){
                if(t2==0){
                    while(t1>0){
                        b[t2++] = a[--t1];
                    }
                }
                if(t2>0) printf("%d\n", b[t2-1]);
            }
        }
    }
    return 0;
}
