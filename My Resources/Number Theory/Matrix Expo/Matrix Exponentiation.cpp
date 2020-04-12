/*Matrix Expo*/
/*Matrix (A*B) Multiplication............
n = row of matA
m = col of matA,row of mat B
k = col of matA,row of mat B
*/
ll temp[][];  //temporary matrix
for(ll i = 1; i <= n; i++)
{
    for(ll j = 1; j <= m; j++)
    {
        for(ll k = 1; k <= m; k++)
        {
            ll keep = ((matA[i][k]%c)*(matB[k][j]%c))%c;
            temp[i][j] = ((temp[i][j]%c) + keep%c + c)%c;
        }
    }
}

for(ll i = 1; i <= 2; i++)
{
    for(ll j = 1; j <= 2; j++)
    {
        matA[i][j] = temp[i][j]; // Save multiplication into matA
    }
}
//Main Matrix Expo
function matrix_power_final(A, x): //A = power matrix
  result = I_n    // I_n = identity matrix
  while x > 0:
    if x % 2 == 1:
      result = result * A
    A = A * A
    x = x / 2
  return result // return this
