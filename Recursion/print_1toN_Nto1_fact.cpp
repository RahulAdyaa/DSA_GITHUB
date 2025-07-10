#include<iostream>
using namespace std;

void print1toN(int n){
    if(n==0) return ;
    print1toN(n-1);
    cout<<n<<endl;
}

void printNto1(int n){
    if(n==0) return ;
    cout<<n<<endl;
    printNto1(n-1);
}

int sum(int n){
    if(n==0){
        return 0;
    }
    return n+sum(n-1);
}
int fact(int n){
    if(n==1){
        return 1;
    }
    return n*fact(n-1);
}

int main(){
    int n;
    cout<<"enter number"<<endl;
    cin>>n;
    print1toN(n);
    cout<<endl;
    printNto1(n);
    cout<<endl;
    cout<<sum(n)<<endl;
    cout<<fact(n)<<endl;

}