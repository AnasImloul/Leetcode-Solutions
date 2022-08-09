class Solution:
    def minNumberOfSemesters(self, n: int, relations: List[List[int]], k: int) -> int:
        graph = [0] * n
        out_degree = [0] * n
        # -1 to fix 1-based indexing offset from prompt.
        for pre_req, course in relations:
            graph[course-1] += 1 << (pre_req-1)
            out_degree[pre_req-1] += 1
        # Just converts course to its shifted value
        c2shift = [1<<course for course in range(n)]
        start = 0
        goal = 2**n-1  # will eq course_total once all have been taken.
        queue = collections.deque([(start,0)])
        seen = [0] * (2 ** n)

        # Similar to Bellman-Ford
        while queue:
            # course_total is state. Each bit representing a taken course.
            course_total, steps = queue.popleft()
            available = []
            for course_num in range(n):
                if (course_total & graph[course_num] == graph[course_num]) \
                            and (course_total & c2shift[course_num] == 0):
                    available.append(course_num)

            # pre_req courses can unlock others.
            pre_reqs = [c2shift[course_num] for course_num in available if out_degree[course_num]]
            leaves = [c2shift[course_num] for course_num in available if out_degree[course_num] == 0] 
            
            # We only include leaf courses when we have extra space
            if len(pre_reqs) <= k:
                course_total += sum(pre_reqs) + sum(leaves[:k-len(pre_reqs)])
                if course_total == goal:
                    return steps + 1
                if not seen[course_total]:
                    queue.append((course_total,steps+1))
                    seen[course_total] = 1
            else:
                # Trying every combination of the pre_reqs.
                # comb is required here because we can't simply take them all (len(pre_reqs) > k)
                for batch in itertools.combinations(pre_reqs, k):
                    diff = sum(batch)
                    t = course_total + diff
                    if t == goal:
                        return steps + 1
                    if not seen[t]:
                        queue.append((t, steps+1))
                        seen[t] = 1![Uploading file...]()

