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

TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;

	while (current->left != NULL) current = current->left;

	return current;
}

TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL) return root;

	if (key < root->key) root->left = delete_node(root->left, key);
	else if (key > root->key) root->right = delete_node(root->right, key);
	else {
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		TreeNode* temp = min_value_node(root->right);

		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
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

int inorder(TreeNode* root) {
	int sum = 0;
	if (root) {
		sum += inorder(root->left);

		printf("[%d] ", root->key);
		sum += root->key;

		sum += inorder(root->right);
	}

	printf("sum : %d\n", sum);
	return sum;
}

void inorder2(TreeNode* root, int key) {
	
	if (root) {
		inorder2(root->left,key);
		if (root->key < key) {
			printf("[%d] ", root->key);
		}

		inorder2(root->right,key);
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

	int sum = inorder(root);
	printf("sum : %d\n", sum);


	int a = get_balance(root);

	printf("total : %d\n", a);


	int search_num = 30;
	inorder2(root, search_num);

}