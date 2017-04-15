// Fast Prime Filter

int composite[(100000000 >> 6) + 1];

bool isPrime(int x) {
    return x == 2 || x > 2 && (x & 1) && !(composite[x >> 6] & (1 << ((x >> 1) & 63)));
}


// Miller-Rabin primality test

ll qpow(ll a, ll b, ll m){
    ll res=1;
    while(b) {
        if (b & 1) res *= a;
        res %= m;
        a *= a;
        a %= m;
        b >>= 1;
    }
    return res;
}

bool mr(ll x, ll n) {
    ll y = n - 1;
    while (!(y & 1)) y >>= 1;
    x = qpow(x, y, n);
    while (y < n - 1 && x != 1 && x != n - 1) {
        x = (x * x) % n;
        y <<= (ll) 1;
    }
    return (x == n - 1) || (y & 1);
}

bool isprime(int n) {
    if (n == 2 || n == 7 || n == 61)
        return true;
    if (n == 1 || !(n & 1))
        return false;
    return mr(2, n) && mr(7, n) && mr(61, n);
}
