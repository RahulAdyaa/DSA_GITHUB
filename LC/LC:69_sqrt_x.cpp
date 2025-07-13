#include<iostream>
using namespace std;

int main() {
    int num =36;

     // =========================
    // ✅ Approach 1: Brute Force
    // =========================
    // TC: O(√n)
    // SC: O(1)
    // Finds square root by checking each i from 1 to num

    // long long i = 0;
    // while (i * i <= num) {
    //     i++;
    // }
    // //Now ans is prev value of i
    // return i - 1;

    // ================================
    // ✅ Approach 2: Binary Search
    // ================================
    // TC: O(log n)
    // SC: O(1)
    // Efficient way using binary search to avoid overflow
    int low = 1;
    int high = num;

    // Binary search to find integer square root
    while (low <= high) {
        // Prevents overflow for large numbers
        long long mid = low + (high - low) / 2;
        long long val = mid * mid;

        // If mid^2 is less than or equal to num, move right
        if (val <= num) {
            low = mid + 1;
        }
        // If mid^2 exceeds num, move left
        else {
            high = mid - 1;
        }
    }

    // 'high' now holds the integer square root of num
    cout << high << endl;

    return 0;
}
