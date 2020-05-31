; ModuleID = 'gen_exp'
source_filename = "gen_exp"

@0 = private unnamed_addr constant [24 x i8] c"a = %d, b = %d, c = %f\0A\00", align 1
@1 = private unnamed_addr constant [24 x i8] c"a + b = %d, a + c = %f\0A\00", align 1
@2 = private unnamed_addr constant [24 x i8] c"a * b = %d, a * c = %f\0A\00", align 1
@3 = private unnamed_addr constant [24 x i8] c"a / b = %d, a / c = %f\0A\00", align 1

define void @main() {
start:
  %a = alloca i32
  %b = alloca i32
  %c = alloca double
  store i32 3, i32* %a
  store i32 2, i32* %b
  store double 2.000000e+00, double* %c
  %0 = load i32, i32* %a
  %1 = load i32, i32* %b
  %2 = load double, double* %c
  %3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([24 x i8], [24 x i8]* @0, i32 0, i32 0), i32 %0, i32 %1, double %2)
  %4 = load i32, i32* %a
  %5 = load i32, i32* %b
  %6 = add i32 %4, %5
  %7 = load i32, i32* %b
  %8 = load double, double* %c
  %9 = fadd i32 %7, double %8
  %10 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([24 x i8], [24 x i8]* @1, i32 0, i32 0), i32 %6, i32 %9)
  %11 = load i32, i32* %a
  %12 = load i32, i32* %b
  %13 = mul i32 %11, %12
  %14 = load i32, i32* %b
  %15 = load double, double* %c
  %16 = fmul i32 %14, double %15
  %17 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([24 x i8], [24 x i8]* @2, i32 0, i32 0), i32 %13, i32 %16)
  %18 = load i32, i32* %a
  %19 = load i32, i32* %b
  %20 = sdiv i32 %18, %19
  %21 = load i32, i32* %a
  %22 = load double, double* %c
  %23 = fdiv i32 %21, double %22
  %24 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([24 x i8], [24 x i8]* @3, i32 0, i32 0), i32 %20, i32 %23)
  ret void
}

declare i32 @printf(i8*, ...)