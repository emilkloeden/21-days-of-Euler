main = print answer
x = [1..500]
y = [1..500]
z = [1..500]
s = 1000

answer = [a*b*c| a <- x, b <- y, c <- z, (a < b) && (b < c) && (a^2 + b^2 == c^2) && (a + b + c == s)]