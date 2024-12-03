class Solution {
public:
    string smallestNumber(string num, long long t) {
        int n = num.length();
        
        // Edge case: if t is 1, return num as it is already divisible by 1
        if (t == 1) {
            return num;
        }
        
        // Edge case: if num contains only 9's and t is not divisible by 9, no solution exists
        if (all_of(num.begin(), num.end(), [](char c) { return c == '9'; }) && t % 9 != 0) {
            return "-1";
        }
        
        // Initialize the result string with num
        string result = num;
        
        // Iterate through each position in the result string
        for (int i = 0; i < n; i++) {
            // Try replacing the current digit with a larger digit
            for (char d = result[i] + 1; d <= '9'; d++) {
                result[i] = d;
                
                // Check if the product of digits is divisible by t
                if (is_divisible(result, t)) {
                    return result;
                }
            }
            
            // If no larger digit works, reset the current digit and move to the next position
            result[i] = '0';
        }
        
        // If no solution is found, append '0' to the result and try again
        result += '0';
        
        // Iterate through each position in the updated result string
        for (int i = 0; i < n + 1; i++) {
            // Try replacing the current digit with a larger digit
            for (char d = result[i] + 1; d <= '9'; d++) {
                result[i] = d;
                
                // Check if the product of digits is divisible by t
                if (is_divisible(result, t)) {
                    return result;
                }
            }
            
            // If no larger digit works, reset the current digit and move to the next position
            result[i] = '0';
        }
        
        // If no solution is found after appending '0', return "-1"
        return "-1";
    }
    
private:
    // Helper function to check if the product of digits in a string is divisible by t
    bool is_divisible(const string& num, long long t) {
        long long product = 1;
        
        // Calculate the product of digits
        for (char c : num) {
            if (c == '0') {
                continue;
            }
            product *= (c - '0');
        }
        
        // Check if the product is divisible by t
        return product % t == 0;
    }
};

// Time Complexity: O(n * 9 * 2) = O(n), where n is the length of the input string num.
// We iterate through each position in the string twice (once for the original string and once after appending '0').
// For each position, we try at most 9 different digits.
// The is_divisible function takes O(n) time to calculate the product of digits.
// Therefore, the overall time complexity is O(n).

// Space Complexity: O(n), where n is the length of the input string num.
// We store the result string, which can have a length of up to n + 1.
// The space required for the is_divisible function is O(1) as it only uses a constant amount of extra space.
// Therefore, the overall space complexity is O(n).