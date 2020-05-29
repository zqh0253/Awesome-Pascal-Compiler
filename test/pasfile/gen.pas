PROGRAM gen_test;
CONST
    cn = 2;
    dn = 123.23;
    a = false;
    s = 'ab';
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
BEGIN

END.