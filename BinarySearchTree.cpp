//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file BinarySearchTree.cpp */

#ifndef TEACH_CSCI235_BST_BINARY_SEARCH_TREE_CPP
#define TEACH_CSCI235_BST_BINARY_SEARCH_TREE_CPP
#include <iostream>

#include "BinarySearchTree.h" 
#include "BinaryNode.h" 

// template<class ItemType>
// BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& treePtr)
// {
//    root_ = this->copyTree(treePtr.root_); // Call inherited method
// }  // end copy constructor

template<class ItemType, class OtherType>
BinarySearchTree<ItemType, OtherType>::BinarySearchTree(const BinarySearchTree<ItemType, OtherType>& tree)
{
  root_ = CopyTree(tree.root_);
}  // end copy constructor

template<class ItemType, class OtherType>
BinarySearchTree<ItemType, OtherType>& BinarySearchTree<ItemType, OtherType>::operator=(const BinarySearchTree<ItemType, OtherType>& right_hand_side)
{
  // COMPLETE ASSIGNMENT OPERATOR
}  // end operator=


template<class ItemType, class OtherType>
BinarySearchTree<ItemType, OtherType>::~BinarySearchTree()
{
   DestroyTree(root_);
}  // end destructor


template<class ItemType, class OtherType>
bool BinarySearchTree<ItemType, OtherType>::IsEmpty() const
{
   return root_ == NULL;
}  // end isEmpty


template<class ItemType, class OtherType>
int BinarySearchTree<ItemType, OtherType>::GetHeight() const
{
   return GetHeightHelper(root_);
}  // end getHeight

template<class ItemType, class OtherType>
int BinarySearchTree<ItemType, OtherType>::GetNumberOfNodes() const
{
   return GetNumberOfNodesHelper(root_);
}  // end getNumberOfNodes

template<class ItemType, class OtherType>
void BinarySearchTree<ItemType, OtherType>::Clear()
{
   DestroyTree(root_);
   root_ = NULL;
}  // end clear

template<class ItemType, class OtherType>
bool BinarySearchTree<ItemType, OtherType>::Remove(const ItemType& target)
{
  cout << "Incomplete Remove " << endl;
  return false;
}  // end remove


template<class ItemType, class OtherType>
OtherType BinarySearchTree<ItemType, OtherType>::GetOther(const ItemType& an_entry) const throw(NotFoundException)
{
  cout << "Incomplete GetOther" << endl;

  return OtherType();
}  // end getEntry
    
    
template<class ItemType, class OtherType>
bool BinarySearchTree<ItemType, OtherType>:: Contains(const ItemType& an_entry) const
{
    cout << "Incomplete Contains" << endl;
    return false;
}  // end contains
template<class ItemType, class OtherType>
OtherType& BinarySearchTree<ItemType, OtherType>::GetOtherReference(const ItemType& an_entry) throw(NotFoundException)
{
  cout << "Incomplete GetOtherReference" << endl;

  return OtherType();
}  // end getEntry

template<class ItemType, class OtherType>
// change to return list
OtherType BinarySearchTree<ItemType, OtherType>::lineNumbersForList(const ItemType& an_entry)
{
    BinaryNode<ItemType, OtherType>* new_node = new BinaryNode<ItemType, OtherType>; // New node
    //returned a subtree that is pointing to null
    OtherType list;
    new_node = binarySearchForWord(an_entry, root_); // Calls a private function to look, in order, and return the relevant node
    if(new_node!= NULL)
    {
        list = new_node->GetOther(); // from the returned node, return up the list of lines
        return list;

    }
    else
        return list;

}  // end contains


template<class ItemType, class OtherType>
void BinarySearchTree<ItemType, OtherType>::PreorderTraverse(void visit(ItemType&)) const
{
   Preorder(visit, root_);
}  // end preorderTraverse

template<class ItemType, class OtherType>
void BinarySearchTree<ItemType, OtherType>::InorderTraverse(void visit(ItemType&)) const
{
   Inorder(visit, root_);
}  // end inorderTraverse
    
template<class ItemType, class OtherType>
void BinarySearchTree<ItemType, OtherType>::InorderTraverseForPrint(void visit(ItemType&)) const
{
    InorderPrint(visit, root_);
}  // end inorderTraverse

template<class ItemType, class OtherType>
void BinarySearchTree<ItemType, OtherType>::PostorderTraverse(void visit(ItemType&)) const
{
   Postorder(visit, root_);
}  // end postorderTraverse
    
    
template<class ItemType, class OtherType>
void BinarySearchTree<ItemType, OtherType>::maxSizeList() const
{
    
    OtherType maxOther = maxSize->GetOther();
    ItemType maxItem = maxSize->GetItem();
    cout << "The word with maximum accurances is: " << maxItem << endl;
    cout << "This word accure " << maxOther.size() << " times ";
    cout << "on lines: ";
    for(int i=0; i<maxOther.size();i++)
    {
        int number = (maxOther.front());
        cout << number << ", ";
        maxOther.pop_front();
        maxOther.push_back(number);
    }
 
}

