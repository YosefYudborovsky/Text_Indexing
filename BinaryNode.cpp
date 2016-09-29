//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
// Modified by Ioannis Stamos

/** @file BinaryNode.cpp */
#ifndef TEACH_CSCI235_BST_BINARY_NODE_CPP
#define TEACH_CSCI235_BST_BINARY_NODE_CPP

#include "BinaryNode.h"
#include <cstddef>
#include <list>
#include <iostream>
using namespace std;

template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>::BinaryNode() : item_(ItemType()), other_(OtherType()), left_ptr_(NULL), right_ptr_(NULL)
{
}  // end default constructor

template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>::BinaryNode(const ItemType& an_item) : item_(an_item), other_(OtherType()), left_ptr_(NULL), right_ptr_(NULL)
{
}  // end constructor

/*template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>::BinaryNode(const ItemType& an_item, const ItemType& other_) : left_ptr_(NULL), right_ptr_(NULL)
{
    item = an_item;
    other = other_;
}  // end constructor*/

// template<class ItemType>
// BinaryNode<ItemType>::BinaryNode(const ItemType& anItem, BinaryNode<ItemType>* leftPtr,
//                              BinaryNode<ItemType>* rightPtr) : item(anItem), left_ptr_(leftPtr), right_ptr_(rightPtr)
// {
// }  // end constructor


template<class ItemType, class OtherType>
void BinaryNode<ItemType, OtherType>::SetItem(const ItemType& an_item)
{
   item_ = an_item;
}  // end setItem

template<class ItemType, class OtherType>
void BinaryNode<ItemType, OtherType>::SetOther(const OtherType& other) // (const OtherType& other)
{
    other_ = other;
    
}  // end setItem

template<class ItemType, class OtherType>
ItemType BinaryNode<ItemType, OtherType>::GetItem() const 
{
   return item_;
}  // end getItem

template<class ItemType, class OtherType>
OtherType BinaryNode<ItemType, OtherType>::GetOther() const 
{
  
    return other_;
}  

template<class ItemType, class OtherType>
OtherType &BinaryNode<ItemType, OtherType>::GetOtherReference()
{
   return other_;
}  

template<class ItemType, class OtherType>
bool BinaryNode<ItemType, OtherType>::IsLeaf() const
{
  return ((left_ptr_ == NULL) && (right_ptr_ == NULL));
}

template<class ItemType, class OtherType>
void BinaryNode<ItemType, OtherType>::SetLeftPtr(BinaryNode<ItemType, OtherType>* left_ptr) 
{
   left_ptr_ = left_ptr;
}  // end setLeftChildPtr

template<class ItemType, class OtherType>
void BinaryNode<ItemType, OtherType>::SetRightPtr(BinaryNode<ItemType, OtherType>* right_ptr) 
{
   right_ptr_ = right_ptr;
}  // end setRightChildPtr

template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>* BinaryNode<ItemType, OtherType>::GetLeftPtr() const
{
  return left_ptr_;
}  // end getLeftChildPtr		

template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>* BinaryNode<ItemType, OtherType>::GetRightPtr() const
{
  return right_ptr_;
}  // end getRightChildPtr


template<class ItemType, class OtherType>
void BinaryNode<ItemType, OtherType>::addLine(int lineNum) // Adds line number to other
{
    //int lineNum = lineNumber;
    try {        
        other_.push_back (lineNum);
    } catch (int num) {
        //other_.push (lineNum);
    }
}
template<class ItemType, class OtherType>
void BinaryNode<ItemType, OtherType>::displayLines() // Display line numbers from the list
{
    cout << " Lines: ";
    
    for(int i=0; i<other_.size();i++)
    {
        int x = (other_.front()+1);
        cout << " " << x << ", ";
        other_.pop_front();
        other_.push_back(x);
    }
}
template<class ItemType, class OtherType>
void BinaryNode<ItemType, OtherType>::displayWordCount() // Adds line number to other
{
    cout << "Count: " << other_.size() << " ";
    //if (binaryTree->maxSize < other_.size())
    //other_.pop_front();
}

#endif // #define TEACH_CSCI235_BST_BINARY_NODE_CPP


