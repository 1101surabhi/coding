class Solution {
public:
    void solve(string digits, vector<string>& ans, string output, int i, string mapping[]){
        if (i >= digits.length()){
            ans.push_back(output) ;
            return ;
        }

        int digit = digits[i] - '0' ;
        string letters = mapping[digit] ;

        for (int j=0; j<letters.length(); j++){
            output.push_back(letters[j]) ;
            solve(digits, ans, output, i+1, mapping) ;
            output.pop_back() ;
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return {} ;
        vector<string> ans ;
        string output = "" ;
        int i = 0 ;
        string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"} ;
        solve(digits, ans, output, i, mapping) ;
        return ans ;
    }
};