int binary_search(int arr[], int start, int end, int key) {
	int mid;
	while (start <= end) {
		mid = start + (end - start) / 2;//prevent overflow
		if (arr[mid] < key)
			start = mid + 1;
		else if (arr[mid] > key)
			end = mid - 1;
		else
			return mid;
	}
	return -1;
}
//search in the array "arr[]" for the value "key" between start and end