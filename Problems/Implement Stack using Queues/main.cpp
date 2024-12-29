class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        int len = q.size();
        q.push(x);
        for (int i = 0; i < len; i++) {
            int num = q.front();
            q.pop();
            q.push(num);
        }
    }
    
    int pop() {
        int num = q.front();
        q.pop();
        return num;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

