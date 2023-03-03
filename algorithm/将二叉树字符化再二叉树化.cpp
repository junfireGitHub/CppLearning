#include<iostream>
#include<cstdio>
#include<cmath>
#include<sstream>

using namespace std;


typedef struct TreeNode {
	int val;
	TreeNode *left;     
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}*BiTree;

class Codec{
public:
	string serialize(TreeNode* root) {
		ostringstream out;
		serialize(root, out);
		return out.str();
	}

	TreeNode* deserialize(string data) {
		istringstream in(data);
		return deserialize(in);
	}

private:

	void serialize(TreeNode* root, ostringstream& out) {
		if (root) {
			out << root->val << ' ';
			serialize(root->left, out);
			serialize(root->right, out);
		}
		else {
			out << "# ";
		}
	}

	TreeNode* deserialize(istringstream& in) {
		string val;
		in >> val;
		if (val == "#")
			return nullptr;
		TreeNode* root = new TreeNode(stoi(val));
		root->left = deserialize(in);
		root->right = deserialize(in);
		return root;
	}
};

TreeNode* createBiTree()
{
	char ch;
	scanf("%c",&ch);
	if (ch == ' ') {
		return nullptr;
	}
	else{
		char *pc = &ch;
		TreeNode *root  = new TreeNode(atoi(pc));
		root->left = createBiTree();
		root->right = createBiTree();
		return root;
	}
}

int main()
{
    TreeNode *root = createBiTree();
	Codec codec;
	TreeNode *root2 = codec.deserialize(codec.serialize(root));
	return 0;
}