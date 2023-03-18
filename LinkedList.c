#include "LinkedList.h"

int main(){
    int dataInt[] = {10,20,40,35};
    string dataString[] = {"hello", "world", "i am", "kaan"};

    Node *headInt = genericNew(dataInt);
    Node *headString = genericNew(dataString);

    headInt = headInt->add(headInt, dataInt+1);
    headInt = headInt->add(headInt, dataInt+2);
    headInt = headInt->add(headInt, dataInt+3);

    headString = headString->add(headString, dataString+1);
    headString = headString->add(headString, dataString+2);
    headString = headString->add(headString, dataString+3);

    headInt->printNode(headInt);
    printf("\n");
    headString->printNode(headString);
}
