#ifndef __TRI_BULLE_H
#define __TRI_BULLE_H

template<typename Type>
void triBulle(Type &_T){
	size_t modif=1;
	size_t n = _T.size()-1;
	Type temp;
	while (modif && n) {
		n--;
		modif=0;
		for (size_t i = 0; i < n; i++) {
			if ( _T[i] > _T[i+1] ) {
				temp = _T[i];
				_T[i] = _T[i+1];
				_T[i+1] = temp;
				modif++;
			}
		}
	}
}

#endif
