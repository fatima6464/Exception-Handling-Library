#ifndef EXCEPTIONhANDLER_h
#define EXCEPTIONhANDLER_h

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <atomic>
#include <csignal>
#include <windows.h>
#include <limits>

using namespace std;


//-----------------------------------  classes for handling exceptions---------------------------------------------------------------------//

class custom                        // Declaration of BASE CLASS Named CUSTOM
{
	protected:
    string message;

public:
	 void setMessage(const string& msg) {
        message = msg;
    }

    string display() const {
        return message;
    }
};

//---------------------------------------------------DERIVED CLASSES OF various EXCEPTIONS---------------------------------------------------

template<typename T>

class DivisionByZeroException : public custom     // Derived exception class for division by zero
{   
public:
    DivisionByZeroException() {
        setMessage("Error: Division by zero");
    }
    
    T divide(T , T );

    void handleDivision(T , T );
};


template<typename T>

class arrayoutofboundsexception: public custom            // Derived exception class for index out of bound
 {
	
	public:
		arrayoutofboundsexception()   {
		setMessage("Error: accessing invalid array index");}
		T accessArrayElement(T * arr, int index, int size);//size and integer must be integer
		T handlearray(T *arr,int index,int size);
		
};

template<typename T>

class NullPointerException :public custom                     // Derived exception class for  dereferencing null pointer
{

public:
     NullPointerException( )
	{
	 setMessage("Null Pointer exception: The pointer is null.");
	}
	void checkpointer(T* ptr);
	void handlepointer(T *ptr);
};

template<typename T>
class UnderflowException :public custom                       // Derived exception class for  arthicmetic underflow
{

public:
    UnderflowException()  {
	 setMessage("Error: Underflow occurred");
	 }
    
};

template<typename T>
class OverflowException : public custom                      // Derived exception class for  arithmetic overflow 
{

public:
    OverflowException()  {
	setMessage("Error: Overflow occurred");
	}
    T add(T a, T b);
    T sub(T a, T b);
    T mul(T a, T b);
    
    void handleAdd(T a, T b);
    void handleSub(T a, T b);
    void handleMul(T a, T b);
    
};



class UserInterruptException                           // Derived exception class for User Interrupt exception
{
public:
   static void signalHandler(int signal);
   static void setupSignalHandler();
};

template<typename T>

class invalidException : public custom                          // Derived exception class for invalid input
{

public:
    invalidException(const string& msg) {
        setMessage(msg);
    }
    void isPos(T no ); 
    void chkPos(T no );
    
    void isNeg(T no );
    void chkNeg(T no);
    
    void isType(const string& input, const string& type);
    void chkType(const string& input, const string& type);
    
    void isNumStr(const T& input);
    void chkNumStr(const T& input);
    
    void isNotEmpty(const T& input);
    void chkNotEmpty(const T& input);
};

template<typename T>

class fileException :  public custom                             // Derived exception class for file exception
{
	public:
	     fileException(const string&msg)
	     {
	     	setMessage(msg);
		 }
	     void fileExists(const T& filename);
	     void chkFileExists(const T& filename);
	     void fileCanAppend(const T& filename);
	     void chkFileCanAppend(const T& filename);
	     void fileCanWrite(const T& filename);
	     void chkFileCanWrite(const T& filename);
};

//  derived exception class for a default exception
class DefaultException : public custom {
public:
    DefaultException() {
        setMessage("Error: Default exception occurred");
    }

    void triggerDefault() {
        throw DefaultException();
    }

    void handleDefault() {
        try {
            triggerDefault();
        } catch (const DefaultException& e) {
            cout << e.display() << endl;
        }
    }
};
class ConversionException : public custom                      // class data conversion exception
{
public:
    ConversionException(const string& msg) {
        setMessage(msg);
    }

    int hexStringToInt(const string& hexStr);
    int octStringToInt(const string& octStr);
};


//------------------------------------------------define class member functions------------------------------------------------------------------//

