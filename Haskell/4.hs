main = print answer

isPalindrome n = (show n == reverse (show n))
list = [999,998..100]
answer = maximum [x*y| x <- list, y <- list, isPalindrome (x*y)]