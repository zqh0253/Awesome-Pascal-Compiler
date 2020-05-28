PROGRAM arrayRecord;
CONST
    a = FALSE;
    b = 10;
    c = 2.2;
    d = 't';
TYPE
    test = INTEGER;
    rtype = RECORD
        a : INTEGER;
        b,c : REAL;
    END;

VAR
    f : test;
    h : string;
    i : BOOLEAN;
    j : ARRAY [0..3] OF INTEGER;
    k : rtype;

BEGIN
    f := 1;
    h := 'string';
    i := FALSE;
    j[0] := 0 + 1 + 2;
    e := j[0] + j[1] * j[2];
    k.a := j[0] + b - c * 4 DIV 3 * 3;
    k.b := 1.3;
END
.