/********* YOUR ARE NOT ALLOWED TO CHANGE ANYTHING FROM HERE TO LINE 71***********/
#include "Helper.h"
using namespace std;

//Merge two sorted linked lists in place for task I
Node * mergeList(Node * l1Head, Node * l2Head);
//Removes all the nodes in a sorted list that have the targeted value
Node * removeTargets(Node * head, int val);
//Remove duplicatesd nodes such that node with the same value only appears once
Node * removeDuplicates(Node * head);
//Find the middle node in a given linked list
Node * findMiddle(Node * head);

//Your program will be tested with the following command:
//./lab7_8 test_case.txt NUMBER_HERE(Replace with real number),
//where lab7_8 is your executable name after compilation, 
//test_case.txt is a txt file that has two lines of numbers for creating two lists,
//NUMBER_HERE is a specific target number for task II.
//Note that (1) NUMBER_HERE can be any number when running the command.
//For example, a real command in practice could be "./lab7_8 test_case.txt 6".
//(2) lines could be empty in test_case.txt, which means empty list could be created
int main(int argc, char * argv[]){
    //Preparation. I get this done so that you can focus on the following three tasks.
    //create a list using the first line in the input file
    Node * l1Head = createListFromFile(argv[1], 1);
    //create a list using the second line in the input file
    Node * l2Head = createListFromFile(argv[1], 2);
    // printList(l1Head);
    // printList(l2Head);

    //Your task I: merge the above two sorted lists and keep the merged list sorted.
    //the merge should be in-place. That is, you are not allowed to create a new list,
    //in which node values are copied from two given lists.
    //Instead, you should change the pointers of each existing node properly 
    //to chain the existing nodes in both lists together.
    Node * listHeadAfterTaskI = mergeList(l1Head, l2Head);
    printList(listHeadAfterTaskI);

    //Your task II: find the middle node in the linked list generated after task I
    //If there are two middle nodes, return the first middle nodes.
    //For example, if the list is head->1->2->3->null, the middle node will be 2;
    //if the list is head->1->2->3->4->null, there are will be two middle 
    //nodes (i.e., 2 and 3), your function should return the *first* one, i.e., 2.
    Node * middleNode = findMiddle(listHeadAfterTaskI);
    if (middleNode){
        cout << "The value of the middle node is " << middleNode->value << endl;
    }else{
        cout << "No middle node in an empty list." << endl;
    }

    //Your task III: remove all the nodes in a sorted list that have the targeted value.
    //For example, assuming the targeted value is 6, and the merged list after task I
    //is head->2->2->6->6->7->7->7->7->8->9->null, 
    //after this task III the list will become head->2->2->7->7->7->7->8->9->null
    int targetVal = stoi(argv[2]);
    Node * listHeadAfterTaskIII = removeTargets(listHeadAfterTaskI, targetVal);
    printList(listHeadAfterTaskIII);

    //Your task IV: remove all the duplicated nodes (such that node with the same value
    // only appears once) in the merged list after task III.
    //Since the list remains sorted (non-descending) after task III, 
    //the final list will be strictly ascending as we removed all the duplicated values.
    //Continuing the previous example in taskIII, 
    //if the list returned by taskIII is head->2->2->7->7->7->7->8->9->null,
    //after this taks IV, it will become head->2->7->8->9->null
    Node * listHeadAfterTaskIV = removeDuplicates(listHeadAfterTaskIII);
    printList(listHeadAfterTaskIV);

    return 0;
}
/********* YOUR ARE NOT ALLOWED TO CHANGE ANYTHING FROM Line 1 TO HERE ***********/



/********* YOU SHOULD IMPLEMENT THREE FUNCTIONS AFTER THIS LINE **********/
Node * mergeList(Node * l1Head, Node * l2Head)
{
	if (l1Head == nullptr) {                 // if list 1 is empty
        return l2Head;
    } else if (l2Head == nullptr) {          // if list 2 is empty
        return l1Head;
    }

    Node dummy = {0, nullptr};               // dummy node to hold nodes of the lists
    
    if (l1Head->value <= l2Head->value) {    // if first value of list 1 is less than first value of list 2
        dummy.next = l1Head;                 // dummy node points to list 1 head pointer
        l1Head = l1Head->next;               // move to next node in list 1
    } else {          
        dummy.next = l2Head;                 // dummy node points to list 2 head pointer
        l2Head = l2Head->next;               // move to next node in list 2
    }

    Node *dummyPtr = dummy.next;             // dummy pointer to point to dummy nodes

    while (l1Head != nullptr && l2Head != nullptr) {
        Node *temp = nullptr;                              // temp pointer for loop set to null each loop
        if (l1Head->value <= l2Head->value) {              // if value in list 1 is less than or equal to value in list 2
            temp = l1Head;                                 // temp points to list 1 pointer
            l1Head = l1Head->next;                         // move to next node in list 1
        } else {
            temp = l2Head;                                 // temp points to list 2 pointer
            l2Head = l2Head->next;                         // move to next node in list 2
        }

        dummyPtr->next = temp;                             // dummy node after current node points to temp pointer
        dummyPtr = temp;                                   // dummy pointer points to temp
    }

    if (l1Head != nullptr) {                // if list 1 pointer is not null
        dummyPtr->next = l1Head;            // dummy pointer points to list 1 pointer
    } else if (l2Head != nullptr) {         // if list 2 pointer is not null
        dummyPtr->next = l2Head;            // dummy pointer points to list 1 pointer
    }

    return dummy.next;        // returns dummy node head pointer(either list 1 or list 2 head)
}

Node * findMiddle(Node * head)
{
    int count = 0;
    Node *curr = head;
    while (curr != nullptr) {
        count++;
        curr = curr->next;
    }
    curr = head;
    for (int i = 1; i < count/2; i++) {
        curr = curr->next;
    }
    return curr;
}

Node * removeTargets(Node * head, int val) 
{
    while (head->value == val) {             // if target value starts in the first node
        head = head->next;
    }

    Node *curr = head;
 
    while (curr->next != nullptr) {          // if value isn't in first nodes this loop starts until last node
        if (curr->next->value == val) {      // if next node value is equal to val
            curr->next = curr->next->next;   // next node points to node after next(skips node with target value)
        } else {
            curr = curr->next;               // curr moves to next node
        }
    }
    return head;
}

Node * removeDuplicates(Node * head) 
{
    Node *curr = head;
    Node *next = curr->next;

    while (next) {
        if (curr->value == next->value) {
            curr->next = next->next;           // points to node after current(skips over)
            next = curr->next;                 // moves to following node
        } else {
            curr = curr->next;                 // moves over one
            next = curr->next;                 // moves over one
        }
    }
    return head;
}

