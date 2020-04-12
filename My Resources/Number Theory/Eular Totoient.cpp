//Here is an implementation using factorization in O(sqrt(n)):
int phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}


//Up to N all numbers phi Number.
int mark[(2000000>>5) + 100];
#define GET(x) (mark[(x)>>5]>>((x)&31)&1)
#define SET(x) (mark[(x)>>5] |= 1<<((x)&31))
int phi[2000005];
void sieve()
{
    register int i, j;
    SET(1);
    for(int i = 1; i <= 2000000; i++) phi[i] = i;
    int n = 2000000;
    for(i = 2; i <= n; i++)
    {
        if(!GET(i))
        {
            for(j = i; j <= n; j += i)
            {
                phi[j] = phi[j]/i*(i-1);
                SET(j);
            }
        }
    }
}
