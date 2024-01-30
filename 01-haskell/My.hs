{-
-- EPITECH PROJECT, 2022
-- $PROJECT_NAME
-- File description:
-- $DESCRIPTION
-}

-- Task 01

mySucc :: Int -> Int
mySucc x = x + 1

-- Task 02

myIsNeg :: Int -> Bool
myIsNeg x
  | x < 0 = True
  | otherwise = False

-- Task 03

myAbs :: Int -> Int
myAbs x
  | x < 0 = -x
  | otherwise = x

-- Task 04

myMin :: Int -> Int -> Int
myMin x y
  | x < y = x
  | y < x = y
  | otherwise = x

-- Task 05

myMax :: Int -> Int -> Int
myMax x y
  | x < y = y
  | y < x = x
  | otherwise = x

-- Task 06

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

-- Task 07

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

-- Task 08

myFst :: (a, b) -> a
myFst (a, b) = a

-- Task 09

mySnd :: (a, b) -> b
mySnd (a, b) = b

-- Task 10

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

-- Task 11

myHead :: [a] -> a
myHead [] = error "myHead: empty list"
myHead [x] = x
myHead (x : _) = x

-- Task 12

myTail :: [a] -> [a]
myTail [] = error "myTail: empty list"
myTail (x : xs) = xs

-- Task 13
myLength :: [a] -> Int
myLength [] = 0
myLength (_ : xs) = myLength xs + 1

-- Task 14

myNth :: [a] -> Int -> a
myNth [] i = error "myNth: empty list"
myNth (x : xs) i
  | i == 0 = x
  | otherwise = myNth xs (i - 1)

-- Task 15

myTake :: Int -> [a] -> [a]
myTake 0 _ = []
myTake _ [] = []
myTake i (x : xs) = x : myTake (i - 1) xs

-- Task 16

myDrop :: Int -> [a] -> [a]
myDrop 0 x = x
myDrop _ [] = []
myDrop i (x : xs)
  | i /= 0 = myDrop (i - 1) xs
  | otherwise = xs

-- Task 17

myAppend :: [a] -> [a] -> [a]
myAppend [] y = y
myAppend (x : xs) y = x : myAppend xs y

-- Task 18

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (x : xs) = myReverse' xs [x]
  where
    myReverse' :: [b] -> [b] -> [b]
    myReverse' [] y = y
    myReverse' (x : xs) y = myReverse' xs (x : y)

-- Task 19

myInit :: [a] -> [a]
myInit [] = error "myInit: empty list"
myInit [a] = []
myInit (x : xs) = x : myInit xs

-- Task 20

myLast :: [a] -> a
myLast [] = error "myLast: empty list"
myLast [a] = a
myLast (x : xs) = myLast xs

-- Task 21

myZip :: [a] -> [b] -> [(a, b)]
myZip [] _ = []
myZip _ [] = []
myZip (x : xs) (y : ys) = (x, y) : myZip xs ys

-- Task 22

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((x, y) : xs) = (x : xs', y : ys')
  where
    (xs', ys') = myUnzip xs

-- Task 23

myMap :: (a -> b) -> [a] -> [b]
myMap _ [] = []
myMap f (x : xs) = f x : myMap f xs

-- Task 24

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter f (x : xs)
  | f x = x : myFilter f xs
  | otherwise = myFilter f xs

-- Task 25

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl _ x [] = x
myFoldl f x (y : ys) = myFoldl f (f x y) ys

-- Task 26

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr _ x [] = x
myFoldr f x (y : ys) = f y (myFoldr f x ys)

-- Task 27

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition _ [] = ([], [])
myPartition f (x : xs)
  | f x = (x : myFst (myPartition f xs), mySnd (myPartition f xs))
  | otherwise = (myFst (myPartition f xs), x : mySnd (myPartition f xs))

-- Task 28

myQuickSort :: (a -> a -> Bool) -> [a] -> [a]
myQuickSort _ [] = []
myQuickSort f (x : xs) = myAppend smallerSorted (myAppend [x] biggerSorted)
    where
      biggerSorted = myQuickSort f (myFilter (f x) xs)
      smallerSorted = myQuickSort f (myFilter (\y -> f x y == False) xs)