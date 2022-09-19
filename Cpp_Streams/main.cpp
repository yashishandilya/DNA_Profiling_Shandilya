/* Dynamic array allocation program in C

Running program looks like:
    Give input of -1 to exit the program.
    Enter value: 1
    Array: 1
    Enter value: 2
    Array: 1 2
    Enter value: 3
    Array: 1 2 3
    Enter value: 4

    Growing array from size 3 to 6
    Array: 1 2 3 4
    Enter value: 5
    Array: 1 2 3 4 5
    Enter value: 6
    Array: 1 2 3 4 5 6
    Enter value: 7

    Growing array from size 6 to 9
    Array: 1 2 3 4 5 6 7
    Enter value: -1
    Done.
 */
#include <stdio.h>
#include <stdlib.h>   // Needed for malloc

#define true 1         // Make true a synonym for 1
const int Delta = 3;   // Array growth increment


//-------------------------------------------------
void displayArray( int theArray[], int size)
{
    printf("Array: ");
    for( int i=0; i<size; i++) {
        printf("%d ",theArray[ i]);
    }
    printf("\n");
} // end of displayArray(...)


//----------------------------------------------------
// Add newNumber into array pArray, currently containing
// "size" elements. Grow the array as needed, updating
// currentSize and maxSize.
//
// Be sure to implement this fully in place within main()
// before attempting to do it here in the function!
//
// To do this, if array is full then:
//   1. Allocate space for new array (pNew) that is the
//      size of the old one (pArray), plus 3 more.
//   2. Copy over the old array (pArray) into the new
//      one (pNew)
//   3. Free up the old array (pArray)
//   4. Make the array (pArray) now be the new array (pNew)
//   5. Update the new array max size
// Add the new element and update the new current size
//
void add( int newNumber,    // New number to be added
          int * *pArray,    // Pointer to existing array
          int *currentSize, // Size of existing (old) array
          int *maxSize)     // Max size, when array is full
{
    // See if array is full
    if (*maxSize == sizeof(*currentSize))
    {
        printf("Old array is full.");
    }
    // 1. Allocate space for new array (pNew) that is the size of
    //    the old one (pArray), plus 3 more.


    // 2. Copy over the old array (pArray) into the new one (pNew)

    // 3. Free up the old array (pArray)

    // 4. Make the array (pArray) now be the new array (pNew)

    // 5. Update the new array max size

    // Add the new element, and update the new current size

} // end of add(...)


//-----------------------------------------------
int main()
{
    int currentSize = 0;
    int maxSize = 0;
    int *pArray = NULL;
    int newNumber = 0;

    // Dynamically allocate space for the initial array
    pArray = (int *)malloc( sizeof( int) * Delta);
    maxSize = Delta;     // Set the initial max size

    // Prompt for, get and store new number
    printf("Give input of -1 to exit the program.\n");
    do {
        printf("Enter value: ");
        scanf("%d", &newNumber);
        if( newNumber == -1) {
            break;   // Exit when -1 is entered
        }

        // Add the new value, growing array if needed
        pArray[0] = newNumber;
        // add( newNumber, &pArray, &currentSize, &maxSize);
        // First implement the code here, before trying to put it
        //    in the add(...) function above.
        // ...


        // Display the array with this new element
        displayArray( pArray, currentSize);
    } while( true);

    printf("Done.\n");
    return 0;
}





















