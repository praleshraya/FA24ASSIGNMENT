
// Name : PRALESH RAYAMAJHI
// Course : CSC 710 Structure and Design Programming Langauge
// Assignment : 1
// Question : 1
// Due Date 20 Sept, 2024
// Application : C++
// Task : Balance the symbol based on opening and closing braces (), {} , /x x/ and [].

program BalancedOperatorsArray;

const
    MAX = 100;  // Maximum size of the stack

type
    // Defining a stack to store strings with a max size of 100
    Stack = record
        items: array[1..MAX] of string;
        top: Integer;  // Holds the index of the top element in the stack
    end;

var
    s: Stack;  // Declaring a stack variable

// Initialize the stack to an empty state by setting `top` to 0
procedure InitStack(var s: Stack);
begin
    s.top := 0;
end;

// Check if the stack is empty by comparing `top` to 0
function IsEmpty(var s: Stack): Boolean;
begin
    IsEmpty := s.top = 0;
end;

// Check if the stack is full by comparing `top` to the maximum size
function IsFull(var s: Stack): Boolean;
begin
    IsFull := s.top = MAX;
end;

// Push a new value onto the stack 
procedure Push(var s: Stack; value: string);
begin
    if IsFull(s) then
        WriteLn('Stack overflow')  // Display an error if the stack is full
    else
    begin
        s.top := s.top + 1;  // Increment the top index
        s.items[s.top] := value;  // Add the new item at the new top position
    end;
end;

// Pop and return the top value from the stack if it's not empty
function Pop(var s: Stack): string;
begin
    if IsEmpty(s) then
    begin
        WriteLn('Stack underflow');  // Display an error if the stack is empty
        Pop := '';  // Return an empty string in case of underflow
    end
    else
    begin
        Pop := s.items[s.top];  // Get the value at the top of the stack
        s.top := s.top - 1;  // Decrement the top index
    end;
end;

// Peek at the top value of the stack without removing it
function Peek(var s: Stack): string;
begin
    if IsEmpty(s) then
        Peek := ''  // Return an empty string if the stack is empty
    else
        Peek := s.items[s.top];  // Return the top item without removing it
end;

// Check if a given pair of symbols (opening and closing) match
function isMatchingPair(opening, closing: string): Boolean;
begin
    if (opening = '(') and (closing = ')') then
        isMatchingPair := True
    else if (opening = '{') and (closing = '}') then
        isMatchingPair := True
    else if (opening = '[') and (closing = ']') then
        isMatchingPair := True
    else if (opening = 'begin') and (closing = 'end') then
        isMatchingPair := True
    else
        isMatchingPair := False;  // Return False if the pair doesn't match
end;

// Check if the operators in the input expression are balanced
function areOperatorsBalanced(expression: string): Boolean;
var
    i: Integer;
    current: string;
begin
    InitStack(s);  // Initialize the stack
    i := 1;

    // Traverse the input expression character by character
    while i <= Length(expression) do
    begin
        current := expression[i];

        // Push opening brackets or 'begin' onto the stack
        if (current = '(') or (current = '{') or (current = '[') then
            Push(s, current)
        // If the current substring is 'begin', push it onto the stack
        else if (current = 'b') and (Copy(expression, i, 5) = 'begin') then
        begin
            Push(s, 'begin');
            i := i + 4;  // Skip to the end of 'begin'
        end
        // For closing brackets, check for a matching pair
        else if (current = ')') or (current = '}') or (current = ']') then
        begin
            // If the stack is empty or there's no matching opening symbol, return False
            if IsEmpty(s) or not isMatchingPair(Pop(s), current) then
            begin
                areOperatorsBalanced := False;
                exit;
            end;
        end
        // For 'end', check if the top of the stack has 'begin'
        else if (current = 'e') and (Copy(expression, i, 3) = 'end') then
        begin
            if IsEmpty(s) or not isMatchingPair(Pop(s), 'end') then
            begin
                areOperatorsBalanced := False;
                exit;
            end;
            i := i + 2;  // Skip to the end of 'end'
        end;

        i := i + 1;  // Move to the next character
    end;

    // If the stack is empty, the operators are balanced
    areOperatorsBalanced := IsEmpty(s);
end;

// Validate the input to ensure it only contains valid symbols or 'begin'/'end'
function IsValidInput(input: string): Boolean;
var
    i: Integer;
begin
    i := 1;
    while i <= Length(input) do
    begin
        // Checking for valid characters 
        if input[i] in ['(', ')', '{', '}', '[', ']'] then
        begin
            i := i + 1;
        end
        // Checking for the 'begin' keyword
        else if Copy(input, i, 5) = 'begin' then
        begin
            i := i + 5;  // Skip 'begin'
        end
        // Checkng for the 'end' keyword
        else if Copy(input, i, 3) = 'end' then
        begin
            i := i + 3;  // Skip 'end'
        end
        else
        begin
            IsValidInput := False;  // Invalid input if other data
            Exit;
        end;
    end;
    IsValidInput := True;  // Input is valid if no invalid characters were found
end;

var
    input: string;
begin
    // repeatedly ask for valid symbols from the user
    repeat
        Write('Enter symbols: ');
        ReadLn(input);

        // Validate the input and give an error message if it's invalid
        if not IsValidInput(input) then
            Writeln('Invalid input. Please enter only symbols: (), {}, [], begin, end')
        else
            Break;  // Input is valid, exit the loop
    until False;

    // Check if the operators are balanced and print the result
    if areOperatorsBalanced(input) then
        Writeln('Balanced.')
    else
        Writeln('Unbalanced.');
end.
