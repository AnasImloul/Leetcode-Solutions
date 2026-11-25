# Runtime: 185 ms (Top 21.14%) | Memory: 19.20 MB (Top 54.36%)

from typing import List
from collections import defaultdict

class Solution:
    # Function to find high-access employees based on access times.
    def findHighAccessEmployees(self, access_times: List[List[str]]) -> List[str]:
        # Create a dictionary to store access times for each employee.
        when = defaultdict(list)

        # Populate the dictionary with access times from the input list.
        for v in access_times:
            a, b = v
            when[a].append(int(b))

        # List to store the names of high-access employees.
        ret = []

        # Iterate through the dictionary to check access patterns for each employee.
        for x, lst in when.items():
            # Sort the access times for each employee.
            lst.sort()

            # Get the number of access times for the current employee.
            k = len(lst)

            # Flag to indicate if the employee is a high-access employee.
            flag = False

            # Check for consecutive accesses within a 100-minute window.
            for i in range(k - 2):
                flag |= lst[i + 2] < lst[i] + 100

            # If the flag is true, the employee is considered high-access, and their name is added to the result.
            if flag:
                ret.append(x)

        # Return the list containing the names of high-access employees.
        return ret
