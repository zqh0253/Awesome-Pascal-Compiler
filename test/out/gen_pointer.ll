; ModuleID = 'gen_type'
source_filename = "gen_type"

%main_A = type { [7 x i32], i32, %"main_$record_0" }
%"main_$record_0" = type { i32, i32 }

@0 = private unnamed_addr constant [14 x i8] c"a.a[%d] = %d\0A\00", align 1

define void @main() {
start:
  %a = alloca %main_A
  %i = alloca i32
  %p = alloca i32*
  %0 = getelementptr %main_A, %main_A* %a, i32 0, i32 1
  %1 = getelementptr i32*, i32** %p, i32 0
  store i32* %0, i32** %1
  %2 = getelementptr i32*, i32** %p, i32 0
  %3 = load i32*, i32** %2
  store i32 1, i32* %3
  %4 = getelementptr %main_A, %main_A* %a, i32 0, i32 2, i32 0
  %5 = getelementptr i32*, i32** %p, i32 0
  store i32* %4, i32** %5
  %6 = getelementptr i32*, i32** %p, i32 0
  %7 = load i32*, i32** %6
  store i32 2, i32* %7
  %8 = getelementptr %main_A, %main_A* %a, i32 0, i32 2, i32 1
  %9 = getelementptr i32*, i32** %p, i32 0
  store i32* %8, i32** %9
  %10 = getelementptr i32*, i32** %p, i32 0
  %11 = load i32*, i32** %10
  store i32 3, i32* %11
  %12 = getelementptr i32, i32* %i, i32 0
  store i32 0, i32* %12
  br label %14

13:                                               ; preds = %14
  ret void

14:                                               ; preds = %start, %17
  %15 = load i32, i32* %12
  %16 = icmp sle i32 %15, 7
  br i1 %16, label %17, label %13

17:                                               ; preds = %14
  %18 = getelementptr i32, i32* %i, i32 0
  %19 = load i32, i32* %18
  %20 = getelementptr %main_A, %main_A* %a, i32 0, i32 1
  %21 = load i32, i32* %20
  %22 = getelementptr %main_A, %main_A* %a, i32 0, i32 2, i32 0
  %23 = load i32, i32* %22
  %24 = getelementptr %main_A, %main_A* %a, i32 0, i32 2, i32 1
  %25 = load i32, i32* %24
  %26 = mul i32 %23, %25
  %27 = getelementptr i32, i32* %i, i32 0
  %28 = load i32, i32* %27
  %29 = mul i32 %26, %28
  %30 = add i32 %21, %29
  %31 = getelementptr %main_A, %main_A* %a, i32 0, i32 0, i32 %19
  store i32 %30, i32* %31
  %32 = getelementptr i32, i32* %i, i32 0
  %33 = load i32, i32* %32
  %34 = getelementptr i32, i32* %i, i32 0
  %35 = load i32, i32* %34
  %36 = getelementptr %main_A, %main_A* %a, i32 0, i32 0, i32 %35
  %37 = load i32, i32* %36
  %38 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @0, i32 0, i32 0), i32 %33, i32 %37)
  %39 = add i32 %15, 1
  store i32 %39, i32* %12
  br label %14
}

declare i32 @printf(i8*, ...)