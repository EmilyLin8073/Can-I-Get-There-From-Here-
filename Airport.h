#ifndef Header_h
#define Header_h

#include<iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

class Node
{
private:
    int airportVal;
    Node* next;
    
public:
    int getAirport ();
    Node(int value);
    int getAirportVal();
    void setAirportVal(int value);
    Node* getNext();
    void setNext(Node* n);
};


class MyList
{
private:
    Node* head;
public:
    MyList();
    void addToList(int value);
    void removeVal(int value);
    
    void printList();
    
    void clearList();
    
    int getListLength();
    
    int getNthElement(int n);
};


class FileNameNode
{
private:
    char* fname;
    FileNameNode* fNext;
public:
    FileNameNode* prepend(char* name);
    char* getName();
    FileNameNode* getNext();
};


class Airport : public MyList
{
private:
    MyList list;
    bool visited;
public:
    Airport();
    bool getVisited();
    void setVisited();
    void markUnvisited();
};


class TravelNetwork
{
private:
    // Create the Data Members for the Travel Network here
    Airport* arr;
    int numOfAirps;
    FileNameNode* fHead = NULL;
    //int countFile = 0;
public:
    
    // Use a constructor to initialize the Data Members for Travel Network
    TravelNetwork();
    
    // The main loop for reading in input
    void processCommandLoop (FILE* inFile);

    void showCommands();
   
    bool dfs (int a, int b);
    
    void depthFirstSearchHelper (int x, int y);

    void doTravel();
    
    void doResize();
    
    void doInsert();
    
    void doDelete();
    
    void doList();
    
    void doFile();
    
};

#endif 
