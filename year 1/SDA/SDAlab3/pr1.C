#include <stdio.h>

typedef enum culori{verde,albastru,galben,rosu}culori;
// typedef enum culori { verde=1, albastru, galben, rosu }culori; //v->[1,2,3,4]
int main(){
	culori v; //v->[0,3]
	printf("0->verde....\n");
	scanf("%d", &v);
	if (v >= 0 && v <= 3)
		printf("\nOK!");
	else
		printf("Valoarea nu este relevanta");
	printf("\nCuloarea = %d", v);
	switch (v) {
	case 0:
	case verde:
		printf("\nVerde");
		break;
	case 1:
		printf("\nAlbastru");
		break;	
	case 2:
		printf("\nGalben");
		break;
	case 3:
		printf("\nRosu");
		break;
	}
	return 0;
}