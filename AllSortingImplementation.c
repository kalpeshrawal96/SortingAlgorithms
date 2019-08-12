#include <stdio.h>
#include <stdlib.h>

#include "DFSdata.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int gTemp,column = 13,c,s,d;//Number of sorting algorithms*variation
FILE *f;
int data[25];

//Methods for bubble sort
void bubbleSortLeftToRight(int *arr, int size);
void bubbleSortRightToLeft(int *arr, int size);
void bubbleSortLeftToRightWithEarlyExit(int *arr, int size);
void bubbleSortRightToLeftWithEarlyExit(int *arr, int size);
void bubbleShakerSort(int *arr, int size);
//Methods for selection sort
void selectionSortLeftToRight(int *arr, int size);
void selectionSortRightToLeft(int *arr, int size);
//Methods for insertion sort
void insertionSortLeftToRight(int *arr, int size);
void insertionSortRightToLeft(int *arr, int size);
void shellInsertionSort(int *arr, int size);
void insertionSortBinary(int *arr, int size);
int binarySearch(int *A,int value,int start,int end);
//Methods for heap sort
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i,int *c,int *m);
//Method for quick sort
void printArr( int arr[], int n );
int partition (int arr[], int l, int h,int *c,int *m);
void quickSortIterative (int arr[], int size);

void createFile();
void whiteSpace(int n);
void chooseSortingAlgorithm();
int chooseSortingDataset();
void skipLine(int lines);
void skipColumns(int columnToSkip);

int main(int argc, char *argv[]) 
{
	createFile();
	chooseSortingAlgorithm();
	
	return 0;
}
//Method to select sorting algorithm not fixed as new algorithms will be added
void chooseSortingAlgorithm()
{
	int dataSet,size;
	while(1)
	{
		//New statements will be added for new algorithms
		printf("Choose one of the following sorting algorithm or press 0 to stop:\n");
		printf("1. Insertion Sort\n");
		printf("2. Selection Sort\n");
		printf("3. Bubble Sort\n");
		printf("4. Heap Sort\n");
		printf("5. Quick Sort\n");
		scanf("%d",&c);
		//New cases will be added for new algorithms
		switch(c)
		{
			case 1:
				printf("Choose variant of Insertion Sort:\n");
				printf("1. Left To Right\n");
				printf("2. Right To Left\n");
				printf("3. Bianry Search\n");
				printf("4. Shell Sort\n");
				scanf("%d",&s);
				dataSet = chooseSortingDataset();
				if(dataSet < 6)
					size = 10;
				else
					size =25;
				if( dataSet > 10 && dataSet < 1)
					break;
				switch(s)
				{
					case 1:
						insertionSortLeftToRight(data,size);
						break;
					case 2:
						insertionSortRightToLeft(data,size);
						break;
					case 3:
						insertionSortBinary(data,size);
						break;
					case 4:
						shellInsertionSort(data,size);
						break;
					default:
						printf("\nSorry Try again with valid input!!!\n");
				}
				break;
			case 2:
				printf("Choose variant of Selection Sort:\n");
				printf("1. Left To Right\n");
				printf("2. Right To Left\n");
				scanf("%d",&s);
				dataSet = chooseSortingDataset();
				if(dataSet < 6)
					size = 10;
				else
					size =25;
				if( dataSet > 10 && dataSet < 1)
					break;
				switch(s)
				{
					case 1:
						selectionSortLeftToRight(data,size);
						break;
					case 2:
						selectionSortRightToLeft(data,size);
						break;
					default:
						printf("\nSorry Try again with valid input!!!\n");
				}
				break;
			case 3:
				printf("Choose variant of Bubble Sort:\n");
				printf("1. Left To Right\n");
				printf("2. Right To Left\n");
				printf("3. Left To Right with Early Exit\n");
				printf("4. Right To Left with Early Exit\n");
				printf("5. Shaker Sort\n");
				scanf("%d",&s);
				dataSet = chooseSortingDataset();
				if(dataSet < 6)
					size = 10;
				else
					size =25;
				if( dataSet > 10 && dataSet < 1)
					break;
				switch(s)
				{
					case 1:
						bubbleSortLeftToRight(data,size);
						break;
					case 2:
						bubbleSortRightToLeft(data,size);
						break;
					case 3:
						bubbleSortLeftToRightWithEarlyExit(data,size);
						break;
					case 4:
						bubbleSortRightToLeftWithEarlyExit(data,size);
						break;
					case 5:
						bubbleShakerSort(data,size);
						break;
					default:
						printf("\nSorry Try again with valid input!!!\n");
				}
				break;
			case 4:
				dataSet = chooseSortingDataset();
				if(dataSet < 6)
					size = 10;
				else
					size =25;
				if( dataSet > 10 && dataSet < 1)
					break;
				heapSort(data,size);
				break;	
			case 5:
				dataSet = chooseSortingDataset();
				if(dataSet < 6)
					size = 10;
				else
					size =25;
				if( dataSet > 10 && dataSet < 1)
					break;
				quickSortIterative (data, size);
				printArr(data,size);
				break;	
			case 0: 
				fclose(f);
				exit(0);
				break;
			default:
				printf("\nSorry Try again with valid input!!!\n");
		}
	}
}

