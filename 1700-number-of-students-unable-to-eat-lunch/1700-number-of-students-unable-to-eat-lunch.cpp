class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int>ss;
        queue<int>sq;
        int n=students.size();
        for(int i=0;i<n;i++){
            ss.push(sandwiches[n-1-i]);
            sq.push(students[i]);
        }
        int ls=0;
        while(!sq.empty() && ls<sq.size()){
            if(sq.front()==ss.top()){
                ss.pop();
                sq.pop();
                ls=0;
            }else{
                sq.push(sq.front());
                sq.pop();
                ls++;
            }
        }
        return sq.size();
    }
};