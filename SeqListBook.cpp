//date: 2024/7/15 20:43

//函数结果状态代码
#define OK 1
#define ERROR 0
#define MAXSIZE 10
#define OVERFLOW -2
typedef struct 
{
    char no[20];
    char name[10];
    float price;
}Book;
typedef struct 
{
    Book *elem;
    int length;
}SqList;
SqList L;