//Method to write data on the file
void writeDataToFile(int compare,int moves,int cost)
{
	f = fopen("output.txt","r+");
	int length;
	//Get the file pointer to the beginning of the file
	fseek(f,0,SEEK_SET);
	//Case to skip lines for specific data set row
	//Fixed no need to change
	switch(d)
	{
		case 1:
			skipLine(4);
			break;
		case 2:
			skipLine(6);
			break;
		case 3:
			skipLine(8);
			break;
		case 4:
			skipLine(10);
			break;
		case 5:
			skipLine(12);
			break;
		case 6:
			skipLine(14);
			break;
		case 7:
			skipLine(16);
			break;
		case 8:
			skipLine(18);
			break;
		case 9:
			skipLine(20);
			break;
		case 10:
			skipLine(22);
			break;
	}
	//Case to skip columns for specific algorithm's variation
	//Need to add the new algorihts in case therefor not fixed
	switch(c)
	{
		case 1:
			// For insertion sort variations
			switch(s)
			{
				case 1:
					// For insertion sort left to right
					skipColumns(1);
					break;
				case 2:
					// For insertion sort right to  left
					skipColumns(2);		
					break;
				case 3:
					// For insertion sort binary
					skipColumns(3);			
					break;
				case 4:
					// For insertion shell sort
					skipColumns(4);			
					break;
			}
			break;
		case 2:
			// For selection sort variations
			switch(s)
			{
				case 1:
					// For selection sort left to right
					skipColumns(5);			
					break;
				case 2:
					// For selection sort right to left
					skipColumns(6);			
					break;
			}
			break;
		case 3:
			// For Bubble sort variations
			switch(s)
			{
				case 1:
					// For bubble sort left to right
					skipColumns(7);			
					break;
				case 2:
					// For bubble sort right to left
					skipColumns(8);			
					break;
				case 3:
					// For bubble sort left to right with early exit
					skipColumns(9);			
					break;
				case 4:
					// For bubble sort right to left with early exit
					skipColumns(10);			
					break;
				case 5:
					// For bubble sort right to left with early exit
					skipColumns(11);			
					break;
			}
			break;
		case 4:
			// For heap sort
			skipColumns(12);
			break;
		case 5:
			// For heap sort
			skipColumns(13);
			break;
		
	}
	length = calculateLength(compare,moves,cost);
	// If the lenght of data to be printed is even then print as it is
	if(length % 2 == 0)
	{
		printf("\nlength:%d\n",length);
		//for leading spaces
		whiteSpace((20-length)/2);
		fprintf(f,"(%d,%d,%d)",compare,moves,cost);
		//for trailing spaces
		whiteSpace((20-length)/2);
	}
	// If the lenght of data to be printed is odd then add extra space 
	else
	{
		printf("\nlength:%d\n",length);
		//for leading spaces
		whiteSpace((20-length-1)/2);
		fprintf(f,"(%d,%d,%d) ",compare,moves,cost);
		//for trailing spaces
		whiteSpace((20-length-1)/2);
	}
	fclose(f);
}

