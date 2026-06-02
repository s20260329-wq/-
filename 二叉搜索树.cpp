#include<stdio.h>
#include <malloc.h>
typedef struct a {
	int data;
	struct a* lchild;
	struct a* rchild;
	
}Tree;
//创建一个节点
Tree* creatNode(Tree* root, int data) {
	root = (Tree*)malloc(sizeof(Tree));
	if (root == NULL) return NULL;
	root->data = data;
	root->rchild = root->lchild = NULL;
	return root;
}
//前序遍历构建二叉排序树
Tree* searchTree(Tree* root, int data) {
	//处理第一个空节点
	if (root == NULL) {
		return creatNode(root, data);
	}
	if (data < root->data) {
		root->lchild=searchTree(root->lchild, data);
	}
	if (root->data < data) {
		root->rchild=searchTree(root->rchild, data);
	}
	return root;
	
}
//中序遍历看是否成功建立
void Traverse(Tree* root) {
	if (root == NULL) return;
	Traverse(root->lchild);
	printf("%d ", root->data);
	Traverse(root->rchild);
}
//前序遍历构建二叉排序树
Tree* searchTree(Tree* root, int data) {
	//处理第一个空节点
	if (root == NULL) {
		return creatNode(root, data);
	}
	if (data < root->data) {
		root->lchild=searchTree(root->lchild, data);
	}
	if (root->data < data) {
		root->rchild=searchTree(root->rchild, data);
	}
	return root;
	
}
//中序遍历看是否成功建立
void Traverse(Tree* root) {
	if (root == NULL) return;
	Traverse(root->lchild);
	printf("%d ", root->data);
	Traverse(root->rchild);
}
//查找
Tree* find(Tree* root, int data,Tree*p) {
	//判断终止条件
	if (root == NULL) return NULL;
	if (root->data == data) return root;
	if (root->data > data) {
		p = root;
		return find(root->lchild, data,p);
	}
	else {
		p = root;
		return find(root->rchild, data,p);
	}
}
//删除
int delet(Tree** root,int data) {//传过来找到节点的右子树,在右子树里面找到最小值
	//判断该删节点的情况两空与一空合为一种情况
	//设置临时变量记录值一会释放
	Tree* temp = *root;
	if ((*root)->lchild == NULL) {
		*root = (*root)->rchild;
		free(temp);
		return 1;
	}
	else if ((*root)->rchild == NULL) {
		*root=(*root)->lchild;
		free(temp);
		return 1;
	}
	else {
		Tree* recod = (*root)->rchild;
		while (  recod->lchild!=NULL) {
			temp = recod;
			recod = recod->lchild;
		}
		(*root)->data = recod->data;
		if (temp == *root) {
			temp->rchild = recod->rchild;
		}
		free()
	}
}
int  deletTree(Tree* root, int  data) {
	if (root == NULL) {
		printf("这是一颗空树");
	}
	if ((root)->data == data) {
		return  delet(&root, data);
	}
	else if ((root)->data > data) {
		return deletTree(root->lchild,data);
	}
	else if(root->data<data) {
		return deletTree(root->rchild, data);
	}
	return 0;
}


int main() {
	int arr[] = { 24,3,5,4,65,7,6,8,678,4,5 };
	Tree* root = NULL;
	Tree p;
	for (int i = 0; i < sizeof(arr) / 4; i++) {
		root=searchTree(root, arr[i]);
	}
	Tree* temp = find(root, 3,&p);
	printf("%d", temp->data);
	//Traverse(root);
}

