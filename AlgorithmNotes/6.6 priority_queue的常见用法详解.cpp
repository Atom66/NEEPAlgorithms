/**
* priority_queue：优先队列，底层用堆实现，队首元素优先级最高
**/
#include <cstdio>
#include <queue>
using namespace std;


//priority_queue的定义
priority_queue<typename> name;


//priority_queue容器内元素的访问
{
    priority_queue<int> q;
    q.push(3);
    q.push(4);
    q.push(1);
    printf("%d\n", q.top()); // 4
}


//priority_queue常用函数实例解析
//push()  O(logN)
//top()  O(1)
//pop()  O(logN)
{
    priority_queue<int> q;
    q.push(3);
    q.push(4);
    q.push(1);
    printf("%d\n", q.top()); // 4
    q.pop();
    printf("%d\n", q.top()); // 3
}
//empty()  O(1)
{
    priority_queue<int> q;
    if (q.empty() == true)
        printf("Empyt\n");
    else
        printf("Not Empty\n");
    q.push(1);
    if (q.empty() == true)
        printf("Empyt\n");
    else
        printf("Not Empty\n");
}
//size()  O(1)
{
    priority_queue<int> q;
    q.push(3);
    q.push(4);
    q.push(1);
    printf("%d\n", q.size()); // 3
}


//priority_queue内元素优先级的设置
//基本数据类型的优先级设置
{
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(3);
    q.push(4);
    q.push(1);
    printf("%d\n", q.top()); // 1
}
//结构体的优先级设置
{
    struct fruit {
        string name;
        int price;
        friend bool operator < (fruit f1, fruit f2)
        return f1.price > f2.price;
    } f1, f2, f3;

    priority_queue<fruit> q;
    f1.name = "桃子";
    f1.price = 3;
    f2.name = "梨子";
    f2.price = 4;
    f3.name = "苹果";
    f3.price = 1;
    q.push(f1);
    q.push(f2);
    q.push(f3);
    cout << q.top().name << " " << q.top().price << endl; //苹果 1
}
{
    struct fruit {
        string name;
        int price;
    } f1, f2, f3;

    struct cmp {
        bool operator () (fruit f1, fruit f2)
        return f1.price > f2.price;
    };

    priority_queue<fruit, vector<fruit>, cmp> q;
    f1.name = "桃子";
    f1.price = 3;
    f2.name = "梨子";
    f2.price = 4;
    f3.name = "苹果";
    f3.price = 1;
    q.push(f1);
    q.push(f2);
    q.push(f3);
    cout << q.top().name << " " << q.top().price << endl; //苹果 1
}


//priority_queue常见用途
//可以解决一些贪心问题，也可以对Dijkstra算法进行优化
//注意：使用top()函数前，必须用empty()函数判断优先队列是否为空
