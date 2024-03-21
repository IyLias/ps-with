class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        colors = [0] * n

        for start in range(n):
            if colors[start] != 0:
                continue
            
            queue = deque([start])
            colors[start] = 1

            while queue:
                node = queue.popleft()

                for neighbor in graph[node]:
                    if colors[neighbor] == 0:
                        colors[neighbor] = -colors[node]
                        queue.append(neighbor)
                    elif colors[neighbor] == colors[node]:
                        return False
        
        return True