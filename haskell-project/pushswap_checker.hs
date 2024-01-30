{-
-- EPITECH PROJECT, 2024
-- pushswap_checker
-- File description:
-- main file
-}

import Data.Char (isDigit)
import System.Environment (getArgs)
import System.Exit (ExitCode (ExitFailure), exitWith)
import Data.List (sort, intercalate)

data StackOp = SA | SB | SC | PA | PB | RA | RB | RR | RRA | RRB | RRR
    deriving (Show, Eq)

applyOp :: StackOp -> [Int] -> [Int] -> ([Int], [Int])
applyOp SA [] y = ([], y)
applyOp SA (x:y:xs) ys = (y:x:xs, ys)
applyOp SA x y = (x, y)
applyOp SB x [] = (x, [])
applyOp SB xs (y:y':ys) = (xs, y':y:ys)
applyOp SB x y = (x, y)
applyOp SC l_a l_b = (fst (applyOp SA l_a l_b), snd (applyOp SB l_a l_b))
applyOp PA x [] = (x , [])
applyOp PA xs (y:ys) = (y:xs, ys)
applyOp PB [] x = ([] , x)
applyOp PB (x:xs) ys = (xs, x:ys)
applyOp RA [] x = ([], x)
applyOp RA (x:xs) ys = (xs ++ [x], ys)
applyOp RB x [] = (x , [])
applyOp RB xs (y:ys) = (xs, ys ++ [y])
applyOp RR l_a l_b = (fst (applyOp RA l_a l_b), snd (applyOp RB l_a l_b))
applyOp RRA [] x = ([], x)
applyOp RRA l_a l_b = (rotateEnd l_a, l_b)
    where rotateEnd [] = []
          rotateEnd xs = last xs : init xs
applyOp RRB x [] = (x, [])
applyOp RRB l_a l_b = (l_a, rotateEnd l_b)
    where rotateEnd [] = []
          rotateEnd xs = last xs : init xs
applyOp RRR l_a l_b = (rotateEnd l_a, rotateEnd l_b)
    where rotateEnd [] = []
          rotateEnd xs = last xs : init xs

applyOps :: [StackOp] -> [Int] -> [Int] -> ([Int], [Int])
applyOps ops l_a l_b = foldl (\(a, b) op -> applyOp op a b) (l_a, l_b) ops

readOperations :: IO [StackOp]
readOperations = do
    ops <- words <$> getLine
    mapM parseOp ops
  where
    opTable = [("sa", SA), ("sb", SB), ("sc", SC), ("pa", PA), ("pb", PB),
               ("ra", RA), ("rb", RB), ("rr", RR), ("rra", RRA),
               ("rrb", RRB), ("rrr", RRR)]
    parseOp opStr = case lookup opStr opTable of
        Just op -> return op
        Nothing -> exitWith (ExitFailure 84)

checkAndPrint :: [StackOp] -> [Int] -> [Int] -> IO ()
checkAndPrint ops initialList finalList =
    if sort finalList == finalList && null initialList
        then putStrLn "OK"
        else putStr "KO: (" >>
          putStr (show finalList) >>
          putStr "," >>
          putStr (show initialList) >>
          putStrLn ")" >>
          exitWith (ExitFailure 84)

readInt :: [Char] -> Maybe Int
readInt "" = Nothing
readInt str
  | all isDigit str = Just (read str)
  | head str == '+' && all isDigit (tail str) = Just (read (tail str))
  | head str == '-' && all isDigit (tail str) = Just (read str)
  | otherwise = Nothing

processArgs :: [String] -> IO ()
processArgs [] = putStrLn "Usage: ./pushswap_checker <op list> | <int list>" >>
                 exitWith (ExitFailure 84)
processArgs x = maybe (exitWith (ExitFailure 84)) processList (mapM readInt x)

processList :: [Int] -> IO ()
processList initialList = do
    operations <- readOperations
    let (finalList, l_b) = applyOps operations initialList []
    checkAndPrint operations l_b finalList

main :: IO ()
main = getArgs >>= processArgs