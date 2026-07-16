class Solution {
    bool fn(string word, string root){
        int j=0; int i=0;
        while(i<word.size() && j<root.size()){
            if(root[j] != word[i]) return false;
            i++;
            j++;
        }
        return j==root.size();
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> words;
        sort(dictionary.begin(), dictionary.end());
        int n=sentence.size();
        string word="";
        for(int i=0; i<=n-1; i++){
            if(sentence[i] == ' '){
                words.push_back(word);
                word="";
            }else{
                word+=sentence[i];
            }
        }
        if(word != "") words.push_back(word);
        //check for root of each word
        vector<string> ans;
        for(auto it: words){
            string word=it;
            bool ok=false;
            for(auto root: dictionary){
                if(fn(word,root)){ //'root' is root of word or not
                    ok=true;
                    ans.push_back(root);
                    break;
                }
            }
            if(!ok) ans.push_back(word);
        }
        string res="";
        for(int i=0; i<ans.size()-1; i++){
            res+=ans[i];
            res+=" ";
        }
        res+=ans[ans.size()-1];
        return res;
    }
};