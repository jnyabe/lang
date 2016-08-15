#!/usr/bin/env ruby

puts (1..STDIN.read.to_i).map{|i|
  case
  when i % 15 == 0; "FizzBuzz"
  when i % 3 == 0; "Fizz"
  when i % 5 == 0; "Buzz"
  else ; i.to_s
  end
}.join("\n")
