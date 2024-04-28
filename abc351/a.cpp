#include<iostream>
#include<vector>
using namespace std;

int main(void){
    int sumA = 0, sumB = 0, wk;
    for(int i=0;i<9;i++) cin >> wk, sumA+=wk;
    for(int i=0;i<8;i++) cin >> wk, sumB+=wk;
    cout << sumA-sumB+1 << endl;
    return 0;
}