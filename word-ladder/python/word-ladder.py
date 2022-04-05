class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        adj_list = {}
        for word in wordList:
            if word == beginWord: continue
            for i in range(len(word)):
                new_word = word[0:i] + "*" + word[i+1:]
                if new_word not in adj_list:
                    adj_list[new_word] = [word]
                else:
                    adj_list[new_word].append(word)
        
        bfs_queue = deque([(beginWord, 1)])
        result = 0
        visited = {beginWord: True}
        
        while bfs_queue:
            for i in range(len(bfs_queue)):
                current_word, level = bfs_queue.popleft()
                
                if current_word == endWord:
                    return level
                
                for i in range(len(current_word)):
                    new_word = current_word[0:i] + "*" + current_word[i+1:]
                    if new_word in adj_list:
                        for word in adj_list[new_word]:
                            if word not in visited:
                                bfs_queue.append((word, level + 1))
                                visited[word] = True
        return 0