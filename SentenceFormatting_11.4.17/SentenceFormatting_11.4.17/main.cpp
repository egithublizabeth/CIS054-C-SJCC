
//  SentenceFormatting_11.4.17
//
//  Created by Elizabeth Yang on 11/4/17.
//  CIS 054: C++ Xcode
//  Summary: Accept a user input “sentence” and convert it to a custom formatted sentence.

#include <iostream> // for cin and cout
#include <cctype>   // for isspace, toupper and tolower
#include <string>   // for getline
#include <cstring>  // for strlen

using namespace std;

// Functions
string white_space(char sentence[200]);
//Precondition: User inputs a string
//Postcondition: A string with whitespaces removed(space, tab, and new line(\n)

string remove_spaces(char sentence[200]);
//Precondition: String removed of whitespaces
//Postcondition: String with multiple spaces removed

string capitalize(char sentence[200]);
//Precondition: String removed of whitespaces and multiple spaces
//Postcondition: String with the first letter capitalized

string lowercase(char sentence[200]);
//Precondition: String removed of whitespaces and multiple spaces and 1st letter is capitalized
//Postcondition: All letters after the 1st letter are lowercased

int main(int argc, const char * argv[])
{
    
    // variables
    //Create a character string (c string) array to store user input sentence.
    char sentence[200];
    
    // Ask user to input a sentence.
    cout << "Enter a grammatically incorrect sentence(max 199 spaces): ";
    cin.getline(sentence, 200);     //getline grabs the whole user input line and places it in the cstring sentence
    
    //Apply functions to user input sentence.
    white_space(sentence);
    remove_spaces(sentence);
    capitalize(sentence);
    cout << lowercase(sentence) << endl; //Display output
    
    return 0;
}

// Function 1: change all whitespace characters to a space
string white_space(char sentence[200])
{
    int i = 0;
    
    for (i=0; sentence[i]; i++)
    {
        if (isspace(sentence[i]))
            sentence[i] = ' ';
    }
    return sentence;
}

// Function 2: remove multiple spaces
string remove_spaces(char sentence[200])
{
    int i = 0;
    int SIZE = strlen(sentence);
    
    while ((sentence[i] != '\0') && (i < SIZE))
    {
        //look for 2 consecutive spaces
        if (sentence[i] == ' ' && sentence[i+1] == ' ')
        for (int j = i; sentence[j]; j++)
        {
            sentence[j] = sentence[j + 1];
        }
        else
            i++;
    }
    return sentence;
}

// Function 3: capitalize the 1st character of the sentence
string capitalize(char sentence[200])
{
    sentence[0] = toupper(sentence[0]);
    return sentence;
        
}

// Function 4: make all other characters lowercase.
string lowercase(char sentence[200])
{
    int i;
    
    for (i = 1; sentence[i]; i++)
    {
        sentence[i] = tolower(sentence[i]);
    }
    return sentence;
}
