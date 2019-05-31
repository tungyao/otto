
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../ottohash/ottohash.h"
void controller();


int main() {
	
	//OttoJson oj({"key","value"});
	//oj.add("seek","key","value");
	// struct hash_table* t = create_hash_table(1024); //1024个集合
	// char le[100];
	// char *key = "xiaoming";
	// printf("key:");
	// scanf("%s",le);
	// hash_insert(t, key, (void*)le);


	// char *ret = (void*)hash_find(t, key); //查找hash表key，对应的value
	// printf("xiaoming = > %s\n", ret);
	// system("pause");
	controller();
	return 0;
}

void controller(){
	int out =0;
	int inp;
	struct hash_table* t;
	register int len;
	char lenna[100];
	char lenns[100];
	char findkey[100];
	char modikey[100];
	char modivalue[100]; 
	while (out == 0)
	{
		printf("creat hash => 1 \t add Key-Value => 2 \t find value =>3 \t midify value => 4 \t get all key => 5 \t quit 0 \n");
		scanf("%d",&inp);
		if(inp==0){
			return;
		}
		switch (inp)
		{
		case 1:
			printf("length:");
			scanf("%d",len);
			t = create_hash_table((int)len);
			printf("success %p \n",&t);
			break;
		case 2:
			printf("key:");
			scanf("%s",lenna);
			printf("value:");
			scanf("%s",lenns);
			hash_insert(t,lenna,(void*)lenns);
			printf("add success: %s : %s \n",lenna,lenns);
			break;
		case 3:
			printf("key:");
			scanf("%s",findkey);
			char* str =(char*)hash_find(t,findkey);
			printf("value => %s \n",str);
			break;
		case 4:
			printf("key:");
			scanf("%s",modikey);
			printf("value:");
			scanf("%s",modivalue);
			hash_set(t,modikey,(void*)modivalue);
			printf("modify success: %s : %s \n",modikey,modivalue);
			break;
		case 5:
			hash_get_all(t);
			break;
		default:
			inp =0;
			break;
		}

	}
	
	
}
