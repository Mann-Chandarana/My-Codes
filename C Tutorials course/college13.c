//Write a program for creating two arrays of different size and merge both arrays into one by sorting those arrays in ascending order. [Merge by sorting]//

   #include <stdio.h>
   int main()
   {
       int array1[20], array2[20], array3[40], size1, size2, i=0, j=0, k=0;
       printf("\nEnter size of array 1:\n");
       scanf("%d", &size1);
       printf("\nEnter sorted elements of Array 1: \n");
       for (i=0; i<size1; i++)
       {
           scanf("%d", &array1[i]);
       }
       i=0;

       printf("\nEnter size of array 2:\n");
       scanf("%d", &size2);
       printf("\nEnter sorted elements of array 2: \n");
       for (j=0; j<size2; j++)
       {
           scanf("%d", &array2[j]);
       }
       j=0;

       while (i<size1 && j<size2)
       {
           if (array1[i] < array2[j])
           {
               array3[k] = array1[i];
               k++;
               i++;
           }
           else
           {
               array3[k] = array2[j];
               k++;
               j++;
           }    
       }
           while (i<size1)
           {
               array3[k] = array1[i];
               i++;
               k++;
           }

           while (j<size2)
           {
               array3[k] = array2[j];
               j++;
               k++;
           }
       printf("\nAfter merging: \n");
       for (k=0; k<(size1+size2); k++)
       {
           printf("\n%d", array3[k]);
       }
       
       return 0;
   }