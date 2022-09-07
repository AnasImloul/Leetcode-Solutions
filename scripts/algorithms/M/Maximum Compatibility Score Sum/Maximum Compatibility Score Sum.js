// Runtime: 239 ms (Top 46.15%) | Memory: 42.4 MB (Top 84.62%)
var maxCompatibilitySum = function(students, mentors) {
    const m = students.length;
    const n = students[0].length;

    let max = 0;

    dfs(0, (1 << m) - 1, 0);

    return max;

    function dfs(studentIdx, bitmask, scoreTally) {
        if (studentIdx === m) {
            max = Math.max(max, scoreTally);

            return;
        }

        for (let mentorIdx = 0; mentorIdx < m; ++mentorIdx) {
            if (bitmask & (1 << mentorIdx)) {
                const matchScore = hammingDistance(students[studentIdx], mentors[mentorIdx]);
                const setMask = bitmask ^ (1 << mentorIdx);

                dfs(studentIdx + 1, setMask, scoreTally + matchScore);
            }
        }

        return;
    }

    function hammingDistance(studentsAnswers, mentorsAnswers) {
        let matches = 0;

        for (let j = 0; j < n; ++j) {
            if (studentsAnswers[j] === mentorsAnswers[j]) ++matches;
        }

        return matches;
    }
};