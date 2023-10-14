//best triangle*/
#include <stdio.h>
#include <math.h>
int main()
{
  int n, i, j, l, count = 0;
  float x[100], y[100];
  float d1, d2, d3, area, s, k, max, kq[120];

  printf("Input the number of the points on the 2D plane(n):\n");
  scanf("\n%d", &n);
  printf("\n");

  if (n < 3)
  {
    printf("Please enter points greater than three.");
  }
  else
  {
    for (i = 0; i < n; i++)
    {
      printf("Input the coordinates of point %d\n", i + 1);
      scanf("%f\n%f", &x[i], &y[i]);
      printf("\n");
    }
    printf("\n");

    printf("Input integer k: ");
    scanf("%f", &k);
    printf("\n");

    for (i = 0; i < n; i++)
    {
      for (j = i + 1; j < n; j++)
      {
        d1 = sqrt(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2));

        for (l = i + 2; l < n; l++)
        {
          d2 = sqrt(pow((x[i] - x[l]), 2) + pow((y[i] - y[l]), 2));
          d3 = sqrt(pow((x[j] - x[l]), 2) + pow((y[j] - y[l]), 2));

          s = (d1 + d2 + d3) / 2;
          area = sqrt(s * (s - d1) * (s - d2) * (s - d3));

          if (area <= k / 2 && area > 0)
          {
            kq[count] = area;
            count++;
          }
        }
      }
    }
  }

  if (count != 0)
  {
    max = kq[0];
    for (i = 0; i <= count - 1; i++)
    {
      if (kq[i] >= max)
        max = kq[i];
    }
    printf("The area of the best triangle is: ");
    printf("%f", max * 2);
    printf("\n");
  }
  else if (n > 3)
    printf("-1\n");
  return 0;
}