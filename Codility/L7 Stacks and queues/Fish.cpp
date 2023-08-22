#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int solution(vector<int>& A, vector<int>& B) {
    if (A.size() == 0)
        return 0;
    stack<int> st;
    int numAlive = A.size();
    for (int i = 0; i < A.size(); i++) {
        if (B[i] == 1) {
            st.push(A[i]); 
        }
        if (B[i] == 0) {
            while (!st.empty()) {
                if (st.top() > A[i]) {
                    numAlive--;
                    break;      
                }
                else if (st.top() < A[i]) {
                    numAlive--;
                    st.pop();   
                }
            }
        }
    }
    cout << numAlive;
    return numAlive;
}
int main()
{
    vector <int> vec1 = { 4, 3, 2, 1, 5 };
    vector <int> vec2 = { 0, 1, 0, 0, 0 };
    solution(vec1, vec2);
}