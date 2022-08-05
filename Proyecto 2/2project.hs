{- Ejercicio 1 -}
data Carrera = Matematica | Fisica | Computacion | Astronomia deriving (Eq,Ord,Bounded,Show)

titulo :: Carrera -> String
titulo Matematica = "Licenciatura en Matematica"
titulo Fisica = "Licenciatura en Fisica"
titulo Computacion = "Licenciatura en ciencias de la Computacion"
titulo Astronomia = "Licenciatura en Astronomia"

{- Ejercicio 3 -}
type Ingreso = Int

data Cargo = Titular | Asociado | Adjunto | Asistente | Auxiliar   deriving (Show)
data Area = Administrativa | Enseñanza | Economica | Psotgrado    deriving (Show)

data Persona = Decane | Docente Cargo | NoDocente Area | Estudiante Carrera Ingreso deriving (Show)

{- ¿Cuál es el tipo del constructor Docente?
Docente es de tipo Persona.
Docente :: Cargo -> Persona
-}

cuantos_doc :: [Persona] -> Cargo -> Int
cuantos_doc [] _ = 0
cuantos_doc ((Docente Titular):xs) Titular = 1 + cuantos_doc xs Titular
cuantos_doc ((Docente Asociado):xs) Asociado = 1 + cuantos_doc xs Asociado
cuantos_doc ((Docente Adjunto):xs) Adjunto = 1 + cuantos_doc xs Adjunto
cuantos_doc ((Docente Asistente):xs) Asistente = 1 + cuantos_doc xs Asistente
cuantos_doc ((Docente Auxiliar):xs) Auxiliar = 1 + cuantos_doc xs Auxiliar
cuantos_doc (_:xs) c = cuantos_doc xs c


 -- Otra posibilidad

igualCargo :: Cargo -> Cargo -> Bool
igualCargo Titular Titular = True
igualCargo Asociado Asociado = True
igualCargo Adjunto Adjunto = True 
igualCargo Asistente Asistente = True 
igualCargo Auxiliar Auxiliar = True
igualCargo _ _ = False

cuantos_doc' :: [Persona] -> Cargo -> Int
cuantos_doc' [] _ = 0
cuantos_doc' ((Docente c1):xs) c2 | igualCargo c1 c2 = 1 + cuantos_doc xs c2
                                  | otherwise = cuantos_doc xs c2
cuantos_doc' (_:xs) c2 = cuantos_doc xs c2

 -- Hacemos la misma función anterior pero esta vez usando usando filter

igualCargo_v2 :: Cargo -> Persona -> Bool
igualCargo_v2 x (Docente y) = igualCargo x y
igualCargo_v2 _ _ = False

cuantos_doc_f :: [Persona] -> Cargo -> Int
cuantos_doc_f xs c = length (filter (igualCargo_v2 c) xs)

{- Ejercicio 4 -}
primerElemento :: [a] -> Maybe a
primerElemento [] = Nothing
primerElemento (x:_) = Just x

{- Ejercicio 5 -}
data Cola = VaciaC | Encolada Persona Cola deriving (Show)

atender :: Cola -> Maybe Cola
atender VaciaC = Nothing
atender (Encolada _ c) = Just c 

encolar :: Persona -> Cola -> Cola
encolar p VaciaC = Encolada p VaciaC
encolar p (Encolada p2 c) = Encolada p2 (encolar p c) 

{-busca' :: Cola -> Cargo -> Maybe Persona
busca' cola cargo = case cola of             -- No funciona, toma el primer cargo que encuentra, el case no da importancia al parametro Cargo de la izquierda, lo ignora
	            VaciaC -> Nothing
	            (Encolada (Docente cargo) _) -> Just (Docente cargo)
	            (Encolada (Docente _) cola2) -> busca' cola2 cargo
	            (Encolada _ cola2) -> busca' cola2 cargo -}


busca :: Cola -> Cargo -> Maybe Persona                    -- Esta si funciona. No se si es eficiente.
busca VaciaC _ = Nothing
busca (Encolada (Docente cargo) cola) cargo2 | igualCargo cargo cargo2 = Just (Docente cargo)
                                             | otherwise = busca cola cargo2
busca (Encolada _ cola) cargo2 = busca cola cargo2 

{- ¿A qué otro tipo se parece Cola?
Se parece al tipo Lista. Donde VaciaC = [] , Encolada = :
Por ejemplo:
3:(2:(5:[])
(Encolada Decane(Encolada (Docente Titular) (Encolada (NoDocente Economica) (VaciaC))))
-}


{- Ejercicio 6 -}
data ListaAsoc a b = Vacia | Nodo a b (ListaAsoc a b)  deriving (Show)

type Diccionario = ListaAsoc String String
type Padron = ListaAsoc Int String

{- Para representar la información almacenada en una guía telefónica se debe instanciar ListaAsoc de la siguiente forma:
 type GuiaTelefonica = ListaAsoc String Int
  Donde el String corresponde a quien corresponde el número de teléfono y el Int al número de teléfono.-}

la_long :: ListaAsoc a b -> Int
la_long Vacia = 0
la_long (Nodo _ _(la)) = 1 + la_long (la)

la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b
la_concat Vacia la = la
la_concat (Nodo a b (la1)) (la2) = Nodo a b (la_concat (la1) (la2))

la_pares :: ListaAsoc a b -> [(a,b)]
la_pares Vacia = []
la_pares (Nodo a b (la)) = (a,b) : la_pares la

la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b
la_busca Vacia _ = Nothing
la_busca (Nodo a b (la)) x | a == x = Just b
                           | otherwise = la_busca la x

la_borrar :: Eq a => a -> ListaAsoc a b -> ListaAsoc a b
la_borrar _ Vacia = Vacia
la_borrar x (Nodo a b (la)) | a == x = la
                            | otherwise = Nodo a b (la_borrar x (la))

-- (Nodo 1 2 (Nodo 2 3 (Nodo 9 10(Vacia))))  (Nodo 100 200 (Nodo 300 400(Vacia)))

{- Ejercicio 7 -}
data Arbol a = Hoja | Rama (Arbol a) a (Arbol a) deriving (Show)

type Prefijos = Arbol String

a_long :: Arbol a -> Int
a_long Hoja = 0
a_long (Rama ar1 a ar2) = 1 + a_long ar1 + a_long ar2

a_hojas :: Arbol a -> Int
a_hojas Hoja = 1
a_hojas (Rama ar1 a ar2) = 0 + a_hojas ar1 + a_hojas ar2

a_inc :: Num a => Arbol a -> Arbol a
a_inc Hoja = Hoja
a_inc (Rama ar1 a ar2) = (Rama (a_inc ar1) (a+1) (a_inc ar2))

a_map :: (a -> b) -> Arbol a -> Arbol b
a_map _ Hoja = Hoja
a_map f (Rama ar1 a ar2) = (Rama (a_map f ar1) (f a) (a_map f ar2))

a_inc' :: Num a => Arbol a -> Arbol a
a_inc' Hoja = Hoja
a_inc' (Rama ar1 a ar2) = a_map (+1) (Rama ar1 a ar2)


-- (Rama (Rama (Rama Hoja (-1) Hoja ) 1 (Rama Hoja (0) Hoja ) ) 2 (Rama (Rama Hoja 4 Hoja) 3 (Rama Hoja 5 Hoja )) )