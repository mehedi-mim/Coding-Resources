long long MOD = 1e9 + 7
int nCr(int n, int r) {
    long long res = 1;
    for (int i = 0; i < r; i++) {
        res = (res * (n - i)) % MOD;
        res = (res * power(i + 1, MOD - 2)) % MOD; // Using modular inverse for division
    }
    return static_cast<int>(res); // Cast the result to int before returning
}