//--------------------------------------member functions of class **division by zero exception---------------------------------------------//


template<typename T>

T DivisionByZeroException<T>::divide(T numerator, T denominator)  //divide  member function
 {
    if (denominator == 0) {
        throw DivisionByZeroException();
    }
    return numerator / denominator;
}

template<typename T>

void DivisionByZeroException<T>::handleDivision(T numerator, T denominator) // handledivision member function
{
    try {
        double result = divide(numerator, denominator);
        cout << "Result: " << result << std::endl;
    } catch (const DivisionByZeroException& e) {
        cout << e.display() << std::endl;
    }
}

template<typename T>
                          
void handleDivision(T numerator, T denominator)                        // another function to access class methods through object
 {
    DivisionByZeroException<T> obj;
	obj.handleDivision(numerator, denominator);
}


//------------------------------------------------------------------------------------------------------------------------------//


//----------------------------------  member functions of class **INVALID EXCEPTION** -----------------------------------------------//

//                          ----------- Function to validate if a number is positive  -----------                                   //

// syntax to access class function with template is return_type class_name<T>::member function_name(parameters)

template<typename T>

void invalidException<T>:: isPos(T number)
 {
    if (number <= 0)
	 {
        throw invalidException("ERROR: Number must be positive.");
    }
}

template<typename T>

void invalidException<T>::chkPos(T number)
 {
    try
	 {
        isPos(number);
        cout << "Number " << number << " is positive." << endl;
    } 
	catch (const invalidException &e)
	 {
        cerr << e.display() << endl;
    }
}

template<typename T>

void chkPos(T number)                                
{
    invalidException<T> obj(" "); 
    
    obj.chkPos(number);                                     // access class member function chkPos through object obj
}

//                              ----  Function to validate if a number is negative     ------                                  //

template<typename T>

void invalidException<T>::isNeg(T number)
 {
    if (number >= 0)
	 {
        throw invalidException("ERROR: Number must be negative." );
    }
}


template<typename T>

void invalidException<T>::chkNeg(T number) 
{
    try
	 {
        isNeg(number);
        cout << "Number " << number << " is negative." << endl;
    } 
	catch (const invalidException& e)
	 {
        cerr << e.display() << endl;
    }
}

template<typename T>

void chkNeg(T number)
{
	invalidException<T> obj(" ");       // class object declaration
	obj.chkNeg(number);                 // access class member function chkNeg through object obj
}

//-------------------------------- Function to validate if a string can be converted to the specified data type----------------------------//

template<typename T>

void invalidException<T>::isType(const string& input, const string& type)
 {
    istringstream iss(input);
    T value;
    if (!(iss >> value) || !iss.eof()) 
	{
        throw invalidException("ERROR: Invalid input. Expected data type: " + type);
    }
}

// Handle type validation

template<typename T>

void invalidException<T>::chkType(const string& input, const string& type)
 {
    try
	 {
        isType(input, type);
        cout << "Input '" << input << "' is valid for type " << type << "." << endl;
     } 
	catch (const invalidException& e)
	 {
        cerr << e.display() << endl;
     }
}

template<typename T>

void chkType(string &input,string &type)
{
	invalidException<T> obj(" ");
	obj.chkType(input,type);
}


//-------------------------------- Function to validate if a string contains only digits-------------------------------------------//

template<typename T>

void invalidException<T>::isNumStr(const T& input)
 {
    for (size_t i = 0; i < input.size(); ++i)
	 {
        if (!isdigit(input[i])) 
		{
            throw invalidException("ERROR: Input must be numeric string.");
        }
    }
}

// Handle numeric validation
template<typename T>

void invalidException<T>::chkNumStr(const T& input)
 {
    try
	 {
        isNumStr(input);
        cout << "Input '" << input << "' is numeric string. " << endl;
    } 
	catch (const invalidException& e)
	 {
        cerr << e.display() << endl;
    }
}

