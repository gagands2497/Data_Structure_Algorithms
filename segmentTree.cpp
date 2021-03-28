//sum of elements in a range
#include <bits/stdc++.h>

using namespace std;

void updateTree(int input[], int tree[], int start, int end, int treeNode, int index, int value)
{

	//base Condition
	if (start == end)
	{
		input[start] = value;	//updating the array value
		tree[treeNode] = value; //updating the leaf value of the tree specific to that array element
		return;
	}

	int mid = (start + end) / 2;
	if (index > mid)
	{
		//go right
		updateTree(input, tree, mid + 1, end, 2 * treeNode + 1, index, value);
	}
	else
	{
		//go left
		updateTree(input, tree, start, mid, 2 * treeNode, index, value);
	}
	//update the tree;
	tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

int query(int tree[], int start, int end, int treeNode, int left, int right)
{
	//completely outside the range
	if (start > right || end < left)
		return 0;

	//completely inside the range
	if (start >= left && end <= right)
		return tree[treeNode];
	//partialy outside and partially inside the range

	int mid = (start + end) / 2;
	int leftAns = query(tree, start, mid, 2 * treeNode, left, right);
	int rightAns = query(tree, mid + 1, end, 2 * treeNode + 1, left, right);

	return leftAns + rightAns;
}

void buildTree(int input[], int tree[], int start, int end, int treeNode)
{

	//baseCase
	if (start == end)
	{
		tree[treeNode] = input[start];
		return;
	}

	int mid = (start + end) / 2;
	buildTree(input, tree, start, mid, 2 * treeNode);
	buildTree(input, tree, mid + 1, end, 2 * treeNode + 1);

	tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
	//result of left child plus result of right child
}

int main()
{
	int n;
	cin >> n;
	int input[n];
	int tree[2 * n];

	for (int i = 0; i < n; i++)
		cin >> input[i];

	int start = 0, end = n - 1; //start and end for range
	int treeNode = 1;			//starting our tree from index 1

	buildTree(input, tree, start, end, treeNode);
	updateTree(input, tree, start, end, treeNode, 2, 10);
	for (int i = 1; i < 2 * n; i++)
	{
		cout << tree[i] << endl;
	}

	int ans = query(tree, start, end, treeNode, 2, 4);

	cout << "Sum between the range is " << ans << endl;
}