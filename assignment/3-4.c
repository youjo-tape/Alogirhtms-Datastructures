#include <stdio.h>

// n 時間の仕事 a を k 人に割り振ったとき、
// 最大の1人の仕事量を x 以下にできるかを判定する
int p(int x, int a[], int n, int k){
    int kNeed = 1, aSum = 0, i;
    for(i = 0; i < n; i ++){
        if(a[i] > x) return 0;
        
        aSum += a[i];
        if(aSum > x){
            aSum = a[i];
            kNeed ++;
        }
    }
    return kNeed <= k;
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
    printf("%d", ub);
    return 0;
}
