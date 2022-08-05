esCero :: Int -> Bool    -- ejercicio 1 a)
esCero x = x == 0

esPositivo :: Int -> Bool   -- ejercicio 1 b)
esPositivo x = x > 0

esVocal :: Char -> Bool            -- ejercicio 1 c)
esVocal x = x `elem` "aeiouAEIOU" 


paraTodo :: [Bool] -> Bool   -- ejercicio 2 a)
paraTodo [] = True
paraTodo (x:xs) = x == True && paraTodo xs

sumatoria :: [Int] -> Int    -- ejercicio 2 b)
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs

productoria :: [Int] -> Int   -- ejercicio 2 c)
productoria [] = 1
productoria (x:xs) = x * productoria xs

factorial :: Int -> Int    -- ejercicio 2 d)
factorial 0 = 1
factorial x | x > 0 = x * factorial (x-1)
            | otherwise = error "Numero negativo"

promedio :: [Int] -> Int     -- ejercicio 2 e)
promedio xs = (sumatoria xs) `div` (length xs)

pertenece :: Int -> [Int] -> Bool    -- ejercicio 3
pertenece _ [] = False
pertenece y (x:xs) = x == y || pertenece y xs

paraTodo' :: [a] -> (a -> Bool) -> Bool  -- ejercicio 4 a)
paraTodo' [] _ = True
paraTodo' (x:xs) t = (t x) && paraTodo' xs t

existe' :: [a] -> (a -> Bool) -> Bool    -- ejercicio 4 b)
existe' [] _ = False
existe' (x:xs) t = (t x) || existe' xs t

sumatoria' :: [a] -> (a -> Int) -> Int    -- ejercicio 4 c)
sumatoria' [] _ = 0
sumatoria' (x:xs) t = (t x) + sumatoria' xs t

productoria' :: [a] -> (a -> Int) -> Int     -- ejercicio 4 d)
productoria' [] _ = 1
productoria' (x:xs) t = (t x) * productoria' xs t

paraTodo'' :: [a] -> (a -> Bool) -> Bool   -- ejercicio 5
paraTodo'' xs t = paraTodo' xs t 

todosPares :: [Int] -> Bool        -- ejercicio 6 a)
todosPares xs = paraTodo' xs even

hayMultiplo :: Int -> [Int] -> Bool   -- ejercicio 6 b)
hayMultiplo y xs = existe' xs (\x -> x `mod` y == 0 )

hayMultiplo' :: Int -> [Int] -> Bool   -- ejercicio 6 b) otra solución 
hayMultiplo' y xs = existe' xs ((==0) . (`mod` y))  -- Haskell lee la composición de funciones f: ==0 y g: `mod` y. Entonces f(g(x)) = ((==0)(x ´mod´ y))

sumaCuadrados :: Int -> Int    -- ejercicio 6 c)
sumaCuadrados x = sumatoria' [0..(x-1)] (^2)

factorial' :: Int -> Int       -- ejercicio 6 d)
factorial' x = productoria' [1..x] (*1)

par :: Int -> Int
par x | even x = x
      | otherwise = 1  

multiplicaPares :: [Int] -> Int      -- ejercicio 6 e)
multiplicaPares xs = productoria' xs (\x -> par x)

-- Ejercicio 7
  -- La función map toma y aplica una funcion a una lista dada que da como resultado otra lista.
  -- La función filter toma y aplica un predicado a una lista y devuelve otra lista con los elementos que cumplieron el predicado.
  -- La expresión map succ [1,-4,6,2,-8] equivale a sumar 1 a cada elemento de la lista. Es decir al aplica la funcion map succ a la lista
  --  daria como resultado la lista [2,-3,7,3,-7]
  -- La expresion filter esPositivo [1,-4,6,2,-8] equivale a filtrar los numeros positivos de la lista, es decir da como resultado una lista donde solo
  --  quedan los numeros positivos. En este caso [1,6,2].

duplica :: Num a => [a] -> [a]    -- ejercicio 8 a)
duplica [] = []
duplica (x:xs) = 2*x : duplica xs

duplica' :: Num a => [a] -> [a]    -- ejercicio 8 b)
duplica' xs = map (*2) xs

soloPares :: Integral a => [a] -> [a]    -- ejercicio 9 a)
soloPares [] = []
soloPares (x:xs) | even x == True = x : soloPares xs
                 | otherwise = soloPares xs

soloPares' :: Integral a => [a] -> [a]    -- ejercicio 9 b)
soloPares' xs = filter even xs

multiplicaPares' :: [Int] -> Int          -- ejercicio 9 c)
multiplicaPares' xs = productoria (filter even xs)       

primIgualesA :: Eq a => a -> [a] -> [a]      --ejercicio 10 a)
primIgualesA _ [] = []
primIgualesA n (x:xs) | x == n = x : primIgualesA n xs
                      | otherwise = primIgualesA n []

