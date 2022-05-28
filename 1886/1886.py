class Solution:
    def r1(matrix: List[List[int]]) -> None:
        for i in range(len(matrix)):
            for j in range(i,len(matrix)):
                matrix[i][j],matrix[j][i] = matrix[j][i],matrix[i][j]
        for i in matrix:
            i.reverse()
            
    def r2(matrix: List[List[int]]) -> None:
        for i in matrix:
            i.reverse()
        for i in range(len(matrix)):
            for j in range(i,len(matrix)):
                matrix[i][j],matrix[j][i] = matrix[j][i],matrix[i][j]
      
    def r3(matrix: List[List[int]]) -> None:
        for i in range(len(matrix)):
            for j in range(i,len(matrix)):
                matrix[i][j],matrix[j][i] = matrix[j][i],matrix[i][j]  
    
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        if mat == target:
            return True
        for i in range(4):
            Solution.r1(mat)
            if mat == target:
                return True
        return False
        

