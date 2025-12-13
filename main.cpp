#include "Exceptionhandler.h"
#include <iostream>
#include <atomic>
#include <string>
#include <windows.h> // Include for Windows-specific functions like Sleep

using namespace std;

// Function prototypes
void setConsoleColor();
void longRunningProcess();
void handleUserInterruption();
void handleOverflowUnderflow();
void handleDivisionByZero();
void handleInvalidInput();
void handleFileNotFound();
void handleIndexOutOfBound();
void handleNullPointer();
void handleDataConversion();
void handleDefault();
int getInputInt(const string& message);
double getInputDouble(const string& message);
char getInputChar(const string& message);
string getInputString(const string& message);
float getInputFloat(const string& message);



int main() {
    system("color F0");

    char mainChoice;
    char continue_choice;


    do {
        system("cls"); // Clear the console on Windows. Use system("clear") for Unix-like systems.

        cout << "                                       Choose an exception type to demonstrate\n" << endl;
        cout << "1. User Interruption\n";
        cout << "2. Overflow/Underflow\n";
        cout << "3. Invalid Input Exception\n";
        cout << "4. File Not Found\n";
        cout << "5. Division by Zero\n";
        cout << "6. Index Out of Bound\n";
        cout << "7. Null Pointer\n";
        cout << "8. Data Conversion\n";
        cout << "9. Default Exception\n";
        
        cin>>mainChoice;
        
        switch (mainChoice) 
		{
            case '1':
                system("cls");
                cout << "\t \t \t USER INTERRUPTION EXCEPTION\n";
                handleUserInterruption();
                break;
                
            case '2':
                system("cls");
                cout << "\t \t \t OVERFLOW/UNDERFLOW EXCEPTION\n";
                handleOverflowUnderflow();
                break;
                
            case '3':
                system("cls");
                cout << "\t \t \t INVALID INPUT EXCEPTION\n";
                handleInvalidInput();
                break;
                
            case '4':
                system("cls");
                cout << "\t \t \t FILE HANDLING EXCEPTIONS\n";
                handleFileNotFound();
                break;
                
            case '5':
                system("cls");
                cout << "\t \t \t DIVISION BY ZERO EXCEPTION\n";
                handleDivisionByZero();
                break;
                
            case '6':
                system("cls");
                cout << "\t \t \t INDEX OUT OF RANGE EXCEPTION\n";
                handleIndexOutOfBound();
                break;
                
            case '7':
                system("cls");
                cout << "\t \t \t NULL POINTER EXCEPTION\n";
                handleNullPointer();
                break;
                
            case '8':
                system("cls");
                cout << "\t \t \t DATA CONVERSION EXCEPTION\n";
                handleDataConversion();
                break;
                
            case '9':
                system("cls");
                cout << "\t \t \t DEFAULT EXCEPTION\n";
                handleDefault();
                break;
                
            default:
                system("cls");
                cout << "Invalid INPUT\n";
                handleDefault();
                break;
        }
        
        cout << "\nDo you want to return to the main menu? (Press 'q' to quit, any other key to return to menu): ";
        continue_choice=getInputChar(" ");

    } while (continue_choice != 'q' && mainChoice != 'Q');

    return 0;
}

// Function definitions

void longRunningProcess() 
{
    for (int i = 0; i < 10; ++i) 
	{
        if (interrupted.load()) 
		{
            Sleep(2000);
            cout << "Process interrupted. Exiting loop...\n";
            cout << "\nERROR: USER INTERRUPTION\n";
            break;
        }
        Sleep(1000);
        cout << "Processing... " << (i + 1) * 10 << "% complete\n";
    }
    if (!interrupted.load()) 
	{
        cout << "\nProcess completed successfully.\n";
        Sleep(2000);
    }
}

void handleUserInterruption() 
{
    // Set up the signal handler for SIGINT
    setupSignalHandler();

    // Start the long-running process
    longRunningProcess();

    // Check if the process was interrupted
    if (interrupted.load())
	 {
        cout << "SIGINT received. Do you want to exit? (y/n): ";
        char choice;
       cin>>choice;
        if (choice == 'y' || choice == 'Y')
		 {
            cout << "\nERROR: USER INTERRUPTION\n";
            cout << "Cleanup after successful termination\n";
            cout.flush();
            Sleep(4000);

            interrupted.store(true);
            // Perform cleanup if needed
            exit(0);
        } 
		else if (choice == 'n' || choice == 'N')
		 {
            // Continue with the process
            cout << "\nContinuing with the process...\n" << endl;
            // Reset the interrupted flag to allow resuming
            interrupted.store(false);
            // Resume the long-running process
            longRunningProcess();
        } else 
		{
            cout << "Invalid choice. Continuing with the process...\n";
        }
    }

    // Perform cleanup after successful completion or interruption
    cout << "Cleanup after successful completion.\n";
    Sleep(2000);
}