primIgualesA' :: Eq a => a -> [a] -> [a]     -- ejercicio 10 b)
primIgualesA' n xs = takeWhile (==n) xs

primIguales :: Eq a => [a] -> [a]       -- ejercicio 11 a)
primIguales [] = []
primIguales [x] = [x]
primIguales (x:xs) | x == head xs = x : primIguales xs
                   | otherwise = [x]

primIguales' :: Eq a => [a] -> [a]        -- ejercicio 11 b)
primIguales' xs = primIgualesA' (head xs) xs

{- Ejercicio 12 -}
--Para cada uno de los siguientes patrones, decidí si están bien tipados, y en tal caso da los tipos de cada subexpresión. 
--En caso de estar bien tipado, ¿el patrón cubre todos los casos de definición?

{-
a) f :: (a,b) -> ...
f x = ...
Esta bien tipado. La unica subexpresión es x = (a,b)
Si, el patrón cubre todos los casos.

b) f :: (a, b) -> ...
f (x , y) = ...
Esta bien tipado. La subexpresión x = a y la subexpresión y = b
Si, el patron cubre todos los casos.

c) f :: [(a, b)] -> ...
f (a , b) = ...
No esta bien tipado. Estoy dando como variable una única tupla cuando el tipo de la función es una lista de tuplas.

d) f :: [(a, b)] -> ...
f (x:xs) = ...
Esta bien tipado. La subexpresión x = (a,b) y la subexpresión xs = [(a,b)]
No cubre todos los casos, no esta cubriendo el caso de lista vacia.

e) f :: [(a, b)] -> ...
f ((x, y) : ((a, b) : xs)) = ...
Esta bien tipado. La subexpresión (x,y) = (a,b), la subexpresión (a,b) = (a,b) y la subexpresión xs= [(a,b)]
No cubre todos los casos, no tiene en cuenta el caso de lista de un solo elemento y de lista vacia.

f) f :: [(Int, a)] -> ...
f [(0, a)] = ...
Esta bien tipado. La subexpresión [(0,a)] = [(Int,a)]
No cubre todos los casos, no tiene en cuenta el caso de lista vacia, los casos de listas de mas de un elemento y no cubre todos los casos donde Int es distinto de 0.

g) f :: [(Int, a)] -> ...
f ((x, 1) : xs) = ...
No esta bien tipado. No instance for (Eq a) arising from the literal `1'. Si queremos llamarla como una constante de un tipo a la variable a, tendriamos que definir a 'a' con
las distintas clases de tipos que necesita el tipo de constante que va a tomar (en este caso que es 1, necesitaria Eq, Num)

h) f :: [(Int, a)] -> ...
f ((1, x) : xs) = ...
Esta bien tipado. La subexpresión (1,x) = (Int,a) y la subexpresión xs = [(Int,a)]
No cubre todos los casos, no tiene en cuenta el caso de lista vacia, y tampoco los casos en que el Int del primer elemento de la lista sea distinto de 1.

i) f :: (Int -> Int) -> Int -> ...
f a b = ...
Esta bien tipado. La subexpresión a = (Int -> Int) y la subexpresión b = Int
Si, el patron cubre todos los casos.

j) f :: (Int -> Int) -> Int -> ...
f a 3 = ...
Esta bien tipado. La subexpresión a = (Int -> Int) y la subexpresión 3 = Int
No cubre todos los casos, no tiene en cuenta los casos de que el Int sea distinto de 3.

k) f :: (Int -> Int) -> Int -> ...
f 0 1 2 = ...
No esta bien tipado. No esta tomando una función que tome un Int y devuelva otro Int.

l) f :: a -> (a -> a) -> ...
f a g = ...
Esta bien tipado. La subexpresión a = a y la subexpresión g = (a -> a).
Si, el patrón cubre todos los casos.
-}

{- Ejercicio 13 -}
{-Para las siguientes declaraciones de funciones, da al menos una definción cuando sea
posible (que no sea la expresión undefined). ¿Podés dar alguna otra definición alternativa
a la que diste en cada caso? -}

{- 
a) f :: (a,b) -> b
 f (x,y) = y
 Otra posibilidad:
 f x = snd x

b) f :: (a,b) -> c
No es posible dar una definición

c) f :: a -> b
No es posible dar un definición

d) f :: (a -> b) -> a -> b
 f g x = g x
 No hay otra definición alternativa

 e) f :: (a -> b) -> [a] -> [b]
 f g xs = g xs
 Otras posibilidades:
 f _ [] = []
 f g (x:xs) = g x : g xs

 f) f :: (a -> b) -> a -> c
 No es posible dar un definición

 g) f :: (a -> b) -> (b -> c) -> a -> c
 f g h x = h(g x)
-}
