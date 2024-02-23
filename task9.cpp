#include<iostream>

enum SortingStrategy {
    BUBBLE_SORT, SELECTION_SORT
};


struct SortingOption {
   SortingStrategy e;
   void (*fptr)(int *,int);
};

void bubble(int * arr,int size) {
   for (int i = 0; i < size - 1;++i) {
      for (int j = 0; j < size - 1 -i; ++j) {
           if (arr[j]  < arr[j + 1]) {
	      std::swap(arr[j],arr[j + 1]);
	   }
      }
   }
}

void selection(int * arr,int size ) {
   int minIndex;
   for (int i = 0;i < size; ++i) {
        minIndex = i;
	for (int j = i + 1; j < size; ++j) {
	    if (arr[j] < arr[minIndex]) {
	        minIndex = j;
	    }
	    if (minIndex != i) {
	       std::swap(arr[minIndex],arr[i]);
	    }
	}
   }
}

int main()
{
   const int size = 2;
   SortingOption arr[size];

   std::cout << "choose the SortingStrategy : " << std::endl;
   std::cout << "Press 1 if u want to use bubble sort :" << std::endl;
   std::cout << "Press 2 if u want to use selection sort :" << std::endl; 
 
   int choice;
   std::cin >> choice;
   
   for (int i = 0; i < size; ++i) {
     if (choice == 1) {
       arr[i].fptr = bubble;
     } else arr[i].fptr = selection;
   }
  const int length = 5;
  int arrr[length];

  std::cout << "Enter the array of integers :" << std::endl;
  for (int i = 0; i < length; ++i) {
     std::cin >> arrr[i];
  }

  for (int j = 0;j < size; ++j) {
	  std::cout << "Enter the " << j <<  "st SortingStrategy " << std::endl; 
	  arr[j].fptr(arrr,length);
     for (int i = 0; i < length; ++i) {
        std::cout << arrr[i] << std::endl;
     }
  }



}
