{-
-- EPITECH PROJECT, 2022
-- $PROJECT_NAME
-- File description:
-- $DESCRIPTION
-}

-- Task 11

-- can store any type of data
-- data stored in a node and two children
data Tree a = Empty | Node (Tree a) a (Tree a) deriving (Show, Read, Eq)

-- Task 12

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree x Empty = Node Empty x Empty
addInTree x (Node l y r)
    | x < y     = Node (addInTree x l) y r
    | otherwise = Node l y (addInTree x r)


-- Task 13

instance Functor Tree where
    fmap _ Empty = Empty
    fmap f (Node l x r) = Node (fmap f l) (f x) (fmap f r)

-- Task 14

listToTree :: Ord a => [a] -> Tree a
listToTree [] = Empty
listToTree (x:xs) = addInTree x (listToTree xs)

-- Task 15

-- traverse tree and store in an array each new element
treeToList :: Tree a -> [a]
treeToList Empty = []
treeToList (Node l x r) = treeToList l ++ [x] ++ treeToList r

-- Task 16

treeSort :: Ord a => Tree a -> [a]
treeSort x = sort' (<) (treeToList x)
    where
        sort' :: (a -> a -> Bool) -> [a] -> [a]
        sort' _ [] = []
        sort' f (x : xs) = smallerSorted ++ [x] ++ biggerSorted
            where
              biggerSorted = sort' f (filter (f x) xs)
              smallerSorted = sort' f (filter (not . f x) xs)

-- Task 17

instance Foldable Tree where
    foldr _ acc Empty = acc
    foldr f acc (Node l x r) = foldr f (f x (foldr f acc r)) l