//This methods create file with all required feild
//We need to add columns for new algorithm or it's variations
void createFile()
{
	int i;
	f = fopen("output.txt", "w");
	if(f==NULL)
		printf("\nFile can not be open\n");
	else
	{
		/* For First Line */
		// Start:This part may need frequent updation
		whiteSpace(6);	
		fprintf(f, "Various Data array");
		whiteSpace(6);	
		whiteSpace(3);
		fprintf(f, "Insertion Sort");
		whiteSpace(3);
		whiteSpace(3);
		fprintf(f, "Insertion Sort");
		whiteSpace(3);
		whiteSpace(3);
		fprintf(f, "Insertion Sort");
		whiteSpace(3);
		whiteSpace(3);
		fprintf(f, "Insertion Sort");
		whiteSpace(3);
		whiteSpace(3);
		fprintf(f, "Selection Sort");
		whiteSpace(3);
		whiteSpace(3);
		fprintf(f, "Selection Sort");
		whiteSpace(3);
		whiteSpace(4);
		fprintf(f, "Bubble Sort ");
		whiteSpace(4);
		whiteSpace(4);
		fprintf(f, "Bubble Sort ");
		whiteSpace(4);
		whiteSpace(4);
		fprintf(f, "Bubble Sort ");
		whiteSpace(4);
		whiteSpace(4);
		fprintf(f, "Bubble Sort ");
		whiteSpace(4);
		whiteSpace(4);
		fprintf(f, "Bubble Sort ");
		whiteSpace(4);
		whiteSpace(5);
		fprintf(f, "Heap Sort ");
		whiteSpace(5);
		whiteSpace(5);
		fprintf(f, "Quick Sort");
		whiteSpace(5);
		
		fprintf(f, "\n");
		/* For Second Line */
		whiteSpace(30);
		whiteSpace(3);
		fprintf(f, "Left to Right ");
		whiteSpace(3);
		whiteSpace(3);
		fprintf(f, "Right to Left ");
		whiteSpace(3);
		whiteSpace(3);
		fprintf(f, "Binary Search ");
		whiteSpace(3);
		whiteSpace(5);
		fprintf(f, "Shell Sort");
		whiteSpace(5);
		whiteSpace(3);
		fprintf(f, "Left to Right ");
		whiteSpace(3);
		whiteSpace(3);
		fprintf(f, "Right to Left ");
		whiteSpace(3);
		whiteSpace(3);
		fprintf(f, "Left to Right ");
		whiteSpace(3);
		whiteSpace(3);
		fprintf(f, "Right to Left ");
		whiteSpace(3);
		whiteSpace(1);
		fprintf(f, "L-R for early exit");
		whiteSpace(1);
		whiteSpace(1);
		fprintf(f, "R-L for early exit");
		whiteSpace(1);
		whiteSpace(4);
		fprintf(f, "Shaker Sort ");
		whiteSpace(4);
		whiteSpace(20);
		whiteSpace(20);
		fprintf(f, "\n");
		/* For thired Line */
		whiteSpace(30);
		for(i = 0 ; i < column ; i++)
		{
			whiteSpace(2);
			fprintf(f, "(comp,move,cost)");
			whiteSpace(2);	
		}
		
		fprintf(f, "\n");
		// End:This part may need frequent updation
		
		/* For Leaving one line */
		whiteSpace(30+(20*column));
		fprintf(f, "\n");
		/* For Small Random Array */
		whiteSpace(5);
		fprintf(f, "Small Random Array: ");
		whiteSpace(5);
		whiteSpace(20*column);
		fprintf(f, "\n");
		/* For Leaving one line */
		whiteSpace(30+(20*column));
		fprintf(f, "\n");
		/* For Small Sorted Array */
		whiteSpace(5);
		fprintf(f, "Small Sorted Array: ");
		whiteSpace(5);
		whiteSpace(20*column);
		fprintf(f, "\n");
		/* For Leaving one line */
		whiteSpace(30+(20*column));
		fprintf(f, "\n");
		/* Small Reverse Array */
		whiteSpace(5);
		fprintf(f, "Small Reverse Array:");
		whiteSpace(5);
		whiteSpace(20*column);
		fprintf(f, "\n");
		/* For Leaving one line */
		whiteSpace(30+(20*column));
		fprintf(f, "\n");
		/* Small Sorted 1 Misplaced: */
		whiteSpace(2);
		fprintf(f, "Small Sorted 1 Misplaced: ");
		whiteSpace(2);
		whiteSpace(20*column);
		fprintf(f, "\n");
		/* For Leaving one line */
		whiteSpace(30+(20*column));
		fprintf(f, "\n");
		/* Small Reverse 1 misplaced: */
		whiteSpace(2);
		fprintf(f, "Small Reverse 1 Misplaced:");
		whiteSpace(2);
		whiteSpace(20*column);
		fprintf(f, "\n");
		/* For Leaving one line */
		whiteSpace(30+(20*column));
		fprintf(f, "\n");
		/* For Large Random Array */
		whiteSpace(5);
		fprintf(f, "Large Random Array: ");
		whiteSpace(5);
		whiteSpace(20*column);
		fprintf(f, "\n");
		/* For Leaving one line */
		whiteSpace(30+(20*column));
		fprintf(f, "\n");
		/* For Large Sorted Array */
		whiteSpace(5);
		fprintf(f, "Large Sorted Array: ");
		whiteSpace(5);
		whiteSpace(20*column);
		fprintf(f, "\n");
		/* For Leaving one line */
		whiteSpace(30+(20*column));
		fprintf(f, "\n");
		/* Large Reverse Array */
		whiteSpace(5);
		fprintf(f, "Large Reverse Array:");
		whiteSpace(5);
		whiteSpace(20*column);
		fprintf(f, "\n");
		/* For Leaving one line */
		whiteSpace(30+(20*column));
		fprintf(f, "\n");
		/* Large Sorted 1 Misplaced: */
		whiteSpace(2);
		fprintf(f, "Large Sorted 1 Misplaced: ");
		whiteSpace(2);
		whiteSpace(20*column);
		fprintf(f, "\n");
		/* For Leaving one line */
		whiteSpace(30+(20*column));
		fprintf(f, "\n");
		/* Large Reverse 1 misplaced: */
		whiteSpace(2);
		fprintf(f, "Large Reverse 1 Misplaced:");
		whiteSpace(2);
		whiteSpace(20*column);
		fprintf(f, "\n");
		fclose(f);
	}
}

