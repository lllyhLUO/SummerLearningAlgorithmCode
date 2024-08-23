//date: 2024/7/15 20:43

//函数结果状态代码
#define OK 1
#define ERROR 0
#define MAXSIZE 10
#define OVERFLOW -2
typedef struct 
{
    float coef; //系数
    float expn; //指数
}Polynomial;
typedef struct 
{
    Polynomial *elem; //基地址
    int length; //多项式中当前项的个数
}SqList;

