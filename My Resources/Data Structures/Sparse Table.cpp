
// K = log(n)
// mxn = sizeof of array

int sp[mxn][k + 1]; // Declare sparse table

for (int i = 1; i <= n; i++)
    sp[i][0] = array[i];    // initialize

    //Building table
for (int j = 1; j <= k; j++)
    for (int i = 1; i + (1 << j)-1 <= n; i++)
        sp[i][j] = f(sp[i][j-1], sp[i + (1 << (j - 1))][j - 1]);

//j = 2 means j = (2^3) = 4; [1 to 4] then [5 to Eight] = 2^3



// here f means function....
// f = min(),max(),sum()..........

// This is for query of sum............
long long sum = 0;
for (int j = k; j >= 0; j--) {
    if ((1 << j) <= R - L + 1) {       // query = [L,R]
        sum += sp[L][j];
        L += 1 << j;
    }
}

//Pre-calculating logarithm
int log[mxn+1];
log[1] = 0;
for (int i = 2; i <= mxn; i++)
    log[i] = log[i/2] + 1;

//And the minimum of a range [L,R] can be computed with:

int j = log[R - L + 1];
int minimum = min(sp[L][j], sp[R - (1 << j) + 1][j]);
