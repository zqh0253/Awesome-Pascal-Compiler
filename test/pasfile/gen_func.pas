PROGRAM gen_func;
var
    a : integer;
    b : integer;
    i : integer;
    c, d: array[5] of integer;
function gcd(a: integer; b: integer): integer;
BEGIN
    if b = 0 then begin
        gcd := a;
    end else begin
        gcd := gcd(b, a%b);
    end;
END;

BEGIN
    a := 18;
    b := 12;
    for i:=1 to a+1 do begin
        printf('gcd(%d, %d) = %d\n', i, b, gcd(i, b));
    end;
END.

