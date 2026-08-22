class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        int n = word.length();
        string result;
        int longestPossible = n - (numFriends - 1);
        for (int i =0; i < n; i++){
            int canTakeLength = min(longestPossible,n-i);
            result = max(result, word.substr(i, canTakeLength));
        }
        return result;
    }
};