//Method to calculate size of data to be written on the file
int calculateLength(int compare,int moves,int cost)
{
	int length = 0;
	do{
		compare /= 10;
		length++;
	}while(compare != 0);
	do{
		moves /= 10;
		length++;
	}while(moves != 0);
	do{
		cost /= 10;
		length++;
	}while(cost != 0);
	//plus 4 for two brakets and commas (comp,move,cost)
	return (length+4);
}

//Method to skip lines in file
void skipLine(int lines)
{
	int i;
	for(i = 0 ; i < lines ; i++)
	{
		fseek(f,(30+(20*column)+2),SEEK_CUR);
	}
}

//Method to skip columns in file
void skipColumns(int columnToSkip)
{
	int i;
	//Since first column is of size 30 
	fseek(f,30,SEEK_CUR);
	// next all columns are of size 20 
	for(i = 0 ; i < columnToSkip - 1 ; i++)
	{
		fseek(f,20,SEEK_CUR);
	}
}

//Method to select dataset fixed no need to change
int chooseSortingDataset()
{
	int i,*arr;
	printf("\nPress respective number for dataset:\n");
	arr = srandomarray;
	printf("\n1. Small Random Array:");
	for(i = 0 ; i < 10 ; i++)
	{
		printf("%2d ",arr[i]);
	}
	arr = ssortedarray;
	printf("\n2. Small Sorted Array:");
	for(i = 0 ; i < 10 ; i++)
	{
		printf("%2d ",arr[i]);
	}
	arr = sreversearray;
	printf("\n3. Small Reverse Array:");
	for(i = 0 ; i < 10 ; i++)
	{
		printf("%2d ",arr[i]);
	}
	arr = ssortedbutone;
	printf("\n4. Small Sorted but 1 misplaced Array:");
	for(i = 0 ; i < 10 ; i++)
	{
		printf("%2d ",arr[i]);
	}
	arr = sreversebutone;
	printf("\n5. Small Reverse but 1 misplaced Array:");
	for(i = 0 ; i < 10 ; i++)
	{
		printf("%2d ",arr[i]);
	}
	arr = lrandomarray;
	printf("\n6. Large Random Array:");
	for(i = 0 ; i < 25 ; i++)
	{
		printf("%2d ",arr[i]);
	}
	arr = lsortedarray;
	printf("\n7. Large Sorted Array:");
	for(i = 0 ; i < 25 ; i++)
	{
		printf("%2d ",arr[i]);
	}
	arr = lreversearray;
	printf("\n8. Large Reverse Array:");
	for(i = 0 ; i < 25 ; i++)
	{
		printf("%2d ",arr[i]);
	}
	arr = lsortedbutone;
	printf("\n9. Large Sorted but 1 misplaced Array:");
	for(i = 0 ; i < 25 ; i++)
	{
		printf("%2d ",arr[i]);
	}
	arr = lreversebutone;
	printf("\n10. Large Reverse but 1 misplaced Array:");
	for(i = 0 ; i < 25 ; i++)
	{
		printf("%2d ",arr[i]);
	}
	printf("\n Enter your choice of data set:");
	scanf("%d",&d);
	switch(d)
	{
		case 1:
			for(i = 0 ; i < 10 ; i++)
			{
				data[i] = srandomarray[i];
			}
			break;
		case 2:
			for(i = 0 ; i < 10 ; i++)
			{
				data[i] = ssortedarray[i];
			}
			break;
		case 3:
			for(i = 0 ; i < 10 ; i++)
			{
				data[i] = sreversearray[i];
			}
			break;
		case 4:
			for(i = 0 ; i < 10 ; i++)
			{
				data[i] = ssortedbutone[i];
			}
			break;
		case 5:
			for(i = 0 ; i < 10 ; i++)
			{
				data[i] = sreversebutone[i];
			}
			break;
		case 6:
			for(i = 0 ; i < 25 ; i++)
			{
				data[i] = lrandomarray[i];
			}
			break;
		case 7:
			for(i = 0 ; i < 25 ; i++)
			{
				data[i] = lsortedarray[i];
			}
			break;
		case 8:
			for(i = 0 ; i < 25 ; i++)
			{
				data[i] = lreversearray[i];
			}
			break;
		case 9:
			for(i = 0 ; i < 25 ; i++)
			{
				data[i] = lsortedbutone[i];
			}
			break;
		case 10:
			for(i = 0 ; i < 25 ; i++)
			{
				data[i] = lreversebutone[i];
			}
			break;
		default:
			printf("\nSorry Try again with valid input!!!\n");
	}
	return d;	
}

//Method to print white spaces
void whiteSpace(int n)
{
	int i;
	for( i = 0 ; i < n ; i++)
		fprintf (f, "-");
}

