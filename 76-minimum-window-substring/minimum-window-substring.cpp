class Solution {
public:
    string minWindow(string s, string t) {
        // Check if string t is empty
        if (t == "") {
            return "";
        }

        // Initialize a map to store the count of characters in t
        unordered_map<char, int> t_counter, window;

        // Count the occurrences of characters in t
        for (auto x : t) {
            t_counter[x] = 1 + t_counter[x];
        }

        int have = 0;           // Number of distinct characters in t that are currently in the window
        int need = t_counter.size();   // Total number of distinct characters in t
        int ans_size = INT_MAX;   // Length of the minimum window substring
        vector<int> ans;          // Start and end indices of the minimum window substring
        int left = 0;             // Left pointer of the sliding window

        // Iterate through the string s using the right pointer
        for (int right = 0; right < s.size(); right++) {
            window[s[right]] = 1 + window[s[right]];

            // Check if the character in s is a part of string t, and if its count in the window becomes equal to its count in t
            if (t_counter.find(s[right]) != t_counter.end() && window[s[right]] == t_counter[s[right]]) {
                have++;
            }

            // When a valid window is found (contains all characters from t), move the left pointer to find a smaller window
            while (have == need) {
                // Update the minimum window information if the current window is smaller
                if ((right - left + 1) < ans_size) {
                    ans = {left, right};
                    ans_size = right - left + 1;
                }

                // Decrease the count of the character going out of the window
                window[s[left]] -= 1;

                // If the character is a part of string t and its count in the window becomes less than its count in t, decrease the have count
                if (t_counter.find(s[left]) != t_counter.end() && window[s[left]] < t_counter[s[left]]) {
                    have--;
                }

                // Move the left pointer to shrink the window
                left++;
            }
        }

        // Check if a valid minimum window was found and return the substring
        return ans_size != INT_MAX ? s.substr(ans[0], ans[1] - ans[0] + 1) : "";
    }
};