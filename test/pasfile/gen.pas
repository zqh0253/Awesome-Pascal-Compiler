PROGRAM gen_test;
CONST
    cn = 2;
TYPE
    A = record
        arr : array[10] of integer;
        i : integer;
    end;
VAR
    b : INTEGER;
    p : ptr INTEGER;
    a : A;
    arr : array[10] of integer;
BEGIN
    p := a.arr;
    a.arr[0] := 2020;
    printf('%d\n', a.arr[0]);
END.