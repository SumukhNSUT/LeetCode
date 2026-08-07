class Solution {
    bool isCoPrime(double num, double den){
        int n=num; 
        int d=den;
        for(int i=2; i<=n; i++){
            if(n%i == 0 && d%i == 0) return false;
        }
        return true;
    }
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for(int den=1; den<=n; den++){
            for(int num=1; num<den; num++){
                double f= (double)num/den;
                // cout << f << endl;
                if(f<1 && f>0 && isCoPrime(num,den)){
                    string str=to_string(num)+"/"+to_string(den);
                    ans.push_back(str);
                }
            }
        }
        return ans;
    }
};