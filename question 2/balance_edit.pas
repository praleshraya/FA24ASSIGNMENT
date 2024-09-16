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
        // Handle 'begin'
        if (Copy(expression, i, 5) = 'begin') then
        begin
            Push(s, 'begin');
            i := i + 5;  // Skip the word 'begin'
        end
        // Handle 'end'
        else if (Copy(expression, i, 3) = 'end') then
        begin
            if IsEmpty(s) or not isMatchingPair(Pop(s), 'end') then
            begin
                areOperatorsBalanced := False;
                exit;
            end;
            i := i + 3;  // Skip the word 'end'
        end
        // Handle opening brackets
        else if (expression[i] in ['(', '{', '[']) then
        begin
            Push(s, expression[i]);
            i := i + 1;
        end
        // Handle closing brackets
        else if (expression[i] in [')', '}', ']']) then
        begin
            if IsEmpty(s) or not isMatchingPair(Pop(s), expression[i]) then
            begin
                areOperatorsBalanced := False;
                exit;
            end;
            i := i + 1;
        end
        else
        begin
            i := i + 1;
        end;
    end;

    // If stack is empty, all operators are matched
    areOperatorsBalanced := IsEmpty(s);
end;

function IsValidInput(input: string): Boolean;
var
    i: Integer;
begin
    i := 1;
    while i <= Length(input) do
    begin
        // Check if it's a valid bracket
        if input[i] in ['(', ')', '{', '}', '[', ']'] then
            i := i + 1
        // Check if it's the keyword 'begin' or 'end'
        else if (Copy(input, i, 5) = 'begin') then
            i := i + 5
        else if (Copy(input, i, 3) = 'end') then
            i := i + 3
        else
        begin
            IsValidInput := False;
            Exit;
        end;
    end;
    IsValidInput := True;
end;

var
    input: string;
begin
    repeat
        Write('Enter symbols: ');
        ReadLn(input);

        if not IsValidInput(input) then
            Writeln('Invalid input. Please enter only symbols: (), {}, [], begin/end')
        else
            Break;  // Input is valid, exit the loop
    until False;

    if areOperatorsBalanced(input) then
        Writeln('Balanced.')
    else
        Writeln('Unbalanced.');
end.
