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
    int result;

    result = destroy(root);
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
node** tree::search_wrapper(char concept_name[])
{
    return search(concept_name, root);
}

//This function searches the tree recursively and returns
//the address of the left or right pointer to the matching node
//Returns 0 if no match
node** tree::search(char concept_name[], node * ptr)
{
    node ** result;

    if (!root)
        return 0;

    //If there is a match, return 1
    if (root -> data.match_concept(concept_name))
        return &root;

    //Otherwise traverse recursively
    result = search(concept_name, root -> left);
    if (result)
        return result;

    return search(concept_name, root -> right);

}














//This function takes a c-string of a concept name 
//and if there is a match, returns 1 and fills the 
//concept in the argument
//Otherwise, it returns 0
int tree::retrieve_wrapper(concept & to_fill, char concept_name[])
{
    return retrieve(to_fill, concept_name, root);
}

//This function searches the tree recursively
int tree::retrieve(concept & to_fill, char concept_name[], node * root_ptr)
{
    if (!root_ptr)
        return 0;

    //If there is a match, return 1 and fill concept
    if (root_ptr -> data.match_concept(concept_name))
    {
        if (!to_fill.copy_concept(root_ptr -> data))
            return 0;
        return 1;
    }

    //Otherwise traverse recursively
    if (retrieve(to_fill, concept_name, root_ptr -> left))
        return 1;
    if (retrieve(to_fill, concept_name, root_ptr -> right))
        return 1;

    return 0;

}


//Wrapper function that calls destroy recursively
int tree::destroy_wrapper()
{
    return destroy(root);
}


//This function takes a pointer as an argument
//and destroys the tree
int tree::destroy(node * & root_ptr)
{
    //Tried to delete empty tree
    if (!root_ptr)
        return 0;

    //If leaf, delete
    if (!root_ptr -> left && !root_ptr -> right)
    {
        delete root_ptr;
        root_ptr = NULL;
        return 1;
    }

    //Delete left subtree, then right
    if (destroy(root_ptr -> left))
        return 1;
    if (destroy(root_ptr -> right))
        return 1;

    return 0;

}

//Wrapper function that calls display_in_order recursively
int tree::display_in_order_wrapper()
{
    return display_in_order(root);
}


//This function displays the concept's info
//ordered by hash
int tree::display_in_order(node * root_ptr)
{
    //Tried to display empty tree
    if (!root_ptr)
        return 0;

    //If at leaf, display concept
    if (!root_ptr -> left && !root_ptr -> right)
    {
        if (!(root -> data.display()))
            return 0;
        return 1;
    }

    //Otherwise, traverse recursively to the left first,
    //then the right
    if (display_in_order(root_ptr -> left))
        return 1;
    if (display_in_order(root_ptr -> right))
        return 1;

    return 0;

}
        


//Wrapper function for concept removal
int tree::remove_concept_wrapper(char concept_name[])
{
    return remove_concept(concept_name, root);
}


//This function takes a concept name and node pointer and
//recursively removes said node
//It returns 0 if unsuccessful
int tree::remove_concept(char concept_name[], node * & root_ptr)
{
    node * temp;

    //Empty pointer
    if (!root_ptr)
        return 0;

    //No children case
    if (!root_ptr -> left && !root_ptr -> right)
    {
        delete root_ptr;
        root_ptr = NULL;
        return 1;
    }

    //Two children case
    if (root_ptr -> left && root_ptr -> right)
    {
    }

    //One child case
    if (root_ptr -> left)
        temp = root_ptr -> left;
    else
        temp = root_ptr -> right;

    delete root_ptr;
    root_ptr = temp;

    return 1;

}



































































    











