#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
int main()
{
  int *a;  // ��������� �� ������
  int i, n;

  printf("size of array: ");
  scanf("%d", &n);
a = (int*)malloc(n * sizeof(int));
  for (i = 0; i<n; i++)
  {
    a[i] = i;
  }
  // ����� ��������� �������
  for (i = 0; i<n; i++)
    printf("%d ", a[i]);
  free(a);
  getchar();   getchar();
  return 0;
}
