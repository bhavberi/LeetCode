class Solution:
    def maxSlidingWindow(self, array: List[int], k: int) -> List[int]:
        arr = list()
        dq = list()
        for i in range(len(array)):
            if len(dq) != 0 and dq[0] == i-k:
                dq.pop(0);
            while len(dq) != 0 and array[dq[-1]] < array[i]:
                dq.pop();
            dq.append(i)
            
            if i>= k-1:
                arr.append(array[dq[0]])
        return arr
