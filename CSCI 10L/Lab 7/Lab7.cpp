//A2:

// #include <iostream>
// #include <string>
// using namespace std;
//
// string findSubstring(string s, int start, int length);
//
// int main(){
// cout << "This is your output: " << findSubstring("abracadabra",3,5) << endl;
//
//   return 0;
// }
//
// string findSubstring(string s, int start, int length){
// string output = "";
// for(int i = start; i < length + start; i++){
//     output = output + s[i];
//   }
// return(output);
// }
//
//
// //A4:
//
// #include <iostream>
// #include <string>
// using namespace std;
//
// string findSubstring(string s, int start, int length){
//   string output = "";
//   for(int i = start; i < length + start; i++){
//     output = output + s[i];
//   }
//   return(output);
// }
//
// int findProtein(string dna, string protein){
//   for(int i = 0; i <= dna.length() - protein.length(); i++){
//     if(protein == findSubstring(dna, i, protein.length())){
//       return i;
//     }
//   }
//   return -1;
// }
//
// int main(){
//   cout << findProtein("ATGCAGAAAGCTACGATCAATGATCGATC AATGGAT","AATG") << endl;
//   return 0;
// }
//
// //B2:
//
// #include <iostream>
// #include <string>
// using namespace std;
//
// string encrypt(string in, int shift);
// int main(){
// cout << encrypt("cat", 3) << endl;
// }
//
// string encrypt(string in, int shift){
// string s="";
//   for(int i = 0; i<in.length(); i++){
//     char c = in[i] + shift;
//     s = s + c;
//   }
// return s;
// }

//B4:

#include <iostream>
#include <string>
using namespace std;

string encrypt(string in, int shift);
int main(){
cout << encrypt("zoo", 3) << endl;
}

string encrypt(string in, int shift){
string s = "";
  for(int i = 0; i<in.length(); i++){
    if (in[i] + shift > 'z') {
      char c = in[i] + shift;
      c = c - 'z';
      c = c + 'a' - 1;
      s = s + c;
    }
    else {
      char c = in[i] + shift;
      s = s + c;
    }
  }
  return s;
}
