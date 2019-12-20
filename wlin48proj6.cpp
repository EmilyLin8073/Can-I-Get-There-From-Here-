#include "Airport.h"

//In this function, we are going to return the airport value
int Node::getAirport ()
{
    return airportVal;
}


//In this function, we are going to set the default value for
//airport and set the next equal to NULL
Node::Node(int value)
{
    this->airportVal = value;
    next = NULL;
}


//In this function, we are going to returnt the airport value
int Node::getAirportVal()
{
    return airportVal;
}


//In this function, we are going to set the airport value
void Node::setAirportVal(int value)
{
    this->airportVal = value;
}


//In this function, we are going to return the next node
Node* Node::getNext()
{
    return next;
}


//In this function, we are going to set the next node to n
void Node::setNext(Node* n)
{
    next = n;
}


//In this function, we are going to assigne the head value to NULL
//for default
MyList::MyList()
{
    head = NULL;
}


//In this function, we are going add the node to the list
void MyList::addToList(int value)
{
    Node* curr = this->head;
    Node* prev = NULL;
    while ((curr!= NULL) && (curr->getAirportVal() < value))
    {
        prev = curr;
        curr = curr->getNext();
    }
    Node* tmp = new Node(value);
    // this code just inserts the node at the beginning of the list
    tmp->setAirportVal(value);
    tmp->setNext (curr);
    
    if( prev == NULL)
    {
        this->head = tmp;
    }
    else
    {
        prev->setNext(tmp);
    }
}


//In this function, we are going to remove the value from the list
void MyList::removeVal(int value)
{
    Node* curr = this->head;
    Node* prev = NULL;
    while ((curr!= NULL) && (curr->getAirportVal() != value))
    {
        prev = curr;
        curr = curr->getNext();
    }
    if (curr == NULL) return;
    if( prev == NULL)
    {
        this->head = curr->getNext();
    }
    else
    {
        prev->setNext(curr->getNext());
    }
    delete curr;
}


//In this function, we are going to print out the list
void MyList::printList()
{
    Node *tmp = this->head;
    while(tmp != NULL)
    {
        cout << (tmp)->getAirportVal() << " ";
        tmp = (tmp)->getNext();
    }
    cout << endl;
}


//In this function, we are going to clear the entire list
void MyList::clearList()
{
    Node* temp = this->head;
    
    while(temp != NULL)
    {
        this->head = (this->head)->getNext();
        delete temp;
        temp = this->head;
    }
}


//In this function, we are going to get the length of the list
int MyList::getListLength()
{
    int count = 0;
    Node *tmp = this->head;
    while(tmp != NULL)
    {
        count ++;
        tmp = (tmp)->getNext();
    }
    return count;
}


//In this function, we are going to get the specific node on the list
int MyList::getNthElement(int n)
{
    int count = 0;
    Node *tmp = this->head;
    
    if (tmp == NULL) return -999;
    while((tmp != NULL) && (count != n))
    {
        count ++;
        tmp = (tmp)->getNext();
    }
    if (n > count) return -999;
    int elem = tmp->getAirportVal();
    return elem;
}


//In this function, we are going to prepend the node
FileNameNode* FileNameNode::prepend(char* name)
{
    FileNameNode* newNode = new FileNameNode;
    newNode->fname = name;
    newNode->fNext = this;
    return newNode;
}


//In this function, we are going to get the name for the file
char* FileNameNode::getName()
{
    return this->fname;
}


//In this function, we are going to get the next file name
FileNameNode* FileNameNode::getNext()
{
    return this->fNext;
}


// Use a constructor to initialize the Data Members for Travel Network
TravelNetwork::TravelNetwork()
{
    numOfAirps = 10;
    arr = new Airport[numOfAirps];
}


