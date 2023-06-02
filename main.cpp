// Multiplication Table CPP

#include <iostream>
#include <iomanip> // For improved formatting/consistent spacing
#include <unistd.h> // For 'setupterm' function
#include <term.h> // For using functions to interact with the terminal

#define CLEAR_SCREEN "clear" // For macro CLEAR_SCREEN to be used

int main()
{
    int rows, cols;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;
    
    if (rows <= 0 || cols <= 0) {
        std::cout << "Invalid input. The rows and columns must be postive numbers." << std::endl;
        return 1; // Return 1 because we want the program to know an invalid input happened.
    }
    
    const char* clear_cmd; // Declares pointer named clear_cmd to use for escaping the sequence for clearing the screen. Needs const char
    setupterm(NULL, STDOUT_FILENO, NULL); //setupterm initializes terminal. NULL passed as first argument. STDOUT_FILENO for reps the file descriptor for standard output.
    clear_cmd = tigetstr("clear"); // clear passed as argument to indicate that we want to retrieve the escape sequence for clearing the screen. clear_cmd pointer stores escape sequence.
    
    std::cout << "\033[2J\033[H" /* tparm(clear_cmd)*/ << std::flush; // tparm expands terminfo capability. std::flush ensures that the output is immediateley written to the output device.
    
    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= cols; j++) {
            std::cout << std::setw(4) << i * j; // Sets width of the field to 4 characters reguardless of number's length. Makes things neater.
        }
        std::cout << std::endl;
    }
        
    std::cout << std::endl << "Press any key to continue...";
        std::cin.ignore();
        std::cin.get();
        
        return 0;
}
