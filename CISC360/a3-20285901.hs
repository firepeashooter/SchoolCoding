-- CISC 360 a3, Fall 2023

-- SEE THE FILE a3.pdf
-- for instructions

module A3
where
import Data.List

-- Rename this file to include your student ID: a3-studentid.hs
-- Also, add your student ID number after the "=":
student_id :: Integer
student_id = 20285901

{- If you are working in a group of 2, uncomment the line below and add the second student's ID number: -}
-- second_student_id =
{- If you are working in a group of 2, uncomment the line above. -}


-- THIS FILE WILL NOT COMPILE UNTIL YOU ADD YOUR STUDENT ID ABOVE
check_that_you_added_your_student_ID_above = ()


-- Variable is a synonym for String.
type Variable = String

-- In our simplified version of classical propositional logic,
-- we have the following definition for a Formula:
data Formula = Top                      -- truth (always true)
             | Bot                      -- falsehood (contradiction)
             | And Formula Formula      -- conjunction
             | Or Formula Formula       -- disjunction
             | Implies Formula Formula  -- implication
             | Not Formula              -- negation
             | Atom Variable            -- atomic proposition ("propositional variable")
             deriving (Eq, Show)

-- Some atoms, for convenience
vA = Atom "A"
vB = Atom "B"
vC = Atom "C"
vD = Atom "D"
vE = Atom "E"
vF = Atom "F"
vp = Atom "p"
vq = Atom "q"

-- Some example formulas that you can use to test your functions
formula1  = Implies (And vA vB) vC
formula2  = Implies Bot (And vA vB)
formula3  = Implies (And vA vB) Top
formula4  = And (Implies vA (And vB vC)) (And vD vE)
formula5  = And vA vB
formula6  = Not vA
formula7  = Implies vA vB
formula8  = Or vA (Not vA)
formula9  = Or vA (Not vB)


{-
Q1: Horn clauses

Write a function that tells us whether a given formula is a *fact* (a single positive literal)
or a *rule* (an implication whose antecedent is a conjunction of positive literals, and whose conclusion is a positive literal).

   1. Positive literals:
      an Atom is a *positive literal*.

   2. Conjunctions of positive literals:
  
       - a positive literal is a *conjunction of positive literals*;
       - an And of conjunctions of positive literals
         is a *conjunction of positive literals*.

      For example, Atom "X" is a positive literal, so it is a conjunction of positive literals.
      And (Atom "B") (Atom "C") is an And of positive literals, so it is a conjunction of positive literals.
      And (And (Atom "B") (Atom "C")) (Atom "D") is a conjunction of positive literals.

   3. Facts:
      a positive literal is a *fact*.

   4. Rules:
      an implication (Implies formula1 formula2) is a *rule* iff formula1 is a conjunction of positive literals, and formula2 is a positive literal.
      
If you're familiar with grammars, the above definitions can also be expressed as:

   <pos-lit> ::= Atom <string>

   <conj>    ::= <pos-lit>
               | And <conj> <conj>

   <fact>    ::= <pos-lit>

   <rule>    ::= Implies <conj> <pos-lit>
-}
data FormulaKind = Fact | Rule | NotClause
                   deriving (Show, Eq)

{- Q1a: 'classify'

Write a function

   classify :: Formula -> FormulaKind

that takes a Formula, and returns:

     Fact       if the formula is a fact
     Rule       if the formula is a rule
     NotClause  if the formula is neither a fact nor a rule 

You will probably need to write at least one helper function.
-}
classify :: Formula -> FormulaKind

classify (Atom _) = Fact
classify(Implies f1 f2) = if isConjOfLiterals f1 && isPositiveLiteral f2 then Rule else NotClause
classify _ = NotClause


isPositiveLiteral :: Formula -> Bool

isPositiveLiteral (Atom _) = True
isPositiveLiteral _ = False

isConjOfLiterals :: Formula -> Bool

isConjOfLiterals (Atom _) = True
isConjOfLiterals (And f1 f2) = isConjOfLiterals f1 && isConjOfLiterals  f2
isConjOfLiterals _ = False


{- Q1b: test cases

Write test cases that completely "cover" the input, output, and code
of 'classify'.  See a3.pdf.
-}
test_classify1 :: Bool
test_classify1 = (classify (Atom "T") == Fact)
{- add your test cases here: -}

--Rule Test
test_classify2 :: Bool
test_classify2 = (classify (Implies (And (Atom "T") (Atom "S")) (Atom "R")) == Rule)

--Extra rule test to see if we can still get it without the and
test_classify3 :: Bool
test_classify3 = (classify (Implies (Atom "T") (Atom "R")) == Rule)

--Not Positive LIteral Test
test_classify4 :: Bool
test_classify4 = (classify (Implies (Atom "T") (Not(Atom "S"))) == NotClause)

--Not Conj Of Literals Test
test_classify5 :: Bool
test_classify5 = (classify (Implies (Not (Atom "T")) (Atom "S")) == NotClause)

--Testing Fallthrough case
test_classify6 :: Bool
test_classify6 = (classify (Not(Atom "T")) == NotClause)


test_classify :: Bool
test_classify = all (\x -> x) [test_classify1, test_classify2, test_classify3, test_classify4, test_classify5, test_classify6
                               ] --           ^ add your test cases here
{- The library function 'all' applies its first argument to each element in the list,
   and returns True iff the first argument returns True every time. -}



{-
Q2: Truth Tables

-- 2023-10-27 in lecture:
      (And (Atom "p") (Atom "q"))    p ∧ q
      
        p     q       p ∧ q      All the valuations of  p, q:
        True  True    True     [ [("p", True), ("q", True)],
        True  False   False      [("p", True), ("q", False)],
        False True    False      [("p", False), ("q", True)],
        False False   False      [("p", False), ("q", False)] ]

To build a truth table for a formula, there are 4 steps:

  1) Traverse the formula to find all atomic propositions (propositional variables).
     for the above example (And (Atom "p") (Atom "q")), return  ["p", "q"]

  2) Find all the possible valuations---combinations of True and False
      for the atomic propositions in the formula.

  3) Evaluate the formula for each valuation obtained in (2).

  4) Use the results of (1-3) to build the table.