//
//
////////#include <iostream>
////////#include <fstream>
////////#include <string>
////////using namespace std;
////////
////////int main() {
////////
////////    ifstream infile;
////////    string word;
////////    char ch;
////////    string words;
////////    //getline(cin, word);
////////    cin >> word;
////////    //cout << word << endl;
////////    cin >> ch;
////////    //cout << ch << endl;
////////    string sentence = word + ".txt";
////////    //cout << sentence << endl;
////////    infile.open(sentence);
////////
////////    if(!infile.is_open())
////////    {
////////        return 1;
////////    }
////////    //infile >> words;
////////    int counter = 0;
////////    while((infile >> words) && infile.good())
////////    {
////////        cin >> words;
////////        //cout << words << endl;
////////        if(words[0] == ch)
////////        {
////////            counter += 1;
////////            cout << words << endl;
////////        }
////////    }
////////    //cout << "what" << words << endl;
////////    if (counter == 0)
////////    {
////////        cout << "No synonyms for " << word << " begin with " << ch << "." << endl;
////////    }
////////
////////
////////    return 0;
////////}
//////
//////#include <string>
//////#include <iostream>
//////#include <fstream>
//////#include <vector>
//////
//////using namespace std;
//////
//////void acquireData(const string &fname, vector<string> &data);
//////void outputVector(const vector<string> &);
//////void searchVector(char, const vector<string> &);
//////
//////int main()
//////{
//////    string filename = "input.txt";
//////    vector <string> dataVector;
//////
//////    acquireData(filename, dataVector);
//////
//////    cout << "Output in main function" << endl;
//////    outputVector(dataVector);
//////
//////    char letter;
//////    cout << "Enter a single character: ";
//////    cin >> letter;
//////    cout << endl;
//////
//////    searchVector(letter, dataVector);
//////
//////    return 0;
//////}
//////
////////using const allows compiler to check if you're
//////// changing values you shouldn't be changing
//////void outputVector(const vector<string> &v)
//////{
//////    //to avoid comparison between int and uint result of size, we use uint for i
//////    for (unsigned int i = 0; i < v.size(); i++)
//////    {
//////        cout << v.at(i) << endl;
//////    }
//////}
//////
//////void acquireData(const string &fname, vector<string> &data)
//////{
//////    ifstream inFile(fname);
//////    string value;
//////
//////    while(inFile >> value)
//////    {
//////        data.push_back(value);
//////    }
//////
//////    inFile.close();
//////}
//////
//////void searchVector(char let, const vector<string> &v)
//////{
//////    bool found = false;
//////
//////    for (unsigned int i = 0; i < v.size(); ++i)
//////    {
//////        if(v.at(i).at(0) == let)
//////        {
//////            cout << v.at(i) << endl;
//////            found = true;
//////        }
//////    }
//////
//////    if (!found) // if found successfully at 111, !found becomes false.
//////    {
//////        cout << "No data starting with " << let << endl;
//////    }
//////
//////}
////
/////* Dynamic array allocation program in C
////
////Running program looks like:
////    Give input of -1 to exit the program.
////    Enter value: 1
////    Array: 1
////    Enter value: 2
////    Array: 1 2
////    Enter value: 3
////    Array: 1 2 3
////    Enter value: 4
////
////    Growing array from size 3 to 6
////    Array: 1 2 3 4
////    Enter value: 5
////    Array: 1 2 3 4 5
////    Enter value: 6
////    Array: 1 2 3 4 5 6
////    Enter value: 7
////
////    Growing array from size 6 to 9
////    Array: 1 2 3 4 5 6 7
////    Enter value: -1
////    Done.
//// */
//#include <stdio.h>
//#include <stdlib.h>   // Needed for malloc
//
//#define true 1         // Make true a synonym for 1
//const int expo = 3;   // Array growth increment
//
//
////-------------------------------------------------
//void displayArray( int theArray[], int size)
//{
//    printf("Array: ");
//    for( int i=0; i<size; i++) {
//        printf("%d ",theArray[ i]);
//    }
//    printf("\n");
//    printf("Array size: %d\n",size);
//} // end of displayArray(...)
////
////
//////----------------------------------------------------
////// Add newNumber into array pArray, currently containing
////// "size" elements. Grow the array as needed, updating
////// currentSize and maxSize.
//////
////// Be sure to implement this fully in place within main()
////// before attempting to do it here in the function!
//////
////// To do this, if array is full then:
//////   1. Allocate space for new array (pNew) that is the
//////      size of the old one (pArray), plus 3 more.
//////   2. Copy over the old array (pArray) into the new
//////      one (pNew)
//////   3. Free up the old array (pArray)
//////   4. Make the array (pArray) now be the new array (pNew)
//////   5. Update the new array max size
////// Add the new element and update the new current size
//////
//void add( int newNumber,// New number to be added
//          int *index,
//          int * *pArray,    // Pointer to existing array
//          int *currentSize, // Size of existing (old) array
//          int *maxSize
//)     // Max size, when array is full
//{
//    // *currentSize = *maxSize;
//    if (*maxSize == *index -1){
//
//        // See if array is full
//        // 1. Allocate space for new array (pNew) that is the size of
//        //    the old one (pArray), plus 3 more.
//        int *pNew = NULL;
//        int n = *currentSize + expo;
//        pNew = (int *)malloc(n * (sizeof(int)));
//
//        // 2. Copy over the old array (pArray) into the new one (pNew)
//        for (int i = 0;i < *currentSize; i++){
//            pNew[i] = *pArray[i];
//        }
//
//        // // 3. Free up the old array (pArray)
//        // free(*pArray);
//        // // 4. Make the array (pArray) now be the new array (pNew)
//        // *pArray = pNew;
//        // // 5. Update the new array max size
//        // *maxSize += expo;
//
//    }
//    // Add the new element, and update the new current size
//    for (int i = 0; i < *maxSize -1; i++){
//        if (i == *index){
//            *pArray[i] = newNumber;
//            (*index)++;
//        }
//    }
//    // *currentSize = *maxSize;
//} // end of add(...)
//
//
////-----------------------------------------------
//int main()
//{
//    int currentSize = 0;
//    int maxSize = 0;
//    int *pArray = NULL;
//    int newNumber = 0;
//    int index = 0;
//    // Dynamically allocate space for the initial array
//    pArray = (int*)malloc(expo * sizeof( int));
//    maxSize = expo;     // Set the initial max size
//
//    // Prompt for, get and store new number
//    printf("Give input of -1 to exit the program.\n");
//    do {
//        printf("Enter value: ");
//        scanf("%d", &newNumber);
//        if( newNumber == -1) {
//            break;   // Exit when -1 is entered
//        }
//
//        // Add the new value, growing array if needed
//        add( newNumber, &index, &pArray, &currentSize, &maxSize);
//        // First implement the code here, before trying to put it
//        //    in the add(...) function above.
//        // ...
//
//
//        // Display the array with this new element
//        displayArray( pArray, currentSize);
//    } while( true);
//
//    printf("Done.\n");
//    return 0;
//}