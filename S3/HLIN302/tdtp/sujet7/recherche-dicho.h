#ifndef __RECHERCHE_DICHO_H
#define __RECHERCHE_DICHO_H

template<typename Type>
size_t rechercheDichotomique(const Type* &T, const Type &c) {
  size_t deb = 0, fin = T.size();
  size_t res = (size_t) -1;

  while ((res == (size_t) -1) && (deb < fin)) {
    size_t mid = (deb + fin) / 2;
    if ( c == T[mid] ) {
      res = mid;
    } else {
      if ( c < T[mid] ) {
	fin = mid;
      } else {
	deb = mid + 1;
      }
    }
  }
  return res;
}

#endif
