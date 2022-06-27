#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::shuffle;
using std::stringstream;

//declaration of sub-functions
string Print(const string& s);
bool IsValidString(const string& s);

/**
 * Main function takes in nine digit string from console and shuffles the string
 * @param argc command line argument count
 * @param argv command line argument array pointer
 * @return 0
 */
int main(int argc, char *argv[]) {
    int totalShuffle = argc;
    // get user input for string
    string digits;
    cout << "Please input 9 digits to be randomly shuffled:" << endl;
    cin >> digits;
    //check if the string length is 9 and all digits
    bool ok = IsValidString(digits);

    if(ok){// if string is valid
        for(int i = 0; i < totalShuffle; i++){
            // shuffle the string
            shuffle(digits.begin(),digits.end(), std::mt19937(std::random_device()()));

            //break down the shuffled string into 3
            string firstLine, secondLine, thirdLine;
            firstLine = digits.substr(0,3);
            secondLine= digits.substr(3,3);
            thirdLine = digits.substr(6,3);

            //header based on iteration of shuffle
            if(i == 0){
                cout << "The first shuffled output is:" << endl;
            }
            else if(i == 1){
                cout << "The second shuffled output is:" << endl;
            }
            else if(i == 2){
                cout << "The third shuffled output is:" << endl;
            }
            else if(i == 3){
                cout << "The fourth shuffled output is:" << endl;
            }
            else if(i == 4){
                cout << "The fifth shuffled output is:" << endl;
            }
            else if(i == 5){
                cout << "The sixth shuffled output is:" << endl;
            }
            else if(i == 6){
                cout << "The seventh shuffled output is:" << endl;
            }
            else if(i == 7){
                cout << "The eighth shuffled output is:" << endl;
            }
            else if(i == 8){
                cout << "The ninth shuffled output is:" << endl;
            }
            else if(i == 9){
                cout << "The tenth shuffled output is: " << endl;
            }

            //output shuffled string as 3x3
            cout << "+-------+ " << endl;
            cout << Print(firstLine) << endl;
            cout << Print(secondLine) << endl;
            cout << Print(thirdLine) << endl;
            cout << "+-------+ " << endl;
        }
    }else{
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
