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

string Print(const string& s);
bool IsValidString(const string& s);

int main(int argc, char *argv[]) {
    int totalShuffle = argc;
    // get user input for string
    string digits;
    cout << "Please input 9 digits to be randomly shuffled:" << endl;
    cin >> digits;

    //check if the string length is 9 and all digits
    bool ok = IsValidString(digits);

    if(ok){

        for(int i = 0; i < totalShuffle; i++){
            // shuffle the string
            shuffle(digits.begin(),digits.end(), std::mt19937(std::random_device()()));
            //break down the string
            string firstLine, secondLine, thirdLine;
            firstLine = digits.substr(0,3);
            secondLine= digits.substr(3,3);
            thirdLine = digits.substr(6,3);
            if(i == 0){
                cout << "The first shuffled output is: " << endl;
                cout << "+-------+ " << endl;
                cout << Print(firstLine) << endl;
                cout << Print(secondLine) << endl;
                cout << Print(thirdLine) << endl;
                cout << "+-------+ " << endl;
            }
            else if(i == 1){
                cout << "The second shuffled output is: " << endl;
                cout << "+-------+ " << endl;
                cout << Print(firstLine) << endl;
                cout << Print(secondLine) << endl;
                cout << Print(thirdLine) << endl;
                cout << "+-------+ " << endl;
            }

        }

    }else{
        cout << "Invalid input" << endl;
    }

    return 0;
}
/**
 *
 * @param s
 * @return
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
 *
 * @param s
 * @return
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
/**
 * Write a simple C++ program. Your program will take a string of 9 digits as console input,
 * randomly shuffle the digits, and print it out to console display in a 3x3 format.

Requirements:
The program takes 1 command line argument, which represents the total number of shuffles it
 will print out (Assume this number is <= 10). eg:
 > ./myhw 2
 > ./myhw 8
The program takes the string of 9 digits through console input.
 It should prompt the user to type in the string of 9 digits. eg:
> Please input 9 digits to be randomly shuffled:
> 111222333
There should be no space or any other characters between each digit.
The program will randomly shuffles the 9 digits
The output of the program should print the shuffled 9 digits in 3x3 format, eg:
 suppose the input command line argument was 2, and the user typed a string of 9 digits “987654321”,
 then the output should be:

 	The first shuffled output is:

	The second shuffled output is:


You’re free to use your preferred IDE, but please make sure your program compiles and runs on CSS linux lab machine.


 */