class TaskManager {
public: 
    priority_queue<pair<int,int>> maxH; // {priority, taskId}
    unordered_map<int,int> task_user;   // taskId -> user
    unordered_map<int,int> task_priority; // taskId -> priority

    TaskManager(vector<vector<int>>& tasks) {
        for(auto &t : tasks) {
            int user = t[0];
            int taskId = t[1];
            int priority = t[2];

            maxH.push({priority, taskId});
            task_user[taskId] = user;
            task_priority[taskId] = priority;
        }
    }
    
    void add(int userId, int taskId, int priority) {
        maxH.push({priority, taskId});
        task_user[taskId] = userId;
        task_priority[taskId] = priority;
    }
    
    void edit(int taskId, int newPriority) {
        task_priority[taskId] = newPriority;
        maxH.push({newPriority, taskId}); // push updated version
    } 
    
    void rmv(int taskId) {
        task_user.erase(taskId);
        task_priority.erase(taskId);
    }
    
    int execTop() {
        while(!maxH.empty()) {
            auto [priority, id] = maxH.top();
            maxH.pop();

            // check if valid
            if(task_priority.count(id) && task_priority[id] == priority) {
                int user = task_user[id];

                task_user.erase(id);
                task_priority.erase(id);

                return user;
            }
        }
        return -1;
    }
};
/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
