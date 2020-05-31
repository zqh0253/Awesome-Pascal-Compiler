; ModuleID = 'gen_type'
source_filename = "gen_type"

%main_A = type { [7 x i32], i32, %"main_$record_0" }
%"main_$record_0" = type { i32, i32 }

@0 = private unnamed_addr constant [14 x i8] c"a.a[%d] = %d\0A\00", align 1

define void @main() {
start:
  %a = alloca %main_A
  %i = alloca i32
  %0 = getelementptr %main_A, %main_A* %a, i32 0, i32 1
  store i32 1, i32* %0
  %1 = getelementptr %main_A, %main_A* %a, i32 0, i32 2, i32 0
  store i32 2, i32* %1
  %2 = getelementptr %main_A, %main_A* %a, i32 0, i32 2, i32 1
  store i32 3, i32* %2
  %3 = getelementptr i32, i32* %i, i32 0
  store i32 0, i32* %3
  br label %5

4:                                                ; preds = %5
  ret void

5:                                                ; preds = %start, %8
  %6 = load i32, i32* %3
  %7 = icmp sle i32 %6, 7
  br i1 %7, label %8, label %4

8:                                                ; preds = %5
  %9 = getelementptr i32, i32* %i, i32 0
  %10 = load i32, i32* %9
  %11 = getelementptr %main_A, %main_A* %a, i32 0, i32 1
  %12 = load i32, i32* %11
  %13 = getelementptr %main_A, %main_A* %a, i32 0, i32 2, i32 0
  %14 = load i32, i32* %13
  %15 = getelementptr %main_A, %main_A* %a, i32 0, i32 2, i32 1
  %16 = load i32, i32* %15
  %17 = mul i32 %14, %16
  %18 = getelementptr i32, i32* %i, i32 0
  %19 = load i32, i32* %18
  %20 = mul i32 %17, %19
  %21 = add i32 %12, %20
  %22 = getelementptr %main_A, %main_A* %a, i32 0, i32 0, i32 %10
  store i32 %21, i32* %22
  %23 = getelementptr i32, i32* %i, i32 0
  %24 = load i32, i32* %23
  %25 = getelementptr i32, i32* %i, i32 0
  %26 = load i32, i32* %25
  %27 = getelementptr %main_A, %main_A* %a, i32 0, i32 0, i32 %26
  %28 = load i32, i32* %27
  %29 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @0, i32 0, i32 0), i32 %24, i32 %28)
  %30 = add i32 %6, 1
  store i32 %30, i32* %3
  br label %5
}

declare i32 @printf(i8*, ...)