#include<iostream>
#include<vector>
using namespace std;

int main(void){
    int n; cin >> n;
    int x,y;
    vector<vector<char> > table(n,vector<char>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> table[i][j];
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            char wk; cin >> wk;
            if(table[i][j] != wk){
                x=i+1;
                y=j+1;
            }
        }
    }
    cout << x << " " << y << endl;
    return 0;
}
