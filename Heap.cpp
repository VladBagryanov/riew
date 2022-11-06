#ifndef HEAPF
#define HEAPF

template <class T>
void Swap(T& a, T& b) {
  T c = a;
  a = b;
  b = c;
}

template <class T>
void PushHeap(T* begin, T* end) {
  T* parent = begin + (end - begin - 2) / 2;
  if (1 < end - begin and *parent < *(end - 1)) {
    Swap(*parent, *(end - 1));
    PushHeap(begin, parent + 1);
  }
}

template <class T, class U>
void SiftDown(T* begin, T* end, U i) {
  U left = 2 * i + 1;
  U right = 2 * i + 2;
  U largest = i;
  if (left < end - begin and begin[largest] < begin[left]) {
    largest = left;
  }
  if (right < end - begin and begin[largest] < begin[right]) {
    largest = right;
  }
  if (largest < i or i < largest) {
    Swap(begin[i], begin[largest]);
    SiftDown(begin, end, largest);
  }
}
template <class T>
void PopHeap(T* begin, T* end) {
  Swap(*begin, *(end - 1));
  SiftDown(begin, end - 1, 0);
}

#endif