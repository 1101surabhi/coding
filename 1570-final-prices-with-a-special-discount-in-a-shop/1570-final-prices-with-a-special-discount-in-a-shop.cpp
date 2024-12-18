class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> answer ;
        for(int i=0; i<prices.size();i++){
            int discount = prices[i] ;
            int j = i+1;
            while(j < prices.size() && prices[j]>prices[i]) j++ ;
            if (j < prices.size() && prices[j] <= prices[i]) discount = prices[i] - prices[j] ;
            answer.push_back(discount) ;
        }
        return answer ;
    }
};