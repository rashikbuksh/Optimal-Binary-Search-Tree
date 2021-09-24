#include <bits/stdc++.h>
using namespace std;

int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++){
        s += freq[k];
    }
    return s;
}

int optimalBST(int key[], int freq[], int n)
{
    int cost[n][n];
    for (int i = 0; i < n; i++){
        cost[i][i] = freq[i];
    }
    //cout<<"i j r c"<<endl;
    for (int L = 2; L <= n; L++)
    {
        for (int i = 0; i <= n-L+1; i++)
        {
            int j = i+L-1;
            cost[i][j] = INT_MAX;
            for (int r = i; r <= j; r++)
            {
            int c=0;
            if(r>i){
                c=cost[i][r-1];
                //cout<<i<<" "<<j<<" "<<r<<" "<<c<<endl;
            }
            if(r < j){
                c+=cost[r+1][j];
                //cout<<i<<" "<<j<<" "<<r<<" "<<c<<endl;
            }
            c+=sum(freq, i, j);
            if (c < cost[i][j])
                cost[i][j] = c;
                //cout<<i<<" "<<j<<" "<<r<<" "<<c<<endl;
            }
        }
    }
    cout<<endl;
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<cost[i][j]<< " ";
        }
        cout<<endl;
    }*/
    return cost[0][n-1];
}

int main()
{
    int key[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(key)/sizeof(key[0]);
    cout << "Cost of Optimal BST is " << optimalBST(key, freq, n);
    return 0;
}
