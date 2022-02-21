#include <iostream>
#include <string>

using namespace std;

string mexp;
long long nums[1000000];
char ops[1000000];
int nums_size, ops_size;

void split_mexp() {
    int start = 0;
    int op_idx = 0;
    
    if (mexp[0] == '-') op_idx++;
    
    while (op_idx < mexp.size()) {
        while(op_idx < mexp.size() && mexp[op_idx] >= '0' && mexp[op_idx] <= '9') op_idx++;
        
        long long n = stoll(mexp.substr(start, op_idx - start));
        nums[nums_size++] = n;
        
        if (op_idx < mexp.size()) ops[ops_size++] = mexp[op_idx++];
        
        start = op_idx;
    }
}

long long calc(long long a, char op, long long b) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
    else return a / b;
}

int compare_operators(char op1, char op2) {
    if ((op1 == '*' || op1 == '/') && (op2 == '*' || op2 == '/')) return 0;
    if ((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-')) return 0;
    if (op1 == '*' || op1 == '/') return 1;
    else return -1;
}

long long solution() {
    if (ops_size == 0) return nums[0];
    
    int f_idx = 0;
    int b_idx = ops_size-1;
    
    long long front = calc(nums[f_idx], ops[f_idx], nums[f_idx+1]);
    long long back = calc(nums[b_idx], ops[b_idx], nums[b_idx+1]);
    
    while (f_idx < b_idx) {
        int comp_ops = compare_operators(ops[f_idx], ops[b_idx]);
        
        if (comp_ops > 0) {
            nums[++f_idx] = front;
            front = calc(nums[f_idx], ops[f_idx], nums[f_idx+1]);
        }
        else if (comp_ops < 0) {
            nums[b_idx--] = back;
            back = calc(nums[b_idx], ops[b_idx], nums[b_idx+1]);
        }
        else {
            if (front >= back){
                nums[++f_idx] = front;
                front = calc(nums[f_idx], ops[f_idx], nums[f_idx+1]);
            }
            else {
                nums[b_idx--] = back;
                back = calc(nums[b_idx], ops[b_idx], nums[b_idx+1]);
            }
        }
    }
    
    return calc(nums[f_idx], ops[f_idx], nums[f_idx+1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> mexp;
    
    split_mexp();
    
    cout << solution();
    
    return 0;
}
