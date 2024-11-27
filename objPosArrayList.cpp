#include "objPosArrayList.h"
using namespace std;
// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP;
    aList= new objPos [arrayCapacity];
    listSize = 0;
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize; 
}

void objPosArrayList::insertHead(objPos thisPos)
{
    //Sanity check
    if (listSize >= ARRAY_MAX_CAP){
        return;
    }
    for (int i = listSize; i >0; i--){
        aList[i] = aList[i-1];
    }

    aList[0] = thisPos;
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    //Sanity Check (error check)
    if (listSize >= arrayCapacity){
        //cout << "Array List Full.  No Insertion." << endl;
        return;
    }
    aList[listSize++] = thisPos;
}

void objPosArrayList::removeHead()
{
    //Sanity Check
    if (listSize == 0){
        return;
    }
    for (int i =0; i < listSize-1; i++){
        aList[i] = aList[i+1];
    }
    listSize --;
}

void objPosArrayList::removeTail()
{
    if (listSize > 0){
        listSize --;
    }   
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize -1];
}

objPos objPosArrayList::getElement(int index) const
{
    // check if index is out of bound
    // then apply respective updates
    //printf("First!\n");
    //printf("Index Org.: %d \n", index);
    if(index <= 0){
        index = 0;  
    }
    else if(index > listSize) {
        index = listSize - 1;
    }
    if(index <= 0){
        index = 0;  
    }
    //listSize = listSize +1;
    //printf("List Size: %d \n", listSize);
    //printf("Index: %d \n", index);

    // Option: You can also "throw exceptions in C++"
    // Option: You can also return an absurd integer to indicate error
    
    // finally, get element
    return aList[index];
}
// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.
