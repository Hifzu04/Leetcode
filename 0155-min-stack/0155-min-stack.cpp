class MinStack {
public:
   stack<pair<int,int>>st;     //{num , min}
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()) {
            st.push({value , value});
        }else {
            int minm = min(st.top().second , value);
            st.push({value , minm});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        int topel = st.top().first;
        return topel;
    }
    
    int getMin() {
        int minel = st.top().second;
        return minel;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */