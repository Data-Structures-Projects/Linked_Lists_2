
#include "MusicPlaylist.hpp"

MusicPlaylist::MusicPlaylist()
{
    // No changes needed
}

/*
 * Purpose: Has to detect if a loop is present in the linkedlist pointed by head
 * @param none
 * @return integer length of loop if one exists. If loop not present return -1
 */
int MusicPlaylist::findLoopInPlaylist(){

    Song* slowPtr = head;
    Song* fastPtr = head;
    int count = 0;
   while (slowPtr && fastPtr && fastPtr->next) {
      slowPtr = slowPtr->next;
      fastPtr = fastPtr->next->next;

      if (slowPtr == fastPtr){
        Song* temp = slowPtr;
         while(slowPtr -> next != temp){
            count ++;
            slowPtr = slowPtr -> next;
         }
         return count + 1;
   }
   
}
return -1;
}

/*
 * Purpose: Has to remove all the Song nodes from [start, end] inclusive.
 * Has to print appropriate messages on cout like below if the linkedlist is empty
 * or if the values of start/ end are improper
 * follow the same order for couts in the writeup - check empty list first, then check wrong start/end values
 * @param integers start and end (1 based indexing not 0 based)
 * @return none
 */
void MusicPlaylist::removeSongs(int start, int end){
    if (!head) {
            std::cout << "Playlist is Empty" << endl;
            return;
        }

        if (start <= 0 || end <= 0 || start > end) {
            std::cout << "Invalid start or end values" << std::endl;
            return;
        }

        Song* prev = nullptr;
        Song* current = head;
        int count = 1;

        while (count < start) {
            prev = current;
            current = current->next;
            count++;
        }

        Song* endNode = current;

        while (count <= end) {
            Song* temp = current;
            current = current->next;
            delete temp;
            count++;
        }

        if (prev) {
            prev->next = current;
        } else {
            head = current;
        }
    
}


/*
 * Purpose: Interweave the webpages alternatively into a new linkedlist 
 * starting with the first webpage in the list one
 * Assign the head of the new interweaved list to the head of this BrowserHistory
 * DO NOT create new nodes and copy the data, just use the same nodes from one and two and change pointers
 * If one of them runs out of length append the remaining of the other one at end
 * @param two linkedlist heads one and two
 * @return none
 */
void MusicPlaylist::mergeTwoPlaylists(Song *headOne, Song * headTwo){
    if (!headOne && !headTwo) {
            return; // Both lists are empty
        } else if (!headOne) {
            head = headTwo; // If one is empty, set the head to two
            return;
        } else if (!headTwo) {
            head = headOne; // If two is empty, set the head to one
            return;
        }
    Song* currentOne = headOne;
    Song* currentTwo = headTwo;
    Song* interweaved = nullptr;
    Song* tail = nullptr;

    
        while (currentOne && currentTwo) {
            if (!interweaved) {
                interweaved = currentOne;
                tail = currentOne;
                currentOne = currentOne->next;
            } else {
                tail->next = currentTwo;
                tail = currentTwo;
                currentTwo = currentTwo->next;
                tail->next = currentOne;
                tail = currentOne;
                currentOne = currentOne->next;
            }
        }

        if (currentOne) {
            tail->next = currentOne; // Append remaining of one
        }

        if (currentTwo) {
            tail->next = currentTwo; // Append remaining of two
        }

        head = interweaved; // Set the head of the interweaved list
    
}