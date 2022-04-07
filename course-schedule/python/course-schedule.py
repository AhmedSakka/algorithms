class Solution(object):
    def DFS(self, node, adj_list, visited, path):
        if node in path:
            return True
        if node in visited:
            return False
        if node not in adj_list:
            return False
        
        res = False
        path.add(node)
        
        for n in adj_list[node]:
            res = self.DFS(n, adj_list, visited, path)
            if res:
                break
        
        visited.add(node)
        path.remove(node)
        return res
    
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        adj_list = {}
        visited = set()
        path = set()
        for p in prerequisites:
            if p[1] not in adj_list:
                adj_list[p[1]] = []
            adj_list[p[1]].append(p[0])
        
        for i in range(numCourses):
            res = self.DFS(i, adj_list, visited, path)
            if res:
                return False
        
        return True