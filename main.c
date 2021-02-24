#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int A[20];
    int size;
    int length;
};
void Display(struct Array arr)
{
    int i;
    for(i=0; i<arr.length; i++)
    {
        printf("%d ",arr.A[i]);
    }
}
void Append(struct Array *arr,int x)
{
    if(arr->length<arr->size){
         arr->A[arr->length]=x;
         arr->length++;
    }
    else
        printf("length out of range");

}
void InsertFirst(struct Array *arr,int x)
{
        arr->A[0]=x;
        arr->length++;

}

void Reverse(struct Array arr)
{
    int i=0,j=arr.length-1,temp;
    while(i<j)
    {
        temp=arr.A[i];
        arr.A[i]=arr.A[j];
        arr.A[j]=temp;
        i++;
        j--;
    }
    Display(arr);
}
void LeftRotation(struct Array arr,int x)
{
    int t,i;
    while(x!=0)
    {
        t=arr.A[0];
        for(i=0; i<arr.length-1; i++)
        {
            arr.A[i]=arr.A[i+1];
        }
        arr.length--;
        Append(&arr,t);
        x--;
    }
    Display(arr);
}
void RightRotation(struct Array arr,int x)
{
    int t,i;
    while(x!=0)
    {
        t=arr.A[arr.length-1];
        for(i=arr.length; i>0; i--)
        {
            arr.A[i]=arr.A[i-1];
        }
        arr.length--;
        InsertFirst(&arr,t);
        x--;
    }
    Display(arr);
}
int CheckSortedArray(struct Array arr)
{
    int i;
    for(i=0; i<arr.length-1;i++ )
    {
        if(arr.A[i]>arr.A[i+1])
            return 0;
    }
    return 1;
}
void InsertElementSorted(struct Array arr,int ele)
{
    int j=arr.length-1;
    while(arr.A[j]>ele)
    {
        arr.A[j+1]=arr.A[j];
        j--;
    }
    arr.A[j+1]=ele;
    arr.length++;
    Display(arr);

}
void ArrangePositiveNegative(struct Array arr)
{
    int i=0,j=arr.length-1,temp;
    while(i<j)
    {
        if(arr.A[i]>=0 && arr.A[j]<0 )
        {
            temp=arr.A[i];
            arr.A[i]=arr.A[j];
            arr.A[j]=temp;
        }
        i++;
        j--;
    }
    Display(arr);
}
struct Array*Merge(struct Array *arr1,struct Array *arr2)
{
      int i,j,k;
      i=j=k=0;

     struct Array *arr3=(struct Array *)malloc(sizeof(struct
    Array));

     while(i<arr1->length && j<arr2->length)
     {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else
            arr3->A[k++]=arr2->A[j++];
     }
     for(;i<arr1->length;i++)
            arr3->A[k++]=arr1->A[i];
     for(;j<arr2->length;j++)
            arr3->A[k++]=arr2->A[j];
     arr3->length=arr1->length+arr2->length;
     arr3->size=10;

     return arr3;
}
int main()
{
    //struct Array arr={{-1,2,3,-5,6},20,5};
    struct Array arr1={{2,9,21,28,35},10,5};
    Display(arr1);
    printf("\n");
    struct Array arr2={{2,3,16,18,28},10,5};
    Display(arr2);
    printf("\n");
    struct Array *arr3;
    arr3=Merge(&arr1,&arr2);
    printf("Merged sorted list\n");
    Display(*arr3);
   // Reverse(arr);
   //LeftRotation(arr,3);
   //RightRotation(arr,2);
   //printf("%d ",CheckSortedArray(arr));
   //InsertElementSorted(arr,4);
  // ArrangePositiveNegative(arr);
   //Display(arr);
    return 0;
}
