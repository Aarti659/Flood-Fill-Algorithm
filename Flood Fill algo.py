class Sol:
   def solve(self, mat, row, col, target):
      def dfs(j, k):
         if (
            j >= 0
            and j < len(mat)
            and k >= 0
            and k < len(mat[0])
            and (j, k) not in seen
            and mat[j][k] == old_color
         ):
            seen.add((j, k))
            mat[j][k] = target
            dfs(j + 1, k)
            dfs(j, k + 1)
            dfs(j, k - 1)
            dfs(j - 1, k)
      seen = set()
      old_color = mat[row][col]
      dfs(row, col)
      return mat
ob = Sol()
mat = [ ["m", "t", "s"], ["p", "k", "j"], ["a", "l", "w"] ]
row = 0
col = 0
target = "g"
print(ob.solve(mat, row, col, target))





