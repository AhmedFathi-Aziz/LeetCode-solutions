class MinStack {
public:
    stack<pair<int, int>> stack;
    MinStack() {
        
    }
    
    void push(int val) {
        if (stack.empty())
            stack.push({val, val});
        else
            stack.push({val, min(stack.top().second, val)});
    }
    
    void pop() {
        stack.pop();
    }
    
    int top() {
        return stack.top().first;
    }
    
    int getMin() {
        return stack.top().second;
    }
};
