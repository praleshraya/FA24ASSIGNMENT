#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(char value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty." << endl;
            return '\0'; // return null character if empty
        }

        char value = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    char peek()
    {
        if (isEmpty())
        {
            return '\0'; // return null character if empty
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

bool isPairMatch(char char1, char char2)
{
    return (char1 == '(' && char2 == ')') ||
           (char1 == '{' && char2 == '}') ||
           (char1 == '[' && char2 == ']');
}

bool isSymbolBalanced(string input)
{
    Stack stack;
    for (int i = 0; i < input.length(); i++)
    {
        char current_value = input[i];
        if (current_value == '(' || current_value == '{' || current_value == '[')
        {
            stack.push(current_value);
        }
        else if (current_value == ')' || current_value == '}' || current_value == ']')
        {
            if (stack.isEmpty())
            {
                return false;
            }
            else if (!isPairMatch(stack.pop(), current_value))
            {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

bool isValidInput(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        char current_value = input[i];
        if (!(current_value == '(' || current_value == ')' ||
              current_value == '{' || current_value == '}' ||
              current_value == '[' || current_value == ']'))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string input;
    cout << "Enter symbols: " << endl;
    cin >> input;

    while (true)
    {
        cout << "Enter symbols: " << endl;
        cin >> input;

        if (!isValidInput(input))
        {
            cout << "Invalid input. Please enter only symbols: (), {}, []" << endl;
        }
        else
        {
            break; // Input is valid, exit the loop
        }
    }

    if (isSymbolBalanced(input))
    {
        cout << "Balanced." << endl;
    }
    else
    {
        cout << "Unbalanced." << endl;
    }
    return 0;
}
