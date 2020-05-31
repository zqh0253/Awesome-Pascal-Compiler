PROGRAM gen_test;
CONST
    cn = 2;

VAR
    b : INTEGER;
    i : INTEGER;
    j : INTEGER;
function f(): integer;
BEGIN
    f := 0;
END;

BEGIN
    for i := 0 to 9 do begin
        j := f();
        repeat
            printf('%d\n', i+1);
            j := j+1;
        until j > 2;
    end;
END.