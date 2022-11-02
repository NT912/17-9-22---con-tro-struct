#include <iostream>
using namespace std;

void inputArray(int *a, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << "a[" << i << "]: ";
    cin >> a[i];
  }
}

void outputArray(int *a, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
}

void shellSort(int *a, int n)
{
  int interval, i, j, temp;
  for (interval = n / 2; interval > 0; interval /= 2)
  {
    for (i = interval; i < n; i++)
    {
      temp = a[i];
      for (j = i; j >= interval && a[j - interval] > temp; j -= interval)
      {
        a[j] = a[j - interval];
      }
      a[j] = temp;
    }
  }
}

void bubbleSort(int *a, int n)
{
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (a[i] < a[j])
      {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
}

int linearSearch(int *a, int n, int x)
{
  int i = 0;
  while (i < n && a[i] != x)
    i++;
  if (i == n)
    return -1;
  return i;
}

int main()
{
  int n, x;
  cout << "Nhap chieu dai cua mang: ";
  cin >> n;

  int *a = new int[n + 1];

  inputArray(a, n);

  bubbleSort(a, n);
  cout << "Mang sap xep giam dan la: ";
  outputArray(a, n);

  shellSort(a, n);
  cout << "\nMang sap xep tang dan la: ";
  outputArray(a, n);

  cout << "\nNhap phan tu can tim: ";
  cin >> x;

  if (linearSearch(a, n, x) == -1)
  {
    cout << "Khong tim thay " << x << " trong mang";
  }
  else
  {
    cout << "Tim thay " << x << " tai vi tri " << linearSearch(a, n, x) + 1;
  }

  delete[] a;
  a = NULL;
  return 0;
}