In this question, you will implement steps (1-3).
-}


-- A Valuation is a list of pairs corresponding to a truth value (i.e. True or False)
--  for each atom in a formula
type Valuation = [(Variable, Bool)]

-- A TruthTable is an enumeration of the valuations for a given formula,
-- with each valuation paired with the corresponding evaluation of that formula.
-- (This corresponds to a truth table with no "intermediate columns".)
data TruthTable = TruthTable [(Valuation, Bool)]

{-
   This function is here so that when you print a TruthTable in GHCi, the table is nice and readable.
   You don't need to understand how this works to complete the assignment.
-}
instance Show TruthTable where
  show (TruthTable rows) =
    case rows of
      [] -> ""
      ([], result) : _ -> "   result is " ++ pad_show result ++ "\n"
      ((c,b) : valu, result) : xs -> 
        c ++ "=" ++ (pad_show b) ++ "   "
          ++ show (TruthTable [(valu,result)])
          ++ show (TruthTable xs)
    where
      pad_show True  = "True "
      pad_show False = "False"

{-
  Q2a: getVariables:

  Traverse a formula and build a list of all Variables in the formula, without duplicates.

  You may use the built-in function "nub", which takes a list and returns the list
  without duplicates.
-}
getVariables :: Formula -> [Variable]

getVariables Top               = []
getVariables Bot               = []

getVariables (Atom v)          = [v]

getVariables (Not phi)         = getVariables phi
getVariables (And phi1 phi2)   = nub (getVariables phi1 ++ getVariables phi2)
getVariables (Or phi1 phi2)    = nub (getVariables phi1 ++ getVariables phi2)
getVariables (Implies phi psi) = nub (getVariables phi ++ getVariables psi)

{-
   Q2b: getValuations:

   Build a list of all possible valuations for a set of atomic propositions
-}
getValuations :: [Variable] -> [Valuation]
getValuations []       = [[]]               -- I can't see how returning [] could work
getValuations (c : cs) = (map ((c, True) :) (getValuations cs)) ++ (map ((c, False) :) (getValuations cs))
{-
                       = ...     getValuations cs

getValuations ("a" : []) =      getValuations []

     getValuations ["a"]    =  [ [("a", True)], [("a", False)] ]

     getValuations []       =  [ [] ]

     Can we take   [[]]
     and build     [ [("a", True)],
                     [("a", False)] ]

     ?          =  [ ("a", True) :  [],
                     ("a", False) : [] ]

     two_power n: return 2 raised to the n

      n         n - 1
     2  =  2 · 2              (for n ≥ 1)

     two_power n: try returning 2 * two_power (n - 1)
-}

{-
  Hint: To apply a function f to every element of a list xs,
   write  map f xs.
  For example, the following adds 1 to the start of every list
   in a list of lists [[2,3], [2,4]]:
   map (\ys -> 1 : ys) [[2,3], [2,4]]  ==  [[1,2,3], [1,2,4]]
-}

