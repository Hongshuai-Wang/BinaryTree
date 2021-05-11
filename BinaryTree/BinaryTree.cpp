#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 二叉树二叉链表结构定义
class BiTNode {
public:
    char data;
    class BiTNode* lchild;
    class BiTNode* rchild;
};
// 二叉树的前序输入
BiTNode * CreateBiTree(BiTNode* BiTree)
{
    // 前序输入
    char node;
    cin >> node;
    if (node == '#')
    {
        BiTree = NULL;
    }
    else
    {
        BiTree = new BiTNode;
        BiTree->data = node;
        BiTree->lchild = CreateBiTree(BiTree->lchild);
        BiTree->rchild = CreateBiTree(BiTree->rchild);
    }
    return BiTree;
}
// 二叉树的前序输入 方案2
void vCreateBiTree(BiTNode* BiTree)
{
    // 前序输入
    char node;
    cin >> node;
    if (node == '#')
    {
        BiTree = NULL;
    }
    else
    {
        BiTree = new BiTNode;
        BiTree->data = node;
        vCreateBiTree(BiTree->lchild);
        vCreateBiTree(BiTree->rchild);
    }
    return;
}
// 前序遍历
void PreorderTraverse(const BiTNode* BiTree)
{
    if (BiTree == NULL)
        return;
    cout << BiTree->data << " ";
    PreorderTraverse(BiTree->lchild);
    PreorderTraverse(BiTree->rchild);
}
// 中序遍历
void InorderTraverse(const BiTNode* BiTree)
{
    if (BiTree == NULL)
        return;
    InorderTraverse(BiTree->lchild);
    cout << BiTree->data << " ";
    InorderTraverse(BiTree->rchild);
}
// 后续遍历
void PostorderTraverse(const BiTNode* BiTree)
{
    if (BiTree == NULL)
        return;
    PostorderTraverse(BiTree->lchild);
    PostorderTraverse(BiTree->rchild);
    cout << BiTree->data << " ";
}
// 层序遍历
void LayerorderTraverse(BiTNode* BiTree)
{
    if (BiTree == NULL)
        return;
    // 由于层序遍历无法递归，需要采用先入先出的队列存储候补节点，
    // 遍历一个候补节点，将子节点入队，并将候补节点弹出
    queue<BiTNode*> Tree_que;
    Tree_que.push(BiTree);
    vector<vector<char>> Tree_vv;
    while (!Tree_que.empty())
    {
        vector<char> Tree_node_v;
        int n = Tree_que.size();
        // 层遍历，并压入下一层的节点
        for (size_t i = 0; i < n; ++i)
        {
            BiTNode* temp = Tree_que.front();
            Tree_que.pop();
            Tree_node_v.push_back(temp->data);
            if (temp->lchild != NULL) Tree_que.push(temp->lchild);
            if (temp->rchild != NULL) Tree_que.push(temp->rchild);
        }
        Tree_vv.push_back(Tree_node_v);
    }
    // 输出结果
    for (size_t i = 0; i < Tree_vv.size(); i++)
    {
        for (size_t j = 0; j < Tree_vv[i].size(); j++)
        {
            cout << Tree_vv[i][j] << " ";
        }
    }
}
// 销毁二叉树
void DestoryBiTree(BiTNode* BiTree)
{
    if (BiTree == NULL)
    {
        return;
    }

    DestoryBiTree(BiTree->lchild);
    DestoryBiTree(BiTree->rchild);

    delete BiTree;
}

int main(int argc, char* argv[])
{
    BiTNode* BiTree = NULL;

    // 前序输入创建扩展二叉树
    cout << "前序创建扩展二叉树:\n";
    BiTree = CreateBiTree(BiTree);

    // 前序遍历
    cout << "\n前序遍历二叉树：\n";
    PreorderTraverse(BiTree);
    // 中序遍历
    cout << "\n中序遍历二叉树：\n";
    InorderTraverse(BiTree);
    // 后续遍历
    cout << "\n后序遍历二叉树：\n";
    PostorderTraverse(BiTree);
    // 层序遍历
    cout << "\n层序遍历二叉树：\n";
    LayerorderTraverse(BiTree);

    // 销毁二叉树
    cout << "\n销毁二叉树!\n";
    DestoryBiTree(BiTree);
    
    cout << "\n执行完毕\n";
    return 0;
}

 // 方案2不行，因为vCreateBiTree(&BiTree)在递归的过程中没有返回指针，
// 导致指针每一次递归都是在移动，而不是指针指向下一个指针
//int main(int argc, char* argv[])
//{
//    BiTNode BiTree;
//
//    // 前序输入创建扩展二叉树
//    cout << "\n前序创建扩展二叉树:\n";
//    vCreateBiTree(&BiTree);
//
//    // 前序遍历
//    cout << "\n前序遍历二叉树：\n";
//    PreorderTraverse(&BiTree);
//    // 中序遍历
//    cout << "\n中序遍历二叉树：\n";
//    InorderTraverse(&BiTree);
//    // 后续遍历
//    cout << "\n后序遍历二叉树：\n";
//    PostorderTraverse(&BiTree);
//    // 层序遍历
//    cout << "\n层序遍历二叉树：\n";
//    LayerorderTraverse(&BiTree);
//
//    // 销毁二叉树
//    cout << "\n销毁二叉树!\n";
//    DestoryBiTree(&BiTree);
//    
//    cout << "\n执行完毕\n";
//    return 0;
//}
