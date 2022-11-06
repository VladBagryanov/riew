#ifndef cstring
#define cstring
#include <iostream>

size_t Strlen(const char* str) {
  size_t i = 0;
  while (str[i] != '\0') {
    ++i;
  }
  return i;
}

int ChekerCmp(const char* first, const char* second, int len) {
  for (int i = 0; i < len; ++i) {
    if (first[i] < second[i]) {
      return -1;
    }
    if (first[i] > second[i]) {
      return 1;
    }
  }
  return 0;
}

int Strcmp(const char* first, const char* second) {
  size_t first_len = Strlen(first);
  size_t second_len = Strlen(second);
  if (first_len == second_len) {
    return ChekerCmp(first, second, first_len);
  }
  if (first_len > second_len) {
    int chek = ChekerCmp(first, second, second_len);
    if (chek == 0) {
      return 1;
    }
    return chek;
  }
  int chek = ChekerCmp(first, second, first_len);
  if (chek == 0) {
    return -1;
  }
  return chek;
}

int Strncmp(const char* first, const char* second, size_t count) {
  if (count == 0) {
    return 0;
  }
  if (count <= Strlen(first) and count <= Strlen(second)) {
    return ChekerCmp(first, second, count);
  }
  return Strcmp(first, second);
}

char* Strcpy(char* dest, const char* src) {
  size_t len = Strlen(src);
  for (size_t i = 0; i < len + 1; ++i) {
    dest[i] = src[i];
  }
  return dest;
}

char* Strncpy(char* dest, const char* src, size_t count) {
  size_t len = Strlen(src);
  if (count >= len) {
    for (size_t i = 0; i < len; ++i) {
      dest[i] = src[i];
    }
    for (size_t i = len; i < count; ++i) {
      dest[i] = '\0';
    }
    return dest;
  }
  for (size_t i = 0; i < count; ++i) {
    dest[i] = src[i];
  }
  return dest;
}

char* Strcat(char* dest, const char* src) {
  Strcpy(dest + Strlen(dest), src);
  return dest;
}

char* Strncat(char* dest, const char* src, size_t count) {
  Strncpy(dest + Strlen(dest), src, count);
  return dest;
}

const char* Strchr(const char* str, char symbol) {
  size_t len = Strlen(str);
  for (size_t i = 0; i < len + 1; ++i) {
    if (str[i] == symbol) {
      return str + i;
    }
  }
  return nullptr;
}

const char* Strrchr(const char* str, char symbol) {
  size_t len = Strlen(str);
  size_t index = len + 1;
  for (size_t i = 0; i < len + 1; ++i) {
    if (str[i] == symbol) {
      index = i;
    }
  }
  if (index == len + 1) {
    return nullptr;
  }
  return str + index;
}

size_t Strspn(const char* dest, const char* src) {
  size_t len_dest = Strlen(dest);
  size_t count = 0;
  for (size_t i = 0; i < len_dest; ++i) {
    if (Strchr(src, dest[i]) != nullptr) {
      ++count;
    } else {
      break;
    }
  }
  return count;
}

size_t Strcspn(const char* dest, const char* src) {
  size_t len_dest = Strlen(dest);
  size_t count = 0;
  for (size_t i = 0; i < len_dest; ++i) {
    if (Strchr(src, dest[i]) == nullptr) {
      ++count;
    } else {
      break;
    }
  }
  return count;
}

const char* Strpbrk(const char* dest, const char* breakset) {
  size_t len_dest = Strlen(dest);
  for (size_t i = 0; i < len_dest; ++i) {
    if (Strchr(breakset, dest[i]) != nullptr) {
      return dest + i;
    }
  }
  return nullptr;
}

const char* Strstr(const char* str, const char* pattern) {
  size_t len_str = Strlen(str);
  size_t len_pattern = Strlen(pattern);
  if (len_str < len_pattern) {
    return nullptr;
  }
  if (len_pattern == 0) {
    return str;
  }
  for (size_t i = 0; i < len_str - len_pattern + 1; ++i) {
    for (size_t j = 0; j < len_pattern; ++j) {
      if (str[i + j] != pattern[j]) {
        break;
      }
      if (j == len_pattern - 1) {
        return str + i;
      }
    }
  }
  return nullptr;
}

#endif