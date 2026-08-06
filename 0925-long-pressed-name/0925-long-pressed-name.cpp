class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0; int j=0;
    
        while(i<name.size() && j<typed.size()){
            if(name[i]==typed[j]){
                i++;
                j++;
            }
            while(j>=1 && typed[j] == typed[j-1] && typed[j]!=name[i]){
                j++;
            }
            if(name[i] !=typed[j] && j>=1 && typed[j]!=typed[j-1]){
                return false;
            }
            if(name[i] != typed[j]) return false;
        }
        return true;
    }
};