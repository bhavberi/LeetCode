class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if target not in nums:
            return [-1,-1]
        l = [nums.index(target),nums.index(target)]
        for i in range(l[0]+1,len(nums)):
            if target == nums[i]:
                l[1]+=1
        return l
