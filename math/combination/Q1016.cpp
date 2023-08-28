#include<stdio.h>
#define ll long long

int mu[1000010];

void buildMu() {
    mu[1] = 1;
    for (int i = 1; i <= 1000000; i++) {
        for (int j = 2 * i; j <= 1000000; j += i) {
            mu[j] -= mu[i];
        }
    }
}

ll sqFreeCnt(ll n) {
    ll cnt = 0;
    for (ll i = 1; i * i <= n; i++) {
        cnt += mu[i] * (n / (i * i));
    }
    return cnt;
}

int main() {
    buildMu();
    ll maxN, minN;
    scanf("%lld%lld\n", &minN, &maxN);
    printf("%lld\n", sqFreeCnt(maxN) - sqFreeCnt(minN - 1));

    return 0;
}