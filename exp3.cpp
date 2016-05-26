#include <iostream>
#include <cctype>
using namespace std;
int main()
{
int num[10]=[0,1,2,3,4,5,6,7,8];
void QuickSort(apvector<int>&num,int top,int bottom)
{
   int middle;
   if (top<bottom)
   {
	middle=partition(num,top,bottom);
	quicksort(num,top,middle);
	quicksort(num,middle+1,bottom);

   }
return;
}

return 0;
}
