#include <stdio.h>
int main(void){
    int n, k, a[100000];
    int i;
    
    // 入力
    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i ++) scanf("%d", &a[i]);
    
    // 二分探索
    int lb = -1, ub = n;
    while(ub - lb > 1){
        int m = (lb+ub)/2;
        if(a[m] >= k) ub = m;
        else lb = m;
    }
    
    // 出力
    printf("%d", ub);
    return 0;
}
