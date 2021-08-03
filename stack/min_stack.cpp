class MinStack {

    int stack_[10000];
    int min_[10000];
    int topPtr, minPtr;
public:
    /** initialize your data structure here. */
    MinStack()
    {
        topPtr = -1;
        minPtr = -1;
    }
    void push(int x)
    {
        if(topPtr >= 10000){
            return;
        }

        stack_[++topPtr] = x;

        if(minPtr >= 0){
            if(min_[minPtr] > x){
                min_[++minPtr] = x;
            }else{
                min_[minPtr+1] = min_[minPtr];
                minPtr += 1;
            }
        }
        else{
            min_[++minPtr] = x;
        }
    }

    void pop(){
        if(topPtr < 0){
            return;
        }

        topPtr--;
        minPtr--;
    }

    int top(){
        return stack_[topPtr];
    }

    int getMin(){
        return min_[minPtr];
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
