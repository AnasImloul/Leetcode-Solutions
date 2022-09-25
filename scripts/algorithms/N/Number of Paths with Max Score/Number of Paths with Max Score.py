# Runtime: 321 ms (Top 53.09%) | Memory: 26.5 MB (Top 8.64%)
class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:

        ## Basic information: height and width of board
        h, w = len(board), len(board[0])

        # ----------------------------------------------------------------------------

        # Use pathon native cahce as memoization for DP
        @cache
        def visit(i, j):

            if i == h-1 and j == w-1:
                ## Base case:

                # score for start coordinate = 0
                # paht count for start coordinate = 1
                return 0, 1

            elif i >= w or j >= h or board[i][j] == 'X':

                ## Base case:
                # Out-of-boundary, or meet obstacle
                return 0, 0

            ## General case:
            # update from three possible preivous moves from right, down, and diagonal

            right_score, right_path_count = visit(i, j+1)
            down_score, down_path_count = visit(i+1, j)
            diag_score, diag_path_count = visit(i+1, j+1)

            max_prevScore = max(right_score, down_score, diag_score)

            cur_path_count = 0
            cur_score = int(board[i][j]) if board[i][j] != "E" else 0

            if right_score == max_prevScore : cur_path_count += right_path_count
            if down_score == max_prevScore : cur_path_count += down_path_count
            if diag_score == max_prevScore : cur_path_count += diag_path_count

            return max_prevScore + cur_score, cur_path_count
        # ----------------------------------------------------------------------------

        ## Remark: Remember to take modulo by constant, this is defined by description
        CONST = 10**9 + 7
        maxScore, validPathCount = visit(0, 0)

        return [maxScore % CONST, validPathCount % CONST] if validPathCount else [0, 0]