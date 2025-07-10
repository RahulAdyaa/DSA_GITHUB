#include<iostream>
#include<vector>
using namespace std;

void swapp(int &n1, int &n2) { // ✅ pass by reference
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

void reverse(int i, vector<int>& arr, int n) {
    if(i >= n / 2) return;
    swapp(arr[i], arr[n - i - 1]);
    reverse(i + 1, arr, n);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    reverse(0, arr, n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
