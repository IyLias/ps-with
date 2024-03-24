class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        visited = [False] * n

        nof_provinces = 0
        for i in range(n):
            if visited[i] == False:
                self.dfs(i, isConnected, visited)
                nof_provinces += 1


        return nof_provinces

    def dfs(self, c, isConnected, visited):
        n = len(isConnected)
        visited[c] = True

        for i in range(n):
            if isConnected[c][i] == 1 and visited[i] == False:
                self.dfs(i,isConnected, visited)