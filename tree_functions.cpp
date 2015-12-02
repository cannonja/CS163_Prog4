//Jack Cannon
//CS 163
//Program 4
//tree_functions.cpp
//
//This file contains the implementations for the methods of the tree class

#include "prog4.h"

//Constructor
tree::tree()
{
    root = NULL;
}

//Destructor
tree::~tree()
{
    delete root;
    root = NULL;
}


//Wrapper function for insert
int tree::insert_wrapper(concept & to_insert)
{
    return insert(to_insert, root);
}
    
    
//This function takes a concept as an argument, creates a leaf,
//and inserts into the new node
int tree::insert(concept & to_insert, node * & root_ptr)
{    
    //If root_ptr is NULL, create new leaf and add concept
    if (!root_ptr)
    {
        root_ptr = new node;
        if (!(root_ptr -> data.copy_concept(to_insert)))
            return 0;
        
        root_ptr -> traverse = root_ptr -> data.get_hash();
        if (root_ptr -> traverse == 0)
            return 0;

        root_ptr -> left = NULL;
        root_ptr -> right = NULL;

        return 1;
    }

    //Otherwise, traverse recursively
    if (to_insert.get_hash() < (root_ptr -> traverse))
    {
        if (insert(to_insert, root_ptr -> left))
            return 0;
    }
    else
    {
        if (insert(to_insert, root_ptr -> right))
            return 0;
    }
    
    return 1;
}
        

//This function takes a c-string of a concept name 
//and returns 1 if the concept is in the tree,
//0 otherwise
int tree::search_wrapper(char concept_name[])
{
    return search(concept_name, root);
}

//This function searches the tree recursively
int tree::search(char concept_name[], node * ptr)
{
    if (!root)
        return 0;

    //If there is a match, return 1
    if (root -> data.match_concept(concept_name))
        return 1;

    //Otherwise traverse recursively
    if (search(concept_name, root -> left))
        return 1;
    if (search(concept_name, root -> right))
        return 1;

    return 0;

}


    




























    











