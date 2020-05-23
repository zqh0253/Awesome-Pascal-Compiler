# Awesome-Pascal-Compiler

### How To Run
+ Since we are in development stage, I put the code in [src/naive](https://github.com/zqh0253/Awesome-Pascal-Compiler/tree/master/src/naive).
+  To compile through `Bison` and `flex`, simply run:
```shell
bash ./comp.sh
```
+ Then you can use `.test` to view the constructed AST tree.
```shell
./test < pasfile/stmtTest.pascal
```
### TO-DO List
- [ ] SPLIT `FieldDec` and `VarDecl`
- [x] Finish `routine part`
- [x] Finish `routine body`
- [ ] Optimize Node::prt, so that the tree can be better viewed 
- [ ] Semantical Analysis
- [ ] Codegen
- [ ] Report Writing

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