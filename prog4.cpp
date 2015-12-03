//Jack Cannon
//CS 163
//Program 4
//prog4.cpp
//
//This file contains the main program for program 4




#include "prog4.h"


int main()
{
    //This section tests the concept class =============================================================
    char con1[20] = "Linear";//Concept name
    char con_match[20] = "Linear";
    char st1[20] = "LLL";//Data structure name
    char st1_match[20] = "LLL";
    char adv[5][20] = {"Fast", "Remove at head", "Stretchable"};//Advantages
    char disadv[5][20] = {"Memory", "Hard to sort", "Hard to search"};//Disadvantages

    concept test1, test2;

    //Should return 0 - NULL data members
    cout << test1.display() << endl;

    //Set concept and data structure data members
    cout << test1.set_concept(con1) << ", ";
    cout << test1.match_concept(con_match) << endl;
    cout << test1.set_structure(st1) << ", ";
    cout << test1.match_structure(st1_match) << endl;
    cout << endl;

    //Get hash value
    cout << test1.get_hash() << endl;

    //Set advantages and disadvantages
    for (int i = 0; i < 3; ++i)
    {
        cout << test1.add_advantage(adv[i]) << ", ";
        cout << test1.add_disadvantage(disadv[i]);
        cout << endl;
    }

    //Should be successful display of the above data mambers
    cout << "display() result: " << test1.display() << endl;

    //Copy contents and display new object with copied data
    //Should match first object
    cout << "copy_concept(test1) result: " << test2.copy_concept(test1) << endl;
    cout << "display() result: " << test2.display() << endl;

    return 0;
}

