{-
   Q2c: evalF:
    Evaluate a formula with a particular valuation,
     returning the resulting boolean value
-}
evalF :: Valuation -> Formula -> Bool
evalF valu formula =
    case formula of
        Top               -> True
        Bot               -> False
        Not phi1          -> not (evalF valu phi1)
        Implies phi1 phi2 -> not (evalF valu phi1) || (evalF valu phi2)
        Atom c            -> undefined
         -- search for (c, q) in valu
         -- and return q
         -- if valu were [("a", False), ("b", True)],
         --  evalF valu (Atom "b") should return True
         --  evalF valu (Atom "a") should return False
         -- Question: can we assume each atom appears in the valuation exactly once?
         --           Yes
         -- evalF [] (Atom "a")        result could be  whatever you want
         --    if you want, could call  error "unknown variable in valuation"
        And phi1 phi2     -> (evalF valu phi1) && (evalF valu phi2)
        Or phi1 phi2      -> (evalF valu phi2) || (evalF valu phi2)

-- buildTable:
--  Build a truth table for a given formula.
--  You can use this function to help check your definitions
--  of getVariables, getValuations and evalF.
buildTable :: Formula -> TruthTable
buildTable psi =
  let valuations = getValuations (getVariables psi)
  in
    TruthTable (zip valuations
                    (map (\valu -> evalF valu psi) valuations))


