#include<iostream> // For input/output operations
#include<vector>   // For using std::vector to store strings
#include<string>   // For using std::string

using namespace std; // Use standard namespace


// Approach 1

// // Function to check if a string of parentheses is valid
// int isvalid(string &str){
//     int count = 0; // Balances parentheses: increment for '(', decrement for ')'
//     for(char &ch : str){
//         if(ch == '('){
//             count++;
//         }
//         else{
//             count--;
//         }
//         if(count < 0){ // Invalid if ')' appears before its matching '('
//             return false;
//         }
//     }
//     return count == 0; // Valid if all parentheses are balanced at the end
// }

// // Recursive function to generate valid parenthesis combinations
// // curr: The current string being built
// // n: The total number of parenthesis pairs required
// // ans: Vector to store the final valid strings
// void generateP(string curr, int n, vector<string>&ans){
//     // **CRITICAL PRUNING STEP:**
//     // If current string length exceeds 2*n, it can't be a valid solution.
//     // This prevents infinite recursion and stack overflow.
//     if (curr.size() > 2 * n) {
//         return;
//     }

//     // Base case: If the current string has reached the target length (2*n)
//     if(curr.size() == 2 * n ){
//         if(isvalid(curr)){ // Check if this complete string is valid
//             ans.push_back(curr); // If valid, add it to results
//         }
//         return; // Stop this recursive path as length is fixed
//     }

//     // Recursive calls: Explore adding either '(' or ')'
//     generateP(curr + "(", n, ans); // Try adding an opening parenthesis
//     generateP(curr + ")", n, ans); // Try adding a closing parenthesis
// }

// int main(){
//     int n = 2; // Example: Generate combinations for 2 pairs of parentheses
//     vector<string> ans; // Stores the generated valid parenthesis strings

//     generateP("", n, ans); // Start generation with an empty string

//     // Print all found valid parenthesis combinations
//     for(auto str : ans){
//         cout << str << endl;
//     }

//     return 0; // Program ends successfully
// }



void generateP(string curr, int n,int open , int close, vector<string>&ans){
    // **CRITICAL PRUNING STEP:**
    // If current string length exceeds 2*n, it can't be a valid solution.
    // This prevents infinite recursion and stack overflow.
    if(curr.size()>2*n){
            return;
    }
    if(curr.size()==2*n ){
        ans.push_back(curr);
    }
    if(open<n){
        generateP(curr+"(",n,open+1,close,ans);
    }
    if(close<open){
        generateP(curr+")",n,open ,close+1,ans);
    }
}

int main(){
    int n = 15; // Example: Generate combinations for 2 pairs of parentheses
    vector<string> ans; // Stores the generated valid parenthesis strings
    int open=0;
    int close=0;
    generateP("", n, open ,close,ans); // Start generation with an empty string

    // Print all found valid parenthesis combinations
    for(auto str : ans){
        cout << str << endl;
    }

    return 0; // Program ends successfully
}
