//
//  main.c
//  leetcode_2
//
//  Created by yeye on 2017/12/26.
//  Copyright © 2017年 meitu. All rights reserved.
//

#include <stdio.h>

/*
 You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 
 You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 
 Example
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 Explanation: 342 + 465 = 807.
 */


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    struct ListNode *p1 = l1, *p2 = l2;
    struct ListNode *result = NULL;
    struct ListNode *tail = NULL;
    
    int sum = 0;
    while (1) {
        if (p1 && p2) {
            sum += p1->val + p2->val;
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1 && (p2 == NULL)) {
            sum += p1->val;
            p1 = p1->next;
        } else if (p2 && (p1 == NULL)) {
            sum += p2->val;
            p2 = p2->next;
        } else {
            break;
        }
        struct ListNode * node = (struct ListNode *)calloc(1, sizeof(struct ListNode));
        node->val = sum % 10;
        sum /= 10;
        node->next = NULL;
        if (result == NULL) {
            result = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    if (sum > 0) {
        struct ListNode * node = (struct ListNode *)calloc(1, sizeof(struct ListNode));
        node->val = sum;
        tail->next = node;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
