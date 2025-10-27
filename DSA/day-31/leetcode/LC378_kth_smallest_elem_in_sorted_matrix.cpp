#include<bits/stdc++.h>
using namespace std;

// topic : min heap

using ll=long long;
class Solution {
private:
    vector<ll>p;
    int size;
    void push(ll n){
        p[size++]=n;
        int idx=size-1;
        while(idx>1){
            int parent=idx>>1;
            if(p[parent]<=p[idx]) break;
            swap(p[parent],p[idx]);
            idx=parent;
        }
    }
    ll pop(){
        ll n=p[1];
        p[1]=p[--size];
        int idx=1;
        int end=size>>1;
        while(idx<=end){
            int l=idx<<1;
            int r=l+1;
            int minChild=l;
            if(r<size && p[r]<p[l]) minChild=r;
            if(p[idx]<=p[minChild]) return n;
            swap(p[idx],p[minChild]);
            idx=minChild;
        }
        return n;
    }
    ll encode(int n1,int n2, int n3){
        return ((ll)n1<<20)|(n2<<10)|n3;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        const ll e=1023;
        p.assign(n+1,0);
        size=1;
        
        for(int i=0;i<n;i++) push(encode(matrix[i][0],i,0));
        
        while(--k){
            auto code=pop();
            int c=(int)(code&e);
            code>>=10;
            int r=(int)(code&e);
            c++;
            if(c<n)push(encode(matrix[r][c],r,c));
        }
        return (int)(pop()>>20);
    }
};

int main(){
    int n, k;
    cout << "Enter n: ";
    cin>>n;
    cout << "Enter k: ";
    cin>>k;
    cout<<"Enter matrix elements: "<<endl;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
        
    }
    Solution s;
    cout << "Kth smallest elem: " << s.kthSmallest(mat, k);
}