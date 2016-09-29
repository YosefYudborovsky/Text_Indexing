

#include "BinarySearchTree.h"  // ADT binary tree operations
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>           // list of lines


using namespace std;

void displayInfo(string& anItem)
{
    cout << "\n" << anItem << " ";
}  // end display


string cleansAWord(string nextWord)
{
    for(int i=0; i <nextWord.length(); i++) // check each char
    {
        nextWord[i] = tolower( nextWord[i]); // convert upper case to lwer case
        if(ispunct(nextWord[i])) // convert punctuation to space
            nextWord.erase(i); //= ' ';
        else if(isdigit(nextWord[i])) // convert numerical data to space
            nextWord.clear();
        
    }
    return nextWord;
}  // end display

int main()
{
    
    BinarySearchTree<string, list<int> >* binary_tree= new BinarySearchTree<string, list<int> >(); // New binary tree     // Read from a file
    ifstream input_file("/Users/Yosi/Desktop/School/Spring\ 2015/CSCI\ 235/Assiignment4/BSTIndex/BSTIndex/document1.txt");
    string nextLine="", nextWord="", searchWord="", clearWord="";
    int lineNumber=0;
    if (input_file.is_open())
    {
        while (!input_file.eof())
        {
            while ( getline (input_file,nextLine) ) // Reads line by line
            {
                istringstream iss(nextLine); // Assigns the line to stringStream
                while ((iss >> nextWord)) // Reads individual words from the stringStream
                {
                    clearWord = cleansAWord(nextWord);
                    if (clearWord.length() > 0)
                    binary_tree->Add(clearWord, lineNumber);
                       
                }
                lineNumber++; // Line number
  
            }
            binary_tree->InorderTraverseForPrint(displayInfo); // to display all the relevant info about each node
            int numNodes = binary_tree->GetNumberOfNodes(); // reurns total number of nodes
            cout << "\n\nNumber of nodes = " << numNodes << endl;
            int hight = binary_tree->GetHeight(); // returns height of the tree
            cout << "The height of the tree = " << hight << endl;
           //cout << "The word with the maximum accurrences = " <<
            binary_tree->maxSizeList(); //->GetItem() << endl;
            
            cout << "\nPlease provide a word to look for: " << endl;
            cin >> searchWord;
            list<int> x = binary_tree->lineNumbersForList(searchWord); // Passes the word to look for its node. returns the list of lines from the relevant node.
            if(x.size()>0)
            {
                cout << "The provided word accure " << x.size() << " times."<< endl;
                cout << "Lines: ";
                for(int i=0; i<x.size();i++)
                {
                    int number = (x.front());
                    cout << number << ", ";
                    x.pop_front();
                    x.push_back(number);
                }

            }
            else
                cout << "Word Does Not Exist " << endl;

        }

    }
    else // If can't open file
    {
        cout << "Can't open one/both file/s" << endl;
    }
    input_file.close();
    return 0;
        
}

