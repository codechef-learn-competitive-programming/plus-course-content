class node
{
public:
	node *left, *right;
	int data, sub_size;
};

int get_size(node *cur)
{
	return cur ? cur->sub_size : 0;
}

node* get(node *root, int k) // 0 to n-1
{
	if (k<0 or k >= root->sub_size)
		return NULL;

	int left_size = get_size(root->left);

	if (left_size > k)
		return get(root->left, k);

	if (left_size == k)
		return root;

	return get(root->right, k - (left_size + 1));
}
