#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds; 
  
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, 
tree_order_statistics_node_update>;
/*
* Allowed operations : 
* order_of_key : return the number of elements which are smaller than key
* find_by_order: returns iterator to the element with given order
*/