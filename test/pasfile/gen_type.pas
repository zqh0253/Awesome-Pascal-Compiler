PROGRAM gen_type;
type
    A = record
        a : array [7] of integer;
        b : integer;
        c : record
            a : integer;
            b : integer;
        end;
    end;
var
    a : A;
    i : integer;
BEGIN
    a.b := 1;
    a.c.a := 2;
    a.c.b := 3;
    for i := 0 to 7 do begin
        a.a[i] := a.b + a.c.a * a.c.b * i;
        printf('a.a[%d] = %d\n', i, a.a[i]);
    end;
END.