// The main loop for reading in input
void TravelNetwork::processCommandLoop (FILE* inFile)
{
    char  buffer[300];
    char* input;
    
    input = fgets ( buffer, 300, inFile );   // get a line of input
    
    // loop until all lines are read from the input
    while (input != NULL)
    {
        // process each line of input using the strtok functions
        char* command;
        command = strtok (input , " \n\t");
        
        printf ("*%s*\n", command);
        
        if ( command == NULL )
            printf ("Blank Line\n");
        
        else if ( strcmp (command, "q") == 0)
            exit(1);
        
        else if ( strcmp (command, "?") == 0)
            showCommands();
        
        else if ( strcmp (command, "t") == 0)
            doTravel();
        
        else if ( strcmp (command, "r") == 0)
            doResize();
        
        else if ( strcmp (command, "i") == 0)
            doInsert();
        
        else if ( strcmp (command, "d") == 0)
            doDelete();
        
        else if ( strcmp (command, "l") == 0)
            doList();
        
        else if ( strcmp (command, "f") == 0)
            doFile();
        
        else if ( strcmp (command, "#") == 0)
            ;
        
        else
            printf ("Command is not known: %s\n", command);
        
        input = fgets ( buffer, 300, inFile );   // get the next line of input
    }
}


void TravelNetwork::showCommands()
{
    printf ("The commands for this project are:\n");
    printf ("  q \n");
    printf ("  ? \n");
    printf ("  # \n");
    printf ("  t <int1> <int2> \n");
    printf ("  r <int> \n");
    printf ("  i <int1> <int2> \n");
    printf ("  d <int1> <int2> \n");
    printf ("  l \n");
    printf ("  f <filename> \n");
}


//In this function, we are going to do the dfs
bool TravelNetwork::dfs (int a, int b)
{
    for (int i = 0; i < arr[a-1].getListLength(); i++)
    {
        int c = arr[a-1].getNthElement(i);
        if (c == b) return true;
        
        if ( arr[c-1].getVisited() == false )
        {
            arr[c-1].setVisited();

            if(dfs(c,b) == true)
            {
                return true;
            }
        }
    }
    return false;
}


//In this function, we are going to print out message after dfs
void TravelNetwork::depthFirstSearchHelper (int x, int y)
{
    //mark all airports as unvisited;
    for (int i = 0; i < numOfAirps; i++)
    {
        arr[i].markUnvisited();
    }
    if (dfs(x, y) == true)
    {
        cout << "You can get from Airport " <<  x << " to Airport " << y << " in one or more flights.\n";
    }
    else
    {
        cout << "You can NOT get from Airport " <<  x << " to Airport " << y << " in one or more flights.\n";
    }
}


void TravelNetwork::doTravel()
{
    int val1 = 0;
    int val2 = 0;
    
    // get an integer value from the input
    char* next = strtok (NULL, " \n\t");
    if ( next == NULL )
    {
        printf ("Integer value expected\n");
        return;
    }
    val1 = atoi ( next );
    if ( val1 == 0 && strcmp (next, "0") != 0)
    {
        printf ("Integer value expected\n");
        return;
    }
    
    // get another integer value from the input
    next = strtok (NULL, " \n\t");
    if ( next == NULL )
    {
        printf ("Integer value expected\n");
        return;
    }
    val2 = atoi ( next );
    if ( val2 == 0 && strcmp (next, "0") != 0)
    {
        printf ("Integer value expected\n");
        return;
    }
    
    printf ("Performing the Travel Command from %d to %d\n", val1, val2);
    depthFirstSearchHelper(val1,val2);
    
}


//In this function, we are going to get the size for airport
void TravelNetwork::doResize()
{
    int val1 = 0;
    
    // get an integer value from the input
    char* next = strtok (NULL, " \n\t");
    if ( next == NULL )
    {
        printf ("Integer value expected\n");
        return;
    }
    val1 = atoi ( next );
    if ( val1 == 0 && strcmp (next, "0") != 0)
    {
        printf ("Integer value expected\n");
        return;
    }
    
    printf ("Performing the Resize Command with %d\n", val1 );
    
    arr->clearList();
    arr = new Airport[val1];
    numOfAirps = val1;
}


