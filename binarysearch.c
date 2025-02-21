#include <stdio.h>

int main(){

int arr[20],n_search,c,num;

printf("Enter number of elements (maximum 20) in array\n");

scanf("%d", &num);

printf("Enter %d integer number\n", num);

for (c=0;c< num; c++)

scanf("%d",&arr[c]);

printf("Enter a number to search\n");

scanf("%d", &n_search);

int first, last, mid;

first = 0;

last = num -1;

mid = (first+last)/2;

while (first <= last)

{

if (arr[mid] < n_search)

first = mid + 1;

else if (arr[mid]= n_search)

{ printf("%d is found at %d location.\n", n_search, mid+1); break;

}

else

last=  mid-1;

mid =  (first + last)/2;
}

if (first > last)

printf("%d is not found in the list.n", n_search);

return 0;

}