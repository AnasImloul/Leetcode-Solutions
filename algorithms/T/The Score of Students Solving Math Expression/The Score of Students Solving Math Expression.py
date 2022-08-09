class Solution:

    def scoreOfStudents(self, s: str, answers: List[int]) -> int:
        correct_ans = eval(s)
        standard_form = []
        for x in s:
            if x == '+':
                standard_form.append(0)
            elif x == '*':
                standard_form.append(1)
            else:
                standard_form.append(int(x))

        @lru_cache(None)
        def divide_and_conquer(equation: Tuple[int]) -> Set[int]:
            if len(equation) == 1:
                return {equation[0]}

            if len(equation) == 3:
                if equation[1] == 0:  # Add
                    return {equation[0] + equation[-1]}
                else:  # Multiply
                    return {equation[0] * equation[-1]}

            my_answers = set()
            for split_point in range(1, len(equation), 2):
                left_answers = divide_and_conquer(equation[:split_point])
                right_answers = divide_and_conquer(equation[split_point + 1:])

                if equation[split_point] == 0:  # Add
                    my_answers |= {x + y for x in left_answers for y in right_answers if x + y <= 1000}
                else:  # Multiply
                    my_answers |= {x * y for x in left_answers for y in right_answers if x * y <= 1000}

            return my_answers

        incorrect_answers = divide_and_conquer(tuple(standard_form))
        total_grade = 0
        for x in answers:
            if x == correct_ans:
                total_grade += 5
            elif x in incorrect_answers:
                total_grade += 2
        return total_grade
