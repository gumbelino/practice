#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

// TIME:    O(2^n)
// SPACE:   O(2^n) stack

set<set<int>> subsets(set<int> s) {

   // sets of sets to return
   set<set<int>> r;
   r.insert(s);

   // empty set, return
   if (s.size() == 0) return r; 
   
   // get first element and erase it from set
   int first = *(s.begin());
   s.erase(s.begin());

   // for each smaller set
   for (set<int> ss: subsets(s)) {
   
      // insert it to return
      r.insert(ss);

      // insert first
      ss.insert(first);

      // insert bigger set to return
      r.insert(ss);

   }

   return r;

} 

// Write a method that returns all subsets of a set
int main(int argc, char* argv[]) {

   set<int> s;

   for (int i = 1; i < argc; i++) {
      s.insert(stoi(argv[i]));
   }

   int index = 1;
   for (set<int> ss: subsets(s)) {
      cout << index++ << ": { ";
      for (int i: ss) {
         cout << i << " ";
      }
      cout << "}" << endl;
   }

   return 0;  
   
}
