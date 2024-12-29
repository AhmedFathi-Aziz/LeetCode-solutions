class MyQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int ret = stack2.top();
        stack2.pop();
        return ret;
    }
    
    int peek() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }
    
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};
