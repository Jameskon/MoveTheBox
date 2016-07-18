//
//  main.c
//  MoveTheBox
//
//  Created by kai on 16/7/8.
//  Copyright © 2016年 K.K Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 11

int currentPersonRow = 3;
int currentPersonCol = 1;

void drawMap();
char enterDirection();

void moveUp();
void moveDown();
void moveLeft();
void moveRight();

// 声明地图 二维数组
char map[ROWS][COLS]=
{
    "##########",
    "#  ####  #",
    "# X####  #",
    "#O       #",
    "######   #",
    "#  ####  #",
    "#        #",
    "#   ######",
    "#         ",
    "##########"
};



int main() {
    //    1、打印地图
    //    2、获取前进方向
    //    3、根据获取前进方向判断并更改小人的前进方向
    //    4、胜利判断
    
    //    测试打印
    //    printf("人%c----箱子%c----墙%c----道路%c\n",map[3][1],map[2][2],map[0][0],map[1][1]);
    
    int flag = 1;
    
    while (flag) {
    
    system("clear");
    drawMap();
        
//        判断游戏是否能够结束
        if (map[8][9]=='X') {
            printf("恭喜你,游戏胜利!\n");
            break;
        }
    char dir = enterDirection();
        
        
    //    printf("Hello, World!%c\n",dir);
    switch (dir) {
        case 'a':
            //            向左移动
            moveLeft();
            break;
        case 's':
            //            向下移动
            moveDown();
            break;
        case 'w':
            //            向上移动
            moveUp();
            break;
        case 'd':
            //            向右移动
            moveRight();
            break;
        case 'q':
            //            退出游戏
            printf("你不会推...哈哈哈!\n");
            flag = 0;
            break;
    }
    
    }
    
    return 0;
}

void drawMap()
{
    for (int i = 0; i<ROWS; i++) {
        printf("%s\n",map[i]);
    }
}

char enterDirection()
{
    printf("请输入小人的前进方向：a向左,s向下,w向上,d向右,q退出游戏\n");
    char dir;
    rewind(stdin);
    scanf("%c",&dir);
    return dir;
}

void moveUp()
{
    
//  判断小人是否能够向上移动
//    如何判断？
//    1.获取小人当前位置坐标
//    2.计算小人上移一格坐标
//    3.判断小人上移一格是什么状况
//    4.根据上一格状况作出相应的动作
//    4.1 上一格是“ ”道路     小人上移一格
//    4.2 上一格是“#”墙壁     小人被阻挡无反应
//    4.3 上一格是"X"箱子     继续判断箱子是否能被推动
//    4.3.1 箱子能够被推动 箱子坐标变成小人坐标 箱子上一格坐标变成箱子坐标 小人当前坐标变成道路
//    4.3.2 箱子不能被推动     不响应
    int nextPersonRow = currentPersonRow - 1;
    int nextPersonCol = currentPersonCol;
    
    if (map[nextPersonRow][nextPersonCol]==' ') {
//        下一个坐标是道路
        map[nextPersonRow][nextPersonCol] = 'O';
        map[currentPersonRow][currentPersonCol] = ' ';
        
        currentPersonRow = nextPersonRow;
        currentPersonCol = nextPersonCol;
        
    }
    else if (map[nextPersonRow][nextPersonCol]=='X')
    {
//        下一个坐标是箱子
        int nextBoxRow = nextPersonRow - 1;
        int nextBoxCol = nextPersonCol;
        if (map[nextBoxRow][nextBoxCol]==' ') {
//          推箱子步骤
//            将箱子的下一个位置设置为箱子
            map[nextBoxRow][nextBoxCol] = 'X';
//            将箱子的位置设置为人
            map[nextPersonRow][nextPersonCol] = 'O';
//            将人的位置设置为道路
            map[currentPersonRow][currentPersonCol] = ' ';
            
            currentPersonRow = nextPersonRow;
            currentPersonCol = nextPersonCol;
            
        }
        
    }
    else if(map[nextPersonRow][nextPersonCol]=='#')
    {
//        下一个坐标是墙壁 不响应
    }

    
    
}