//In this function, we are going to insert airport
void TravelNetwork::doInsert()
{
    int val1 = 0;
    int val2 = 0;
    
    // get an integer value from the input
    char* next = strtok (NULL, " \n\t");

    if ( next == NULL )
    {
        printf ("Integer value expected\n");
        return;
    }
    val1 = atoi ( next );
    if ( val1 == 0 && strcmp (next, "0") != 0)
    {
        printf ("Integer value expected\n");
        return;
    }
    
    // get another integer value from the input
    next = strtok (NULL, " \n\t");

    if ( next == NULL )
    {
        printf ("Integer value expected\n");
        return;
    }
    val2 = atoi ( next );

    if ( val2 == 0 && strcmp (next, "0") != 0)
    {
        printf ("Integer value expected\n");
        return;
    }

    if (val1 < 1 || val1 > numOfAirps){
        cout << "Error Input: Airport number is out of range.\n";
        return;
    }
    
    if (val2 < 1 || val2 > numOfAirps){
        cout << "Error Input: Airport number is out of range.\n";
        return;
    }
    arr[val1-1].addToList(val2);
}


//In this function, we are going to delete the airport
void TravelNetwork::doDelete()
{
    int val1 = 0;
    int val2 = 0;
    
    // get an integer value from the input
    char* next = strtok (NULL, " \n\t");
    if ( next == NULL )
    {
        printf ("Integer value expected\n");
        return;
    }
    val1 = atoi ( next );
    if ( val1 == 0 && strcmp (next, "0") != 0)
    {
        printf ("Integer value expected\n");
        return;
    }
    
    // get another integer value from the input
    next = strtok (NULL, " \n\t");
    if ( next == NULL )
    {
        printf ("Integer value expected\n");
        return;
    }
    val2 = atoi ( next );
    if ( val2 == 0 && strcmp (next, "0") != 0)
    {
        printf ("Integer value expected\n");
        return;
    }
    printf ("Performing the Delete Command from %d to %d\n", val1, val2);
    arr[val1-1].removeVal(val2);
}


//In this function, we are going to display the list
void TravelNetwork:: doList()
{
    for(int i=0; i<numOfAirps; i++)
    {
        printf("In airport %d\n",i+1);
        arr[i].printList();
    }
    
}


//In this function, we are going to read in the file
void TravelNetwork::doFile()
{
    // get a filename from the input
    char* fname = strtok (NULL, " \n\t");
    if ( fname == NULL )
    {
        printf ("Filename expected\n");
        return;
    }
    
    printf ("Performing the File command with file: %s\n", fname);
    // fHead = fHead->prepend(fname);
    
//    if (fHead != NULL){
//        while(fHead->getNext() != NULL) {
//            if(strcmp(fHead->getName(), fname) == 0) {
//                return;
//            }
//            fHead = fHead->getNext();
//        }
//    }
//    
//    fHead = fHead->prepend(fname);

    FILE* newInput;
    newInput = fopen(fname, "r");
    processCommandLoop(newInput);
    fclose(newInput);
    
    // next steps:  (if any step fails: print an error message and return )
    //  1. verify the file name is not currently in use
    //  2. open the file using fopen creating a new instance of FILE*
    //  3. recursively call processCommandLoop() with this new instance of FILE* as the parameter
    //  4. close the file when processCommandLoop() returns
}


int main (int argc, char** argv)
{
    
    // set up the variable inFile to read from standard input
    FILE* inFile = stdin;
    
    // set up the data needed for the airport adjcency list
    TravelNetwork airportData;
    
    // call the method that reads and parses the input
    airportData.processCommandLoop (inFile);
    
    printf ("Goodbye\n");
    return 1;
}
