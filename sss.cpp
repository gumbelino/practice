#include <iostream>
#include <set>
#include <string> // FORGOT

using namespace std;

/**
 * Helper method to determine whether or not a string 's' contains
 * all characters 'chars'
 */
bool containsAll(string s, set<char> chars) {
   for (char c: chars)
      if (s.find(c) == s.npos) return false;
   return true;
}

/**
 * Recursive method that
 * Returns shortest substring of s that contains all chararters in chars
 *         "" if none
 * Example: chars = {a, b, c}, s = axcxbx, returns acb
 */
string shortestSubString(set<char> chars, string s) {   
   
   // remove one char at a time
   for (auto it = s.begin(); it != s.end(); it++) {

      char c = *it;
      it = s.erase(it);

      // check if substring contains all characters
      if (containsAll(s,chars)) {
         return shortestSubString(chars, s);
      }
      
      s.insert(it, c);

   }

   // determines correct or wrong answer!!
   if (!containsAll(s, chars))
      return "";
   return s;

}

/*
 * argv[1] = set of chars
 * argv[2] = string
 */
int main(int argc, char* argv[]) {
   
   set<char> chars;
   string charString(argv[1]);
   
   for (char c: charString)
      chars.insert(c);

   cout << "sss: " << shortestSubString(chars, argv[2]) << endl;
   
   return 0;

}
