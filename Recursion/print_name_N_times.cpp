#include<iostream>
using namespace std;

void printNTimes(int n){
    if(n<1){
        return;
    }
    string name="rahul ";
    cout<<name<<endl;
    printNTimes(n-1);
}
int main(){
    int n;
    cout<<"enter number"<<endl;
    cin>>n;
    printNTimes(n);

}