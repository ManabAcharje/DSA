class Solution:
    def minMoves(self, nums: list[int]) -> int:
        # nums.sort()
        ans = 0
        mini = 2**31-1
        for i in range(len(nums)):
            ans += nums[i]
            mini = min(mini,nums[i])
        return ans - len(nums)*mini