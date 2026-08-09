class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        double ans=0;
        int i=0;
        int j=0;
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());
        while(i<prices.size() && j<discounts.size()){
            int p=prices[i];
            int d=discounts[j];
            double fp= (double) (p* (100-d))/ (double) 100;
            ans+=fp;
            i++;
            j++;
        }
        while(i<prices.size()){
            ans+=double(prices[i]);
            i++;
        }
        return ans;
    }
};