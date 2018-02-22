//  main.cpp
//  Names_12.16.17
//
//  Created by Elizabeth Yang on 12/16/17.
//  Copyright © 2017 Elizabeth Yang. All rights reserved.
//  CIS 054, C++, Xcode
//  Summary: Find the the Rank of a Baby Name
//  Inputs: Name
//  Output: Baby Name Rank

#include <iostream> // used for cin and cout
#include <fstream> //used for cin/cout for files
#include <cstdlib> //used by the exit() function
#include <cstring> //used for strcasecmp

using namespace std;

int main(int argc, const char * argv[])
{
    // Variables to control the disk file
    ifstream name_file;
    
    // Variables for fields of each record in the file
    char boy_Name[200] = "";
    char girl_Name[200] = "";
    
    //Variables for input
    char inputName[200];
    
    //Variables for finding the name rank
    int rank = 0; //counter for rank
    int boy_rank = 0; //rank for boy
    int girl_rank = 0; // rank for girl
    
    //title
    cout << "Find the Rank of a Baby Name" << endl;
    cout << "----------------------------" << endl;

    // Open File
    name_file.open("/users/elizabeth/Desktop/FirstNames2015.txt");
        
    // Test file if it opened correctly
    if(name_file.fail())
    {
        cerr << "Unable to open name_file.txt" << "-- first pass" << endl; //cerr = standard output stream for errors
        exit(1);
    }
    
    cout << endl;
        
    // input a name to search
    cout << "Enter a baby name to search for: " << endl;
    cin >> inputName;
    cout << endl;
        
    //Search for the name in the file
    while (!name_file.eof()) //while not end of file
    {
        name_file >> boy_Name >> girl_Name; //read the first line

        rank++;
        
        //Find the name rank from the boy
        if (strcasecmp(inputName, boy_Name) == 0) //if both strings are equal then it will return false, false = 0, (true in this case)
            boy_rank = rank;
        
        //Find the name rank from the girl
        if (strcasecmp(inputName, girl_Name) == 0) //if both strings are equal then it will return false, false = 0, (true in this case)
            girl_rank = rank;
    }
        
    // Use the rank, to get desired output sentence
    if (boy_rank < 0 || boy_rank > 1001) //there are a thousand records
    {
        cout << inputName << " is not found in boys" << endl;
    }
    else
    {
        cout << inputName << " is ranked " << boy_rank << " in boys" << endl;
    }
    
    if (girl_rank < 0 || girl_rank > 1001) //there are a thousand records
    {
        cout << inputName << " is not found in girls" << endl;
    }
    else
    {
        cout << inputName << " is ranked " << girl_rank << " in girls" << endl;
    }
        
    // Close the file
    name_file.close();
    
    cout << endl;
    
    return 0;
}






