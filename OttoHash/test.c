
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "OttoHash.h"
int main() {
	
	//OttoJson oj({"key","value"});
	//oj.add("seek","key","value");

	struct hash_table* t = create_hash_table(1024); //1024个集合

	hash_insert(t, "xiaoming", (void*)24);


	int ret = (int)hash_find(t, "xiaoming"); //查找hash表key，对应的value
	printf("xiaoming = > %d\n", ret);
	system("pause");
	return 0;
}