//////////////////////////////////////////////////////////////
//      Protected Utility Methods Section
//////////////////////////////////////////////////////////////

template<class ItemType, class OtherType>
int BinarySearchTree<ItemType, OtherType>::GetHeightHelper(BinaryNode<ItemType, OtherType>* node_ptr) const
{
   if (node_ptr == NULL)
      return 0;
   else
      return 1 + max(GetHeightHelper(node_ptr->GetLeftPtr()), 
                     GetHeightHelper(node_ptr->GetRightPtr()));
}  // end GetHeightHelper

template<class ItemType, class OtherType>
int BinarySearchTree<ItemType, OtherType>::GetNumberOfNodesHelper(BinaryNode<ItemType, OtherType>* node_ptr) const
{
    if (node_ptr == NULL)
        return 0;
    else
        return 1 +(GetNumberOfNodesHelper(node_ptr->GetLeftPtr()) +
                       GetNumberOfNodesHelper(node_ptr->GetRightPtr()));

}  // end GetNumberOfNodesHelper


template<class ItemType, class OtherType>
bool BinarySearchTree<ItemType, OtherType>::Add(const ItemType& new_item,  int new_other) // const OtherType&
{
    
    BinaryNode<ItemType, OtherType>* new_node = new BinaryNode<ItemType, OtherType>(new_item);
    new_node->addLine(new_other); // Adds the new lie number to the "Other" list
    root_ = InsertInorder(new_node, root_);

   return true;
}  // end add


//////////////////////////////////////////////////////////////
//
//      Protected Utility Methods Section
//
//////////////////////////////////////////////////////////////

template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>* BinarySearchTree<ItemType, OtherType>::InsertInorder(BinaryNode<ItemType, OtherType>* newNodePtr,
										      BinaryNode<ItemType, OtherType>* subTreePtr)
{
    BinaryNode<ItemType, OtherType>* tempPtr;
    if (subTreePtr == NULL) // existing node is not larger nor smaller
        return newNodePtr;
    
    else if (newNodePtr->GetItem() > subTreePtr->GetItem()) // if new node is larger than existing node
    {
        tempPtr = InsertInorder(newNodePtr, subTreePtr->GetRightPtr());
        subTreePtr->SetRightPtr(tempPtr);

        return subTreePtr;
    }
    
    else if (newNodePtr->GetItem() == subTreePtr->GetItem()) // if new node is equal existing node
    {

        int x = newNodePtr->GetOther().front();
        subTreePtr->addLine(x); // sets the other in the existing node to using the new other

        if(subTreePtr->GetOther().size() > maxSize->GetOther().size())
                maxSize = subTreePtr;        
        RemoveNode(newNodePtr); //(newNodePtr->GetItem()); // removes the new node
        return subTreePtr;
        
    }
    else //(newNodePtr->GetItem() < subTreePtr->GetItem())  // if new node is smaller than existing node
    {
        tempPtr = InsertInorder(newNodePtr, subTreePtr->GetLeftPtr());
        subTreePtr->SetLeftPtr(tempPtr);

        return subTreePtr;
        
    }
    
}  // end insertInorder
    
template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>* BinarySearchTree<ItemType, OtherType>::binarySearchForWord(ItemType an_entry, BinaryNode<ItemType, OtherType>* subTreePtr)
    {
        BinaryNode<ItemType, OtherType>* tempPtr;
        if (subTreePtr == NULL) // existing tree is empty
            return subTreePtr;

        else if (subTreePtr->GetItem() < an_entry) // if the word in the subtree is lsmaller than the target word
        {
            tempPtr = binarySearchForWord(an_entry, subTreePtr->GetRightPtr());
            subTreePtr->SetRightPtr(tempPtr);
            return tempPtr;

            //return subTreePtr;
        }
        
        else if (subTreePtr->GetItem() == an_entry) // if new node is equal existing node
        {
            return subTreePtr;

        }
        else //if (subTreePtr->GetItem() < an_entry) // if new node is smaller than existing node
        {
            tempPtr = binarySearchForWord(an_entry, subTreePtr->GetLeftPtr());
            subTreePtr->SetLeftPtr(tempPtr);
            return tempPtr;

            //return subTreePtr;

        }
        //else return 0;
        
}  // end insertInorder
    
