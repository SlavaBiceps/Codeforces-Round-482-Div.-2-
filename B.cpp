#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,l,f,maxx,res;
    long long b[3],mas[60];
    string ress[3],a[3];
    ress[0]="Kuro";
    ress[1]="Shiro";
    ress[2]="Katie";
    cin >> n;
    for(int i=0; i<3; i++)
        cin >> a[i];
    l=a[0].length();
    f=0;
    for(int i=0; i<3; i++){
        memset(mas, 0, sizeof mas);
        for (int j=0; j<l; j++) {
            if (a[i][j]>='a' && a[i][j]<='z') {
                mas[a[i][j]-'a']++;
            }
            else {
                mas[a[i][j]-'A'+27]++;
            }
        }
        b[i] = 0;
        for(int j=0; j<56 ; j++){
            b[i]=max(b[i],mas[j]);
        }
        b[i]+=n;
        if(n==1 && b[i]==l+1) {
            b[i]=l-1;
        }
        if(b[i]>=l) {
            b[i]=l;
        }
    }
    maxx=max(b[0],max(b[1],b[2]));
    f=0;
    for(int i=0; i<3; i++){
        if(maxx==b[i]) {
            f++;
        }
    }
    if (f>1) cout << "Draw";
    else {
        if(b[0]>b[1] && b[0]>b[2]){
            cout << ress[0];
        } else if(b[1] > b[2]){
            cout << ress[1];
        } else {
            cout << ress[2];
        }
    }
}