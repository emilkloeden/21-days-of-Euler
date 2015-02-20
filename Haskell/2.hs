main = print (sum ans)

maxNum = 4000000
fibs = 0 : 1 : zipWith (+) fibs (tail fibs)-- took from interwebs
ans = [x | x <- takeWhile (<=maxNum) fibs,  even x] -- also took from interwebs

{-
    zipWith     - takes an operation (addition here)
                two lists and combines list1[i] with list2[i]
                using chosen operation

    takeWhile   - takes items from a list where predicate
                returns true takeWhile (predicate) list

    even        - takes a parameter and returns true is 
                parameter is even.
    
    print       - takes one argument (hence brackets)

    sum         - sums a list
-}