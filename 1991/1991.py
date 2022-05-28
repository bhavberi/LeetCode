class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        if len(nums)==1:
            return 0
        left = [0,]
        right = [0,]
        sum=nums[0]
        for i in nums[1:]:
            left.append(sum)
            sum+=i
        sum=nums[-1]
        for i in nums[-2:0:-1]:
            right = [sum,]+right
            sum+=i
        right = [sum,]+right
        # print(left,right)
        for i in range(len(nums)):
            if left[i]==right[i]:
                return i
        return -1
