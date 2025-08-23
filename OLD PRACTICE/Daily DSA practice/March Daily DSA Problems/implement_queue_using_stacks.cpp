class MyQueue {
    public:
        stack<int>st;
        MyQueue() {
            st = {};
        }
        
        void push(int x) {
            if(st.empty())
            {
                st.push(x);
            }
            else
            {
                solve(x);
            }
        }
        
        int pop() {
            int top = st.top();
            st.pop();
            return top;
        }
        
        int peek() {
            return st.top();
        }
        
        bool empty() {
            return st.empty();
        }
        void solve(int x)
        {
            if(st.empty())
            {
                st.push(x);
                return;
            }
            int top = st.top();
            st.pop();
            solve(x);
            st.push(top);
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