void moveDown()
{
    int nextPersonRow = currentPersonRow + 1;
    int nextPersonCol = currentPersonCol;
    
    if (map[nextPersonRow][nextPersonCol]==' ') {
        //        下一个坐标是道路
        map[nextPersonRow][nextPersonCol] = 'O';
        map[currentPersonRow][currentPersonCol] = ' ';
        
        currentPersonRow = nextPersonRow;
        currentPersonCol = nextPersonCol;
        
    }
    else if (map[nextPersonRow][nextPersonCol]=='X')
    {
        //        下一个坐标是箱子
        int nextBoxRow = nextPersonRow + 1;
        int nextBoxCol = nextPersonCol;
        if (map[nextBoxRow][nextBoxCol]==' ') {
            //          推箱子步骤
            //            将箱子的下一个位置设置为箱子
            map[nextBoxRow][nextBoxCol] = 'X';
            //            将箱子的位置设置为人
            map[nextPersonRow][nextPersonCol] = 'O';
            //            将人的位置设置为道路
            map[currentPersonRow][currentPersonCol] = ' ';
            currentPersonRow = nextPersonRow;
            currentPersonCol = nextPersonCol;
            
        }
        
    }
    else if(map[nextPersonRow][nextPersonCol]=='#')
    {
        //        下一个坐标是墙壁 不响应
    }
}

void moveLeft()
{
    int nextPersonRow = currentPersonRow;
    int nextPersonCol = currentPersonCol - 1;
    
    if (map[nextPersonRow][nextPersonCol]==' ') {
        //        下一个坐标是道路
        map[nextPersonRow][nextPersonCol] = 'O';
        map[currentPersonRow][currentPersonCol] = ' ';
        
        currentPersonRow = nextPersonRow;
        currentPersonCol = nextPersonCol;
        
    }
    else if (map[nextPersonRow][nextPersonCol]=='X')
    {
        //        下一个坐标是箱子
        int nextBoxRow = nextPersonRow;
        int nextBoxCol = nextPersonCol - 1;
        if (map[nextBoxRow][nextBoxCol]==' ') {
            //          推箱子步骤
            //            将箱子的下一个位置设置为箱子
            map[nextBoxRow][nextBoxCol] = 'X';
            //            将箱子的位置设置为人
            map[nextPersonRow][nextPersonCol] = 'O';
            //            将人的位置设置为道路
            map[currentPersonRow][currentPersonCol] = ' ';
            currentPersonRow = nextPersonRow;
            currentPersonCol = nextPersonCol;
            
        }
        
    }
    else if(map[nextPersonRow][nextPersonCol]=='#')
    {
        //        下一个坐标是墙壁 不响应
    }
    
}

void moveRight()
{
    int nextPersonRow = currentPersonRow;
    int nextPersonCol = currentPersonCol + 1;
    
    if (map[nextPersonRow][nextPersonCol]==' ') {
        //        下一个坐标是道路
        map[nextPersonRow][nextPersonCol] = 'O';
        map[currentPersonRow][currentPersonCol] = ' ';
        
        currentPersonRow = nextPersonRow;
        currentPersonCol = nextPersonCol;
        
    }
    else if (map[nextPersonRow][nextPersonCol]=='X')
    {
        //        下一个坐标是箱子
        int nextBoxRow = nextPersonRow;
        int nextBoxCol = nextPersonCol + 1;
        if (map[nextBoxRow][nextBoxCol]==' ') {
            //          推箱子步骤
            //            将箱子的下一个位置设置为箱子
            map[nextBoxRow][nextBoxCol] = 'X';
            //            将箱子的位置设置为人
            map[nextPersonRow][nextPersonCol] = 'O';
            //            将人的位置设置为道路
            map[currentPersonRow][currentPersonCol] = ' ';
            currentPersonRow = nextPersonRow;
            currentPersonCol = nextPersonCol;
            
        }
        
    }
    else if(map[nextPersonRow][nextPersonCol]=='#')
    {
        //        下一个坐标是墙壁 不响应
    }
}


