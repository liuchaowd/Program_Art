#include <iostream>
void MaxHeap(int heap[], int i, int len);
void MaxHeap_(int heap[], int i, int len);
void swap(int & left, int & right)
{
  int temp = left;
  left = right;
  right = temp;
}

//建立大根堆
void BuildHeap(int heap[], int len)
{
  if (heap == NULL)
  {
    return;
  }
  int index = len/2;
  for (int i = index; i >= 0; i--)
  {
    //MaxHeap(heap, i, len);
    MaxHeap_(heap, i, len);
  }
}

//递归调整大根堆
void MaxHeap(int heap[], int i, int len)
{
  int largeIndex = i;
  int left = i * 2;
  int right = i * 2 + 1;
  if (left < len && heap[left] > heap[i])
    largeIndex = left;
  if (right < len && heap[right] > heap[largeIndex])
    largeIndex = right;
  if (largeIndex != i)
  {
    swap(heap[i], heap[largeIndex]);
    MaxHeap(heap, largeIndex, len);
  }
}

//非递归调整大根堆
void MaxHeap_(int array[], int i, int length)
{

  int child,temp;
  for (temp = array[i]; 2*i + 1 < length; i = child)
  {

    child = 2 * i + 1;
    if (child < length - 1 && array[child + 1] > array[child])
      child++;
    if (temp < array[child])
      array[i] = array[child];
    else
      break;
    array[child] = temp;
  }
}

int main(int argc, char** argv)
{
  int k;
  std::cin >> k;
  int * heap = new int[k];
  int array[8] = {6 , 7 , 5, 15 , 1 , 12, 9, 3};
  int len = sizeof(array)/sizeof(int);
  for (int index = 0; index != k; index++)
  {
    heap[index] = array[index];
  }
  BuildHeap(heap, k);
  for (int index = k; index != sizeof(array)/sizeof(int); index++)
  {
    if (array[index] < heap[0]);
    {
      heap[0] = array[index];
      MaxHeap(heap, 0, k);
    }
  }

  for (int index = 0; index != k; index++)
    std::cout << heap[index] << " ";
  std::cout << std::endl;
}

