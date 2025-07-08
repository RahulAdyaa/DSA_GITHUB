class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;  // Pointer to the last digit of num1
        int j = num2.size() - 1;  // Pointer to the last digit of num2
        int carry = 0;            // Carry for addition
        string result = "";       // String to store the final result

        // Loop until all digits are processed or there's a carry left
        while (i >= 0 || j >= 0 || carry) {
            // Get the current digit from num1 if i is valid, else 0
            int digit1 = (i >= 0) ? num1[i] - '0' : 0;

            // Get the current digit from num2 if j is valid, else 0
            int digit2 = (j >= 0) ? num2[j] - '0' : 0;

            // Calculate the sum of digits and carry
            int val = digit1 + digit2 + carry;

            // Update carry for next iteration
            carry = val / 10;

            // Append the current digit to result
            result += (val % 10) + '0';

            // Move to the next digits (left)
            i--;
            j--;
        }

        // The result is in reverse order, reverse it before returning
        reverse(result.begin(), result.end());
        return result;
    }
};
