#ifndef __TRI_RAPIDE_H
#define __TRI_RAPIDE_H

template<typename Type>
void triRapide_aux(Type &T, int deb, int fin) {
  if (deb >= fin) return;
  int d = deb, f = fin, pivot;
  pivot = (deb + fin) / 2;
  while (d < f) {
    while ( (d < pivot) && (T[d] <= T[pivot]) ) {
      d++;
    }
    while ((pivot < f) && (T[f] >= T[pivot])) {
      f--;
    }
    Type temp;
    temp = T[d];
    T[d] = T[f];
    T[f] = temp;    
    if (pivot == d) 
      pivot = f;
    else 
      if (pivot == f) 
    	pivot = d;
  }
  triRapide_aux(T, deb, pivot-1);
  triRapide_aux(T, pivot + 1, fin);
}
template<typename Type>
void triRapide(Type &T) {
  triRapide_aux(T, 0, T.size()-1);
}

#endif
