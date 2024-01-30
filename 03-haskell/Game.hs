import GHC.Unit.Database (GenericUnitInfo(unitIsTrusted))
{-
-- EPITECH PROJECT, 2022
-- $PROJECT_NAME
-- File description:
-- $DESCRIPTION
-}

-- Task 01
-- Task 02

data Item = Sword | Bow | MagicWand deriving (Eq)

-- Task 03

-- For making our type an instance of the Show superclass

instance Show Item where
    show Sword = "sword"
    show Bow = "bow"
    show MagicWand = "magic wand"

-- Task 04

data Mob = Mummy | Skeleton Item | Witch (Maybe Item) deriving (Eq)

-- Task 05

createMummy :: Mob -- a Mummy
createMummy = Mummy

createArcher :: Mob -- a Skeleton holding a Bow
createArcher = Skeleton Bow

createKnight :: Mob -- a Skeleton holding a Sword
createKnight = Skeleton Sword

createWitch :: Mob -- a Witch holding Nothing
createWitch = Witch Nothing

createSorceress :: Mob -- a Witch holding a MagicWand
createSorceress = Witch (Just MagicWand)

-- Task 06

create :: String -> Maybe Mob
create x = case x of
    "mummy" -> Just createMummy
    "doomed archer" -> Just createArcher
    "dead knight" -> Just createKnight
    "witch" -> Just createWitch
    "sorceress" -> Just createSorceress
    _ -> Nothing

-- Task 07

equip :: Item -> Mob -> Maybe Mob
equip x y = case y of
    Mummy -> Nothing
    Skeleton _ -> Just y
    Witch _ -> Just y

-- Task 08
instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton x) = "skeleton holding a " ++ show x
    show (Witch Nothing) = "witch"
    show (Witch (Just MagicWand)) = "sorceress"
    show (Witch (Just x)) = "witch holding a " ++ show x

-- Task 09

class HasItem a where
    getItem :: a -> Maybe Item
    hasItem :: a -> Bool

-- Task 10

instance HasItem Mob where
    hasItem Mummy = False
    hasItem (Skeleton _) = True
    hasItem (Witch Nothing) = False
    hasItem (Witch _) = True

    getItem Mummy = Nothing
    getItem (Skeleton x) = Just x
    getItem (Witch x) = x