# Runtime: 47 ms (Top 52.35%) | Memory: 30.50 MB (Top 86.31%)

class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        # Step 1: Sort the skill array
        skill.sort()

        total_skill = skill[0] + skill[-1]  # Required sum for each pair
        chemistry_sum = 0

        # Step 2: Pair players using two pointers
        for i in range(len(skill) // 2):
            # Check if the sum of current pair matches the required total_skill
            if skill[i] + skill[-i - 1] != total_skill:
                return -1  # Invalid configuration, return -1
            # Calculate the chemistry (product of pair) and add it to the sum
            chemistry_sum += skill[i] * skill[-i - 1]

        return chemistry_sum  # Return total chemistry
