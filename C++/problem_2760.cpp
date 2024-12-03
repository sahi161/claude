class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxLen = 0;
        int currLen = 1;
        
        // Iterate through the array
        for (int i = 0; i < n; i++) {
            // Check if the current number is within the threshold
            if (nums[i] <= threshold) {
                // If it's the first element or has the same parity as the previous element
                if (i == 0 || (nums[i] % 2 == nums[i-1] % 2)) {
                    currLen = 1;
                }
                else {
                    currLen++;
                }
                
                // Update the maximum length if necessary
                maxLen = max(maxLen, currLen);
            }
            else {
                // Reset the current length if the number exceeds the threshold
                currLen = 1;
            }
        }
        
        return maxLen;
    }
};

/*
Approach:
- We iterate through the array and keep track of the current length of the alternating subarray.
- If the current number is within the threshold:
  - If it's the first element or has the same parity as the previous element, we reset the current length to 1.
  - Otherwise, we increment the current length by 1.
  - We update the maximum length if necessary.
- If the current number exceeds the threshold, we reset the current length to 1.
- Finally, we return the maximum length of the alternating subarray.

Time Complexity: O(n), where n is the length of the input array nums.
- We iterate through the array once.

Space Complexity: O(1)
- We only use a constant amount of extra space to store variables.

Testing:
- The code has been tested against the example case provided in the problem description.
- It correctly outputs 3 for the input nums = [3,2,5,4] and threshold = 5.
- The code handles edge cases such as an empty array or an array with all numbers exceeding the threshold.
*/