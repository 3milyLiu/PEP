// Shunting Yard Algorithm
// by Edsger Dijkstra
// ========================


// type of tokens
type Toks = List[String]

// the operations in the basic version of the algorithm
val ops = List("+", "-", "*", "/")

// the precedences of the operators
val precs = Map("+" -> 1,
		"-" -> 1,
		"*" -> 2,
		"/" -> 2)

// helper function for splitting strings into tokens
def split(s: String) : Toks = s.split(" ").toList


// (6) Implement below the shunting yard algorithm. The most
// convenient way to this in Scala is to implement a recursive 
// function and to heavily use pattern matching. The function syard 
// takes some input tokens as first argument. The second and third 
// arguments represent the stack and the output of the shunting yard 
// algorithm.
//
// In the marking, you can assume the function is called only with 
// an empty stack and an empty output list. You can also assume the
// input os  only properly formatted (infix) arithmetic expressions
// (all parentheses will be well-nested, the input only contains 
// operators and numbers).

// You can implement any additional helper function you need. I found 
// it helpful to implement two auxiliary functions for the pattern matching:  
// 
def is_op(op: String) : Boolean = ops.contains(op)

// def prec(op1: String, op2: String) : Boolean = ...

def pop_left(st: Toks, out: Toks) : (Toks, Toks) = st match {
    case "(" :: tail => (tail,out)
    case op :: tail => pop_left(tail, op :: out)
    case Nil => throw new IllegalStateException("No left (")
  }

def pop_ops(op1: String,st: Toks,out: Toks) : (Toks,Toks) = st match{
	case "(" :: tail=> (op1 :: st,out)
    case op2 :: tail=>
      if (precs(op1)<= precs(op2)) {
        pop_ops(op1, tail, op2 :: out)
      } 
	  else{
		 (op1 :: st, out)
	  }
    case Nil => (List(op1), out)
  }

def syard(toks: Toks, st: Toks = Nil, out: Toks = Nil) : Toks = toks match {
  case tok :: tail =>
    val (stack, output) = tok match {
      case "(" => ("(" :: st, out)
      case ")" => pop_left(st, out)
      case op if is_op(op) => pop_ops(op, st, out)
      case num => (st, num :: out)
    }
    syard(tail, stack, output)
  case Nil => out.reverse ++ st
}
	

// test cases
//syard(split("3 + 4 * ( 2 - 1 )"))  // 3 4 2 1 - * +
//syard(split("10 + 12 * 33"))       // 10 12 33 * +
//syard(split("( 5 + 7 ) * 2"))      // 5 7 + 2 *
//syard(split("5 + 7 / 2"))          // 5 7 2 / +
//syard(split("5 * 7 / 2"))          // 5 7 * 2 /
//syard(split("9 + 24 / ( 7 - 3 )")) // 9 24 7 3 - / +

//syard(split("3 + 4 + 5"))           // 3 4 + 5 +
//syard(split("( ( 3 + 4 ) + 5 )"))    // 3 4 + 5 +
//syard(split("( 3 + ( 4 + 5 ) )"))    // 3 4 5 + +
//syard(split("( ( ( 3 ) ) + ( ( 4 + ( 5 ) ) ) )")) // 3 4 5 + +

 
// (7) Implement a compute function that evaluates an input list
// in postfix notation. This function takes a list of tokens
// and a stack as argumenta. The function should produce the 
// result as an integer using the stack. You can assume 
// this function will be only called with proper postfix 
// expressions.    

def compute(toks: Toks, st: List[Long] = Nil) : Long = toks match {
  case op :: tail if is_op(op)=>st match{
    case r :: l :: stack =>
      val res = op match {
        case "+" => l + r
        case "-" => l - r
        case "*" => l * r
        case "/" => l / r
        case "^" => Math.pow(l, r).toLong
        }
    compute(tail, res :: stack)
    case _ => throw new IllegalStateException("no!")
    }
  case num :: tail => compute(tail, num.toLong :: st)
  case Nil => st match {
  case res :: Nil => res
  case _ => throw new IllegalStateException("no!")
  }
}

// test cases
// compute(syard(split("3 + 4 * ( 2 - 1 )")))  // 7
// compute(syard(split("10 + 12 * 33")))       // 406
// compute(syard(split("( 5 + 7 ) * 2")))      // 24
// compute(syard(split("5 + 7 / 2")))          // 8
// compute(syard(split("5 * 7 / 2")))          // 17
// compute(syard(split("9 + 24 / ( 7 - 3 )"))) // 15




