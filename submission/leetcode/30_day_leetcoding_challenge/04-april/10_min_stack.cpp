// time O(n) | space O(n)

class MinStack {
public:
    /** initialize your data structure here. */
    stack <int> s;
    stack <int> minStack;
    MinStack() {
        while(not s.empty()) s.pop();
        while(not minStack.empty()) minStack.pop();
        
        s.push(INT_MAX);
        minStack.push(INT_MAX);
    }
    
    void push(int x) {
        s.push(x);
        minStack.push(min(x, minStack.top()));
    }
    
    void pop() {
        s.pop();
        minStack.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */