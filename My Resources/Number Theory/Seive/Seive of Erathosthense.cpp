//Normal Efficient Sieve................
int n;
is_prime[0] = is_prime[1] = true;
for (int i = 2; i * i <= n; i++)
{
    if (is_prime[i] == 0)
    {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = true;
    }
}

//Counting primes using block sieving
int prime[10000000];
int primes[40000];
int is_prime[40000];
int ith;
void  count_primes(int n) {
    ith = 0;
    const int S = 30000;
    int nsqrt = sqrt(n);
    for(int i = 0;i <= nsqrt+1;i++) primes[i] = is_prime[i] =  1;
    int pos = 0;
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes[pos++] = i;
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }
    bool block[S];
    for (int k = 0; k * S <= n; k++) {
        for(int i = 0;i < S;i++) block[i] = true;
        int start = k * S;
        int pr = start;
        for (int i = 0 ;i < pos; i++) {
            int p = primes[i];
            int start_idx = (start + p - 1) / p;
            int keep;
            if(start_idx > p) keep = start_idx;
            else keep = p;
            int j = keep * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i]){
                prime[ith++] = pr;
            }
            pr++;
        }
    }
    printf("%d\n",ith);
}

//Linear sieve
// Works less than 10^7 ,memory needs much
//Linear Sieve.....Use array instead of vector to speed up
int prime[10000000];
int ith;
int cnt;
const int N = 10000000;
int lp[N+1];
int  main()
{
    for (int i=2; i<=N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            prime[ith++] = i;
        }
        for (int j=0; j < ith && prime[j]<=lp[i] && i*prime[j]<=N; ++j)
            lp[i * prime[j]] = prime[j];
    }
   printf("%d\n",ith);
    return 0;
}
//Bitwise sieve

int prime[10000000];
int ith;
bool Check(int N,int pos){return (bool)(N & (1<<pos));}
int Set(int N,int pos){return N=N | (1<<pos);}
int status[(100000000/32)+2];
void sieve(int n)
{
    for(int  i = 3; i*i <= n; i+= 2)
    {
        if( Check(status[i>>5],i&31)==0)
        {
            for(int  j = i*i; j <= n; j += (i<<1) )
            {
                status[j>>5]=Set(status[j>>5],j & 31)   ;
            }
        }
    }
    prime[ith++] = 2;
    for(int i=3; i<=n; i+=2)
        if( Check(status[i>>5],i&31)==0){
            prime[ith++] = i;
        }

}
