//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
// Modified by Ioannis Stamos and Yosef Yudborovsky

#ifndef TEACH_CSCI235_BST_BINARY_NODE_H_
#define TEACH_CSCI235_BST_BINARY_NODE_H_
#include <iostream>

using namespace std;

template<class ItemType, class OtherType>
class BinaryNode
{   
public:
   BinaryNode();
   BinaryNode(const ItemType& an_item);
   
    
    /* BinaryNode(const ItemType& anItem, */
   /*            BinaryNode<ItemType>* leftPtr, */
   /*            BinaryNode<ItemType>* rightPtr); */

    void SetItem(const ItemType& an_item);

   void SetOther(const OtherType& other); // (const OtherType& other)

   ItemType GetItem() const;
   
   OtherType GetOther() const;
   OtherType &GetOtherReference();

   bool IsLeaf() const;

   BinaryNode<ItemType, OtherType>* GetLeftPtr() const;
   BinaryNode<ItemType, OtherType>* GetRightPtr() const;
   
   void SetLeftPtr(BinaryNode<ItemType, OtherType>* leftPtr);
   void SetRightPtr(BinaryNode<ItemType, OtherType>* rightPtr);
    void addLine(int lineNum); // Adds line number to other
    void displayLines(); // Display line numbers from the list
    void displayWordCount(); // Displays count of words

 private:
   ItemType          item_;   // Data portion (key)
   OtherType         other_;  // Data portion (value)
   // int lineNum;
   BinaryNode<ItemType, OtherType>* left_ptr_;   // Pointer to left child
   BinaryNode<ItemType, OtherType>* right_ptr_;  // Pointer to right child
    
}; // end BinaryNode

#include "BinaryNode.cpp"

#endif // TEACH_CSCI235_BST_BINARY_NODE_H_
