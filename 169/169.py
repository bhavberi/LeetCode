class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        d = dict()
        for i in nums:
            if i in d.keys():
                d[i]+=1
            else:
                d[i]=1
        for i in d:
            if d[i] > len(nums)/2:
                return i
        return 0
