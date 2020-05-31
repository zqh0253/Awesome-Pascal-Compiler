PROGRAM gen_exp;
var
    a : integer;
    b : integer;
    c : real;

BEGIN
    a := 3;
    b := 2;
    c := 2.0;
    printf('a = %d, b = %d, c = %f\n', a, b, c);
    printf('a + b = %d, a + c = %f\n', a + b, b + c);
    printf('a * b = %d, a * c = %f\n', a * b, b * c);
    printf('a / b = %d, a / c = %f\n', a / b, a / c);
END.

