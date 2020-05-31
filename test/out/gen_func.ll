; ModuleID = 'gen_func'
source_filename = "gen_func"

@0 = private unnamed_addr constant [18 x i8] c"gcd(%d, %d) = %d\0A\00", align 1

define void @main() {
start:
  %a = alloca i32
  %b = alloca i32
  %i = alloca i32
  %c = alloca [5 x i32]
  %d = alloca [5 x i32]
  store i32 18, i32* %a
  store i32 12, i32* %b
  store i32 1, i32* %i
  %0 = load i32, i32* %a
  %1 = add i32 %0, 1
  br label %3

2:                                                ; preds = %3
  ret void

3:                                                ; preds = %start, %6
  %4 = load i32, i32* %i
  %5 = icmp sle i32 %4, %1
  br i1 %5, label %6, label %2

6:                                                ; preds = %3
  %7 = load i32, i32* %i
  %8 = load i32, i32* %b
  %9 = load i32, i32* %i
  %10 = load i32, i32* %b
  %11 = call i32 @main_gcd(i32 %9, i32 %10)
  %12 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @0, i32 0, i32 0), i32 %7, i32 %8, i32 %11)
  %13 = add i32 %4, 1
  store i32 %13, i32* %i
  br label %3
}

declare i32 @printf(i8*, ...)

define internal i32 @main_gcd(i32 %0, i32 %1) {
start:
  %a = alloca i32
  store i32 %0, i32* %a
  %b = alloca i32
  store i32 %1, i32* %b
  %gcd = alloca i32
  %2 = load i32, i32* %b
  %3 = icmp eq i32 %2, 0
  br i1 %3, label %6, label %8

4:                                                ; preds = %8, %6
  %5 = load i32, i32* %gcd
  ret i32 %5

6:                                                ; preds = %start
  %7 = load i32, i32* %a
  store i32 %7, i32* %gcd
  br label %4

8:                                                ; preds = %start
  %9 = load i32, i32* %b
  %10 = load i32, i32* %a
  %11 = load i32, i32* %b
  %12 = srem i32 %10, %11
  %13 = call i32 @main_gcd(i32 %9, i32 %12)
  store i32 %13, i32* %gcd
  br label %4
}