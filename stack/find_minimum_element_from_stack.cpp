#include<iostream>
#include<stack>
using namespace std;

int minimum_element;
stack <int> st;

void push_element(int item)
{
    if(st.size() == 0){
        st.push(item);
        minimum_element = item;
    }else{
        if(item > minimum_element){
            st.push(item);
        }
        else if(item <= minimum_element){
            st.push((2*item) - minimum_element);
            minimum_element = item;
        }
    }
}

int main()
{
    int data[] = {5,7,3,8,1,6,12,13};
    for(int i = 0; i < 8; i++){
        push_element(data[i]);
    }

    cout << minimum_element << endl;

    return 0;
}