template<typename T>

void chkNumStr(T &input)
{
	invalidException<T> obj(" ");
	obj.chkNumStr(input);
}

// -------------------------------------------------Function to validate if a string is empty-------------------------------------//

template<typename T>

void invalidException<T>::isNotEmpty(const T& input) 
{
    if (input.empty()) 
	{
        throw invalidException("ERROR: Input cannot be empty.");
    }
}

// Handle not empty validation
template<typename T>

void invalidException<T>::chkNotEmpty(const T& input)
 {
    try
	 {
        isNotEmpty(input);
        cout << "Input '" << input << "' is not empty." << endl;
    } 
	catch (const invalidException& e)
	{
        cerr << e.display() << endl;
    }
}
template<typename T>

void chkNotEmpty(T &input)
{
	invalidException<T> obj(" ");
	obj.chkNotEmpty(input);
}
//--------------------------------------------------------------------------------------------------------------------------------------------//

//-------------------------------------------------member functions of FILE EXCEPTION class---------------------------------------------------//

// ----------------------------------------------- Function to validate if a file exists-------------------------------------------//

template<typename T>
void fileException<T>::fileExists(const T& filename)
 {
    ifstream file(filename.c_str());
    if (!file.is_open()) 
	{
        throw fileException("File '" + filename + "' not found.");
    }
}

template<typename T>
void fileException<T>::chkFileExists(const T& filename)
 {
    try
	 {
        fileExists(filename);
        cout << "File '" << filename << "' exists." << endl;
    } 
	catch (const fileException& e) 
	{
       cerr << e.display() << endl;
    }
}

template<typename T>

void chkFileExists(const T& f_name)
 {
    fileException<T> obj(" ");
    obj.chkFileExists(f_name);
}

// ----------------------------------------------- Function to validate if file can append -------------------------------------------//

template<typename T>

void fileException<T>::fileCanAppend(const T& filename)
 {
   ifstream file(filename.c_str());
    if (!file.is_open())
	 {
        throw fileException("File '" + filename + "' does not exist or cannot be opened for appending.");
    }
}

template<typename T>

void fileException<T>::chkFileCanAppend(const T& filename)
 {
    try
	 {
        fileCanAppend(filename);
        std::cout << "File '" << filename << "' exists and can be opened for appending." << std::endl;
    } 
	catch (const fileException& e) 
	{
        std::cerr << e.display() << std::endl;
    }
}

template<typename T>

void chkFileCanAppend(const T& f_name)
 {
    fileException<T> obj(" ");
    obj.chkFileCanAppend(f_name);
}

// ----------------------------------------------- Function to validate file can write-------------------------------------------//

template<typename T>

void fileException<T>::fileCanWrite(const T& filename)
 {
    ofstream file(filename.c_str(), ios::out | ios::app); // Open file in output mode, appending if it exists
    if (!file.is_open())
	 {
        throw fileException("File '" + filename + "' cannot be opened for writing.");
    }
}

template<typename T>

void fileException<T>::chkFileCanWrite(const T& filename)
 {
    try
	 {
        fileCanWrite(filename);
        cout << "File '" << filename << "' is created and can be opened for writing." << endl;
    } 
	catch (const fileException& e)
	 {
       cerr << e.display() << endl;
    }
}

template<typename T>

void chkFileCanWrite(const T& f_name)
 {
    fileException<T> obj(" ");
    obj.chkFileCanWrite(f_name);
}
//----------------------------------------------------------------------------------------------------------------------------------------------//

//-------------------------------------------member functions of ARRAY OUT OF INDEX EXCEPTION class---------------------------------------------//

template<typename T>
 
T arrayoutofboundsexception<T>:: accessArrayElement(T * arr, int index, int size) // access array element member function
{
 
    if (index < 0 || index >= size) {
        throw arrayoutofboundsexception();
    }
    return arr[index] ;
}

 
template<typename T>
   
