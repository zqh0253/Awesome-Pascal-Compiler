PROGRAM stmtTest;
CONST
    a = 1;
VAR
    b, c, d : INTEGER;

BEGIN
    b := 1;
    c := 0;
    IF a = 1 THEN BEGIN
        FOR d:=1 TO 10 DO BEGIN 
            c := c + 1;
            WHILE C <= 5 DO BEGIN 
                d := 0;
                d := 0;
            END;

            REPEAT 
                d := 0;
            UNTIL C > 5;
        END;
    END  
    ELSE 
    BEGIN 
        d := 0;
    END;
    
    CASE d + 1 OF 
		0: BEGIN str := 'A1'; c := 1; END;
		1: str := 'B2';
		2: str := 'C3';
		3: str := 'D4';
	END;

    GOTO 1;
    WRITE(d);
    WRITELN(d);
END.