#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	//Allows you to generate random number
	srand(time(NULL));

	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	int a[nl];
	sizeof(n1); // �������� ������ a �� 5 ���������
  int i;
  // ���� ��������� �������
  for (i = 0; i<nl; i++)
  {
    a[i] = rand();
  }
  // ����� ��������� �������
  for (i = 0; i<5; i++)
    printf("%d ", a[i]); // ������ � ������� ������ ����������
  getchar(); getchar();

	int *a;  // ��������� �� ������
  int i, n;

  printf("Enter new array size: ");
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
