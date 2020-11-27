#ifndef SortedCheck_h
#define SortedCheck_h

bool sortedCheck(long* list, long size){
    // Provide your code here...
    for(int i = 0; i < size - 1; i++) {
        if (list[i] <= list[i + 1]) 
            continue;

        else 
            return false;
    }
    return true;
}

#endif 
