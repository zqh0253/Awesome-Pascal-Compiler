PROGRAM gen_test;
CONST
    cn = 2;

VAR
    b : INTEGER;
function f(a: integer): integer;
BEGIN
    f := a+2;
END;

BEGIN
    IF false THEN begin
        b := f(cn);
    end else begin
        b := 1;
    end;

    b := printf('%d', b);
END.