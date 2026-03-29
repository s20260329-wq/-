#include<stdio.h>
#include<stdlib.h>
typedef int  ElemType;
typedef struct as{
	ElemType data;
	struct as*lchild;
	struct as*rchild;
}Tree; 
//先序递归建立
Tree*PreBuilt(Tree*t)
{   int number;
    scanf("%d",&number);
    if(number==-1){
    	return NULL;
	}
	t=(Tree*)malloc(sizeof(Tree));
	t->data=number;
	t->rchild=NULL;
	t->lchild=NULL;
	t->lchild=PreBuilt(t->lchild);
	t->rchild=PreBuilt(t->rchild);
	return t;
}
//中序递归建立
Tree*InBuilt(Tree*t)
{
	int number;
	scanf("%d",&number);
	//利用递归走到左子树底部再赋值左子树底部也是虚拟子树的根节点
	if(number!=-1){
		t=(Tree*)malloc(sizeof(Tree));
		t->lchild=InBuilt(t->rchild);
		t->data=number;
		t->rchild=InBuilt(t->rchild);
		return t;
	}
	else{
		return NULL;
	}
	
}
//后序递归建立
Tree*ProBuilt(Tree*t)
{
	int number;
	scanf("%d",&number);
	if(number==-1){
		return NULL;
	} 
	else{
		t=(Tree*)malloc(sizeof(Tree));
		t->lchild=PreBuilt(t->lchild);
		t->rchild=PreBuilt(t->rchild);
		t->data=number;
		return t;
	}
	//依然先找到最底层的左子树
	//直接跳到右子树
	//最后给左子树即虚拟节点的根赋值 
}
//树的输出
//先序递归遍历
void PreLook(Tree*t)
{
	if(t==NULL) return ;
	//碰见根节点先遍历再跳到左子树
	printf("%d ",t->data);
	PreLook(t->lchild);
	PreLook(t->rchild);
	
	//左子树遍历完再跳到右子树 
 } 
 //中序遍历
 void InLook(Tree*t)
 {
 	// 先判断终止条件
 	if(t==NULL) return ; 
	 //一直寻找左子树
	 InaLook(t->lchild);
	 printf("%d ",t->data);
	 //左子树结束后跳转到右子树 
	 InLook(t->rchild);
  } 
  //后序遍历
  void ProLook(Tree*t)
  {
  	//判断终止条件
  	if(t==NULL) return ;
	  //找到左子树为空
	  ProLook(t->lchild);
	  //跳转到右子树为空
	  ProLook(t->rchild);
	  //再输出根节点的值 
	  printf("%d ",t->data);
   } 
   //交换二叉树
  Tree*IO(Tree*root)
  {
  	//先序遍历只不过把输出那一步改为交换指针那一步
  	if(root==NULL) return NULL;
	  Tree*temp;
	  temp=root->lchild;
	  root->lchild=root->rchild;
	  root->rchild=temp;
	  IO(t->lchid);
	  IO(t->rchild);
   } 
   //后续交换二叉树
   Tree*ProIO(Tree*root)
   {
   	if(root==NULL){
   		return NULL;
	   }
	   ProIO(root->lchid);
	   ProIo(root->rchild);
	   Tree*tem=root->lchild;
	   root->lchild=root->rchild;
	   root->rchild=tem;
	} 
//二叉树对称
int (Tree*lchild,Tree*rchild)
{
	//先判断上一次传递的值是否相等
	if(lchild==NULL&&rchild==NULL) return 1;
	else if(lchild==NULL&&rchild!=NULL) return 0; 
	else if(lchild!=NULL&&rchild==NULL) return 0;
	else if(lchild->data!=rchild->data) return 0;
	else if(lchild->data==rchild->data) return 1;
	int i=
 } 
 //二叉树的最大深度
 int DeepTree(Tree*t){
 	//判断终止条件
	 if(t==NULL) return 0;
	 int len=DeepTree(t->lchild);
	 int r=DeepTree(t->rchild);
	 return  1+(len>r?len:r);
 } 
int main(){
	Tree*t;
	PreBuilt(t);
	PreLook(t);
}