T arrayoutofboundsexception<T>::handlearray(T *arr,int index,int size)           // handle array member function
{
		try 
		{
         T result = accessArrayElement(arr, index, size);                   // pass arguments to access array elements
		 cout << "Element at index " << index << ": " << result<<endl;    
        } 
	    catch ( arrayoutofboundsexception& e)
		 {                            // catch the message
       cerr << e.display() << endl;
        }	
}

template<typename T>
T handleArray(T *arr, int index, int size) {
    arrayoutofboundsexception<T> obj;
    obj.handlearray(arr, index, size);
}
//----------------------------------------------------------------------------------------------------------------------------------------//

//-------------------------------------------member functions of NULL POINTER EXCEPTION class---------------------------------------------//

// Function to check pointer and print its content
template<typename T>

void  NullPointerException<T>::checkpointer(T *ptr) {
    if (ptr == nullptr) {
        throw NullPointerException();
    } else {
        cout << "Pointer points to a valid memory location with value: " << *ptr << std::endl;
    }
}

// Wrapper function with try-catch block
template<typename T>

void NullPointerException<T>:: handlepointer(T *ptr)
 {
    try 
	{
        checkpointer(ptr);
    } 
	catch (NullPointerException &e)
	 {
       cerr << "ERROR: " << e.display() <<endl;
    }
}

template<typename T>

void handlepointer(T *ptr)
{
	NullPointerException<T> obj;
	obj.handlepointer(ptr);
}
 
 //-------------------------------------------------------------------------------------------------------------------------------------------//
 //---------------------------------------member functions of class user interrupt------------------------------------------------------------//

std::atomic<bool> interrupted(false );

void UserInterruptException::signalHandler(int signal)       // signal handler member function
 {
    if (signal == SIGINT) {
        interrupted.store(true);
        std::cout << "\nSIGINT received. Preparing to exit...\n";
        // Handle the interrupt here
    }
}

// Function to set up the signal handler
void UserInterruptException::setupSignalHandler()            // set up signal handler member function
 {
    signal(SIGINT, &UserInterruptException::signalHandler);
}

 void setupSignalHandler()        // wajeeha yeh additional function jis mae hum class k object declare kerty hain phir obj. k through class k function ko call kerty
 {
    // Create an instance of the class
    UserInterruptException obj;     
    obj.setupSignalHandler();
}
//-----------------------------------------------------------------------------------------------------------------------------------------//

//------------------------------------------------ define member functions of over flow class -----------------------------------------------------//

template<typename T>

T OverflowException<T>:: add(T a, T b)         // add member funtcion 
{
    if ((b > 0 && a > numeric_limits<T>::max() - b)) 
	{
        throw OverflowException();
    } 
	else if (b < 0 && a < numeric_limits<T>::min() - b) 
	{
        throw UnderflowException<T>();
    } 
	else
	{
        return a + b;
    }
}

template<typename T>

void OverflowException<T>::handleAdd(T a, T b)   // handle add member function
 {
    try
	 {
        T result = add(a, b);
        cout << "Result of addition: " << result << endl;
    } 
	catch (const OverflowException& e) 
	{
        cout << e.display() << endl;
    } 
	catch (const UnderflowException<T>& e) 
	{
        cout << e.display() << endl;
    }
}

template<typename T>
T handleAdd(T a, T b)                    // another function to call member function through class object
{
	OverflowException <T> obj;
	obj.handleAdd(a,b);
}


template<typename T>

T OverflowException<T>::sub(T a, T b)         // sub member function
{
    if ((b > 0 && a < numeric_limits<T>::min() + b))
	 {
        throw UnderflowException<T>();
    } 
	else if (b < 0 && a > numeric_limits<T>::max() + b) 
	{
        throw OverflowException();
    }
    return a - b;
}

template<typename T>

