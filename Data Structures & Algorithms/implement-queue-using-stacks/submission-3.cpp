class MyQueue {
private:
    stack<int>st;
public:

    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        if(st.empty()){
            return -1;
        }
        int x = st.top();
        st.pop();
        if(st.empty()){
            return x;
        }
        int res = pop();
        st.push(x);
        return res;
    }
    
    int peek() {
        if (st.empty()) return -1;

        int x = st.top();
        st.pop();

        if (st.empty()) {
            st.push(x);  // Important fix
            return x;
        }

        int res = peek();
        st.push(x);
        return res;
    }

    bool empty() {
        return st.empty();
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