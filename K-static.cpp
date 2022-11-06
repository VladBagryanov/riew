#ifndef KTH
#define KTH

template <class T>
void Swap(T& a, T& b) {
  T c = a;
  a = b;
  b = c;
}

template <class T>
T* Partition(T* begin, T* end) {
  T pivot = begin[0];
  int pivot_point = 0;
  for (int i = 1; i < end - begin; ++i) {
    if (begin[i] < pivot) {
      ++pivot_point;
      Swap(begin[pivot_point], begin[i]);
    }
  }
  Swap(begin[0], begin[pivot_point]);
  return pivot_point + begin;
}

template <class T>
void KthElement(T* begin, T* k, T* end) {
  while (true) {
    T* mid = Partition(begin, end);
    if (mid == k) {
      return;
    }
    if (mid < k) {
      begin = mid + 1;
    } else if (k < mid) {
      end = mid;
    } else {
      return;
    }
  }
}
#endif