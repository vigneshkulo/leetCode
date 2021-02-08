class Solution:
    def multiply(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        
        def pack(matrix):
            memo = {}
            
            for row in range(len(matrix)):
                for col in range(len(matrix[0])):
                    if (matrix[row][col] != 0):
                        memo[(row, col)] = matrix[row][col]
            
            return memo
        
        a_matrix = pack(A)
        b_matrix = pack(B)
        
        output = [[0 for col in range(len(B[0]))] for row in range(len(A))]
        for (row, col) in a_matrix:
            for k in range(len(A[0])):
                if (col, k) in b_matrix:
                    output[row][k] += (a_matrix[(row, col)] * b_matrix[(col, k)])
        
        return output
