#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int n; cin >> n;
    vector<long long> a(n);
    stack<int> b;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        long long wk = a[i];
        while(1){
            if(b.empty() || b.top() != wk){
                b.push(wk);
                break;
            }
            wk++;
            b.pop();
        }
    }
    cout << b.size() << endl;
    return 0;
}