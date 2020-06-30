// Shunting Yard Algorithm 
// including Associativity for Operators 
// =====================================

// type of tokens
type Toks = List[String]

// helper function for splitting strings into tokens
def split(s: String) : Toks = s.split(" ").toList

// let- and right-associativity
abstract class Assoc
case object RA extends Assoc
case object LA extends Assoc

// power is right-associative,
// everything else is left-associative
def assoc(s: String) : Assoc = s match {
  case "^" => RA
  case _ => LA
}


// the precedences of the operators
val precs = Map("+" -> 1,
  		"-" -> 1,
		"*" -> 2,
		"/" -> 2,
                "^" -> 4)

// the operations in the basic version of the algorithm
val ops = List("+", "-", "*", "/", "^")

// (8) Implement the extended version of the shunting yard algorithm.
// This version should properly account for the fact that the power 
// operation is right-associative. Apart from the extension to include
// the power operation, you can make the same assumptions as in 
// basic version.

def is_op(op: String) : Boolean = ops.contains(op)

def prec(op1: String, op2: String) : Boolean = {
  if(precs(op1)<= precs(op2))
    true
  else false
}

def pop_left(st: Toks, out: Toks) : (Toks, Toks) = st match {
    case "(" :: tail => (tail,out)
    case op :: tail => pop_left(tail, op :: out)
    case Nil => throw new IllegalStateException("No left (")
  }

def pop_ops(op1: String,st: Toks,out: Toks) : (Toks,Toks) = st match{
	case "(" :: tail=> (op1 :: st,out)
  case op2 :: tail=>
     if (assoc(op2) == LA && prec(op1, op2) || 
     assoc(op2) == RA && precs(op1) < precs(op2)){
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
// syard(split("3 + 4 * 8 / ( 5 - 1 ) ^ 2 ^ 3"))  // 3 4 8 * 5 1 - 2 3 ^ ^ / +


// (9) Implement a compute function that produces a Long(!) for an
// input list of tokens in postfix notation.

	def compute(toks: Toks, st: List[Long] = Nil) : Long = toks match {
  case op :: tail if is_op(op)=>
    st match {
      case r :: l :: stack=>
        val res = op match{
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
  case Nil => st match{
    case res :: Nil => res
    case _ => throw new IllegalStateException("no!")
  }
}

// test cases
// compute(syard(split("3 + 4 * ( 2 - 1 )")))   // 7
// compute(syard(split("10 + 12 * 33")))       // 406
// compute(syard(split("( 5 + 7 ) * 2")))      // 24
// compute(syard(split("5 + 7 / 2")))          // 8
// compute(syard(split("5 * 7 / 2")))          // 17
// compute(syard(split("9 + 24 / ( 7 - 3 )"))) // 15
// compute(syard(split("4 ^ 3 ^ 2")))      // 262144
// compute(syard(split("4 ^ ( 3 ^ 2 )")))  // 262144
// compute(syard(split("( 4 ^ 3 ) ^ 2")))  // 4096
// compute(syard(split("( 3 + 1 ) ^ 2 ^ 3")))   // 65536
