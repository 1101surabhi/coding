class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false ;
        
        int count1[26] = {0}, count2[26] = {0} ;
        for (int i=0; i<s1.size(); i++){
            count1[s1[i]-'a']++ ; 
        }
        int wsize = s1.size() ;
        int i = 0 ;

        while (i<wsize){
            count2[s2[i]-'a']++ ;
            i++ ;
        }

        if (equal(count1, count2)) return true ;

        while (i < s2.size()){
            count2[s2[i]-'a']++ ;
            count2[s2[i-wsize]-'a']-- ;
            if (equal(count1, count2)) return true ;
            i++ ;
        }

        return false ;
    }

    bool equal(int a[26], int b[26]){
        for (int i=0; i<26; i++){
            if (a[i] != b[i]) return false ;
        }
        return true ;
    }
};