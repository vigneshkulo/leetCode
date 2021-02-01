#include <stdio.h>

#define POOL_SIZE	100
#define BLOCK_SIZE	2
#define ALLOC_MASK	0x1

char memoryPool[POOL_SIZE];

void mem_init() {
	short* ptr = (short*) memoryPool;
	ptr[0] = 0xFFFF;
	ptr[1] = (POOL_SIZE / BLOCK_SIZE) - 2;
	ptr[(POOL_SIZE / BLOCK_SIZE) - 1] = 0xFFFF;
}

void print_mem() {
	printf("\n");
	for (int row = 0; row < 10; ++row) {
		printf(" * Row %2d: ", row);
		for (int col = 0; col < 10; ++col) {
			printf("%04d ", memoryPool[(row * 10) + col]);
		}
		printf("\n");
	}

	return;
}

short* findFreeBlock(unsigned int num_blocks) {
	short* ptr = (short*) memoryPool;
	ptr += 1;
	
	while ((ptr[0] & ALLOC_MASK) && (ptr[0] > 0)) {
		if ( (ptr[0] & ~ALLOC_MASK) > num_blocks) {
			break;
		}
		ptr += (ptr[0] & ~ALLOC_MASK);
	}

	if (ptr[0] <= 0) {
		return NULL;
	}

	return ptr;
}

char* custom_malloc(unsigned int size) {
	printf("\n* %s: allocate %u bytes\n", __func__, size);

	if (size == 0) {
		return NULL;
	}

	short num_blocks = size / BLOCK_SIZE;
	num_blocks += 1;
	if (num_blocks % 2) {
		num_blocks += 1;
	}

	short* ptr = findFreeBlock(num_blocks);
	if (ptr == NULL) {
		return NULL;
	}

	short available = ptr[0];

	ptr[0] = num_blocks;
	ptr[0] = num_blocks | ALLOC_MASK;
	if ((available - num_blocks) > 0) {
		ptr[num_blocks] = available - num_blocks;
	}
	ptr += 1;

	return (char*)ptr;
}

void custom_free(char* ptr) {
	short *sptr = (short*) ptr;
	short next = 0;

	printf("\n* %s: free %p\n", __func__, ptr);

	sptr -= 1;
	if (!(sptr[0] & ALLOC_MASK)) {
		return;
	}

	sptr[0] &= ~ALLOC_MASK;
	if (!(sptr[sptr[0]] & ALLOC_MASK)) {
		next = sptr[0];
		sptr[0] += sptr[sptr[0]];
		sptr[next] = 0;
	}

	return;
}

/* Leaky function - DONT MIND */
void main() {
	mem_init();
	print_mem();

	char* arr = (char*) custom_malloc (10);
	print_mem();
	arr = (char*) custom_malloc (10);
	print_mem();
	arr = (char*) custom_malloc (10);
	print_mem();
	arr = (char*) custom_malloc (10);
	print_mem();
	arr = (char*) custom_malloc (10);
	print_mem();
	custom_free(arr);
	print_mem();
	custom_free(arr);
	print_mem();
	arr = (char*) custom_malloc (10);
	print_mem();
	arr = (char*) custom_malloc (10);
	print_mem();
	arr = (char*) custom_malloc (10);

	if (arr) {
		for (int i = 0; i < 10; ++i) {
			arr[i] = 'a' + i;
		}

		for (int i = 0; i < 10; ++i) {
			printf("%c ", arr[i]);
		}
		printf("\n");
	}
	print_mem();

	custom_free(arr);
	print_mem();
}
