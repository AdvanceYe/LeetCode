//
//  main.c
//  leetcode_3
//
//  Created by yeye on 2017/12/30.
//  Copyright © 2017年 meitu. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    printf("%d\n", lengthOfLongestSubstring("pwwcw"));
    return 0;
}

//TODO: 【没做出来，需要多刷】
int lengthOfLongestSubstring(char* s) {
    //记录start位置
    int start = 0;
    int len = (int)strlen(s);
    int position[256];
    int result = 0;
    memset(position, -1, sizeof(int) * 256);

    for (int i = 0; i < len; i++) {
        //如果上次存的<start
        if(position[s[i]] >= start){
            result = (result > i - start) ? result : i - start;
            start = position[s[i]] + 1;
        }
        position[s[i]] = i;

        if (i == len -1) {
            result = (result > i - start + 1) ? result : i - start + 1;
        }
    }
    return result;
}
