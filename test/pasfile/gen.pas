PROGRAM gen_test;
CONST
    cn = 2;
TYPE
    test = INTEGER;
    rtype = RECORD
        a : INTEGER;
        b,c : REAL;
        d : RECORD
            a : INTEGER;
            b,c : REAL;
        END;
    END;
VAR
    b : test;
    asd: rtype;
    asdf: INTEGER;
function f(a: integer): integer;
BEGIN
    f := a+1;
END;

BEGIN
    b := 1;
    asd.d.a := 1+f(asd.d.a);
END.