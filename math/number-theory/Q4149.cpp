#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <set>


using namespace std;

using ull = unsigned long long;
vector<ull> alist = { 2,7,61 };

inline ull addmod(ull x, ull y, ull m) {
	x %= m;
	y %= m;

	return (x >= m - y ? x - (m - y) : x + y);
}

inline ull mulmod(ull x, ull y, ull m) {
	x %= m;
	y %= m;

	ull r = 0;
	while (y > 0) {
		if (y % 2 == 1)
			r = addmod(r, x, m);
		x = addmod(x, x, m);
		y /= 2;
	}

	return r;
}

ull powmod(ull x, ull y, ull m) {
	x %= m;
	ull r = 1ULL;
	while (y > 0) {
		if (y & 1)
			r = (r * x) % m;
		x = (x * x) % m;
		y = y >> 1;
	}

	return r;
}

inline bool miller_rabin(ull n, ull a) {
	// 이 한 줄이 없으면 틀렸다고 뜬다.. 자세히 알아봐야할 듯 
	if (a % n == 0) return true;

	ull d = n - 1;
	while (d % 2 == 0) {
		if (powmod(a, d, n) == n - 1)
			return true;
		d /= 2;
	}
	ull tmp = powmod(a, d, n);
	return tmp == n - 1 || tmp == 1;
}

bool is_prime(ull n) {

	if (n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;

	for (ull a : alist)
		if (!miller_rabin(n, a))
			return false;

	return true;
}



int main()
{
	int n;
	scanf("%d", &n);

	int count = 0;
	for (int i = 0; i < n; i++) {
		ull area;
		cin >> area;

		if (is_prime(2 * area + 1)) {
			count++;
		}
		
	}

	printf("%d\n", count);
}

