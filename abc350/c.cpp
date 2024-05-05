#include<iostream>
#include<vector>
using namespace std;

int main(void){
    int n;cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        int wk;cin >> wk;wk--;
        a[i] = wk;
    }
    int sum = 0;
    vector<pair<int,int> > b(0);
    for(int i=0;i<n;i++){
        while(i != a[i]){
            sum++;
            b.push_back(pair<int,int>(i+1,a[i]+1));
            swap(a[i],a[a[i]]);
        }
    }
    cout << sum << endl;
    for(pair<int,int> bb: b){
        cout << min(bb.first,bb.second) << " " << max(bb.first,bb.second) << endl;
    }
    return 0;
}