#ifndef BinSearch_h
#define BinSearch_h

long binSearch(long* list, long n, long val){
    // Provide your code here

    int start = 0;
    int end = n - 1;
    
    while (start <= end) {
		int mid = (start + end)/2;

		if (list[mid] == val) {
			return mid;
		}
		else if (list[mid] < val) {
			start = mid + 1;
		}
		else
			end = mid - 1; 
    }
    return -1;
}

#endif
