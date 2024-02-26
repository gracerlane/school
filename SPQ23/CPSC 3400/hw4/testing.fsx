let rec replace list origVal newVal = 
 match list with
 |[]->list                
 |hd::tl->
  if hd = origVal                                
	 then newVal::replace tl origVal newVal      
	else hd::replace tl origVal newVal         

let rec mergeList (listA:(int)list) (listB:(int)list) = 
 match (listA, listB) with
  |(_,[]) -> listA                
  |([],_) -> listB               
  |(ahd::atl, bhd::btl) -> ahd::bhd::mergeList atl btl       

let rec search (dict:(string*int)list) key = 
 match dict with 
 |[] -> None    
 |hd::tl -> 
  if fst(hd) = key      
	 then Some(snd(hd))
	else search tl key 

let rec insert dict key value =
 match dict with
 |[] -> [(key, value)]           
 |hd::tl ->
  if fst(hd) = key              
	 then dict                 
	else hd::insert tl key value    

let rec remove (dict:(string*int)list) key = 
 match dict with 
 |[] -> dict              
 |hd::tl -> 
  if fst(hd) = key         
	 then tl               
	else hd::remove tl key 

let rec count (dict:(string*int)list) func =
 match dict with
 |[] -> 0      
 |hd::tl -> 
  if func(snd(hd))      
	 then 1 + count tl func  
	else count tl func       

let twoDigitCount dict =
 count dict (fun x -> x >= 10 && x <= 99)  