// Grace Lane
// hw4

// I specified the list parameters because it was unacceptable when the list empty and would result in an error

(* 
1. replace list origVal newVal: The function takes a list of integers (list), an integer
to be replaced (origVal), and a replacement integer (newVal). The function returns a list such
that each occurrence of origVal in list is replaced with newVal. All other elements remain
unchanged.
Examples:
> replace [1; 2; 3; 2; 2; 4; 2; 5] 2 6;;
val it : int list = [1; 6; 3; 6; 6; 4; 6; 5]
*)
let rec replace list origVal newVal = 
 match list with
 |[]->list                // if list is empty
 |hd::tl->
  if hd = origVal                                // if hd equals the value you're looking for
	 then newVal::replace tl origVal newVal        // put the newVal where head is and call replace on the tl
	else hd::replace tl origVal newVal             // else put the hd back and call replace on the tl


(*
2. mergeList listA listB: Both parameters are lists of integers. The function returns a list
that merges the lists in alternating fashion. The first item is the first item from listA, the second
item is the first item from listB, the third item is the second item form listA, and so on.
Continue in this fashion until one list runs out; then append the remaining items from the longer
list.
Examples:
> let m1 = [1; 2; 3; 4; 5; 6];;
> let m2 = [7; 8; 9; 10];;
> mergeList m1 m2;;
val it : int list = [1; 7; 2; 8; 3; 9; 4; 10; 5; 6]
*)
let rec mergeList (listA:(int)list) (listB:(int)list) = 
 match (listA, listB) with
  |(_,[]) -> listA                // if listB is empty, return listA
  |([],_) -> listB                // if listA is empty, return listB
  |(ahd::atl, bhd::btl) -> ahd::bhd::mergeList atl btl         // get the head from both lists and put the head from listA then the head from listB in the front and call mergeLsit on atl and btl


(*
3. Write the following functions for a dictionary. The dictionary is implemented using a list of
tuples. Each tuple represent a key-value pair has two items: the first is a string and represents the
key, the second is an integer and represents the value. The dictionary is unordered and each key
must be unique.
a. search dict key: Returns an option type with what the corresponding value is if the key is in
the dictionary and None if the key is not in the dictionary.
> let fruits = [("apple", 5); ("pear", 73); ("lime", 42); ("orange", 8);
("kiwi", 17)];;
> search fruits "pear";;
val it : int option = Some 73
> search fruits "banana";;
val it : int option = None
*)
let rec search (dict:(string*int)list) key = 
 match dict with 
 |[] -> None         // if the dict is empty
 |hd::tl -> 
  if fst(hd) = key       // if the key in hd is the target key
	 then Some(snd(hd))    // then return Some of the value
	else search tl key     // else call search on tl and key


(*
b. insert dict key value: If the key is not already in the dictionary, a new dictionary is
returned with the key-value pair inserted into the dictionary. If the key is already in the
dictionary, return the dictionary with no modifications.
> insert fruits "pear" 16;;
val it : (string * int) list =
[("apple", 5); ("pear", 73); ("lime", 42); ("orange", 8); ("kiwi", 17)]
> insert fruits "banana" 44;;
val it : (string * int) list =
[("banana", 44); ("apple", 5); ("pear", 73); ("lime", 42); ("orange", 8);
("kiwi", 17)]
*)
let rec insert dict key value =
 match dict with
 |[] -> [(key, value)]               // if the dict is empty then add the entry
 |hd::tl ->
  if fst(hd) = key                   // if the hd key is the key being inserted
	 then dict                         // then return the original dict
	else hd::insert tl key value       // else add hd to the front and call insert on tl and key and value


(*
c. remove dict key: If the key is in the dictionary, a new dictionary is returned with the
corresponding key-value pair removed. If the key is not in the dictionary, return the dictionary
with no modifications.
> remove fruits "pear";;
val it : (string * int) list =
[("apple", 5); ("lime", 42); ("orange", 8); ("kiwi", 17)]
> remove fruits "banana";;
val it : (string * int) list =
[("apple", 5); ("pear", 73); ("lime", 42); ("orange", 8); ("kiwi", 17)]
*)
let rec remove (dict:(string*int)list) key = 
 match dict with 
 |[] -> dict                    // if the dict is empty return the dict
 |hd::tl -> 
  if fst(hd) = key              // if the hd key is the target key
	 then tl                      // then return the tl
	else hd::remove tl key        // else put hd at the front and call remove on tl and key


(*
d. count dict func: The parameter func is a Boolean function that takes a single integer
parameter and returns true or false. The function calls func with each value (of the key-value
pair) and returns the number of nodes that evaluate to true.
> let countAll x = true;;
val countAll : x:'a -> bool
> let countEven x = x % 2 = 0;;
val countEven : x:int -> bool
> count fruits countAll;;
val it : int = 5
> count fruits countEven;;
val it : int = 2
*)
let rec count (dict:(string*int)list) func =
 match dict with
 |[] -> 0                     // if the dict is empty then return 0
 |hd::tl -> 
  if func(snd(hd))            // if the value when passed into the function returns true
	 then 1 + count tl func     // then add 1 and call count on tl and func
	else count tl func          // else just call count on tl and func


(*
e. twoDigitCount dict: Returns the number of entries that have a two-digit positive integer
(10 to 99) value. REQUIREMENT: This function must be a single call to count using a lambda
function.
> twoDigitCount fruits;;
val it : int = 3
*)
let twoDigitCount dict =
 count dict (fun x -> x >= 10 && x <= 99)        // call count on dict and the lambda function that checks if the value is a two-digit positive integer