class MinStack {
public:
    stack<long long> st;
    long long min;
    MinStack() {
        min = LLONG_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            min = val;
            st.push(val);
        }
        else if( val > min) st.push(val);
        else {
            st.push(2LL*val-min);
            min = val;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        else{
            long long x = st.top();
            st.pop();
            if(x<min){
                min = 2LL*min - x;
            }
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long x = st.top();
        if(min<x) return x;
        return min;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */