#include <iostream>
#include <vector>
#include <map>
#include <concurrent_priority_queue.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};


class Solution {
public:
	// 剑指 Offer 34. 二叉树中和为某一值的路径
	void dfs(TreeNode* root, int target)
	{
		if (root == nullptr)
		{
			return;
		}
		path.push_back(root->val);
		if (root->left == nullptr && root->right == nullptr && target == root->val)
		{
			res.push_back(path);
		}
		dfs(root->left, target - root->val);
		dfs(root->right, target - root->val);
		path.pop_back();
	}


	vector<vector<int>> pathSum(TreeNode* root, int target) {
		dfs(root, target);
		return res;
	}

	// 0101. 对称二叉树
	void PreTraversal(TreeNode* root, vector<int>& path)
	{
		if (root == nullptr)
		{
			path.push_back(-999);
			return;
		}
		if (root->left != nullptr || root->right != nullptr)
		{
			PreTraversal(root->left, path);
		}
		
		path.push_back(root->val);
		if (root->left != nullptr || root->right != nullptr)
		{
			PreTraversal(root->right, path);
		}
		

	}
	void PostTraversal(TreeNode* root, vector<int>& path)
	{
		if (root == nullptr)
		{
			path.push_back(-999);
			return;
		}
		if (root->left != nullptr || root->right != nullptr)
		{
			PostTraversal(root->right, path);
		}
		
		path.push_back(root->val);
		if (root->left != nullptr || root->right != nullptr)
		{
			PostTraversal(root->left, path);
		}
		
	}

	bool isSymmetric(TreeNode* root) {
		vector<int> pre_path, post_path;
		PreTraversal(root, pre_path);
		PostTraversal(root, post_path);
		if (pre_path.size() != post_path.size())
		{
			return false;
		}
		for (int i= 0; i < pre_path.size(); ++i)
		{
			if (pre_path[i] != post_path[i])
			{
				return false;
			}
		}
		return true;
	}

private:
	vector<vector<int>> res;
	vector<int> path;
};
//
//vector<int> topKFrequent(vector<int>& nums, int k) {
//	map<int, int> fre_map;
//	for (auto num : nums)
//	{
//		fre_map[num]++;
//	}
//	priority_queue<pair<int, int>> que;
//	for (auto it : fre_map)
//	{
//		que.emplace(it.second, it.first);
//	}
//	vector<int> res;
//	for (int i = 0; i < k && i < que.size(); i++)
//	{
//		res.push_back(que.top().second);
//		que.pop();
//	}
//	return res;
//}


int main2()
{
	//TreeNode* 
	return 0;
}