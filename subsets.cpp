#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

// TIME:    O(n!)
// SPACE:   O(n!)

set<set<int>> subsets(set<int> s) {

   // set of sets to return
   set<set<int>> t;

   // proper subset? don't include this line
   t.insert(s);

   if (s.size() == 0) return t;
   
   auto it = s.begin();
   auto end = s.end();

   // for each subset
   for (; it != end; it++) {

      // save removed element in x
      int x = *it;
      s.erase(it);

      // insert this subset to return
      t.insert(s);

      // insert all its subsets as well
      for (set<int> a: subsets(s)) {
         t.insert(a);
      }

      // reinsert element x
      it = s.insert(x).first;
   }

   return t;

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
