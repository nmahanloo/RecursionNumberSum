// Nima Mahanloo
// Group 9 Recursion NumberSum
#include <iostream>
using namespace std;

struct node
{
    int digit;
    node* next = nullptr;
};

int addNum (node* head, int sum)
{
    if (head)
        sum = sum + head->digit;
    else
        return sum;
    addNum (head->next, sum);
}

void pushNum (node* (&head), int num)
{
    bool flag = true;
    int rate = 0;
    if (num > 999)
        rate = 1000;
    else if (num > 99)
        rate = 100;
    else if (num > 9)
        rate = 10;
    else
        rate = 1;
    while (num > 0)
    {
        if (flag == false)
        {
            head->next = new node;
            head = head->next;
        }
        head->digit = num / rate;
        num = num % rate;
        rate = rate / 10;
        flag = false;
    }
}

int getNumber (int &num)
{
    while ((num < 0) || (num > 9999))
    {
        cout << "please enter maximum 4 digit natural number > ";
        cin >> num;
    }
    return num;
}
int main()
{
    int num = -1;
    int numCpy = -1;
    int sum = 0;
    node* head = new node;
    node* tail = head;
    num = getNumber(num);
    numCpy = num;
    pushNum (head, numCpy);
    sum = addNum(tail, sum);
    cout << "Sum of " << num << " digits is " << sum << endl;
    return 0;
}
