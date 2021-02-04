class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int weightSum = 0;
        for (int i = 0; i < stones.size(); i++) {
            weightSum += stones[i];
        }
        vector<int> dp = vector<int>(weightSum, 0);
        int target = weightSum / 2;
        for (int i = 0; i < stones.size(); i++) {
            for (int j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return weightSum - dp[target] - dp[target];
    }
};
