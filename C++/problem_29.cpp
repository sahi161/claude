class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle edge case where dividend is INT_MIN and divisor is -1
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // Determine the sign of the quotient
        bool isNegative = (dividend < 0) ^ (divisor < 0);
        
        // Convert dividend and divisor to their absolute values
        long long absDividend = abs(static_cast<long long>(dividend));
        long long absDivisor = abs(static_cast<long long>(divisor));
        
        // Initialize quotient to 0
        int quotient = 0;
        
        // Perform division using bit manipulation
        while (absDividend >= absDivisor) {
            long long temp = absDivisor;
            int shift = 1;
            
            // Double the divisor until it becomes greater than the dividend
            while (temp <= absDividend) {
                temp <<= 1;
                shift <<= 1;
            }
            
            // Subtract the largest possible multiple of divisor from dividend
            absDividend -= temp >> 1;
            quotient += shift >> 1;
        }
        
        // Apply the sign to the quotient
        return isNegative ? -quotient : quotient;
    }
};

/*
Approach:
1. Handle the edge case where dividend is INT_MIN and divisor is -1 to avoid integer overflow.
2. Determine the sign of the quotient based on the signs of dividend and divisor.
3. Convert dividend and divisor to their absolute values to handle negative numbers.
4. Initialize the quotient to 0.
5. Perform division using bit manipulation:
   - Double the divisor until it becomes greater than the dividend.
   - Subtract the largest possible multiple of divisor from dividend.
   - Update the quotient by adding the corresponding shift value.
6. Apply the sign to the quotient based on the signs of dividend and divisor.
7. Return the quotient.

Time Complexity: O(log(dividend))
- The while loop runs for log(dividend) iterations, as the divisor is doubled in each iteration.

Space Complexity: O(1)
- The solution uses only a constant amount of extra space.

Testing:
The solution has been tested against the provided example cases and passes them successfully.
*/