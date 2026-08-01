class Solution {
    bool fn(int s, int e, int p1, int p2, vector<int>& nums, bool flag) {
        //base case
        if (s > e) return p1>=p2;

        if (flag) {
            //player 1 turn
            bool left = fn(s + 1, e, p1 + nums[s], p2, nums, false);
            bool right = fn(s, e - 1, p1 + nums[e], p2, nums, false);
            return left || right;
        } else {
            //player 2 turn
            bool left = fn(s + 1, e, p1, p2 + nums[s], nums, true);
            bool right = fn(s, e - 1, p1, p2 + nums[e], nums, true);
            return left && right;
        }
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        return fn(0, n- 1, 0, 0, nums, true);
    }
};