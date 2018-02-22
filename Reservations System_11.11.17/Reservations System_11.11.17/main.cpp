
//  Reservations System_11.11.17
//
//  Created by Elizabeth Yang on 11/11/17.
//  CIS 54: X++
//  Summary: A Seat Reservation System

#include <iostream>
#include <cctype>
using namespace std;

// Function declarations (prototypes)
char ** CreateArrayOfSeats (int NumberOfRows, int seats);
void InitializeSeats (char **ArrayOfSeats, int NumberOfRows, int seats);
void DisplayArrayOfSeats (char **ArrayOfSeats, int NumberOfRows, int seats);
void MemoryCleanup (char **ArrayOfSeats, int NumberOfRows, int seats);

int main(int argc, char* argv[])
{
    char answer;
    char **ArrayOfSeats;
    int NumberOfRows;
    int NumberOfSeats;
    char rowSelection;  // 1 to max NumberOfRows, input from the user
    char seatSelection; // 'A' to max seats, input from the user, convert to a number
    int row;    // index into ArrayOfSeats, 0 to NumberOfRows-1
    int seat;   // index into ArrayOfSeats, 0 to seats-1
    
    // get the number of NumberOfRows and seats from the user
    cout << "Enter the number of number of rows: ";
    cin  >> NumberOfRows;
    cout << "Enter the number of seats on each row: ";
    cin  >> NumberOfSeats;
    
    int AvailableSeats;
    AvailableSeats = NumberOfRows*NumberOfSeats;
    
    ArrayOfSeats = CreateArrayOfSeats(NumberOfRows, NumberOfSeats);
    InitializeSeats (ArrayOfSeats, NumberOfRows, NumberOfSeats);
    cout << endl;
    DisplayArrayOfSeats  (ArrayOfSeats, NumberOfRows, NumberOfSeats);
    
    do
    {
        
        cout << endl << "Enter a seat selection" << endl << "  (example 5F -or- 00 to quit): ";
        cin  >> rowSelection;       // get row from the user
        cin  >> seatSelection;      // get the seat from the user
        if (rowSelection=='0')
            continue;               // skip the rest of the loop
        
        seatSelection = toupper(seatSelection); // convert to upper case
        row = rowSelection - '1';     // count from zero to work with the array
        seat = seatSelection - 'A';   // convert 'A' to 0, 'B' to 1, 'C' to 2, etc.
        
        //------ you need to coomplete the rest of the program------
        
        cout << "Available Seats: " << AvailableSeats << endl;
        
        // Verify that a valid row and seat were entered
        if (row < 0 || row > NumberOfRows - 1 || seat < 0 || seat > NumberOfSeats - 1)
        {
            cout << "Illegal value, try again." << endl;
        }
        else
        {
            if (ArrayOfSeats[row][seat] == '-')                    // See if the seat selection is already taken (see if it has an '-')
            {
                cout << "Seat has already been reserved. Try again." << endl;       //   if it has an '-', display a message that the seat is taken
            }
            else
            {
                ArrayOfSeats[row][seat] = '-';                  //   else, put an '-' in that location using ArrayOfSeats[row][seat] = '-';
                cout << "Your seat has been reserved." << endl;
                AvailableSeats-- ;
                cout << "Available Seats Left:  " << AvailableSeats << endl;
            }
            if(AvailableSeats == 0)    // See if all the seats are taken, hint:keep a count each time a seat is taken, and compare to the maximum number of seats (NumberOfRows*seats)
            {
                cout << "All seats have been reserved." << endl;
            }
        }
        
        cout << endl;
        DisplayArrayOfSeats (ArrayOfSeats, NumberOfRows, NumberOfSeats);
        
        // Reserve another seat?
        do
        {
            cout << "Reserve another seat? (Y/N)" << endl;
            cin >> answer;
            
            answer = toupper(answer);
            if(answer != 'Y' && answer != 'N')
                cout << "Illegal response." << endl;
            
        }while(answer != 'Y' && answer != 'N');
        
        if (answer == 'N')
            row = -1; //stops the program
        
    } while (AvailableSeats > 0 && rowSelection != '0' && row >= 0);
    
    MemoryCleanup (ArrayOfSeats, NumberOfRows, NumberOfSeats);   // return the memory that was allocated
    
    cout << "Press the ENTER key to continue...";
    char buff[100];
    cin.getline (buff, 100);
    return 0;
}

char **CreateArrayOfSeats (int NumberOfRows, int seats)    // ** means pointer to pointers
{
    char **ArrayOfSeats;
    ArrayOfSeats = new char*[NumberOfRows];          // create an array of pointers for the NumberOfRows
    for(int r = 0; r < NumberOfRows; r++)
        ArrayOfSeats[r] = new char[seats];   // create an array of seats for each row
    return ArrayOfSeats;                     // return pointer to the array back to the main program
}

void InitializeSeats (char **ArrayOfSeats, int NumberOfRows, int seats)
{
    for (int r=0; r<NumberOfRows; r++)          // initialize the data for each row
    {
        for (int s=0; s<seats; s++)
            ArrayOfSeats[r][s] = 'A' + s;    // put 'A' 'B' 'C' etc in each row
    }
}

void DisplayArrayOfSeats (char **ArrayOfSeats, int NumberOfRows, int NumberOfSeats)
{
    for (int r=0; r<NumberOfRows; r++)              // for each row
    {
        cout.width(2);
        cout << r+1 << ' ';                 // Display row numbers starting from 1
        for (int s=0; s<NumberOfSeats; s++)
            cout << ArrayOfSeats[r][s] << ' ';   // Display info for each seat
        cout << endl;                       // new line after each row
    }
}

void MemoryCleanup (char **ArrayOfSeats, int NumberOfRows, int NumberOfSeats)
{
    for (int r=0; r<NumberOfRows; r++)
        delete [] ArrayOfSeats[r];   // delete each row of seats individually
    delete [] ArrayOfSeats;          // delete the row array
}
