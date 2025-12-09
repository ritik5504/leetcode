class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        long long ans = 0;

        unordered_map<long long, long long> leftFreq, rightFreq;

        for (auto x : nums) rightFreq[x]++;

        for (int j = 0; j < nums.size(); j++) {
            rightFreq[nums[j]]--;

            long long target = nums[j] * 2;
            ans = (ans + leftFreq[target] * rightFreq[target]) % MOD;

            leftFreq[nums[j]]++;
        }

        return ans;
    }
};