//This methos does the searching job from binary search variation of the Insertion Sort
int binarySearch(int *A,int value,int start,int end)
{
	int mid;
	if(start == end)
	{
		gTemp++;
		if(A[start] > value) 
            return start;
        else
            return start+1;
	}
	if(start > end)
        return start;
    mid = (start+end)/2;
    gTemp++;
	if(A[mid] < value)
        return binarySearch(A, value, mid+1, end);
    else if(A[mid] > value)
    {
    	gTemp++;
		return binarySearch(A, value, start, mid-1);
	}
    else
    {
    	gTemp++;
		return mid;
	}
}
//This method is implementation of Insertion Sort with binary searching
void insertionSortBinary(int *arr, int size)
{
	int i,j,k,l,c = 0,m = 0,sorted = 1,temp,cost;//Intialize all variables variable i depicts sorted array elements
	gTemp = 0;
	for(i = 1 ; i < size ; i++/*,c++*/ )
	{
		j = 0;
		j = binarySearch(arr,arr[i],0,i-1);
		if(arr[j]>arr[i])
		{
			temp = arr[i];
			m++;//If transfer to temp is to be counted		
			for(k = i ; k > j ; k--/*,c++*/)
			{
				arr[k] = arr[k-1];
				m++;
			}
			arr[j] = temp;
			m++;//If transfer to temp is to be counted
		}
		printf("\nPass:%d",i);
		sorted++;
		printf("\n");
		for(l = 0 ; l<size ; l++)
		{
			printf("\t%d",arr[l]);
		}
	}
	//Final result
	printf("\nFinal Result:\n");
	for(l = 0 ; l<size ; l++)
	{
		printf("\t%d",arr[l]);
	}
	c = gTemp;
	cost = c + m*3;
	printf("\n%d Number of comparions:%d\tNumber of transfers:%d cost:%d",sorted,c,m,cost);
	writeDataToFile(c,m,cost);
}

//This method is implementation of Insertion Sort with binary searching
void insertionSortRightToLeft(int *arr, int size)//Left to right sorting
{
	int i,j,k,l,c = 0,m = 0,sorted = 1,temp,cost,f = 0;//Intialize all variables variable i depicts sorted array elements
	
	for(i = 1 ; i < size ; i++/*,c++*/ )
	{
		f = 0;
		for(j = i - 1 ; j >= 0; --j/*,c+=2*/)
		{
			c++;
			//printf("\nTest for j:%d i:%d\n",j,i);
			//printf("\narr[%d]:%d < arr[%d]:%d\n",j,arr[j],i,arr[i]);
			if(arr[j] < arr[i])
			{
				//printf("\n--------------IF condition true %d--------------\n",j);
				f++;
				break;	
			}	
		}
		if(j == -1)
			j = 0;
		//printf("\n-------------- outside Test J : %d--------------------------\n",j);
		if(j == 0 && !f)
		{
			//printf("\n--------------SWAP when j == 0--------------\n");
			temp = arr[i];
			m++;//If transfer to temp is to be counted		
			//printf("\nTest: i:%d j:%d\n",i,j);
			for(k = i ; k > j ; k--/*,c++*/)
			{
				arr[k] = arr[k-1];
				m++;
			}
			arr[j] = temp;
			m++;//If transfer to temp is to be counted
		}
		if(f)
		{
			if(i == j + 1)
				continue;
			//printf("\n--------------SWAP when condition is true--------------\n");
			temp = arr[i];
			m++;//If transfer to temp is to be counted		
			//printf("\nTest: i:%d j:%d\n",i,j);
			for(k = i ; k > j + 1 ; k--/*,c++*/)
			{
				arr[k] = arr[k-1];
				m++;
			}
			arr[j+1] = temp;
			m++;//If transfer to temp is to be counted
			//printf("\nflag is true\n");
		}
		printf("\nPass:%d",i);
		sorted++;
		printf("\n");
		for(l = 0 ; l<size ; l++)
		{
			printf("\t%d",arr[l]);
		}
	}
	//Final result
	printf("\nFinal Result:\n");
	for(l = 0 ; l<size ; l++)
	{
		printf("\t%d",arr[l]);
	}
	cost = c + m*3;
	printf("\n%d Number of comparions:%d\tNumber of transfers:%d cost:%d",sorted,c,m,cost);
	writeDataToFile(c,m,cost);
}