void handleOverflowUnderflow()
 {
    char continueChoice;

    do
	 {
        system("cls"); // Clear the console on Windows. Use system("clear") for Unix-like systems.

        int operationChoice;
        cout << "Choose operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n";
        operationChoice = getInputInt("Enter operation: ");

        switch (operationChoice)
		 {
            case 1:
			 {
                cout << "Choose data type:\n1. Integer\n2. Double\n";
                int typeChoice = getInputInt("Choose data type: ");
                cout << "\n\n";

                switch (typeChoice)
				 {
                    case 1:
					 {
                        int int_a = -2000000000;
                        int int_b = -1500000000;
                        cout << "Addition of " << int_a << " and " << int_b << " is: ";
                        handleAdd(int_a, int_b);
                        break;
                    }
                    
                    case 2:
					 {
                        double double_a = -1.7e308;
                        double double_b = -1.7e308;
                        cout << "Addition of " << double_a << " and " << double_b << " is: ";
                        handleAdd(double_a, double_b);
                        break;
                    }
                    default:
					 {
                        cout << "\nInvalid Input" << endl;
                        break;
                    }
                }
                break;
            }
            case 2:
			 {
                cout << "Choose data type:\n1. Integer\n2. Double\n";
                int typeChoice = getInputInt("Choose data type: ");

                switch (typeChoice)
				 {
                    case 1: {
                        int int_c = -2000000000;
                        int int_d = -1500000000;
                        cout << "Subtraction of " << int_c << " and " << int_d << " is: ";
                        handleSub(int_c, int_d);
                        break;
                    }
                    case 2:
					 {
                        double double_c = -1.7e308;
                        double double_d = -1.7e308;
                        cout << "Subtraction of " << double_c << " and " << double_d << " is: ";
                        handleSub(double_c, double_d);
                        break;
                    }
                    default:
					 {
                        cout << "\nInvalid Input" << endl;
                        break;
                    }
                }
                break;
            }
            case 3:
			 {
                cout << "Choose data type:\n1. Integer\n2. Double\n";
                int typeChoice = getInputInt("Choose data type: ");

                switch (typeChoice)
				 {
                    case 1: {
                        int int_e = 20000;
                        int int_f = 20000;
                        cout << "Multiplication of " << int_e << " and " << int_f << " is: ";
                        handleMul(int_e, int_f);
                        break;
                    }
                    case 2:
					 {
                        double double_e = 1.7e154;
                        double double_f = 1.7e154;
                        cout << "Multiplication of " << double_e << " and " << double_f << " is: ";
                        handleMul(double_e, double_f);
                        break;
                    }
                    default: 
					{
                        cout << "\nInvalid Input" << endl;
                        break;
                    }
                }
                break;
            }
            default:
			 {
                cout << "\nInvalid Operation Choice" << endl;
                break;
            }
        }

        cout << "\nDo you want to perform another operation? (Press 'y' to quit, any other key to continue): ";
        continueChoice = getInputChar(" ");

    } 
	while (continueChoice != 'y' && continueChoice != 'Y');
}

void handleDivisionByZero()
 {
    double numerator, denominator;
    numerator = getInputDouble("Enter numerator: ");
    denominator = getInputDouble("Enter denominator: ");

    handleDivision(numerator, denominator); // call handleDivision function
}

void handleInvalidInput() 
{
	  char continueChoice;

do
 {
	system("cls");
	int operationChoice;
	
	 cout<<"\t \t \t INVALID INPUT EXCEPTION\n";
	 
     cout << "\t\tChoose operation:\n1. positive number validation\n2. negative number validation \n3. datatypes validation\n4. numeric string validation \n5. non-empty validation.\n";
         
	operationChoice=getInputInt("Enter  ");
	
system("cls");

   switch (operationChoice)
    {
            case 1:
			{    // User input for positive number validation
                     int posNumber;
                      cout<<"\t \t \t POSITIVE INPUT EXCEPTION\n";
                      cout << "Enter a positive number: ";
                       posNumber=getInputInt(" ");
                      chkPos(posNumber);
                       break;
}

case 2:
{

// User input for negative number validation
int negNumber;
 cout<<"\t \t \t NEGATIVE INPUT EXCEPTION\n";
cout << "Enter a negative number: ";
 negNumber=getInputInt(" ");
chkNeg(negNumber);
 break;
}

case 3:
	{
	
	string typeInput,type="int";
	 cout<<"\t \t \t  INTERGER INPUT EXCEPTION\n";
    cout << "Enter a number (to validate type int): ";
     typeInput=getInputString(" ");
    chkType<int>(typeInput, type);
    break;
}

case 4:
{
// User input for numeric string validation
string numericInput;
 cout<<"\t \t \t NUMERIC STRING INPUT EXCEPTION\n";
cout << "Enter a numeric string: ";
 numericInput=getInputString(" ");
chkNumStr(numericInput);
 break;
}

case 5:
{
// User input for not empty validation
string nonEmptyInput;
 cout<<"\t \t \t NON-EMPTY INPUT EXCEPTION\n";
cout << "Enter a non-empty string: ";
cin.ignore(); // Clear the newline character left in the buffer
getline(cin, nonEmptyInput);
chkNotEmpty(nonEmptyInput);
 break;
}
 default:
  {
    cout << "\nInvalid Operation Choice" << endl;
    handleDefault();
    cout << "\nDo you want to return to the main menu? (Press 'y' to quit, any other key to return to menu): ";
    cin >> operationChoice;
    break;
        }

} 
cout << "\nDo you want to perform another operation? (Press 'y' to quit, any other key to continue): ";
        cin >> continueChoice;

    } 
	while (continueChoice != 'y'&&continueChoice !='Y');
}


