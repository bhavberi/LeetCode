class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i=0
        while i<len(nums):
        # for i in range(len(nums)):
            if nums[i] in nums[i+1:]:
                nums.remove(nums[i])
            else:
                i+=1

