class Solution {
public:
    int minOperations(string s1, string s2) {
        int n=s1.size();
        int res=0;
        for(int i=n-1; i>=0; i--){
            if(s2[i]==s1[i]){
                continue;
            }else{
                if(s1[i]=='1'){
                    if((i-1)>=0 && s1[i-1]=='1'){
                        res++;
                        s1[i]='0';
                        s1[i-1]='0';
                    }else if(i-1<0 && i+1<n){
                        res+=2;
                        s1[i]='0';

                    }else if(i-1<0) return -1;
                    else{
                        res+=2;
                        s1[i]='0';
                    }
                }
                else {
                    res++;
                    s1[i]='1';
                }
            }
        }
        return res;
    }
};