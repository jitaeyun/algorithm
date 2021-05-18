class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> st,t;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int n = peek();
        t.pop();
        return n;
    }
    
    /** Get the front element. */
    int peek() {
        if(!t.empty()) return t.top();
        while(!st.empty()){
            t.push(st.top());
            st.pop();
        }
        return t.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty()&&t.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */