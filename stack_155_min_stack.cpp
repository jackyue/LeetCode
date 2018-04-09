/*************************************************************************************** 
 * 用两个stack结构解决该问题：element_stack执行正常的push/pop/top操作，min_val_stack用于
 * 维护element_stack操作数据过程中最小元素。
 * 时间复杂度O(n)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        if (min_val_stack.empty() || x <= min_val_stack.top()) {
            min_val_stack.push(x);
        }
        element_stack.push(x);
    }
    
    void pop() {
        if (!element_stack.empty()
                && !min_val_stack.empty()
                && element_stack.top() == min_val_stack.top()) {
            min_val_stack.pop();
        }
        if (!element_stack.empty()) {
            element_stack.pop();
        }
    }

    int top() {
        if (!element_stack.empty()) {
            return element_stack.top();
        }
    }
    
    int getMin() {
        if (!min_val_stack.empty()) {
            return min_val_stack.top();
        }
    }
private:
    std::stack<int> element_stack;
    std::stack<int> min_val_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
 