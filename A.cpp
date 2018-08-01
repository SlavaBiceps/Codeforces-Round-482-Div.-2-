#include<iostream>
int main(){
    long long n;
    std::cin>>n;
    n++;
    if (n==1)std::cout<<0;
    else if (n%2==0) std::cout<<n/2;
    else std::cout<<n;
    return 0;
}