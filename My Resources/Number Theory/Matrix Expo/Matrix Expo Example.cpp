//Codeforces 337C

#include <bits/stdc++.h>
using namespace std;
#define ll  long long

//Matrix Expo Part

#define c   1000000009
ll A[4][4];
ll M[4][4];
ll I[4][4];
void I_mul_M()
{
    ll temp[4][4];
    memset(temp,0,sizeof temp);
    for(ll i = 1; i <= 2; i++)
    {
        for(ll j = 1; j <= 2; j++)
        {
            for(ll k = 1; k <= 2; k++)
            {
                ll keep = ((I[i][k]%c)*(M[k][j]%c))%c;
                temp[i][j] = ((temp[i][j]%c) + keep%c + c)%c;
            }
        }
    }

    for(ll i = 1; i <= 2; i++)
    {
        for(ll j = 1; j <= 2; j++)
        {
            I[i][j] = temp[i][j]; // Save multiplication into matA
        }
    }

}

void M_mul_M()
{
    ll temp[4][4];
    memset(temp,0,sizeof temp);
    for(ll i = 1; i <= 2; i++)
    {
        for(ll j = 1; j <= 2; j++)
        {
            for(ll k = 1; k <= 2; k++)
            {
                ll keep = ((M[i][k]%c)*(M[k][j]%c))%c;
                temp[i][j] = ((temp[i][j]%c) + keep%c + c)%c;
            }
        }
    }

    for(ll i = 1; i <= 2; i++)
    {
        for(ll j = 1; j <= 2; j++)
        {
            M[i][j] = temp[i][j]; // Save multiplication into matA
        }
    }

}

ll solve(ll n,ll con)
{
    A[1][1] = 0;
    A[1][2] = con;
    I[1][1] = I[2][2] = M[2][2] =  1;
    I[1][2] = I[2][1] = M[1][2] =  0;
    M[1][1] = M[2][1] = 2;

    while(n > 0)
    {
        if(n%2 == 1)
        {
            I_mul_M();
        }
        M_mul_M();
        n /= 2;
    }

    ll ans[4][4]; //temporary matrix
    memset(ans,0,sizeof ans);
    for(ll i = 1; i <= 1; i++)
    {
        for(ll j = 1; j <= 2; j++)
        {
            for(ll k = 1; k <= 2; k++)
            {
                ll keep = ((A[i][k]%c)*(I[k][j]%c))%c;
                ans[i][j] = ((ans[i][j]%c) + keep%c + c)%c;
            }
        }
    }
    ll pnt = ans[1][1];
    return pnt;
}


// Matrix Expo end..................

int main()
{
    ll n,m,k;
    cin >> n >> m >> k;
//  first part
    ll cnt = 0;
    ll lo,up;
    lo = 0;
    up = n;

    while(lo <= up)
    {
        ll mid = (lo+up)/2;

        ll n_p = (n - (mid*k));
        ll m_p  = (m - (mid*k));

        if(n_p < 0 ){
        up = (mid-1);
        continue;
        }

        ll keep = (n_p/k)*(k-1) + (n_p%k);

        if(keep >= m_p)
        {
            cnt = mid;
            up = mid-1;
        }
        else lo = mid+1;
    }
// last part
     //cout << cnt <<" " << solve(0,k) << endl;
    ll res = solve(cnt,k);
    res = (res + (m - cnt*k)) % c;
    cout << res << endl;
    return 0;
}
