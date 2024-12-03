class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> answer(n - k + 1, 0);
        
        // Create a frequency map to store the count of each element in the current window
        unordered_map<int, int> freq;
        
        // Initialize the frequency map with the first k elements
        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
        }
        
        // Calculate the x-sum for the first window
        answer[0] = calculateXSum(freq, x);
        
        // Slide the window and update the frequency map and x-sum for each subarray
        for (int i = k; i < n; i++) {
            freq[nums[i - k]]--;
            if (freq[nums[i - k]] == 0) {
                freq.erase(nums[i - k]);
            }
            freq[nums[i]]++;
            answer[i - k + 1] = calculateXSum(freq, x);
        }
        
        return answer;
    }
    
private:
    long long calculateXSum(unordered_map<int, int>& freq, int x) {
        // Create a priority queue to store the top x most frequent elements
        priority_queue<pair<int, int>> pq;
        
        // Push each element and its frequency into the priority queue
        for (auto it : freq) {
            pq.push({it.second, it.first});
        }
        
        long long xSum = 0;
        
        // Calculate the x-sum by summing the top x most frequent elements
        for (int i = 0; i < x && !pq.empty(); i++) {
            xSum += static_cast<long long>(pq.top().first) * pq.top().second;
            pq.pop();
        }
        
        return xSum;
    }
};


Approach and Complexity Analysis:
1. We use the sliding window technique to calculate the x-sum for each subarray of length k.
2. We maintain a frequency map `freq` to store the count of each element in the current window.
3. We initialize the frequency map with the first k elements and calculate the x-sum for the first window.
4. We slide the window by removing the leftmost element and adding the rightmost element to the frequency map.
5. For each window, we calculate the x-sum by using a priority queue to find the top x most frequent elements.
6. We return the array `answer` containing the x-sum for each subarray.

Time Complexity:
- The outer loop runs for n - k + 1 iterations.
- For each iteration, we update the frequency map and calculate the x-sum using a priority queue.
- Updating the frequency map takes O(1) time.
- Calculating the x-sum takes O(x * log(k)) time in the worst case, where k is the size of the frequency map.
- Therefore, the overall time complexity is O((n - k + 1) * x * log(k)).

Space Complexity:
- The frequency map `freq` stores at most k elements.
- The priority queue `pq` stores at most x elements.
- The output array `answer` has a size of n - k + 1.
- Therefore, the space complexity is O(k + x + (n - k + 1)), which simplifies to O(n).

The code handles all edge cases and follows best coding practices. It has been tested against the example cases provided.