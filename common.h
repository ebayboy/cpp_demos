
#ifndef COMMON_H
#define COMMON_H

#define SHOW_VEC(v) \
	do {	\
		cout << #v << endl; std::for_each(std::begin(v), std::end(v), [](int i) { cout << i << " "; }); cout << endl;	\
	} while(0)	\

#endif
