BinarySearch:
	g++ BinarySearch.cpp -o BinarySearch

MergeSort:
	g++ MergeSort.cpp -o MergeSort

LinkedList: LinkedList.h Node.h
	g++ LinkedList.cpp Node.cpp -o LinkedList

clean:
	rm -f BinarySearch MergeSort LinkedList
