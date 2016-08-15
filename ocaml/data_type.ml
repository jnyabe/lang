1+2*3
let pi = 4.0 *. atan 1.0
let square x = x *. x
square(sin pi) +. square(cos pi)
let rec fib n = if n < 2 then 1 else fib(n-1) + fib(n-2)
fib 10
