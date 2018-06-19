#include <stdio.h>

// 長さ x の槍を k 本作れ"ない"かどうかを返す
int p(int x, int a[], int n, int k){
    int nSpear = 0, i;
    for(i = 0; i < n; i ++) nSpear += a[i]/x;
    return nSpear < k;
}

int main(void){
    int n, k, a[100000], i;
    
    // 入力
    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i ++) scanf("%d", &a[i]);
    
    // 二分探索
    int lb = -1, ub = 1000000001;
    while(ub - lb > 1){
        int m = (lb+ub)/2;
        if(p(m, a, n, k)) ub = m;
        else lb = m;
    }
    
    // 出力
    printf("%d", lb);
    return 0;
}
