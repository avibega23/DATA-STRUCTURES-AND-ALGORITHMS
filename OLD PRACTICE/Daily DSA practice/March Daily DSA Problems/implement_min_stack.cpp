class MinStack {
    public:
        stack<long long>st;
        long long mini = LLONG_MAX;
    
        MinStack(){
            st = {};
            mini = LLONG_MAX;
        }
        
        void push(int val) {
            if(st.empty())
            {
                st.push(val);
                mini = val;
            }
            else
            {
                if(val < mini)
                {
                    long long x = 2*(long long)val-mini;
                    st.push(x);
                    mini = val;
                }
                else
                {
                    st.push(val);
                }
            }
        }
        
        void pop() {
            if(st.top()<mini)
            {
                long long x = 2*mini-st.top();
                mini = x;
                st.pop();
            }
            else
            {
                st.pop();
            }
        }
        
        int top() {
            if(st.top()<mini)
            {
                return mini;
            }
                return st.top();
        }
        
        int getMin() {
            return mini;
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