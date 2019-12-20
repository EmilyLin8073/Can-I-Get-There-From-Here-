#include "Airport.h"

//In this function, we are setting the airport is not visvited as
//default
Airport::Airport()
{
    visited = false;
}


//In this function, we are going to mark the airport as visvited
bool Airport::getVisited()
{
    return visited;
}

//In this function, we are goin to set the airport as visvited
void Airport::setVisited()
{
    visited = true;
}


//In this function, we are going to set the airport as unvisvited
void Airport::markUnvisited()
{
    visited = false;
}
