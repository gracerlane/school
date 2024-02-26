// Expression type (DO NOT MODIFY)
type Expression =
	| X
	| Y
	| Const of float
	| Neg of Expression
	| Add of Expression * Expression
	| Sub of Expression * Expression
	| Mul of Expression * Expression

// exprToString formatting function (DO NOT MODIFY)
let exprToString expr =
	let rec recExprStr parens expr =
		let lParen = if parens then "(" else ""
		let rParen = if parens then ")" else ""
		match expr with
		| X -> "x"
		| Y -> "y"
		| Const n -> n.ToString()
		| Neg e -> lParen + "-" + recExprStr true e + rParen
		| Add (e1, e2) -> lParen + recExprStr true e1 + "+" + recExprStr true e2 + rParen
		| Sub (e1, e2) -> lParen + recExprStr true e1 + "-" + recExprStr true e2 + rParen
		| Mul (e1, e2) -> lParen + recExprStr true e1 + "*" + recExprStr true e2 + rParen
	recExprStr false expr

// TODO: write simplify function
let rec simplify expr = 
	match expr with
	| X -> X                                           // if expr is X, then return X
	| Y -> Y                                           // if expr is Y, then return Y
	| Const n -> Const n                               // if expr is a Const, then return that Const
	| Neg e ->                                         // if expr is Neg (some expression)
		let simpEx = simplify e                          // simplify the expression
		match simpEx with                                
		| Const n -> Const (-n)                          // if simpEx is a Const, then return the Const as a negative
		| Neg ex -> ex                                   // if simpEx is another Neg (some expression (ex)) then simplify ex
		| _ ->  Neg (simplify e)                         // if simpEx is anything else then Neg of simplify e
	| Add (expr1, expr2) ->                            // if expr is Add (one, two), then
		let simpEx1 = simplify expr1                     // simplify the first
		let simpEx2 = simplify expr2                     // simplify the second
		match simpEx1, simpEx2 with                      
		| Const n1, Const n2 -> Const (n1+n2)            // if both simplified expressions are consts, then add them
		| ex, Const 0.0 -> ex                            // if simpEx1 is an expression and simpEx2 is const 0.0, then simplify simpEx1
		| Const 0.0, ex -> ex                            // if simpEx1 is Const 0.0 and simpEx2 is an expression, then simplify simpEx2
		| ex1, ex2 ->                                    // if both are expressions, then 
			Add (ex1, ex2)                                 // add simpEx1 and simpEx2
	| Sub (expr1, expr2) ->                            // SO ON AND SO FORTH... 
		let simpEx1 = simplify expr1                      
		let simpEx2 = simplify expr2                      
		match simpEx1, simpEx2 with                       
		| Const n1, Const n2 -> Const (n1-n2)             
		| ex, Const 0.0 -> ex
		| Const 0.0, ex -> simplify (Neg ex)
		| e1', e2' -> 
			if e1' = e2' then Const 0.0
			else Sub (e1', e2')
	| Mul (expr1, expr2) ->
		let simpEx1 = simplify expr1
		let simpEx2 = simplify expr2
		match simpEx1, simpEx2 with
		| Const n1, Const n2 -> Const (n1*n2)
		| _, Const 0.0 -> Const 0.0
		| Const 0.0, _ -> Const 0.0
		| ex, Const 1.0 -> ex
		| Const 1.0, ex -> ex
		| ex1, ex2 -> 
			Mul (simpEx1, simpEx2)

// Provided Tests (DO NOT MODIFY)
printfn "---Provided Tests---"
let t1 = Add (Const 9.0, Const 4.0)
let t2 = Sub (Const 10.0, Const 3.5)
let t3 = Mul (Const 6.0, Const 7.0)
let t4 = Neg (Const 0.3)
let t5 = Neg (Const -9.0)
let t6 = Add (X, Const 0.0)
let t7 = Add (Const 0.0, Y)
let t8 = Sub (X, Const 0.0)
let t9 = Sub (Const 0.0, Y)
let t10 = Sub (Y, Y)
let t11 = Mul (X, Const 0.0)
let t12 = Mul (Const 0.0, Y)
let t13 = Mul (X, Const 1.0)
let t14 = Mul (Const 1.0, Y)
let t15 = Neg (Neg X)
let t16 = Sub (Mul (Const 1.0, X), Add (X, Const 0.0))
let t17 = Add (Sub (Const 3.0, Const 8.0), Mul (Const 7.0, Const 3.0))
let t18 = Sub (Sub (Add (Y, Const 3.0), Add (Y, Const 3.0)), Add (Const 0.0, Add (Y, Const 3.0)))
let t19 = Sub (Const 0.0, Neg (Mul (Const 1.0, X)))
let t20 = Mul (Add (X, Const 2.0), Neg (Sub (Mul (Const 2.0, Y), Const 5.0)))

printfn "t1  Correct: 13\t\tActual: %s" (exprToString (simplify t1))
printfn "t2  Correct: 6.5\tActual: %s" (exprToString (simplify t2)) 
printfn "t3  Correct: 42\t\tActual: %s" (exprToString (simplify t3))
printfn "t4  Correct: -0.3\tActual: %s" (exprToString (simplify t4))
printfn "t5  Correct: 9\t\tActual: %s" (exprToString (simplify t5))
printfn "t6  Correct: x\t\tActual: %s" (exprToString (simplify t6))
printfn "t7  Correct: y\t\tActual: %s" (exprToString (simplify t7))
printfn "t8  Correct: x\t\tActual: %s" (exprToString (simplify t8))
printfn "t9  Correct: -y\t\tActual: %s" (exprToString (simplify t9))
printfn "t10 Correct: 0\t\tActual: %s" (exprToString (simplify t10))
printfn "t11 Correct: 0\t\tActual: %s" (exprToString (simplify t11))
printfn "t12 Correct: 0\t\tActual: %s" (exprToString (simplify t12))
printfn "t13 Correct: x\t\tActual: %s" (exprToString (simplify t13))
printfn "t14 Correct: y\t\tActual: %s" (exprToString (simplify t14))
printfn "t15 Correct: x\t\tActual: %s" (exprToString (simplify t15))
printfn "t16 Correct: 0\t\tActual: %s" (exprToString (simplify t16))
printfn "t17 Correct: 16\t\tActual: %s" (exprToString (simplify t17)) 
printfn "t18 Correct: -(y+3)\tActual: %s" (exprToString (simplify t18))
printfn "t19 Correct: x\t\tActual: %s" (exprToString (simplify t19))
printfn "t20 Correct: (x+2)*(-((2*y)-5))"
printfn "    Actual:  %s" (exprToString (simplify t20))