//Method for implementing insertion sort left to right
void insertionSortLeftToRight(int *arr, int size)//Left to right sorting
{
	int i,j,k,l,c = 0,m = 0,sorted = 1,temp,cost,f = 0;//Intialize all variables variable i depicts sorted array elements
	
	for(i = 1 ; i < size ; i++/*,c++*/ )
	{
		f = 0;
		for(j = 0 ; j < i ; j++/*,c+=2*/)
		{
			c++;
			if(arr[j] > arr[i])
			{
				f++;
				break;	
			}	
		}
		if(f)
		{
			temp = arr[i];
			m++;//If transfer to temp is to be counted		
			for(k = i ; k > j ; k--/*,c++*/)
			{
				arr[k] = arr[k-1];
				m++;
			}
			arr[j] = temp;
			m++;//If transfer to temp is to be counted
		}
		printf("\nPass:%d",i);
		sorted++;
		printf("\n");
		for(l = 0 ; l<size ; l++)
		{
			printf("\t%d",arr[l]);
		}
	}
	printf("\nFinal Result:\n");
	for(l = 0 ; l<size ; l++)
	{
		printf("\t%d",arr[l]);
	}
	cost = c + m*3;
	printf("\n%d Number of comparions:%d\tNumber of transfers:%d cost:%d",sorted,c,m,cost);
	writeDataToFile(c,m,cost);
}

// Method for Selection Sort Left to Right
void selectionSortLeftToRight(int *arr, int size)
{
	int i,j,s,temp,c = 0,m = 0,cost;
	for(i = 0 ; i < size ; i++)
	{
		s = i;
		for(j = i + 1  ; j < size  ; j++)
		{
			c++;
			if(arr[j] < arr[s])
			{
				s = j;
			}
		}
		if(i!=s)
		{
			temp = arr[i];
			m++;
			arr[i] = arr[s];
			m++;
			arr[s] = temp;
			m++;
		}
	}
	printf("\n");
	for(i = 0 ; i<size ; i++)
	{
		printf("\t%d",arr[i]);
	}
	cost = m * 3 + c; 
	printf("\n Moves:%d Compariosion:%d Total Cost:%d",m,c,cost);
	writeDataToFile(c,m,cost);
}

// Method for Selection Sort Right to Left
void selectionSortRightToLeft(int *arr, int size)
{
	int i,j,s,temp,c = 0,m = 0,cost;
	for(i = size - 1 ; i >= 0 ; i--)
	{
		s = i;
		for(j = i - 1 ; j >= 0 ; j--)
		{
			c++;
			if(arr[j] > arr[s])
			{
				s = j;
			}
		}
		if(i!=s)
		{
			temp = arr[i];
			m++;
			arr[i] = arr[s];
			m++;
			arr[s] = temp;
			m++;
		}
		printf("\nc:%d\n",c);
	}
	printf("\n");
	for(i = 0 ; i<size ; i++)
	{
		printf("\t%d",arr[i]);
	}
	cost = m * 3 + c; 
	printf("\n Moves:%d Compariosion:%d Total Cost:%d",m,c,cost);
	writeDataToFile(c,m,cost);
}

//Method for bubble sort left to right
void bubbleSortLeftToRight(int *arr, int size)
{
	int i,j,temp,c = 0,m = 0,cost;
	printf("\nUnsorted data for without early exit:\n");
	for(i = 0 ; i<size ; i++)
	{
		printf("\t%d",arr[i]);
	}
	for(i = 0 ; i < size - 1 ; i++)
	{
		printf("\nfor i:%d\n",i);
		for(j = 0 ; j < size-1 - i ; j++)
		{
			c++;
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				m += 3;
			}
		}
		for(j = 0 ; j<size ; j++)
		{
			printf("\t%d",arr[j]);
		}
	}
	printf("\nFinal:\n");
	for(i = 0 ; i<size ; i++)
	{
		printf("\t%d",arr[i]);
	}
	cost = m * 3 + c; 
	printf("\n Moves:%d Compariosion:%d Total Cost:%d",m,c,cost);
	writeDataToFile(c,m,cost);
}

//Method for bubble sort right to left
void bubbleSortRightToLeft(int *arr, int size)
{
	int i,j,temp,c = 0,m = 0,cost,t;
	for(t = 0 ; t<size ; t++)
	{
		printf("\t%d",arr[t]);
	}
	for(i = size - 1 ; i > 0 ; i--)
	{
		printf("\nfor i:%d\n",i);
		for(j = size - 1 ; j > size -1 - i ; j--)
		{
			/* ----- printf("\nfor j:%d\n",j); ----- */
			c++;
			if(arr[j] < arr[j-1])
			{
				/* ----- printf("\narr[%d]:%d > arr[%d]:%d\n",j,arr[j],j-1,arr[j-1]); ----- */
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
				m += 3;
			}
		}
		for(t = 0 ; t<size ; t++)
		{
			printf("\t%d",arr[t]);
		}
	}
	printf("\nFinal:\n");
	for(t = 0 ; t < size ; t++)
	{
		printf("\t%d",arr[t]);
	}
	cost = m * 3 + c; 
	printf("\n Moves:%d Compariosion:%d Total Cost:%d",m,c,cost);
	writeDataToFile(c,m,cost);
}

