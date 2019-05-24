#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef OTTOHASH_H
#define	OTTOHASH_H


//结构体
struct hash_table;

//创建结构体 hash表
struct hash_table* create_hash_table(int n);

//插入键值
void hash_insert(struct hash_table* t, char* key, void* value);

//寻找键值
void* hash_find(struct hash_table* t, char* key);

//删除键值
void hash_delete(struct hash_table* t, char* key);

//修改键值
void hash_set(struct hash_table* t, char* key, void* value);

//清空hash表
void hash_clear(struct hash_table* t);

//删除hash表
void destroy_hash_table(struct hash_table* t);

#endif // OTTOHASH_H
