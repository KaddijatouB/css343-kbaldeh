#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::string;
using std::stringstream;
using std::stoi;
using std::endl;
using std::shuffle;

/**
 * Declaration of sub-functions to use as helpers in main
 */
string Print(const string& s);
bool IsValidString(const string& s);

/**
 * Main function takes in nine digit string from console and shuffles the string
 * @param argc command line argument count determines amount of shuffles
 * @param argv command line argument array pointer
 * @return 0
 */
int main(int argc, char *argv[]) {
    int totalShuffle;
    if (argc > 1){
        // check if the argument string is a digit and not the null terminating character
        for (int i = 0; argv[1][i] != '\0'; i++){
            if (isdigit(argv[1][i])) {
                //set total shuffle to the value converting string to int
                totalShuffle = stoi(argv[1]);
            }
        }
    } else{
        totalShuffle = 1;
    }
    // get user input for string of nine digits
    string digits;
    cout << "Please input 9 digits to be randomly shuffled:" << endl;
    cin >> digits;
    // check if the string length is 9 and all digits
    bool ok = IsValidString(digits);
    // if string is valid
    if(ok){
        // vales to represent each iteration
        const char* value[10] = { "first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth","ninth", "tenth"};
        //loop to shuffle and print to console
        for(int i = 0; i < totalShuffle; i++){
            // shuffle the string using shuffle method of algorithm
            shuffle(digits.begin(),digits.end(), std::mt19937(std::random_device()()));

            // break down the shuffled string into 3
            string firstLine, secondLine, thirdLine;
            firstLine = digits.substr(0,3);
            secondLine= digits.substr(3,3);
            thirdLine = digits.substr(6,3);

            // header based on iteration of shuffle
            cout << "The " << value[i] << " shuffled output is:" << endl;
            // output shuffled string as 3x3
            cout << "+-------+ " << endl;
            cout << Print(firstLine) << endl;
            cout << Print(secondLine) << endl;
            cout << Print(thirdLine) << endl;
            cout << "+-------+ " << endl << endl;
        }
    }else{// if string contains other characters instead of numbers
        cout << "Invalid input" << endl;
    }
    return 0;
}
/**
 * Adds space and | character to a string
 * @param s string that is passed for reference
 * @return string representation to add
 */
string Print(const string& s){
    stringstream ss;
    ss << "| ";
    for(int i = 0; i < s.length(); ++i){
        ss  << s[i] << " ";
    }
    ss <<"|" ;
    return ss.str();
}
/**
 * Validates the string length and digits
 * @param s the string being validated
 * @return true if string is valid, false otherwise.
 */
bool IsValidString(const string& s){
    //check the string length is 9
    if(s.length() != 9){
        return false;
    }
    //check if the string has only digits and no spaces
    for(int i = 0; i < s.length(); ++i) {
        if(!isdigit(s[i])){
            return false;
        }
    }
    return true;
}
