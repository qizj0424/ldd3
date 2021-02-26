/*一个火bai柴人游戏，亲自验证，可运行*/
/*在编译du时添加如下命令：-std=c++11，否则zhi会编译错误*/
#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <thread>
#include <conio.h>
using namespace std;
const unsigned char CTRL_KEY = 0XE0;
const unsigned char LEFT = 0X4B;
const unsigned char RIGHT = 0X4D;
const unsigned char DOWN = 0X50;
const unsigned char UP = 0X48;
int men2[2] = {0,0};
int women2[2]={10,10};
int Game();
void gotoxy(int x,int y) //光标移动到(x,y)位置
{
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos;
pos.X = x;
pos.Y = y;
SetConsoleCursorPosition(handle,pos);
}
int TorF()
{
if ( men2[0] == women2[0] && men2[1] == women2[1] ) return 1;
else return 0;
}
int clean(int mm, int nn)
{
gotoxy ( mm, nn );
printf ( " " );
gotoxy ( mm,nn+1);
printf ( " " );
gotoxy ( mm,nn+2);
printf (" ");
}
int men(int x, int y)
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|daoFOREGROUND_BLUE|FOREGROUND_GREEN);

gotoxy( x,y );
printf(" O");

gotoxy( x,y+1 );
printf("<H>");
gotoxy( x,y+2 );
printf("I I");

}
int women(int i,int j)
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);

gotoxy( i+1,j );
printf(" O");

gotoxy( i+1,j+1 );
printf("<H>");
gotoxy( i,j+2 );
printf("/I I\\");
}
int m=10, n=10;
int womenmove()
{
int turn;
int YNbreak=0;
while( YNbreak==0 )
{
YNbreak = TorF();
turn=rand()%3;
clean(m,n);
if ( turn == 0 ) m++;
if ( turn == 1 ) m--;
if ( turn == 2 ) n++;
if ( turn == 3 ) n--;

if ( m<0 ) m=0;
if ( m>=75 ) m=75;

if ( n<0 ) n=0;
if ( n>=22 ) n=22;
women( m,n );

women2[0]=m;
women2[1]=n;
Sleep(100);
}
system ( "cls" );
gotoxy ( 28,10 );
printf ( "You died!!!\n" );
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);
system ( "pause" );
return 0;
}
int x=0;int y=0;
int menmove()
{
system("cls");
while (1)
{

switch(getch())
{
case UP:y--;break;

case DOWN:y++;break;

case LEFT:x--;break;

case RIGHT:x++;break;
}

system("cls");
if ( x<0 ) x=0;
if ( x>77 ) x=77;

if ( y<0 ) y=0;
if ( y>22 ) y=22;

men(x,y);

men2[0]=x;
men2[1]=y;
}
}
int Game()
{
women(10,10);
men(0,0);

int t=0;
thread qq(womenmove);
menmove();

qq.join();
return 0;
}
int main()
{
printf ( "游戏开始后,随机按下一个键，唤醒你的蓝色小人.如果你被红色的老女人碰到了，那么你就死了\n" );
printf ( "方向键操控小人\n" );
system ( "pause" );
system ( "cls" );
Game();
return 0;
}
