#include <stdlib.h>
#include <stdio.h>

int main()
{
	int i;

	// log binary arch
	if (sizeof(void*) == 4)
		printf("x86\n\n");
	else if (sizeof(void*) == 8)
		printf("amd64\n\n");
	else
		return -1;

	// allocate some objects
	// need ~16 allocations to enable windows low fragmentation heap management for selected size
	for (i = 0; i < 0x20; i++) {
		printf("0x%p\n", malloc(256));
	}

	// spin here to collect dump
	while (1);

	return 0;
}