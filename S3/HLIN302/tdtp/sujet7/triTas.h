#ifndef __TRI_TAS
#define __TRI_TAS

//#define Pere(i) (i ? (i - 1) / 2 : -1)
#define FilsG(i) (2 * i + 1)
#define FilsD(i) (2 * i + 2)
//#define EstRacine(i) (!i)
//#define EstFeuille(i, n) (i > (n / 2))

template<typename Type>
void entasser(Type &T, size_t i, size_t n) {
  size_t max_indice = i,
    fg = FilsG(i),
    fd = FilsD(i);
  if ((fg < n) && (T[max_indice] < T[fg]) ) {
    max_indice = fg;
  }
  if ((fd < n) && (T[max_indice] < T[fd]) ) {
    max_indice = fd;
  }
  if (i != max_indice) {
  	Type temp;
  	temp = T[i];
  	T[i] = T[max_indice];
  	T[max_indice] = temp;
    entasser(T, max_indice, n);
  }
}
// template<typename Type>
// void entasser(Type &T, size_t i, size_t n) {
//   size_t 
//     fg = FilsG(i),
//     fd = FilsD(i);
//   if ((fg < n) && (T[i] < T[fg]) ) {
//   	Type temp;
//   	temp = T[i];
//   	T[i] = T[fg];
//   	T[fg] = temp;
//     entasser(T, fg, n);
//   }
//   if ((fd < n) && (T[i] < T[fd]) ) {
//   	Type temp;
//   	temp = T[i];
//   	T[i] = T[fd];
//   	T[fd] = temp;
//     entasser(T, fd, n);
//   }
// }
template<typename Type>
void initTas(Type &T) {
  for (size_t i = T.size() / 2 - 1; i != (size_t) -1; i--) {
    entasser(T, i, T.size());
  }
}

template<typename Type>
void triParTas(Type* &T) {
  initTas(T);
  for (size_t i = T.size() - 1; i != (size_t) -1; i--) {
    echanger(T[0], T[i]);
    entasser(T, 0, i);
  }
}
#endif
