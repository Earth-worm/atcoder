#include<iostream>
#include<vector>
#include<set>

using namespace std;
long long n, m;

struct UnionFind {
    vector<int> par;
    vector<int> s;
    
    UnionFind(int N) : par(N), s(N,1) {
        for(int i = 0; i < N; i++) par[i] = i;
    }
    
    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if(s[y] > s[x]) swap(y,x);
        s[x] += s[y];
        s[y] = s[x];
        par[x] = y;
    }
    
    bool isSame(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int size(int x){
        return s[root(x)];
    }
};

int main(){
    cin >> n >> m;
    UnionFind uf(n);
    for(int i=0;i<m;i++){
        int wk1,wk2;
        cin>>wk1>>wk2;
        wk1--;
        wk2--;
        uf.unite(wk1,wk2);
    }
    long long ans = 0;
    for(int i=0;i<n;i++){
        if(i != uf.root(i)) continue;
        long long s = uf.size(i);
        ans += s*(s-1)/2;
    }
    ans -= m;
    cout << ans << endl;
    return 0;
}