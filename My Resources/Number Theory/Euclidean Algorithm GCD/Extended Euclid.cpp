/*This implementation of extended Euclidean algorithm
produces correct results for negative integers as well.
from cp-algorithm
*/

#define ll long long
ll gcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
/*From Forthright Blog*/
int ext_gcd(int A,int B,int *X,int *Y){
int x2,y2,x1,y1,x,y,r2,r1,q,r;
x2 = 1;y2 = 0;
x1 = 0;y1 = 1;
for(r2 = A,r1 = B;r1 != 0;r2 = r1,r1 = r,x2 = x1,y2 = y1,x1 = x,y1 = y){
    q = r2/r1;
    r = r2%r1;
    x = x2 - (q*x1);
    y = y2 - (q*y1);
}
*X = x2;*Y = y2;return r2;
}
/*From online
Call in main:
ll a,b,X,Y,g;
eGCD(a,b,X,Y,g);
*/
void eGCD(ll a,ll b,ll&x,ll&y,ll&g){
    if(!b)x=1,y=0,g=a;
    else eGCD(b,a%b,y,x,g),y-=a/b*x;
}
