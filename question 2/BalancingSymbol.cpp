/*
 Name : PRALESH RAYAMAJHI
 Course : CSC 710 Structure and Design Programming Langauge
 Assignment : 1
 Question : 1
 Due Date 20 Sept, 2024
 Application : C++
 Task : Balance the symbol based on opening and closing braces (), {} , /x x/ and [].
*/
#include <iostream>
using namespace std;

// Creating a node datatype
struct Node
{
    string data; // data is string to support multi-character symbols
    Node *next;  // this is for holding memory address of the next node
};

class Stack
{
private:
    Node *top; // to create top of the list (stack)

public:
    Stack()
    {
        top = nullptr; // assigning null pointer
    }

    // For adding data to the stack
    void push(string value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // For deleting data from the stack
    string pop()
    {
        if (isEmpty())  // checking if the stack is empty
        {
            cout << "Stack is Empty." << endl;
            return ""; // return empty string if empty
        }

        // if not empty, perform data operation
        string value = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    // Return top of stack
    string peek()
    {
        if (isEmpty()) // checking if the stack is empty
        {
            return ""; // return empty string if empty
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

// Validating pairs of braces
bool isPairMatch(string open, string close)
{
    return (open == "(" && close == ")") ||
           (open == "{" && close == "}") ||
           (open == "[" && close == "]") ||
           (open == "/*" && close == "*/");
}

// Checking if input is balanced or not
bool isSymbolBalanced(string input)
{
    Stack stack;
    for (int i = 0; i < input.length(); i++)
    {
        string current_value;

        // Handle multi-character symbols /* and */
        if (input[i] == '/' && input[i + 1] == '*')
        {
            current_value = "/*";
            i++; // Skip the next character as we've already processed /*
        }
        else if (input[i] == '*' && input[i + 1] == '/')
        {
            current_value = "*/";
            i++; // Skip the next character as we've already processed */
        }
        else
        {
            current_value = input[i];
        }

        // Push opening symbols
        if (current_value == "(" || current_value == "{" || current_value == "[" || current_value == "/*")
        {
            stack.push(current_value);
        }
        // Handle closing symbols
        else if (current_value == ")" || current_value == "}" || current_value == "]" || current_value == "*/")
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

// Checking if input is valid or not
bool isValidInput(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        char current_value = input[i];

        // Check for valid symbols
        if (!(current_value == '(' || current_value == ')' ||
              current_value == '{' || current_value == '}' ||
              current_value == '[' || current_value == ']' ||
              (current_value == '/' && input[i + 1] == '*') ||
              (current_value == '*' && input[i + 1] == '/')))
        {
            return false;
        }

        // If it's /* or */, skip the next character
        if ((current_value == '/' && input[i + 1] == '*') || (current_value == '*' && input[i + 1] == '/'))
        {
            i++; // Skip the next character
        }
    }
    return true;
}

int main()
{
    string input; // for user input

    // Continuous running code
    while (true)
    {
        cout << "Enter symbols: " << endl;
        cin >> input;

        // Checking for proper input by user
        if (!isValidInput(input))
        {
            cout << "Invalid input. Please enter only symbols: (), {}, [], /*, */" << endl;
        }
        else
        {
            // Checking if input is balanced or not
            if (isSymbolBalanced(input))
            {
                cout << "Balanced." << endl;
            }
            else
            {
                cout << "Unbalanced." << endl;
            }
            break; // Input is valid and processed, exit the loop
        }
    }

    return 0;
}
