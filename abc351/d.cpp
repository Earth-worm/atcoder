#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

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
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };
    int h,w; cin>>h>>w;
    vector<string> field(h);
    for(int i=0;i<h;i++) cin >> field[i];
    vector<vector<bool> > touch(h, vector<bool>(w));
    vector<vector<int> > count(h, vector<int>(w));

    UnionFind uf(h*w);
    for(int y=0;y<h;y++){
        for(int x=0;x<w;x++){
            touch[y][x] = false;
            for(int k = 0; k < 4; k++){
                int xx = x + dx[k], yy = y + dy[k];
                if(xx < 0 || yy < 0 || xx >= w || yy >= h) continue;
                if(field[yy][xx] == '#') touch[y][x] = true;
            }
        }
    }
    for(int y=0;y<h;y++){
        for(int x=0;x<w;x++){
            if(field[y][x] == '#') continue;
            for(int k = 0; k < 4; k++){
                int xx = x + dx[k], yy = y + dy[k];
                if(xx < 0 || yy < 0 || xx >= w || yy >= h) continue;
                if(field[yy][xx] == '#') continue;
                if(!touch[yy][xx] && !touch[y][x]){
                    uf.unite(yy*w+xx,y*w+x);
                }
            }
        }
    }
    for(int y=0;y<h;y++){
        for(int x=0;x<w;x++){
            set<int> s;
            if(field[y][x] == '#') continue;
            for(int k = 0; k < 4; k++){
                int xx = x + dx[k], yy = y + dy[k];
                if(xx < 0 || yy < 0 || xx >= w || yy >= h) continue;
                if(field[yy][xx] == '#') continue;
                int root = uf.root(yy*w+xx);
                if(s.find(root) != s.end() || (root/w == y && root%w == x) || !touch[y][x] || touch[root/w][root%w]) continue;
                s.insert(root);
                count[root/w][root%w]++;
            }
        }
    }
    int ans = 0;
    for(int y=0;y<h;y++)for(int x=0;x<w;x++)ans = max(count[y][x]+uf.size(y*w+x),ans);
    cout << ans << endl;
    return 0;
}