// 205. Isomorphic Strings
// Hash Table

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //check if the size of the string is unequal, return false
        if(s.size() != t.size()){
            return false;
        }
        // two maps for string s and string t
        unordered_map<char, char> arr1, arr2;

        // loop through string s
        for(int i = 0; i < s.size(); i++) {
            // if the character in the map matches current character
            if(arr1.find(s[i]) == arr1.end()){
                // check the map for string t with current character, return false if it is not a match
                if(arr2.find(t[i]) != arr2.end()){
                    return false;
                }else{
                    arr1[s[i]] = t[i];
                    arr2[t[i]] = s[i];
                }
            }
            // compare string s character matches string t, return false if no match
            else if(arr1[s[i]] != t[i]){
                return false;
            }
        }
        // if all conditions are met, return true
        return true;
    }
};

