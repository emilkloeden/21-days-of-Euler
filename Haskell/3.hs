main = print answer

maxNum = 600851475143
factors 0 = [0]
factors 1 = [1]
factors 2 = [1,2]
factors n = [ i | i <- [ 1,2..(1 + floor(sqrt(fromIntegral n)))], n `mod` i == 0 ] ++ [n]
prime n = (length (factors n) == 2)
answer = maximum [i| i <- factors maxNum, prime i]
