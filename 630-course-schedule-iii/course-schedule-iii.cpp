class Solution {
private:
    static bool compare(vector<int>a, vector<int>b){
        return a[1] < b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int>q;
        sort(courses.begin(),courses.end(), compare);
        int total_duration = 0;
        for(int i = 0; i < courses.size(); i++){
            int current_duration = courses[i][0];
            int finish_time = courses[i][1];

            q.push(current_duration);
            total_duration += current_duration;
            if(total_duration > finish_time){
                total_duration = total_duration - q.top();
                q.pop();
            }
        }
        
        return q.size();
    }
};