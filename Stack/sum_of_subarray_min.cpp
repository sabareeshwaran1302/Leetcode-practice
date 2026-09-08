/*
Problem Link: https://leetcode.com/problems/sum-of-subarray-minimums/
Problem 907: Sum of Subarray Minimums


1. We need the sum of minimums of all subarrays.
2. Instead of finding every subarray, take one element at a time and ask:
   In how many subarrays is this element the minimum?
3. For every arr[i], find:
   - left[i] = nearest smaller element on the left
   - right[i] = nearest smaller element on the right
4. We use a stack to find these quickly:
   - Left → remove >=
   - Right → remove >
5. If no smaller element exists:
   - left → -1
   - right → n
6. Calculate how many subarrays can use arr[i] as minimum:
leftChoices = i - left[i];
rightChoices = right[i] - i;

numberOfSubarrays = leftChoices * rightChoices;
7. Add its contribution:
contribution = arr[i] * numberOfSubarrays;
So the main formula is simply:

arr[i]
  ×
(number of choices on left)
  ×
(number of choices on right)
In one sentence:
Find how far each element can extend left and right while remaining the minimum, 
count those subarrays, multiply by the element, and add everything.

*/

class Solution {
public:
    typedef struct {
        vector<int> val;
        int top;
    } Stack;

    Stack createStack(int n) {
        Stack s;
        s.val.resize(n);
        s.top = 0;
        return s;
    }

    bool isEmpty(const Stack &s) { return s.top == 0; }
    bool isFull(const Stack &s) { return s.top == (int)s.val.size(); }

    bool push(Stack *s, int val) {
        if (isFull(*s)) return false;
        s->val[s->top] = val;
        s->top++;
        return true;
    }

    bool pop(Stack *s, int *val) {
        if (isEmpty(*s)) return false;
        s->top--;
        *val = s->val[s->top];
        return true;
    }

    int peek(const Stack &s) {
        if (isEmpty(s)) return -1;
        return s.val[s.top - 1];
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        long long ans = 0;
        Stack s = createStack(n);
        int val;
        const int MOD = 1000000007;

        // Previous smaller (>=)
        for (int i = 0; i < n; i++) {
            while (!isEmpty(s) && arr[peek(s)] >= arr[i]) {
                pop(&s, &val);
            }
            if (isEmpty(s))
                left[i] = -1;
            else
                left[i] = peek(s);
            push(&s, i);
        }

        while (!isEmpty(s)) pop(&s, &val);

        // Next smaller (>)
        for (int i = n - 1; i >= 0; i--) {
            while (!isEmpty(s) && arr[peek(s)] > arr[i]) {
                pop(&s, &val);
            }
            if (isEmpty(s))
                right[i] = n;
            else
                right[i] = peek(s);
            push(&s, i);
        }

        for (int i = 0; i < n; i++) {
            long long leftChoices = i - left[i];
            long long rightChoices = right[i] - i;
            long long contribution = (leftChoices * rightChoices) % MOD;
            contribution = (contribution * arr[i]) % MOD;
            ans = (ans + contribution) % MOD;
        }

        return (int)ans;
    }
};