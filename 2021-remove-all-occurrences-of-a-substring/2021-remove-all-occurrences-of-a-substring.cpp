class Solution {
public:
    string removeOccurrences(string s, string part) {
        int i = 0;
        while (i < s.size()) {
            if (s[i] == part[0]) {
                bool isSub = true;
                for (int j = 0; j < part.size(); j++) {
                    if (s[i + j] != part[j]) {
                        isSub = false;
                        break;
                    }
                }
                if (isSub) {
                    s.erase(i, part.length());
                    i = 0;
                } else i++;
            }
            else i++ ;
        }
        return s;
    }
};