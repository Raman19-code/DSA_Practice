#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Step 1: reverse the whole string
        int i = 0, j = s.size() - 1;
        while (i < j) swap(s[i++], s[j--]);

        // Step 2: reverse each word
        i = 0;
        while (i < s.size()) {
            if (s[i] == ' ') { i++; continue; }
            int start = i;
            while (i < s.size() && s[i] != ' ') i++;
            int end = i - 1;
            while (start < end) swap(s[start++], s[end--]);
        }

        // Step 3: remove extra spaces
        string ans;
        i = 0;
        while (i < s.size()) {
            while (i < s.size() && s[i] == ' ') i++; // skip spaces
            if (i >= s.size()) break;
            int j = i;
            while (j < s.size() && s[j] != ' ') j++;
            if (!ans.empty()) ans += ' ';
            ans += s.substr(i, j - i);
            i = j;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    string result = sol.reverseWords(s);
    cout << "Reversed words: " << result << endl;

    return 0;
}
