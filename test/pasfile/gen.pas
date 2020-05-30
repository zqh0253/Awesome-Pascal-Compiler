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
    b := f(cn);
    b := printf('%d', b);
END.