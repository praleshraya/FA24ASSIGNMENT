program BalancedOperatorsArray;

const
    MAX = 100;  // Maximum size of the stack

type
    Stack = record
        items: array[1..MAX] of string;
        top: Integer;
    end;

var
    s: Stack;

procedure InitStack(var s: Stack);
begin
    s.top := 0;
end;

function IsEmpty(var s: Stack): Boolean;
begin
    IsEmpty := s.top = 0;
end;

function IsFull(var s: Stack): Boolean;
begin
    IsFull := s.top = MAX;
end;

procedure Push(var s: Stack; value: string);
begin
    if IsFull(s) then
        WriteLn('Stack overflow')
    else
    begin
        s.top := s.top + 1;
        s.items[s.top] := value;
    end;
end;

function Pop(var s: Stack): string;
begin
    if IsEmpty(s) then
    begin
        WriteLn('Stack underflow');
        Pop := '';
    end
    else
    begin
        Pop := s.items[s.top];
        s.top := s.top - 1;
    end;
end;

function Peek(var s: Stack): string;
begin
    if IsEmpty(s) then
        Peek := ''
    else
        Peek := s.items[s.top];
end;

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
        isMatchingPair := False;
end;

function areOperatorsBalanced(expression: string): Boolean;
var
    i: Integer;
    current: string;
begin
    InitStack(s);  // Initialize the stack
    i := 1;

    while i <= Length(expression) do
    begin
        current := expression[i];

        // Push opening brackets or 'begin' onto the stack
        if (current = '(') or (current = '{') or (current = '[') then
            Push(s, current)
        else if (current = 'b') and (Copy(expression, i, 5) = 'begin') then
        begin
            Push(s, 'begin');
            i := i + 4;  // Skip to the end of 'begin'
        end
        // Handle closing brackets or 'end'
        else if (current = ')') or (current = '}') or (current = ']') then
        begin
            if IsEmpty(s) or not isMatchingPair(Pop(s), current) then
            begin
                areOperatorsBalanced := False;
                exit;
            end;
        end
        else if (current = 'e') and (Copy(expression, i, 3) = 'end') then
        begin
            if IsEmpty(s) or not isMatchingPair(Pop(s), 'end') then
            begin
                areOperatorsBalanced := False;
                exit;
            end;
            i := i + 2;  // Skip to the end of 'end'
        end;

        i := i + 1;
    end;

    // If stack is empty, all operators are matched
    areOperatorsBalanced := IsEmpty(s);
end;

var
    expr: string;
begin
    Write('Enter an expression to check for balanced operators (begin/end, {}, (), []): ');
    ReadLn(expr);

    if areOperatorsBalanced(expr) then
        WriteLn('The expression is balanced.')
    else
        WriteLn('The expression is not balanced.');
end.
