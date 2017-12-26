//
//  main.c
//  leetcode_1
//
//  Created by yeye on 2017/12/23.
//  Copyright © 2017年 meitu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// MARK: - qsort
typedef struct {
    int index;
    int data;
} Node;

int compar(const void *p1, const void *p2) {
    if (((Node *)p1)->data < ((Node *)p2)->data) {
        return -1;
    } else if (((Node *)p1)->data < ((Node *)p2)->data) {
        return 1;
    } else {
        return 0;
    }
}

int* twoSum_qsort(int* nums, int numsSize, int target) {
    int i, j;
    static int ret[2]= {0, 0};
    Node *num_nodes = (Node *)calloc(numsSize, sizeof(Node));
    
    for (i = 0; i < numsSize; i++) {
        num_nodes[i].index = i;
        num_nodes[i].data = nums[i];
    }
    
    qsort(num_nodes, numsSize, sizeof(Node), compar);
    
    i = 0; j = numsSize - 1;
    while (i < numsSize && j >= 0 && i <= j) {
        if (num_nodes[i].data + num_nodes[j].data == target) {
            
        } else if (num_nodes[i].data + num_nodes[j].data < target) {
            i++;
        } else {
            j--;
        }
    }
    return ret;
}

// MARK: - hash table
typedef struct HashNode {
    int key;
    int val;
    struct HashNode * next;
} HashNode;

static inline int hash(int val, int n) {
    int index = val % n;
    return index > 0 ? index : -index;
}

int* twoSum(int* nums, int numsSize, int target) {
    static int ret[2] = { 0, 0 };
    int i;
    
    HashNode **hashTable = (HashNode **)calloc(numsSize, sizeof(HashNode *));
    int idx;
    HashNode *p, *tail;
    for (i = 0; i < numsSize; i++) {
        idx = hash(nums[i], numsSize);
        p = hashTable[idx];
        tail = NULL;
        while (p != NULL) {
            tail = p;
            p = p->next;
        }
        HashNode *new_node = (HashNode *)calloc(1, sizeof(HashNode));
        new_node->val = nums[i];
        new_node->key = i;
        new_node->next = NULL;
        if (tail) {
            tail->next = new_node;
        } else {
            hashTable[idx] = new_node;
        }
    }
    
    for (i = 0; i < numsSize; i++) {
        int diff = target - nums[i];
        idx = hash(diff, numsSize);
        p = hashTable[idx];
        while (p != NULL) {
            if (p->val == diff && p->key != i) {
                ret[0] = i;
                ret[1] = p->key;
                return ret;
            }
            p = p->next;
        }
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int numbers[] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76 };
    
    int target = 78;
    
    int *index = twoSum(numbers, sizeof(numbers) / sizeof(numbers[0]), target);
    
    int i;
    for (i = 0; i < 2; i++){
        printf("index%d = %d ", i + 1, index[i]);
    }
    printf("\n");
    
//    int more = 4 % 9;
//    printf("more = %d\n", more);
    return 0;
}


//https://leetcode.com/problems/two-sum/description/
/*
 Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 You may assume that each input would have exactly one solution, and you may not use the same element twice.
 Example:
 Given nums = [2, 7, 11, 15], target = 9,
 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */




