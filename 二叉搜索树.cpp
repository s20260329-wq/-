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
Tree* help(Tree* root,Tree**FF) {//传过来找到节点的右子树,在右子树里面找到最小值
	if (root == NULL) {
		FF = NULL; return NULL;
	}
	if (root->lchild == NULL ) {
		return root;
	}
	*FF = root;
	return help(root->lchild, FF);
}
Tree* deletTree(Tree* root, int  data) {
	Tree* F=NULL;
	Tree* l = find(root, data, &F);//l为返回的目标节点
	if (l == NULL) return NULL;
	//找到节点的三种情况
	//叶子节点
	/*if (l->lchild == NULL &&l->rchild == NULL) {
		if (F->lchild == l) {
			 F->lchild = NULL; return root;
		}
		else{ F->rchild = NULL; return root; }
	}*/
	//有一个节点是空
	if (l->lchild == NULL || l->rchild == NULL) {
		if (F->lchild == l) {
			F->lchild = (l->lchild == NULL ? l->rchild : l->lchild);
			return root;
		}
		else {
			F->rchild = (l->lchild == NULL ? l->rchild : l->lchild);
			return root;
		}
	}
	//没有空节点
	Tree* FF;
	Tree* H = help(l->rchild, &FF);
	if (H == NULL && FF == NULL) {
		if (F->lchild == l) {
			F->lchild = NULL; return root;
		}
		else {
			F->rchild = NULL; return root;
		}
		return root;
	}
		if (F->lchild == l) F->lchild = H;
		else F->rchild = H;
		FF->lchild = H->rchild;
		H->lchild = l->lchild;
		H->rchild = l->rchild;
		return root;
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