//Method for bubble sort left to right with early exit
void bubbleSortLeftToRightWithEarlyExit(int *arr, int size)
{
	int i,j,temp,c = 0,m = 0,cost,flag = 0;
	printf("\nUnsorted data :\n");
	for(i = 0 ; i<size ; i++)
	{
		printf("\t%d",arr[i]);
	}
	for(i = 0 ; i < size - 1 ; i++)
	{
		flag = 0;
		printf("\nfor i:%d\n",i);
		for(j = 0 ; j < size-1 - i ; j++)
		{
			c++;
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				m += 3;
				flag++;
			}
		}
		for(j = 0 ; j<size ; j++)
		{
			printf("\t%d",arr[j]);
		}
		if(flag==0)
		{
			break;
		}		
	}
	printf("\nFinal:\n");
	for(i = 0 ; i<size ; i++)
	{
		printf("\t%d",arr[i]);
	}
	cost = m * 3 + c; 
	printf("\n Moves:%d Compariosion:%d Total Cost:%d",m,c,cost);
	writeDataToFile(c,m,cost);
}

//Method for bubble sort right to left with early exit
void bubbleSortRightToLeftWithEarlyExit(int *arr, int size)
{
	int i,j,temp,c = 0,m = 0,flag,cost,t;
	printf("\nUnsorted data :\n");
	for(t = 0 ; t<size ; t++)
	{
		printf("\t%d",arr[t]);
	}
	for(i = size - 1 ; i > 0 ; i--)
	{
		printf("\nfor i:%d\n",i);
		flag = 0;
		for(j = size - 1 ; j > size -1 - i ; j--)
		{
			/* ----- printf("\nfor j:%d\n",j); ----- */
			c++;
			if(arr[j] < arr[j-1])
			{
				/* ----- printf("\narr[%d]:%d > arr[%d]:%d\n",j,arr[j],j-1,arr[j-1]); ----- */
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
				m += 3;
				flag++;
			}
		}
		for(t = 0 ; t<size ; t++)
		{
			printf("\t%d",arr[t]);
		}
		if(flag == 0)
		{
			break;
		}
	}
	printf("\nFinal:\n");
	for(t = 0 ; t < size ; t++)
	{
		printf("\t%d",arr[t]);
	}
	cost = m * 3 + c; 
	printf("\n Moves:%d Compariosion:%d Total Cost:%d",m,c,cost);
	writeDataToFile(c,m,cost);
}

//Method for Bubble Shaker Sort
void bubbleShakerSort(int *arr, int size)
{
	int i,j = 0,temp,c = 0,m = 0,flag,cost,t,even,odd = 0;
	even = size;
	printf("\nUnsorted data :\n");
	for(t = 0 ; t < size ; t++)
	{
		printf(" %d",arr[t]);
	}
	for(i = 0 ; i < size - 1 ; i++ )
	{
		flag = 0;
		if(i % 2 == 0 )
		{
			for( ; j < even - 1  ; j++ )
			{
				c++;
				if(arr[j] > arr[j+1])
				{
					temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
					m += 3;
					flag++;
				}	
			}
			even--;
		}
		else
		{
			for( ; j > odd ; j--)
			{
				/* ----- printf("\nfor j:%d\n",j); ----- */
				c++;
				if(arr[j] < arr[j-1])
				{
					/* ----- printf("\narr[%d]:%d > arr[%d]:%d\n",j,arr[j],j-1,arr[j-1]); ----- */
					temp = arr[j];
					arr[j] = arr[j-1];
					arr[j-1] = temp;
					m += 3;
					flag++;
				}
			}	
		}
		printf("\nfor i:%d\n",i);
		for(t = 0 ; t<size ; t++)
		{
			printf("\t%d",arr[t]);
		}
		if(flag == 0)
		{
			break;
		}
	}
	printf("\nFinal :\n");
	for(t = 0 ; t<size ; t++)
	{
		printf("\t%d",arr[t]);
	}
	cost = m * 3 + c; 
	printf("\n Moves:%d Compariosion:%d Total Cost:%d",m,c,cost);
	writeDataToFile(c,m,cost);
}

//Method for Shell Sort
void shellInsertionSort(int *arr, int size)
{
	int i,j,t,p,c = 0,m = 0,cost,temp,prime[] = {1,2,3,5,7,11,13,17,19,23};
	printf("\nUnsorted data :\n");
	for(t = 0 ; t < size ; t++)
	{
		printf(" %d",arr[t]);
	}
	for(t = 9 ; t >= 0 ; t--)
	{
		for (i = prime[t]; i < size ; i++)
	    {
	    	for (j = i; j >= prime[t] ; j -= prime[t])
	        {
	        	c++;
				if(arr[j - prime[t]] > arr[i])
	        	{
	        		temp = arr[i];
					arr[j] = arr[j - prime[t]];
					j-=prime[t];
					arr[j] = temp;
					m += 3;	
				}
			}
	        printf("\nfor i:%d\n",i);
		    for(p = 0 ; p < size ; p++)
		    {
		    	printf("\t%d",arr[p]);
			}
		}
	    printf("\nAfter a phase\n",t);
	    for(p = 0 ; p < size ; p++)
	    {
	    	printf("\t%d",arr[p]);
		}
	}
	printf("\nFinal Result:\n");
	for(p = 0 ; p<size ; p++)
	{
		printf("\t%d",arr[p]);
	}
	cost = c + m*3;
	printf("\n Moves:%d Compariosion:%d Total Cost:%d",m,c,cost);
	writeDataToFile(c,m,cost);
}

