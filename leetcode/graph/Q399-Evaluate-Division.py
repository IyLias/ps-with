class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        var_graph = {}

        for (start, end), value in zip(equations, values):
            self.add_edge(var_graph, start, end, value)
            self.add_edge(var_graph, end, start, 1 / value)

        results = []
        # now answer the queries
        for (start, end) in queries:
            result = self.eval_queries(var_graph, start, end)
            results.append(result)

        return results

    def add_edge(self, graph, start, end, value):
        if start in graph:
            graph[start][end] = value
        else:
            graph[start] = {end: value}

    def eval_queries(self, graph, start, end):

        if start in graph and end in graph and start == end:
            return 1.0
        elif start in graph and end in graph:
            return self.dfs(graph, start, end, set(), 1.0)
        else:
            return -1.0

    def dfs(self, graph, start, end, visited, value):

        if start == end:
            return value
        visited.add(start)

        for neighbor, weight in graph.get(start, {}).items():
            if neighbor not in visited:
                result = self.dfs(graph, neighbor, end, visited, value * weight)
                if result != -1:
                    return result

        return -1.0