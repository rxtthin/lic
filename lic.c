#include <stdio.h>
#include <stdlib.h>

static unsigned long count_lines(const char *file_path) {
	FILE *f = fopen(file_path, "r");
	if(!f) {
		fprintf(stderr, "Failed to open file `%s`.\n", file_path);
		exit(-1);
	}

	unsigned long count = 0;
	char c;
	while((c = fgetc(f)) != EOF) {
		if(c == '\n') {
			++count;
		}
	}

	fclose(f);

	return count;
}

int main(int argc, const char **argv) {
        unsigned int  total = 0; 
	unsigned long count;
        for(unsigned int i=1; i<argc; ++i) {
		count = count_lines(argv[i]);
		total += count;
		printf("%s: %lu\n", argv[i], count);
	}

        printf("\ntotal lines: %u\n", total);
}
