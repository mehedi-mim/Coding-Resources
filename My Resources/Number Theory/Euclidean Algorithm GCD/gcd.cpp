//Euclidean algorithm works in O(log (min(a,b))).
//Normal....
int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
    return gcd (b, a % b);
}
//recursive.....
int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}
//Non-recursive.....
#define ll long long
ll gcd (ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
//lcm
ll lcm (ll a, ll b) {
    return a / gcd(a, b) * b;
}