//Method for reheapify
void heapify(int arr[], int n, int i,int *c,int *m)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
 	int temp;
 	*c += 1;
    if (l < n && arr[l] > arr[largest])
    {
    	largest = l;
	}
	*c += 1;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        *m += 3;
		temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest,c,m);
    }
}

//Method for heap sort
void heapSort(int arr[], int n)
{
    int i,j,c = 0,m = 0,cost = 0,temp;
	printf("Unsorted:\n");
	for(j = 0 ; j < n ; j++)
    {
    	printf("%d\t",arr[j]);
	}
	printf("\n");
	for (i = n / 2 - 1 ; i >= 0 ; i--)
    {
    	heapify(arr, n, i,&c,&m);
    	for(j = 0 ; j < n ; j++)
    	{
    		printf("%d\t",arr[j]);
		}
		printf("\n");
	}
	for (i = n-1 ; i >= 0 ; i--)
    {
    	temp = arr[0];
 		arr[0] = arr[i];
 		arr[i] = temp;
 		heapify(arr, i, 0,&c,&m);
        for(j = 0 ; j < n ; j++)
    	{
    		printf("%d\t",arr[j]);
		}
		printf("\n");
    }
    printf("Final:\n");
	for(j = 0 ; j < n ; j++)
    {
    	printf("%d\t",arr[j]);
	}
	printf("\n");
	cost = c + m*3;
	printf("\n Moves:%d Compariosion:%d Total Cost:%d",m,c,cost);
	writeDataToFile(c,m,cost);
}

//Method for QuickSort
void quickSortIterative (int arr[], int size)
{
    int h = size - 1;
	int l = 0;
    int c = 0,m = 0,cost = 0;
	// Create an auxiliary stack
    int stack[ h - l + 1 ];
 
    // initialize top of stack
    int top = -1;
 
    // push initial values of l and h to stack
    stack[ ++top ] = l;
    stack[ ++top ] = h;
 
    // Keep popping from stack while is not empty
    while ( top >= 0 )
    {
        // Pop h and l
        h = stack[ top-- ];
        l = stack[ top-- ];
 
        // Set pivot element at its correct position
        // in sorted array
        int p = partition( arr, l, h ,&c,&m);
 		
		printArr(arr,size);
        // If there are elements on left side of pivot,
        // then push left side to stack
        if ( p-1 > l )
        {
            stack[ ++top ] = l;
            stack[ ++top ] = p - 1;
        }
 
        // If there are elements on right side of pivot,
        // then push right side to stack
        if ( p+1 < h )
        {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = h;
        }
    }
    cost = c + m*3;
	printf("\n Number of comparions:%d\tNumber of transfers:%d cost:%d",c,m,cost);
	writeDataToFile(c,m,cost);
}

//Method for Quick Sort partition processing  
int partition (int arr[], int l, int h,int *c,int *m)
{
    printf("l:%d h:%d\n",l,h);
	int left = l,right = h - 1,t;//left is pinter to lowest location and right is pointer to highest location
	while(left < right)
	{
		while(arr[left] <= arr[h] && left < right){
			*c+=1;
			left++;
			printf("\ntest left:%d data:%d pivot:%d",left,arr[left],arr[h]);
			if(left==h)
			break;
		}
		*c+=1;
		while(arr[right] >= arr[h] && left < right){
			right--;
			*c+=1;
			printf("\ntest right:%d data:%d pivot:%d",right,arr[right],arr[h]);
		}
		*c+=1;
		*c+=2;
		if(arr[left]>arr[h] && arr[right]<arr[h]){
			printf("\nswap left:%d data:%d right:%d data:%d",left,arr[left],right,arr[right]);
			t = arr[left];
			arr[left] = arr[right];
			arr[right] = t;
			*m+=3;
			left++;right--;
		}
	}
	printf("\nfinal left:%d right:%d",left,right);
	*c+=1;
	if(arr[left]>arr[h])
	{
		
		t = arr[left];
		arr[left] = arr[h];
		arr[h] = t;
		*m+=3;
		printf("\n-----------------------------end of one iteration------------------------------------\n");
		return left;	
	}
	else
	{
    	printf("\n-----------------------------end of one iteration------------------------------------\n");
		return h;
	}
}

//Method to print the array after each pass
void printArr( int arr[], int n )
{
    int i;
    printf("\n");
    for ( i = 0; i < n; ++i )
        printf( "%d ", arr[i] );
    printf("\n");
}