void handleFileNotFound()
 {
	  char continueChoice;
	  do{
	  
   system("cls");
	int operationChoice;
	 cout<<"\t \t \t FILE HANDLING EXCEPTIONS\n";
        cout << "Choose operation:\n1. file existence validation\n2. file append validation \n3.file creating validation.\n";
         operationChoice=getInputInt(" ");
   system("cls");
   
   switch (operationChoice)
    {
    case 1:
	{   
// User input for file existence validation
string filename;
 cout<<"\t \t \t FILE EXISTANCE EXCEPTION\n";
cout << "Enter a filename to check if it exists: ";
 filename=getInputString(" ");
chkFileExists(filename);
break;
}

// User input for file append validation
case 2:
{
string appendFilename;
 cout<<"\t \t \t FILE APPENDING EXCEPTION\n";
cout << "Enter a filename to check if it exists for appending: ";
 appendFilename=getInputString(" ");
chkFileCanAppend(appendFilename);
break;
}

case 3:
{	
// User input for file write validation
string writeFilename;
 cout<<"\t \t \t FILE CREATION EXCEPTION\n";
cout << "Enter a filename to create a file: ";
 writeFilename=getInputString(" ");
chkFileCanWrite(writeFilename);
break;}

 default: 
 {
                cout << "\nInvalid Operation Choice" << endl;
                break;
            }
        }
 cout << "\nDo you want to perform another operation? (Press 'y' to quit, any other key to continue): ";
         continueChoice=getInputChar(" ");;

	} while (continueChoice != 'y'&&continueChoice !='Y');

}

void handleIndexOutOfBound()
 {
    int s = 5; // Size must be an integer
    float array[s];
    int index_value;

    for (int i = 0; i < 5; i++)
	 {
        cout << "Enter the array " << i + 1 << " element: ";
         array[i]=getInputFloat(" ");
    }

    cout << "\nEnter the index number of array you want to access: " << endl;
     index_value=getInputInt(" ");

    handleArray(array, index_value, s); // Call handleArray function
}

void handleNullPointer()
 {
    int* ptr = nullptr; // Pointer initialized to null
    int value;
    char continueChoice;
    do
	 {
        system("cls");
        int choice;
        cout << "Choose an option:" << endl;
        cout << "1. Set null pointer " << endl;
        cout << "2. Set pointer to a valid value" << endl;
        choice=getInputInt(" ");

        switch (choice)
		 {
            case 1:
			 {
                handlepointer(ptr); // Call handleNull function
                break;
            }
            case 2:
			 {
                cout << "Enter a value to store: ";
                value=getInputInt(" ");
                ptr = &value;
                 handlepointer(ptr); 
                break;
            }
            default:
			 {
                cout << "Invalid choice." << endl;
                break;
            }
        }

        cout << "\nDo you want to perform another operation? (Press 'y' to quit, any other key to continue): ";
        continueChoice=getInputChar(" ");;

    } while (continueChoice != 'y' && continueChoice != 'Y');
}

void handleDataConversion()
 {
    string hexstr, octstr;
    cout << "Enter first hexadecimal string: ";
    cin >> hexstr;
    cout << "Enter first octal string: ";
    cin >> octstr;

    cout << "Converting hex strings:" << endl;
    cout << "Hexadecimal value of " << hexstr << " is: " << testHexStringToInt(hexstr) << endl;

    cout << "Converting octal strings:" << endl;
    cout << "Octal value of " << octstr << " is: " << testOctStringToInt(octstr) << endl;
}

// Function to handle input exceptions for integers
int getInputInt(const string& message)
 {
    int input;
    while (true) {
        cout << message;
        if (cin >> input) {
            return input;
        } else {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Function to handle input exceptions for doubles
double getInputDouble(const string& message) {
    double input;
    while (true) {
        cout << message;
        if (cin >> input) {
            return input;
        } else {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

char getInputChar(const string& message) {
    char input;
    while (true) {
        cout << message;
        if (cin >> input) {
            return input;
        } else {
            cout << "Invalid input. Please enter a character." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

string getInputString(const string& message) {
    string input;
    while (true) {
        cout << message;
        if (cin >> input) {
            return input;
        } else {
            cout << "Invalid input. Please enter a string." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

float getInputFloat(const string& message) {
    float input;
    while (true) {
        cout << message;
        if (cin >> input) {
            return input;
        } else {
            cout << "Invalid input. Please enter a float." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}


