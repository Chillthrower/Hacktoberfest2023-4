#include <iostream>
#include <string>

class Solution {
public:
    int maxVowels(std::string s, int k) {
        int n = s.size();
        int max_num = 0;
        int b = 0; // Count of vowels within the current window

        // Initialize the count of vowels within the first window of size k
        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                b++;
            }
        }
        max_num = b; // Initialize the maximum count

        // Move the window to the right and update the count
        for (int i = k; i < n; i++) {
            if (s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u') {
                b--;
            }
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                b++;
            }
            max_num = std::max(max_num, b);
        }

        return max_num;
    }
};

int main() {
    Solution solution;

    std::string s = "leetcode";
    int k = 3;

    int maxVowelsCount = solution.maxVowels(s, k);

    std::cout << "Maximum number of vowels in a substring of size " << k << " is: " << maxVowelsCount << std::endl;

    return 0;
}
