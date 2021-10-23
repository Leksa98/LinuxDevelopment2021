#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc == 1) {
		printf("help\n");
	} else if (argc == 2) {
		int N = atoi(argv[1]);
		for (int i = 0; i < N; i++) {
			printf("%d\n", i);
		}
	} else if (argc == 3) {
		int M = atoi(argv[1]);
		int N = atoi(argv[2]);
		int S = 1;
		for (int i = M; i < N; i+=S) {
			printf("%d\n", i);
		}
	} else {
		int M = atoi(argv[1]);
		int N = atoi(argv[2]);
		int S = atoi(argv[3]);
		for (int i = M; i < N; i+=S) {
			printf("%d\n", i);
		}
	}
	return 0;
}
