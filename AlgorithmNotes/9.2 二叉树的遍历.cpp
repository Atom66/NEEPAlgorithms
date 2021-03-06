/**
* 二叉树的遍历：DFS实现的三种：先序、中序、后序
*               BFS实现的一种：层次
**/

//先序遍历
void preorder(node* root) {
    if (root == NULL) {
        return; //到达空树，递归边界
    }
    printf("%d\n", root->data); //访问根结点root，例如将其数据域输出
    preorder(root->lchild); //访问左子树
    preorder(root->rchild); //访问右子树
}

//中序遍历
void inorder(node* root) {
    if (root == NULL) {
        return; //到达空树，递归边界
    }
    inorder(root->lchild); //访问左子树
    printf("%d\n", root->data); //访问根结点root，例如将其数据域输出
    inorder(root->rchild); //访问右子树
}

//后序遍历
void postorder(node* root) {
    if (root == NULL) {
        return; //到达空树，递归边界
    }
    postorder(root->lchild); //访问左子树
    postorder(root->rchild); //访问右子树
    printf("%d\n", root->data); //访问根结点root，例如将其数据域输出
}

//层序遍历
void LayerOrder(node* root) {
    queue<node*> q; //注意队列里是存地址
    q.push(root); //将根结点地址入队
    while (!q.empty()) {
        node* now = q.front(); //取出队首元素
        q.pop();
        printf("%d\n", now->data); //访问队首元素
        if (now->lchild != NULL)
            q.push(now->lchild); //左子树非空
        if (now->rchild != NULL)
            q.push(now->rchild); //右子树非空
    }
}
//如果需要计算结点所处的层次
struct node {
    int data; //数据域
    int layer; //层次
    node* lchild; //左指针域
    node* rchild; //右指针域
};
void LayerOrder(node* root) {
    queue<node*> q; //注意队列里是存地址
    root->layer = 1; //根结点的层号为1
    q.push(root); //将根结点地址入队
    while (!q.empty()) {
        node* now = q.front(); //取出队首元素
        q.pop();
        printf("%d\n", now->data); //访问队首元素
        if (now->lchild != NULL) {
            //左子树非空
            now->lchild->layer = now->layer + 1; //左孩子的层号为当前层号+1
            q.push(now->lchild);
        }
        if (now->rchild != NULL) {
            //右子树非空
            now->rchild->layer = now->layer + 1; //右孩子的层号为当前层号+1
            q.push(now->rchild);
        }
    }
}


/**
* 重要问题：给定一课二叉树的先序遍历序列和中序遍历序列，重建这棵二叉树
**/
//当前先序序列区间为[preL,preR]，中序序列区间为[inL,inR]，返回根结点地址
node* create(int preL, int preR, int inL, int inR) {
    if (preL > preR) {
        return NULL; //先序序列长度小于等于0时直接返回
    }
    node* root = new node; //新建一个新的结点，用来存放当前二叉树的根结点
    root->data = pre[preL]; //新结点的数据域为根结点的值
    int k;
    for (k = inL; k <= inR; k++) {
        if (in[k] == pre[preL])
            break; //在中序序列中找到in[k]==pre[L]的结点
    }
    int numLeft = k - inL; //左子树的结点个数

    //左子树的先序区间为[preL+1,preL+numLeft]，中序区间为[inL,k-1]
    //返回左子树的根结点地址，赋值给root的左指针
    root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);

    //右子树的先序区间为[preL+numLeft+1,preR]，中序区间为[k+1,inR]
    //返回右子树的根结点地址，赋值给root的右指针
    root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);

    return root; //返回根结点地址
}
