#include <iostream>
#include <string>
#include <set>

using namespace std;

/**
 * Runtime:
 *    |chars| = k
 *    |s| = n
 *    => O(k*n)   
 */
bool containsAll(string s, set<char> chars) {
   for (char c: chars)
      if (s.find(c) == s.npos) return false;
   return true;
}

/**
 * Number of substrings:
 *    T(1) = 1
 *    T(n) = T(n-1) + n
 *         = T(n-2) + 2n - 1
 *         = T(n-3) + 3n - 1 - 2
 *         = T(n-k) + kn - k(k-1)/2
 *         if n-k = 1
 *    T(n) = T(1) + (n-1)n - (n-1)(n-2)/2
 *         => O(n^2)
 * 
 * Runtime:
 *    TODO
 */
set<string> getSubStrings(string s) {

   set<string> ret;

   // insert s[0]...s[n-1]
   ret.insert(s);

   if (s.size() < 2) return ret;

   // truncate first character
   // insert substrings of s[0]...s[n-2]
   for (string ss: getSubStrings(s.substr(0, s.size()-1)))
      ret.insert(ss);

   // truncate last character
   // insert substrings of s[1]...s[n-1]
   for (string ss: getSubStrings(s.substr(1, s.size()-1)))
      ret.insert(ss);

   return ret;

}

string shortestSubString(set<char> chars, string s) {

   // get all substrings of s
   set<string> ss = getSubStrings(s);

   // shortest string to return
   string ret = "";

   // get first string 
   for (string s: ss)
      if (containsAll(s, chars)) {
         ret = s;
         break;
      }

   // return shortest string that contains all characters in chars
   for (string s: ss)
      if (containsAll(s, chars))
         if (s.length() < ret.length())
             ret = s;

   // no substring found
   return ret;

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

   string s(argv[2]);
   string ss = shortestSubString(chars, s);

   if (ss.length() == 0) {
      cout << "sss: NONE" << endl;
      return 0;
   }
   
   // fancy print
   int i = s.find(ss);
   s.insert(i,"[");
   s.insert(i+ss.length()+1,"]");

   cout << "sss: " << s << endl;
   
   return 0;

}
