
//  String Reversal_11.5.17
//
//  Created by Elizabeth Yang on 11/5/17.
//  Cis 54 C++ Xcode
//  Summary: Reverse a user input string

#include <iostream>     //for cin and cout
#include <cctype>       //for tolower
#include <string>       //for getline
#include <cstring>      //for strlen, strcmp

using namespace std;


int main(int argc, const char * argv[])
{
    // variables
    int i;
    char initial_sentence[200];     //used for comparison for palindrome
    
    //create a cstring to hold the user input string
    char sentence[200];
    
    //Accept a user input string
    cout << "Enter a string: ";
    cin.getline(sentence,200);                  //grab the user input line
    
    //Convert string to lowercase
    for (i = 0; sentence[i]; i++)
    {
        sentence[i] = tolower(sentence[i]);
    }
    
    cout << "Your string lowercased is: " << sentence << endl;
    
    strncpy(initial_sentence, sentence, 200);    //for palindrome: make a copy of the original lowercased input to compare later with the reverse string
    
    //Create front pointer
    char *first = sentence;                     //first character pointer
    
    //Create rear pointer
    char *last = first + strlen(sentence) - 1;   //last character pointer
    
    //Reverse the string
    while( last > first)
    {
        char temp = *first;                     //create a temporary character to hold the swapping of letters
        *first = *last;                         //first letter is now equal to last letter
        *last = temp;                           //last letter is now equal to the first letter
        
        first++;                                //increment the front pointer
        last--;                                 //decrement the rear pointer
        
    }
    
    //Output the reverse string
    cout << "The Reverse String is: " << sentence << endl;
    
    //check to see if its a palindrome
    if (strcmp(initial_sentence, sentence))       //if both strings are equal then it will return false(true in this case)
        cout << "It is not a palindrome." << endl;   // retuns true(not equal) = not a palindrome
    else
        cout << "It is a palindrome." << endl;      // retuns false(equal) = it is a palindrome
    
    return 0;
}

