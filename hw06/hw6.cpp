//
//  main.cpp
//  hw06
//
//  Created by Patricia Antlitz on 3/12/23.
//
/***********************************************
Author: <Patricia Antlitz>
Date: <03/12/2023>
Purpose: <Practice copy constructor and copy constructor overload>
Sources of Help: <https://www.learncpp.com/cpp-tutorial/overloading-the-assignment-operator/>
Time Spent: <4hrs>
***********************************************/
/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
Date:
Name:
*/

#include <iostream>
using namespace std;

class DynamicStringArray
{
public:
    //A default constructor that sets the dynamic array to nullptr and sets size to 0.
    DynamicStringArray():dynamicArray(nullptr), size(0){}
    DynamicStringArray(const DynamicStringArray &obj);
    DynamicStringArray operator=(const DynamicStringArray &obj);
    ~DynamicStringArray();
    
    void setSize(int aSize)
    {
        size = aSize;
    }
    //A function that returns size.
    int getSize(void) const
    {
        return size;
    }
    //A function named addEntry that takes a string as input.
    void addEntry(string inputStr);
    //A function named deleteEntry that takes a string as input
    bool deleteEntry(string inputStr);
    
    /*
     A function named getEntry that takes an integer as input and returns
     a pointer that references
     to the string at that index in dynamicArray
     */
    string getEntry(int input);
    
private:
    //A private member variable called dynamicArray that references a dynamic array of type string
    string *dynamicArray;
    //A private member variable called size that holds the number of entries in the array.
    int size;
};

int main(int argc, const char * argv[])
{
    //list object
    DynamicStringArray list;
    //add strings to list
    list.addEntry("apple");
    list.addEntry("pear");
    list.addEntry("raspberry");
    list.addEntry("orange");

    // Output list
    cout << "List:" << endl;
    for (int i = 0; i < list.getSize(); i++)
    {
        cout << list.getEntry(i) << ", ";
    }
    cout << endl << endl;

    //Add an item to the original list
    cout << "Add strawberry to the List:" << endl;
    list.addEntry("strawberry");
    for (int i = 0; i < list.getSize(); i++)
    {
        cout << list.getEntry(i) << ", ";
    }
    cout << endl << endl;

    //Delete an item
    cout << "Updated list after removing raspberry from it:" << endl;
    list.deleteEntry("raspberry");
    
    for (int i = 0; i < list.getSize(); i++)
    {
        cout << list.getEntry(i) << ", ";
    }
    cout << endl << endl;
    //print the address to show its different
    cout << "Original list object is stored in address: " << &list << endl;
    cout << endl;

    cout << "Copy constructor test:" << endl << endl;
    
    //create a new list with values from the original list
    DynamicStringArray newList(list);
    cout << "Copied list:" << endl;
    for (int i = 0; i < newList.getSize(); i++)
    {
        cout << newList.getEntry(i) << ", ";
    }
    cout << endl << endl;
    //new list's address
    cout << "New list object is stored in address: " << &newList << endl;
    cout<< endl;

    //alters the original list to test if the copied list is altered as well
    cout << "Add banana and pineapple to the original list:" << endl;
    list.addEntry("banana");
    list.addEntry("pineapple");
    for (int i = 0; i < list.getSize(); i++)
    {
        cout << list.getEntry(i) << ", ";
    }
    cout << endl << endl;
    
    cout << "Check if new items on the original list were copied to the copied list:" << endl;
    for (int i = 0; i < newList.getSize(); i++)
    {
        cout << newList.getEntry(i) << ", ";
    }
    cout << endl << endl;

    return 0;
}
/*
 The function should create a new
 dynamic array one element larger than dynamicArray, copy all elements from dynamicArray into
 the new array, add the new string onto the end of the new array, increment size, delete the old
 dynamicArray, and then set dynamicArray to the new array.
 */
void DynamicStringArray::addEntry(string inputStr)
{
    if(size != 0)
    {
        string* arr = new string[size + 1];
        // copy all elements from dynamicArray into the new array,
        for(int i = 0; i < size; i++)
        {
            arr[i] = dynamicArray[i];
        }
        //add the new string onto the end of the new array,
        arr[size] = inputStr;
        // increment size,
        size++;

        //delete the old dynamicArray,
        delete[] dynamicArray;
    
        // and then set dynamicArray to the new array.
        dynamicArray = arr;
    }
    else
    {
        dynamicArray = new string[1];
        size = 1;
        dynamicArray[0] = inputStr;
    }
}
//bool type to return false or true
/*
 The function should search
 dynamicArray for the string. If not found, it returns false. If found, it creates a new dynamic
 array one element smaller than dynamicArray. It should copy all elements except the input
 string into the new array, delete dynamicArray, decrement size, and return true.
 */
bool DynamicStringArray::deleteEntry(string inputStr)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if(dynamicArray[i].compare(inputStr) == 0)
        {
            break;
        }
    }
        
    if(i == size)
    {
        return false;
    }
    
    string * arr = new string[size - 1];
    
    int arrIndex = 0;
    
    for(i = 0; i < size; i++)
    {
        if(dynamicArray[i].compare(inputStr) != 0)
            arr[arrIndex++] = dynamicArray[i];
    }
    delete[] dynamicArray;
    dynamicArray = arr;
    size--;
    
    return true;
}
/*
 A function named getEntry that takes an integer as input and returns a pointer that references
 to the string at that index in dynamicArray. It should return nullptr if the index is out of
 dynamicArray’s bounds.
 */
string DynamicStringArray::getEntry(int input)
{

    return dynamicArray[input];
}

//copy constructor
DynamicStringArray::DynamicStringArray(const DynamicStringArray &obj)
{
    size = obj.size;
    
    dynamicArray = new string[size];
    
    for(int i = 0; i < size; i++)
    {
        dynamicArray[i] = obj.dynamicArray[i];
    }
}

/*
 Overload the copy assignment operator so that the dynamic array is properly copied to the
 target object.
 
 Note to Greater: once you give me your feedback, would you clarify why both the Copy constructor and the overload copy assignment operator are necessary?
 */
DynamicStringArray DynamicStringArray::operator=(const DynamicStringArray &obj)
{
    size = obj.size;
    dynamicArray = new string[size];

    for(int i = 0; i < size; i++)
    {
        dynamicArray[i] = obj.dynamicArray[i];
    }

    return *this;
}

//A destructor that frees up the memory allocated to the dynamic array.
DynamicStringArray::~DynamicStringArray()
{
    //Delete, since this is a basic code, I believe this is sufficient to delete the lists
    delete[] dynamicArray;
    cout << "Deleted " << dynamicArray << endl;
}
