{-
-- EPITECH PROJECT, 2022
-- $PROJECT_NAME
-- File description:
-- $DESCRIPTION
-}

import Data.Char (isDigit)
import System.Environment (getArgs)
import System.Exit (ExitCode (ExitFailure), exitWith)
import Text.Read (readMaybe)

-- Task 01

myElem :: (Eq a) => a -> [a] -> Bool
myElem _ [] = False
myElem x (y : ys)
  | x == y = True
  | otherwise = myElem x ys

-- Task 02

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv x y
  | div x y == 0 = Nothing
  | otherwise = Just (div x y)

-- Task 03

safeNth :: [a] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth (x:xs) 0 = Just x
safeNth (x : xs) i = safeNth xs (i - 1)

-- Task 04

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just n)
  | n == maxBound = Nothing
  | otherwise = Just (n + 1)
-- Task 05

myLookup :: (Eq a) => a -> [(a, b)] -> Maybe b
myLookup _ [] = Nothing
myLookup x (y : ys)
  | myFst y == x = Just (mySnd y)
  | otherwise = myLookup x ys
  where
    myFst :: (a, b) -> a
    myFst (a, b) = a
    mySnd :: (a, b) -> b
    mySnd (a, b) = b

-- Task 06

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo f x y = do
  x' <- x
  f x' <$> y

-- Task 07

readInt :: [Char] -> Maybe Int
readInt (x : xs)
  | all isDigit xs = Just (read (x : xs))
  | otherwise = Nothing

-- Task 08

getLineLength :: IO Int
getLineLength = length <$> getLine

-- Task 09

printAndGetLength :: String -> IO Int
printAndGetLength x = putStrLn x >>
  return (length x)

-- Task 10

printBox :: Int -> IO ()
printBox x
  | x <= 0 = return ()
  | otherwise = printBox' x x
  where
    printBox' :: Int -> Int -> IO ()
    printBox' 0 _ = return ()
    printBox' x iteration =
      if isStartOrEnd iteration x
        then putStrLn ('+' : (replicate ((iteration * 2) - 2) '-' ++ "+")) >>
             printBox' (x - 1) iteration
        else putStrLn ('|' : (replicate ((iteration * 2) - 2) ' ' ++ "|")) >>
             printBox' (x - 1) iteration
    isStartOrEnd :: Int -> Int -> Bool
    isStartOrEnd x y = x == y || y == 1

-- Task 11

concatLines :: Int -> IO String
concatLines 0 = return ""
concatLines x = concatLines' x []
  where
    concatLines' :: Int -> [String] -> IO String
    concatLines' 1 [] = return ""
    concatLines' 0 (y : ys) =
      return ('"' : concat (reverse (y : ys)) ++ "\"")
    concatLines' x y = do
      line <- getLine
      concatLines' (x - 1) (line : y)

-- Task 12

getInt :: IO (Maybe Int)
getInt = readInt <$> getLine

-- Task 13

calculate :: Int -> String -> Int -> Maybe Int
calculate n1 op n2 = case op of
  "+" -> Just (n1 + n2)
  "-" -> Just (n1 - n2)
  "*" -> Just (n1 * n2)
  "/" -> if n2 /= 0 then Just (n1 `div` n2) else Nothing
  "%" -> Just (n1 `mod` n2)
  _ -> Nothing

main :: IO ()
main = do
  args <- getArgs
  case args of
    -- in the case where it is a string [3] and there are 2 Just num because the readInt is succesful and the result is a Just (succeeds), print the output, if Nothing is returned, exit with 84
    [n1, op, n2] -> case (readInt n1, readInt n2) of
      (Just num1, Just num2) -> case calculate num1 op num2 of
        Just result -> print result
        Nothing -> exitWith (ExitFailure 84)
      _ -> exitWith (ExitFailure 84)
    _ -> exitWith (ExitFailure 84)