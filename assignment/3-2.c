#include <stdio.h>

// x 個のりんごが入るバッグ k 個で足りるかどうかを返す
int p(int x, int a[], int n, int k){
    int nBag = 0, i;
    for(i = 0; i < n; i ++) nBag += (a[i]-1)/x + 1;
    return nBag <= k;
}

int main(void){
    int n, k, a[100000], i;
    
    // 入力
    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i ++) scanf("%d", &a[i]);
    
    // 二分探索
    int lb = 0, ub = 1000000001;
    while(ub - lb > 1){
        int m = (lb+ub)/2;
        if(p(m, a, n, k)) ub = m;
        else lb = m;
    }
    
    // 出力
    printf("%d", ub);
    return 0;
}
