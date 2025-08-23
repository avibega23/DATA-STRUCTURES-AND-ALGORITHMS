class MyStack {
    public:
        queue<int>q;
        MyStack() {
            q = {};
        }
        
        void push(int x) {
            int s = q.size();
            q.push(x);
            for(int i = 0;i<s;i++)
            {
                q.push(q.front());
                q.pop();
            }
        }
        
        int pop() {
            int top = q.front();
            q.pop();
            return top;
        }
        
        int top() {
            return q.front();
        }
        
        bool empty() {
            return q.empty();
        }
    };
    
    /**
     * Your MyStack object will be instantiated and called as such:
     * MyStack* obj = new MyStack();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->top();
     * bool param_4 = obj->empty();
     */




     //optimal approach

     class MyQueue {
        public:
            stack<int>st;
            stack<int>st1;
            MyQueue() {
                st = {};
                st1 = {};
            }
            
            void push(int x) {
                
                    if(st.empty())
                    {
                        st.push(x);
                        return;
                    }
                    else
                    {
                        while(!st.empty())
                        {
                            st1.push(st.top());
                            st.pop();
                        }
                        st.push(x);
                        while(!st1.empty())
                        {
                            st.push(st1.top());
                            st1.pop();
                        }
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
        };
        
        /**
         * Your MyQueue object will be instantiated and called as such:
         * MyQueue* obj = new MyQueue();
         * obj->push(x);
         * int param_2 = obj->pop();
         * int param_3 = obj->peek();
         * bool param_4 = obj->empty();
         */



         // most optimal code


         class MyQueue {
            public:
                stack<int>st;
                stack<int>st1;
                MyQueue() {
                    st = {};
                    st1 = {};
                }
                
                void push(int x) {
                    
                        if(st.empty())
                        {
                            st.push(x);
                            return;
                        }
                        else
                        {
                            while(!st.empty())
                            {
                                st1.push(st.top());
                                st.pop();
                            }
                            st.push(x);
                            while(!st1.empty())
                            {
                                st.push(st1.top());
                                st1.pop();
                            }
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
            };
            
            /**
             * Your MyQueue object will be instantiated and called as such:
             * MyQueue* obj = new MyQueue();
             * obj->push(x);
             * int param_2 = obj->pop();
             * int param_3 = obj->peek();
             * bool param_4 = obj->empty();
             */