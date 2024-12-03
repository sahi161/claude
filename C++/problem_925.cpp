class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.length();
        int m = typed.length();
        
        // Edge case: if typed is shorter than name, it's not possible
        if (m < n) {
            return false;
        }
        
        int i = 0; // pointer for name
        int j = 0; // pointer for typed
        
        while (i < n && j < m) {
            if (name[i] == typed[j]) {
                // Characters match, move both pointers
                i++;
                j++;
            } else if (i > 0 && name[i-1] == typed[j]) {
                // Current character in typed is a long press of the previous character in name
                j++;
            } else {
                // Characters don't match and it's not a long press, return false
                return false;
            }
        }
        
        // Check if all characters in name have been matched
        if (i < n) {
            return false;
        }
        
        // Check if remaining characters in typed are long presses of the last character in name
        while (j < m) {
            if (typed[j] != name[n-1]) {
                return false;
            }
            j++;
        }
        
        return true;
    }
};

// Time Complexity: O(n), where n is the length of the typed string.
// We iterate through the typed string once.

// Space Complexity: O(1), as we only use a constant amount of extra space.

// Approach:
// 1. We use two pointers, i for name and j for typed, to compare the characters.
// 2. If the characters match, we move both pointers.
// 3. If the characters don't match, we check if the current character in typed is a long press of the previous character in name.
//    If it is, we move the j pointer. Otherwise, we return false.
// 4. After the loop, we check if all characters in name have been matched. If not, we return false.
// 5. Finally, we check if the remaining characters in typed are long presses of the last character in name.
//    If any character doesn't match, we return false. Otherwise, we return true.

// The solution handles edge cases such as typed being shorter than name and
// ensures that all characters in name are matched in the correct order.
// It optimizes for time and space complexity by using a linear scan with two pointers
// and avoids using any extra data structures.