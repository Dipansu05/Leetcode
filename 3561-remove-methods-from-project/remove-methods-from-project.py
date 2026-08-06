class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:

        adj = [[] for _ in range(n)]
        indegree=[0]*n
        suspicious = [False]*n
        for u, v in invocations:
            adj[u].append(v)
            indegree[v] += 1

        queue = deque([k])
        suspicious[k] = True

        while queue:
            curr = queue.popleft()
            for neighbor in adj[curr]:
                indegree[neighbor] -= 1

                if not suspicious[neighbor]:
                    suspicious[neighbor] = True
                    queue.append(neighbor)

        result = []
        cannot_remove = False

        for i in range(n):
            if suspicious[i] and indegree[i] > 0:
                cannot_remove = True
                break

            if not suspicious[i]:
                result.append(i)

        if cannot_remove:
            return list(range(n))

        return result

        