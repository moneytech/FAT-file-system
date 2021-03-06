#define NAME_LENGTH 24
#define BLOCK_SIZE 1024
#define BLOCK_NUMBER 0x00010000

typedef struct _directory_entry {
	char name[NAME_LENGTH];	// file name
	time_t create_t;		
	time_t modify_t;
	time_t access_t;
	int file_length;		// file length in bytes
	int start_block;		// block_nr of file start
	uint8_t flags;			// 0 for file, 1 for directory		
	struct _directory_entry* next;
	struct _directory_entry* child_first;
	struct _directory_entry* real_dir;
} directory_entry;

struct _global_variables {
	directory_entry* root; 	// directory_entry of root
	char* disk;				// name of disk file
	FILE* debug;		    // FILE* of debug file
	size_t K;
	size_t free_cur;
	int init;
} FS;



