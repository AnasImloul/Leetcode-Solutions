// Runtime: 1 ms (Top 98.48%) | Memory: 42.5 MB (Top 63.64%)
class Solution {
    public int maximumGood(int[][] statements) {
        int[] result = { 0 };
        maximumGood(statements, new boolean[statements.length], 0, 0, result);
        return result[0];
    }

    /*
        This function uses backtracking to do the DFS. We are basically constructing all possible scenarios and verifying them.

        statements (int[][]): This is the input statements.
        goodPeople (boolean[]): This array tells who are good and bad in the group.
        currentPerson (int): This is the current person that we are verifying.
        currentGoodPeople (int): This is the number of the good people identified so far.
        result (int[]): This array holds the result, the total number of good people.
    */
    private void maximumGood(int[][] statements, boolean[] goodPeople, int currentPerson, int currentGoodPeople, int[] result) {
        if (currentPerson == goodPeople.length) {
            result[0] = Math.max(result[0], currentGoodPeople);
            return;
        }

        // Now we are going to use backtracking to do DFS.

        // Scenario 1: Assume the current person is good and verify it.
        goodPeople[currentPerson] = true;
        // Prune the tree if the sum of unverified people (goodPeople.length - currentPerson) and verifyied good people (currentGoodPeople) is less than the result.
        if (goodPeople.length - currentPerson + currentGoodPeople < result[0]) {
            return;
        }
        if (isValid(statements, goodPeople, currentPerson)) {
            maximumGood(statements, goodPeople, currentPerson + 1, currentGoodPeople + 1, result);
        }

        // Scenario 2: Assume the current person is bad and verify it.
        goodPeople[currentPerson] = false;
        // Prune the tree for the same reason mentioned earlier.
        if (goodPeople.length - currentPerson - 1 + currentGoodPeople < result[0]) {
            return;
        }
        if (isValid(statements, goodPeople, currentPerson)) {
            maximumGood(statements, goodPeople, currentPerson + 1, currentGoodPeople, result);
        }

        return;
    }

    private boolean isValid(int[][] statements, boolean[] goodPeople, int currentPerson) {
        // To verify if the current assumption of good/bad people is correct, we need to do 2 things.
        // 1. We need to verify the statements from all processed good people. What they said about the current person should be correct.
        for (int i = 0; i < currentPerson; ++i) {
            if (goodPeople[i]) {
                if (goodPeople[currentPerson] && statements[i][currentPerson] == 0) {
                    return false;
                }
                if (!goodPeople[currentPerson] && statements[i][currentPerson] == 1) {
                    return false;
                }
            }
        }

        // 2. We need to verify the statement from the current person if he is good. What he said about other people should be correct.
        if (goodPeople[currentPerson]) {
            for (int i = 0; i < currentPerson; ++i) {
                if (goodPeople[i] && statements[currentPerson][i] == 0) return false;
                if (!goodPeople[i] && statements[currentPerson][i] == 1) return false;
            }
        }

        return true;
    }
}