#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char Name[12];
    int Age;
    float Weight;
    int RollNumber;
} sStudentInfo;
int main(int argc, char *argv[])
{
    //Create pointer to the structure
    sStudentInfo psInfo[2]={0};

    printf("Size of structure  =  %u\n\n",(char *)(&psInfo+1) - (char *)&psInfo);


// To find size of array	
	
	int arr[2]={0, 1};
	
	printf("\n Size of arr = %u", (char *) (&arr +1) - (char *) &arr);
    return 0;
}
