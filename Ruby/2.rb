#!/usr/bin/env ruby

# Declare a method that returns the nth fibonacci number
def fib (n)
    a,b = 0, 1

    return 0 if n <= 0
    
    i = 0
    until i >= n do
        a, b = b, a + b
        i += 1
    end
    return a
end

# Populate an array with even fibonacci numbers
i = 1
initial_range = []

begin
    initial_range.push(fib(i)) if fib(i).even?
    i += 1
end until fib(i) > 4000000

# print the sum of that array
p initial_range.inject(0) { |a, b| a + b }
