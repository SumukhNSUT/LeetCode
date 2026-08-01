class Solution {
public:
    string winningPlayer(int x, int y) {
        //x -> cnt of 75
        //y -> cnt of 10

        //total 115
        int cnt=0;
        while(x>=1 && y>=4){
            x--;
            y-=4;
            cnt++;
        }

        if(cnt%2 == 0) return "Bob";
        return "Alice";
    }
};