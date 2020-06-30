// Part 2 about finding a single tour for a board using the Warnsdorf Rule
//=========================================================================

// !!! Copy any function you need from file knight1.scala !!!
//
// If you need any auxiliary function, feel free to 
// implement it, but do not make any changes to the
// templates below.

type Pos = (Int, Int)    // a position on a chessboard 
type Path = List[Pos]    // a path...a list of positions

def is_legal(dim: Int, path: Path, x: Pos) : Boolean = {
  if((x._1>=0) && (x._1<dim) && (x._2>=0) && (x._2<dim) && !path.contains(x))
    true
  else
    false
}

def legal_moves(dim: Int, path: Path, x: Pos) : List[Pos] = {
    val first = x._1
    val second = x._2
    val legal = List((first + 1, second + 2), (first + 2, second + 1), (first + 2, second - 1), (first + 1, second - 2), (first - 1, second - 2), (first - 2, second - 1), (first - 2, second + 1), (first - 1, second + 2))
     legal.filter(x=>is_legal(dim,path,x))
}

//(6) Complete the function that calculates a list of onward
//    moves like in (2) but orders them according to Warnsdorf’s 
//    rule. That means moves with the fewest legal onward moves 
//    should come first.


def ordered_moves(dim: Int, path: Path, x: Pos) : List[Pos] = {
    legal_moves(dim, path, x).sortBy(c=>legal_moves(dim, path, c).size)
}


//(7) Complete the function that searches for a single *closed* 
//    tour using the ordered_moves function from (6). This
//    function will be tested on a 6 x 6 board. 


def first(xs: List[Pos], f: Pos => Option[Path]) : Option[Path] = xs match {
  case Nil=>None
  case(x::xs)=>{
    val firstf = f(x)
    if(firstf.isDefined)
      firstf
    else
      first(xs,f)
    }
}

def first_closed_tour_heuristic(dim: Int, path: Path) : Option[Path] = {
    val dimSquared = dim*dim
    if((path.size == dimSquared) && (legal_moves(dim,List(),path.last).contains(path.head)))
        Some(path)
    else
      first(ordered_moves(dim, path, path.head),(x=>first_closed_tour_heuristic(dim, x::path)))
}

//(8) Same as (7) but searches for *non-closed* tours. This 
//    version of the function will be called with dimensions of 
//    up to 30 * 30.

def first_tour_heuristic(dim: Int, path: Path) : Option[Path] = {
    val dimSquared = dim*dim
    if(path.size == dimSquared)
        Some(path)
    else
    	first(ordered_moves(dim, path, path.head),(x=>first_tour_heuristic(dim, x::path)))
}


