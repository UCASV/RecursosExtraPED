#include <iostream>

void BubbleSort(int arr[], int size) {
  for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        // Intercambiar los elementos
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void SelectionSort(int arr[], int size) {
  for (int i = 0; i < size - 1; ++i) {
    int min_idx = i;
    for (int j = i + 1; j < size; ++j) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;  // Encuentra el índice del elemento más pequeño
      }
    }
    // Intercambia el elemento más pequeño con el primero de la parte no ordenada
    int temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
  }
}

void InsertionSort(int arr[], int size) {
  for (int i = 1; i < size; ++i) {
    int key = arr[i];
    int j = i - 1;
    // Mueve los elementos mayores a una posición adelante
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}

void PrintArray(const int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
  int size = sizeof(arr) / sizeof(arr[0]); 

  std::cout << "Arreglo original: ";
  PrintArray(arr, size);

  // Prueba de ordenamiento burbuja
  BubbleSort(arr, size);
  std::cout << "Ordenado con Burbuja: ";
  PrintArray(arr, size);

  // Reinicializar el arreglo a su estado original
  int arr2[] = {64, 34, 25, 12, 22, 11, 90};

  // Prueba de ordenamiento por selección
  SelectionSort(arr2, size);
  std::cout << "Ordenado con Selección: ";
  PrintArray(arr2, size);

  // Reinicializar el arreglo a su estado original
  int arr3[] = {64, 34, 25, 12, 22, 11, 90};

  // Prueba de ordenamiento por inserción
  InsertionSort(arr3, size);
  std::cout << "Ordenado con Inserción: ";
  PrintArray(arr3, size);

  return 0;
}