{-
Q3: Tiny Theorem Prover

    This question asks you to complete an implementation of a
    continuation-based backtracking theorem prover that follows the rules
    given in a3.pdf.
 
    The prover is structured using two functions that do all the work,
    and one function that "kicks off" the process by passing continuations:

       prove_core  looks at the goal formula (the formula we're trying to prove),
                     trying the -Right rules;
 
       prove_left  looks at the assumptions, trying the -Left rules;

       prove_all   calls prove_core, collecting all solutions.
                                    
    [X] Use-Assumption
    [ ] Top-Right                   Top introduction   ⊤-intro    
    [X] Implies-Right               implication introduction  →i
    [X] And-Right                   ∧i
    [ ] Or-Right-1 and Or-Right-2   ∨i1 ∨i2
    
    [X] Bot-Left                    ⊥e
    [X] Implies-Left                →e
    [ ] And-Left                    ∧e1, ∧e2
    [ ] Or-Left                     ∨e
-}

-- a Context is a list of Formulas, representing assumptions
type Context = [Formula]

{- A Derivation represents the rules used to construct a proof.

   For example, if we prove

    [vB] |- (And vB Top)
     
   by using UseAssumption to prove vB, TopRight to prove Top, and then AndRight,
   the Derivation would be

     AndRight (UseAssumption vB) TopRight

   As a tree, drawn the way computer scientists usually draw it, this looks like

               AndRight
              /        \
       UseAssumption   TopRight
            vB

   But it's easier to see the connection to the rules if we draw the root at the bottom:

            vB                        ---------- UseAssumption       ----------- TopRight
       UseAssumption   TopRight       [vB] |- vB                     [vB] |- Top
              \        /              --------------------------------------------------- AndRight
               AndRight                               [vB] |- And vB Top

The arguments to a Derivation constructor represent the premises used,
or for UseAssumption, the assumption formula being used.

OrRight takes an extra first argument indicating whether rule OrRight-1 or OrRight-2
was used.

For example,

   [OrRight 2 (UseAssumption vB)]

should be returned by

   prove_all [vB] (Or vA vB)

-}
data Derivation = UseAssumption Formula
                | TopRight
                | BotLeft
                | ImpliesRight Derivation
                | AndRight Derivation Derivation
                | ImpliesLeft Derivation Derivation
                | AndLeft Derivation
                | OrLeft Derivation Derivation
                | OrRight Int Derivation
                deriving (Show, Eq)

{-
  prove_core: Given a context, a formula, and two continuations representing success and failure,
          call the appropriate continuation.
-}
prove_core :: Context         -- formulas being assumed (to the left of the turnstile  |-  )
           -> Formula         -- goal formula to be proved (to the right of the turnstile)
           -> (Derivation -> (() -> b) -> b,
                              -- kSucceed: call this if we proved the formula,
                              --    with the constructed Derivation and a function to call to get more proofs
               () -> b)       -- kFail: call this if we can't prove the formula
           -> b

--  [Top] ⊢ Top


prove_core ctx goal (kSucceed, kFail) =
  let try_prove_left () = prove_left ctx ([], ctx) goal (kSucceed, kFail)
      try_right_rules () =
           case goal of
                Top              -> -- Top-Right rule        --      ––––––––– Top-Right
                     -- undefined                            --      ctx ⊢ Top              ⊤   by ⊤intro
                     -- we have succeeded
                     -- call kSucceed  ::  Derivation -> (() -> b) -> b
                     --
                     kSucceed TopRight (\() -> try_prove_left)   -- almost correct (please don't correct it right now)
                     

                Implies phi psi  -> -- Implies-Right rule
                     prove_core (phi : ctx)
                            psi
                            (\deriv -> \more ->
                                 kSucceed (ImpliesRight deriv) more,
                             try_prove_left)

                And phi1 phi2    -> -- And-Right rule
                     prove_core ctx phi1
                            (\deriv1 -> \more1 ->
                                 prove_core ctx phi2
                                      (\deriv2 -> \more2 ->
                                          kSucceed (AndRight deriv1 deriv2)
                                                   more2,
                                       more1),
                                 try_prove_left)

                Or phi1 phi2     -> -- Or-Right rules (try Or-Right-1, if it fails, try Or-Right-2)
                     undefined
                
                _                 -> -- Can't use any of the -Right rules, so:
                     try_prove_left ()
  in
    if elem goal ctx then  -- Use-Assumption rule
      kSucceed (UseAssumption goal) try_right_rules
    else
      try_right_rules ()

{-
  prove_left: Given an original context,
                    a context that prove_left has already processed,
                    a context that prove_left has not processed,
                    a goal formula,
                    and two continuations,
                    call the appropriate continuation.
-}
prove_left :: Context              -- the original context
           -> (Context, Context)   -- the "done" context, and the "to do" context
           -> Formula              -- the goal formula
           -> (Derivation -> (() -> b) -> b,            -- kSucceed: call this if we proved the formula
               () -> b)            -- kFail: call this if we can't prove the formula
           -> b
           
prove_left original (done, []) goal (kSucceed, kFail) =
                       --  ^^ the "to do" context is empty, so there's nothing remaining to examine
    if original == done then
        -- prove_left looked at everything but didn't change the context at all, so fail
        kFail ()
    else
        -- prove_left changed something, so we are giving prove_core stronger assumptions
        prove_core done goal (kSucceed, kFail)
        
prove_left original (done, focus : rest) goal (kSucceed, kFail) =

    let leave_alone () =   -- leave_alone: Call this to move "focus", the head of the to-do list,
                           --              into the "done" list without changing "focus"
            prove_left original (done ++ [focus], rest) goal (kSucceed, kFail)
    in
      case focus of
        Bot ->                -- Bot-Left rule
            kSucceed BotLeft leave_alone
            
        Implies phi1 phi2 ->  -- Implies-Left rule
            prove_core (done ++ rest) phi1 (-- kSucceed:
                                        \deriv1 -> \more1 ->
                                             prove_core (done ++ [phi2] ++ rest)
                                                    goal
                                                    (\deriv2 -> \more2 ->
                                                        kSucceed (ImpliesLeft deriv1 deriv2) more2,
                                                     more1),
                                        -- kFail:
                                        leave_alone)
 
        And phi1 phi2 ->      -- And-Left rule
            undefined
        
        Or phi1 phi2 ->       -- Or-Left rule
            undefined
 
        focus -> leave_alone ()


{-
  prove_all: Given a context and a formula,
             collect all possible derivations that prove the formula (according to the rules given in a3.pdf).
-}
prove_all :: Context -> Formula -> [Derivation]
prove_all ctx goal = prove_core ctx goal (\deriv -> \more -> deriv : (more ()),
                                      \() -> [])

{-
  prove: Given a context and a formula,
         return True if the formula is provable using the rules given in a3.pdf,
            and False otherwise.
-}
prove :: Context -> Formula -> Bool
prove ctx goal = prove_core ctx goal (\deriv -> \more -> True,   -- success continuation (what to call if prove_core
                                                                 --  can prove  goal)
                                      \() -> False)              -- failure continuation (what to call if prove_core
                                                                 --  cannot prove  goal)
{-                                    \x -> x - 1  
                                      \deriv -> (\more -> True)
                                     (\x -> (\y -> y - x))
                                     \() -> False
                                     \z -> False
-}

test_imp1 = prove [Implies vB vC] (Implies vB vC)
test_imp2 = prove [Implies vB vC] (Implies (And vB vB) vC)
test_imp3 = not (prove [Implies (And vB vD) vC] (Implies vB vC))

test_imps = test_imp1 && test_imp2 && test_imp3

test_or1 = prove [Or vA vB] (Or vB vA)
test_or2 = prove [Or vC (And vA (Implies vA vB))] (Or vB vC)
test_or3 = prove [vA, Or (Implies vA vB) (Implies vA vC)] (Or vB (Or vB vC))
test_or4 = not (prove [Or vC (And vA (Implies vA vD))] (Or vB vC))
test_or5 = elem (OrRight 1 (UseAssumption vB)) (prove_all [vA, vB] (Or vB vA))
        && elem (OrRight 2 (UseAssumption vA)) (prove_all [vA, vB] (Or vB vA))
test_ors = test_or1 && test_or2 && test_or3 && test_or4 && test_or5



{-
  Q4 bonus: See a3.pdf.  If you do the bonus, COPY THIS FILE into a3bonus.hs first.
            Submit both files.
-}