void OverflowException<T>::handleSub(T a, T b)         // handle sub member function
{
    try
	 {
        T result = sub(a, b);
        cout << "Result of subtraction: " << result << endl;
    } 
	catch (const OverflowException& e)
	 {
        cout << e.display() << endl;
    } 
	catch (const UnderflowException<T>& e) 
	{
        cout << e.display() << endl;
    }
}

template<typename T>
T handleSub(T a, T b)                     
{
	OverflowException <T> obj;
	obj.handleSub(a,b);
}



template<typename T>

T  OverflowException<T>::mul(T a, T b)        // mul member function
 {
    if (a > 0) 
	{
        if (b > 0) 
		{
            if (a > numeric_limits<T>::max() / b) 
			{
                throw OverflowException();
            }
        } 
		else if (b < 0) 
		{
            if (a > numeric_limits<T>::min() / b)
			 {
                throw  UnderflowException<T>();
            }
        }
    }
	 else if (a < 0) 
	 {
        if (b > 0) 
		{
            if (a < numeric_limits<T>::min() / b)
			 {
                throw  UnderflowException<T>();
            }
        } 
		else if (b < 0) 
		{
            if (a < numeric_limits<T>::max() / b)
			 {
                throw OverflowException();
            }
        }
    }
    // Handle the case where b is zero to prevent division by zero errors
    if (b == 0) {
        return 0; // Multiplication by zero results in zero
    }
    return a * b;
}

template<typename T>

void OverflowException<T>::handleMul(T a, T b) // handle mul member function
{
    try {
        T result = mul(a, b);
        cout << "Result of multiplication: " << result << endl;
    } catch (const OverflowException& e) {
        cout << e.display() << endl;
    } catch (const UnderflowException<T>& e) {
        cout << e.display() << endl;
    }
}

template<typename T>

T handleMul(T a, T b)
{
	OverflowException <T> obj;
	obj.handleMul(a,b);
}

//-----------------------------------------------------------------------------------------------------------------------------------------//

//----------------------------------default exception--------------------------------//


void handleDefault() {
    DefaultException obj;
    obj.handleDefault();
}
//-------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------member functions of data conversion exception-----------------------//

bool isValidHex(const string& hexStr) {
    for (char c : hexStr) {
        if (!isxdigit(c)) {
            return false;
        }
    }
    return true;
}

bool isValidOct(const string& octStr) {
    for (char c : octStr) {
        if (c < '0' || c > '7') {
            return false;
        }
    }
    return true;
}

int ConversionException::hexStringToInt(const string& hexStr) {
    if (!isValidHex(hexStr)) {
        throw ConversionException("Invalid hexadecimal string: " + hexStr);
    }

    try {
        size_t idx;
        int value = stoi(hexStr, &idx, 16);
        if (idx != hexStr.size()) {
            throw ConversionException("Hexadecimal conversion out of range: " + hexStr);
        }
        return value;
    } catch (...) {
        throw ConversionException("Hexadecimal conversion out of range: " + hexStr);
    }
}

int ConversionException::octStringToInt(const string& octStr) {
    if (!isValidOct(octStr)) {
        throw ConversionException("Invalid octal string: " + octStr);
    }

    try {
        size_t idx;
        int value = stoi(octStr, &idx, 8);
        if (idx != octStr.size()) {
            throw ConversionException("Octal conversion out of range: " + octStr);
        }
        return value;
    } catch (...) {
        throw ConversionException("Octal conversion out of range: " + octStr);
    }
}

int testHexStringToInt(const string& hexStr) {
    try {
        ConversionException obj(" ");
        return obj.hexStringToInt(hexStr);
    } catch (const ConversionException& e) {
        cerr << e.display() << endl;
        return 0;
    }
}

int testOctStringToInt(const string& octStr) {
    try {
        ConversionException obj(" ");
        return obj.octStringToInt(octStr);
    } catch (const ConversionException& e) {
        cerr << e.display() << endl;
        return 0;
    }
}

//               -------------------------------------------------------------------------------------------------------------------
#endif // EXCEPTIONHANDLER_H
