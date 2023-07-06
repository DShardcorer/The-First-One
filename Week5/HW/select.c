#include <stdio.h>
void choose(int arr[], int n, int k, int index) {
    if (k == 0)
      {
        for (int i = 0; i < index; i++)
	  {
            printf("%d ", arr[i]);
          };
        printf("\n");
        return;
      };
    for (int i = 1; i <= n; i++)
      {
        int j;
        for (j = 0; j < index; j++)
	  {
            if (i == arr[j] || i == arr[j] - 1 || i == arr[j] + 1)
	      {
                break;
              };
          };
        if (j == index)
	  {  
            arr[index] = i;
            choose(arr, n, k - 1, index + 1);  
          };
      };
}

int main()
{
  int n, k;
  printf("Input n: ");
  scanf("%d", &n);
  printf("Input k: ");
  scanf("%d", &k);
  int arr[k];  
  choose(arr, n, k, 0);  
  return 0;
}
