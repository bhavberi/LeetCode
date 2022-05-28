class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        score1 = list(score)
        score1.sort(reverse = True)
        ans = list()
        for i in score:
            index = score1.index(i)+1
            if index==1:
                ans.append("Gold Medal")
            elif index==2:
                ans.append("Silver Medal")
            elif index==3:
                ans.append("Bronze Medal")
            else:
                ans.append(str(index))
        return ans

