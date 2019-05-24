

#include "OttoHash.h"
#define my_malloc malloc  //定义分配内存函数 (设定时分配内存)
#define my_free free  //定义释放内存函数 


struct hash_node {
	char* key;
	void* value; 
	struct hash_node* next;
};

struct hash_table {
	struct hash_node** hash_set; 
	int n;
};


struct hash_table* create_hash_table(int n) {
	struct hash_table* t =(struct hash_table*) my_malloc(sizeof(struct hash_table)); //分配整个hash表内存

	memset(t, 0, sizeof(struct hash_table));  //初始化整个hash表内存

	t->hash_set = my_malloc(n * sizeof(struct hash_node*)); //保存指针头位置

	memset(t->hash_set, 0, sizeof(struct hash_node*) * n);

	t->n = n; 

	return  t;

}
//hash算法
static unsigned int hash_index(char* str)
{
	register unsigned int h;
	register unsigned char* p;

	for (h = 0, p = (unsigned char*)str; *p; p++)
		h = 31 * h + *p; //p 每加一下,指针就移动一次

	return h;
}
void hash_insert(struct hash_table* t, char* key, void* value) {

	struct hash_node* node = (struct hash_node*)my_malloc(sizeof(struct hash_node));
	memset(node, 0, sizeof(struct hash_node));
	node->key = _strdup(key);
	node->value = value;




	int index = (hash_index(key) % t->n); 

	struct hash_node* header = t->hash_set[index];

	node->next = header;
	t->hash_set[index] = node;
}



void hash_set(struct hash_table* t, char* key, void* value) {
	

}



void* hash_find(struct hash_table* t, char* key) {
	
	int index = (hash_index(key) % t->n); 
	struct hash_node* walk = (t->hash_set[index]);

	while (walk) {
		if (strcmp((walk)->key, key) == 0) {
			return walk->value;
		}
		walk = walk->next;
	}

	return NULL;
}




void hash_delete(struct hash_table* t, char* key) {
	int index = (hash_index(key) % t->n); 
	struct hash_node** walk = &(t->hash_set[index]);

	while (*walk) {
		if (strcmp((*walk)->key, key) == 0) {
			struct hash_node* rm_node = *walk;
			*walk = (*walk)->next;

			rm_node->next = NULL;

			my_free(rm_node->key);
			my_free(rm_node);
		}
		else
		{
			walk = &((*walk)->next);

		}
	}
}



void hash_clear(struct hash_table* t) {
	for (int i = 0; i < t->n; i++) {
		struct hash_node* walk = t->hash_set[i];
		t->hash_set[i] = NULL;

		while (walk) {
			struct hash_node* rm_node = walk;
			walk = walk->next;
			rm_node->next = NULL;

			my_free(rm_node->key);
			my_free(rm_node);
		}
	}
}

void destroy_hash_table(struct hash_table* t) {
	
	hash_clear(t);
	if (t->hash_set) {
		my_free(t->hash_set);
		t->hash_set =NULL;
	}

	my_free(t);
}