template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>* BinarySearchTree<ItemType, OtherType>::RemoveValue(BinaryNode<ItemType, OtherType>* subTreePtr,
										    const ItemType target, 
										    bool& success)
{
  cout << "Incomplete RemoveValue" << endl;
  success = false;
  return NULL;
}  // end RemoveValue

template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>* BinarySearchTree<ItemType, OtherType>::RemoveNode(BinaryNode<ItemType, OtherType>* nodePtr)
{
    delete nodePtr;
  //cout << "Incomplete Remove Node" << endl;
  return NULL;
}  // end RemoveNode

template<class ItemType, class OtherType> 
BinaryNode<ItemType, OtherType>* BinarySearchTree<ItemType, OtherType>::RemoveLeftmostNode(BinaryNode<ItemType, OtherType>* nodePtr,
                                                                     ItemType& inorderSuccessor)
{
  cout << "Incomplete RemoveLeftmostNode" << endl;
  return NULL;
}  // end RemoveLeftmostNode


template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>* BinarySearchTree<ItemType, OtherType>::FindNode(BinaryNode<ItemType, OtherType>* subTreePtr,
                                                           const ItemType& target) const 
{
  cout << "Incomplete FindNode" << endl;
  return NULL;
}  // end findNode

template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>* BinarySearchTree<ItemType, OtherType>::CopyTree(const BinaryNode<ItemType, OtherType>* node_ptr) const
{
   BinaryNode<ItemType, OtherType>* new_tree_ptr = NULL;
   // Copy tree nodes during a preorder traversal
   if (node_ptr != NULL) { 
     // Copy node
     new_tree_ptr = new BinaryNode<ItemType, OtherType>(node_ptr->GetItem());
     new_tree_ptr->SetOther(node_ptr->GetOther());

     new_tree_ptr->SetLeftPtr(CopyTree(node_ptr->GetLeftPtr()));
     new_tree_ptr->SetRightPtr(CopyTree(node_ptr->GetRightPtr()));
   }  // end if
   return new_tree_ptr;
}  // end copyTree

template<class ItemType, class OtherType>
void BinarySearchTree<ItemType, OtherType>::DestroyTree(BinaryNode<ItemType, OtherType>* node_ptr)
{
   if (node_ptr != NULL) {
      DestroyTree(node_ptr->GetLeftPtr());
      DestroyTree(node_ptr->GetRightPtr());
      delete node_ptr;
   }  // end if
}  // end destroyTree

template<class ItemType, class OtherType>
void BinarySearchTree<ItemType, OtherType>::Preorder(void visit(ItemType&), BinaryNode<ItemType, OtherType>* node_ptr) const
{
   if (node_ptr != NULL)
   {
      ItemType theItem = node_ptr->GetItem();
      visit(theItem);
      Preorder(visit, node_ptr->GetLeftPtr());
      Preorder(visit, node_ptr->GetRightPtr());
   }  // end if
}  // end preorder

template<class ItemType, class OtherType>
void BinarySearchTree<ItemType, OtherType>::Inorder(void visit(ItemType&), BinaryNode<ItemType, OtherType>* node_ptr) const
{
   if (node_ptr != NULL)
   {
      Inorder(visit, node_ptr->GetLeftPtr());
      ItemType theItem = node_ptr->GetItem();
      visit(theItem); // , theOther
       
       Inorder(visit, node_ptr->GetRightPtr());
   }  // end if
}  // end inorder

template<class ItemType, class OtherType>
void BinarySearchTree<ItemType, OtherType>::InorderPrint(void visit(ItemType&), BinaryNode<ItemType, OtherType>* node_ptr) const
{
    if (node_ptr != NULL)
    {
        InorderPrint(visit, node_ptr->GetLeftPtr());
        ItemType theItem = node_ptr->GetItem();
        visit(theItem); // , theOther
        node_ptr->displayWordCount(); // Calls a function at BinaryNode.h to display the words (item)
        node_ptr->displayLines(); // Calls a function at BinaryNode.h to display the list of lines (other)
        InorderPrint(visit, node_ptr->GetRightPtr());
    }  // end if
}  // end inorder

template<class ItemType, class OtherType>
void BinarySearchTree<ItemType, OtherType>::Postorder(void visit(ItemType&), BinaryNode<ItemType, OtherType>* node_ptr) const
{
   if (node_ptr != NULL)
   {
      Postorder(visit, node_ptr->GetLeftPtr());
      Postorder(visit, node_ptr->GetRightPtr());
      ItemType theItem = node_ptr->GetItem();
      visit(theItem);
   } // end if
}  // end postorder
    
#endif // TEACH_CSCI235_BST_BINARY_SEARCH_TREE_CPP
    








