/*
Problem Link : https://leetcode.com/problems/number-of-recent-calls/
Problem 933 : Number of Recent Calls

You have a RecentCounter class which counts the number of recent requests within a certain time frame.

Implement the RecentCounter class:

RecentCounter() Initializes the counter with zero recent requests.
int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, and returns the number of requests that has happened in the past 3000 milliseconds (including the new request). Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].
It is guaranteed that every call to ping uses a strictly larger value of t than the previous call.

 

Example 1:

Input
["RecentCounter", "ping", "ping", "ping", "ping"]
[[], [1], [100], [3001], [3002]]
Output
[null, 1, 2, 3, 3]


Logic in simple points
1. Use a queue
   - The queue stores all the ping times.
   - front points to the oldest ping.
   - rear points to the position where the next ping will be inserted.
2. When ping(t) is called
   - First, insert the current time t into the queue.
   insert(q, t);
3. Check old pings
   - We only need pings from:
   t - 3000  to  t
   - So if the oldest ping is less than t - 3000, it is too old.
4. Remove old pings
   while(!isempty(q) && q.arr[q.front] < t-3000)
   {
       pop(q);
   }
   - Keep removing from the front until the oldest remaining ping is within the required range.
5. Count remaining elements
   return q.rear - q.front;
   - Everything between front and rear represents a recent ping.
   - So:
   Number of recent pings = rear - front



*/

class RecentCounter {
public:
#include <iostream>


typedef struct
{
    int arr[10000];
    int front;
    int rear;
} Q;
Q q;

void init(Q &q)
{
    q.front = 0;
    q.rear = 0;
}

bool isempty(Q q)
{
    return q.front == q.rear;
}

bool isfull(Q q)
{
    return q.rear == 10000;
}

bool insert(Q &q, int data)
{
    if (isfull(q))
    {
        return false;
    }

    q.arr[q.rear] = data;
    q.rear++;

    return true;
}

bool pop(Q &q)
{
    if (isempty(q))
    {
        return false;
    }

    q.front++;

    return true;
}

void display(Q q)
{
    if (isempty(q))
    {
        cout << "Queue is Empty.";
        return;
    }

    int i = q.front;

    while (i < q.rear)
    {
        cout << q.arr[i] << "  ";
        i++;
    }
}
  RecentCounter() {
    init(q);
    }
    
    int ping(int t) 
    {
        insert(q , t);
        while(!isempty(q) && q.arr[q.front] < t-3000)
        {
            pop(q);
        }
        return q.rear - q.front;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */