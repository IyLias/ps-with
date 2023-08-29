#include<stdio.h>
#define ll long long

int mu[1000010];

void build_mu() {
    mu[1] = 1;
    for (int i = 1; i <= 1000000; i++) {
        for (int j = 2 * i; j <= 1000000; j += i) {
            mu[j] -= mu[i];
        }
    }
}

ll sq_free_cnt(ll n) {
    ll cnt = 0;
    for (ll i = 1; i * i <= n; i++) {
        cnt += mu[i] * (n / (i * i));
    }
    return cnt;
}

int main() {
    build_mu();
    int K;
    scanf("%d", &K);

    ll start = 0, end = 2000000000;
    while (start < end) {
        ll mid = (start + end) / 2;
        ll value = sq_free_cnt(mid);
        if (value > K) end = mid - 1;
        else if (value == K) end = mid;
        else start = mid + 1;
    }

    printf("%lld\n", end);

    return 0;
}