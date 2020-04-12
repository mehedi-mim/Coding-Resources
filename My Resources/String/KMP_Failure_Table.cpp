#include <bits/stdc++.h>
using namespace std;

void solve(string s)
{
    int n = s.size();
    int P[n+10]; // Failure Table
    memset(P,0,sizeof P);
    int j = 0,i = 1;
    while(j < i && i < n){
       if(s[j] != s[i]){
        if(j == 0){
            P[i] = 0;
            i++;
        }
        else{
            j = P[j-1];
        }
       }
       else{
        P[i] = j+1;
        i++;
        j++;
       }
    }
    for(int i = 0;i < n;i++) cout << P[i] <<" ";
    cout << endl;
    //Every index shows length of prefix(from start) and suffix(from i) are matched.
}

int main()
{
    string pattern;
    cin >> pattern;
    solve(pattern);
}
