#include <stdio.h>
#include <string.h>
// Add functions and includes as needed

enum ChunkType
{
	VERTS_TYPE,
	NORMS_TYPE,
	ANIM_TYPE,
	TEXTURE_TYPE,
	UV_TYPE
};

int checkType(char*);
int checkName(char*);

int main(int argc, char *argv[])
{
	// do your magic stuff here
	printf("%d ", argc);
	if (argc != 5)
	{
		return -1;
	}
	for (int i = 0; i < argc; i++) printf("%s ", argv[i]);
	if ((strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "-T") == 0) &&
		(strcmp(argv[3], "-n") == 0 || strcmp(argv[3], "-N") == 0))
	{
		if (checkType(argv[2]) == 0 && checkName(argv[4]) == 0)
		{
			return 0;
		}
		return -1;
	}
	if ((strcmp(argv[1], "-n") == 0 || strcmp(argv[1], "-N") == 0) &&
		(strcmp(argv[3], "-t") == 0 || strcmp(argv[3], "-T") == 0))
	{
		if (checkName(argv[2]) == 0 && checkType(argv[4]) == 0)
		{
			return 0;
		}
		return -1;
	}
	
	return -1;
}

int checkType(char* type)
{
	if (strcmp(type, "VERTS_TYPE") == 0) return 0;
	if (strcmp(type, "NORMS_TYPE") == 0) return 0;
	if (strcmp(type, "ANIM_TYPE") == 0) return 0;
	if (strcmp(type, "TEXTURE_TYPE") == 0) return 0;
	if (strcmp(type, "UV_TYPE") == 0) return 0;
	return -1;
}

int checkName(char* name)
{
	if (strlen(name) < 20 && strlen(name) > 0) return 0;
	return -1;
}