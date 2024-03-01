// Your First C++ Program

#include <algorithm> 
#include <iostream>
#include <vector>
// #include<string.h>

using namespace std;

//1. they didnt include algorithm which makes it impossible to run the code
//2. gpt did not understand the prompt well and got a random number
//it wont work even if it was right since it didnt get a new seed, making it print the same thing everytime
//3. the sorting is overcomplicated, we can just use a>b
//4. we are supposed to make it so that program accepts both inputs:4 and 4-6, but gpt didnt do that
//
vector<string> split_string(string str, string range_str)
{
    // 1. Declare variables which will be used or returned.
    vector<string> result;
    int start_len, end_len;
    range_str.erase(remove(range_str.begin(), range_str.end(), ' '), range_str.end());
    // 2. Parse the range_str for the function
    if(range_str.length() == 1 && isdigit(range_str[0]))
    {
        start_len = stoi(range_str);
        end_len = stoi(range_str);
    }
    else{
        sscanf(range_str.c_str(), "%d-%d", &start_len, &end_len);
    }
    
    cout <<"Start length: " <<start_len << "\n";
    cout << "End Length: "<<end_len << "\n";
    // 3. Remove whitespaces from the string
    //remove moves all the elements that are not a whitespace infront and moves white spaces
    //to the back, returning the iterator that is pointing to the element of the last element not removed
    //erase erases all elements starting at the given iterator which is returned by the remove, and stops erasing at the end of the string given by end
    str.erase(remove(str.begin(), str.end(), ' '), str.end());


    // cout << str << "\n"; 
    // 4. Loop through the string
    int pos = 0;
    int a = 0;
    bool perfect = true;
    while (pos < str.length())
    {
        // 5. Determine the length of the next word
        // I think gpt is getting the length by rolling a random with range 0~7 for some reason
        // error for sure
        //I think gpt thought we were just choosing from a range of 4~6 when in reality we are taking turns 4 and 6
        // int len = rand() % (end_len - start_len + 1) + start_len;
        // cout << len;
        int len = 0;
        if(a % 2 == 0)
        {
            len = start_len;
        }
        else if(a % 2 != 0){
            len = end_len;
        }

        // 6. Make sure we don't go past the end of the string
        if (pos + len > str.length())
        {
            len = str.length() - pos;
            perfect = false;
        }

        // 7. Add the word to the result array
        string word = str.substr(pos, len);

        result.push_back(word);

        pos += len;
        a++;
    }

    // 8. Sort the words using a custom comparison function
    //string that has memory address to a and b, true means a goes first, false means  b goes first 
    //* is pointer, & is address of operator
    //doesnt put short word at the end
    sort(result.begin(), result.end() - (perfect ? 0 : 1), [](const string &a, const string &b)
    {
        return a < b;
    });
    

    // 9. Return the result computed
    return result;
}

int main()
{ 
    string str = "abcdEfghijklmnoPqrsTuvwxaz";
    string str2 = "hellomywonderfulfriend2000";
    string str3 = "abcd abcddd abcd aaabcd aabc abbbcd abcd aaabcd"; 
    string str4 = "abcd AAAbcd Abcd 00as0a dsa0 0d0";   
    string str5 = "19750230132123";
    string str6 = "aaaaa aaaaaa aaaaa aaaaaa aaaaa aaaaaa aaaaa aaaaaa";
    string range_str = "4-6";
    string range_str2 = "1-5";
    vector<string> result = split_string(str, range_str);
    vector<string> result2 = split_string(str6, "50-1");
    for (const auto &word : result)
    {
        cout << word << " ";
    }
    cout << "\n";
    for (const auto &word : result2)
    {
        cout << word << " ";
    }
    // str.remove(str.begin(), str.end(), "a");
    
    // int a = remove(str.begin(), str.end(), "a");
    cout << endl;
    return 0;
}