#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> split_string(string str, string range_str) {
 // 1. Declare variables which will be used or returned.
 vector<string> result;
 int start_len, end_len;
 // 2. Parse the range_str for the function
 sscanf(range_str.c_str(), "%d-%d", &start_len, &end_len);
 cout << start_len << " " << end_len << "\n";
 // 3. Remove whitespaces from the string
 str.erase(remove(str.begin(), str.end(), ' '), str.end());
 // 4. Loop through the string
 int pos = 0;
 int a = 0;
 while (pos < str.length()) {
 // 5. Determine the length of the next word
 int len = 0;
 if(a % 2 == 0)
        {
            len = start_len;
        }
        else if(a % 2 != 0){
            len = end_len;
        }
 // 6. Make sure we don't go past the end of the string
 if (pos + len > str.length()) {
 len = str.length() - pos;
 }
 // 7. Add the word to the result array
 string word = str.substr(pos, len);
 result.push_back(word);
 pos += len;
 a++;
 }
 // 8. Sort the words using a custom comparison function
 sort(result.begin(), result.end(), [](const string& a, const string& b) {
 string::const_iterator ita = a.begin(), itb = b.begin();
 while (ita != a.end() && itb != b.end()) {
 if (isdigit(*ita) && !isdigit(*itb)) {
 return true;
 } else if (!isdigit(*ita) && isdigit(*itb)) {
 return false;
 } else if (isupper(*ita) && !isupper(*itb)) {
 return true;
 } else if (!isupper(*ita) && isupper(*itb)) {
 return false;
 } else if (*ita < *itb) {
 return true;
 } else if (*ita > *itb) {
 return false;
 } else {
 ++ita;
 ++itb;
 }
 }
 return a.length() < b.length();
 });
 // 9. Return the result computed
 return result;
}
int main() {
 string str = "abcd Efghij klmn oPqrsT uvwx yz";
 string str2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
 string range_str = "1-5";
 vector<string> result = split_string(str2, range_str);
 for (const auto& word : result) {
 cout << word << " ";
 }
 cout << endl;
 return 0;
}