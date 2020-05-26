bison -d -o pascal.cpp pascal.y
flex -o scanner.cpp pascal.l
c++ scanner.cpp pascal.cpp ast/ast.cpp -o test -std=c++11
mv pascal.*pp build
mv scanner.*pp build
