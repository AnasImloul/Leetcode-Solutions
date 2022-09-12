// Runtime: 7 ms (Top 34.04%) | Memory: 8.7 MB (Top 65.50%)
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int size = students.size();
        queue<int> student_choice;
        for(int i = 0 ; i < size ; ++i){
            student_choice.push(students[i]);
        }
        int rotations = 0 , i = 0;
        while(student_choice.size() && rotations < student_choice.size()){
            if(student_choice.front() == sandwiches[i]){
                student_choice.pop();
                i++;
                rotations = 0;
            } else {
                int choice = student_choice.front();
                student_choice.pop();
                student_choice.push(choice);
                rotations++;
            }
        }
        return student_choice.size();
    }
};