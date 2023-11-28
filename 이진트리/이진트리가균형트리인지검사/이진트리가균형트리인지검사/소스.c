# include<stdio.h>
# include<stdlib.h>

# define MAX(a,b)(a)

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* search(TreeNode* node, int key) {
	if (node == NULL) return NULL;
	if (key == node->key)return node;
	else if (key < node->key)return search(node->left, key);
	else return search(node->right, key);
}

TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key) {
	if (node == NULL)return new_node(key);

	if (key < node->key) node->left = insert_node(node->left, key);
	else if (key > node->key) node->right = insert_node(node->right, key);

	return node;
}

int get_height(TreeNode* node) {
	int height = 0;

	if (node != NULL) height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

int get_balance(TreeNode* node) {
	if (node == NULL) return 0;

	return get_height(node->left) - get_height(node->right);
}

void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);

		
		printf("[%d] ", root->key);
		inorder(root->right);

		int a = get_balance(root);
		printf("a : %d\n", a);

	}
}

int main(void) {
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);


	inorder(root);

	int a = get_balance(root);

	printf("total : %d", a);
}