# Awesome-Pascal-Compiler

### How To Run
+ build
```shell
mkdir cmake-build/ && cd cmake-build/
cmake .. && cd ..
cmake --build cmake-build --target apc
```
+ Then you can use test target to test (all test target in /test/CMakeLists.txt)
```shell
cmake --build cmake-build --target apc-test-*
```
### TO-DO List
- [x] SPLIT `FieldDec` and `VarDecl`
- [x] Finish `routine part`
- [x] Finish `routine body`
- [x] Optimize Node::prt, so that the tree can be better viewed 
- [x] Semantical Analysis
- [x] Codegen
- [x] Report Writing

```
                       _oo0oo_
                      o8888888o
                      88" . "88
                      (| -_- |)
                      0\  =  /0
                    ___/`---'\___
                  .' \\|     |// '.
                 / \\|||  :  |||// \
                / _||||| -:- |||||- \
               |   | \\\  -  /// |   |
               | \_|  ''\---/''  |_/ |
               \  .-\__  '-'  ___/-. /
             ___'. .'  /--.--\  `. .'___
          ."" '<  `.___\_<|>_/___.' >' "".
         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
         \  \ `_.   \_ __\ /__ _/   .-` /  /
     =====`-.____`.___ \_____/___.-`___.-'=====
                       `=---='

     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

            Buddha blessed     BUG gone
```