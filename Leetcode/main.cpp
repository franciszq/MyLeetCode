#include<iostream>
#include<string>
#include<vector>
using namespace std;


 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


 vector<int> reversePrint(ListNode* head) {
	 vector<int> res_tmp, res;
	 while (true)
	 {
		 res_tmp.push_back(head->val);
		 head = head->next;
		 if (head->next == NULL)
		 {
			 res_tmp.push_back(head->val);
			 break;
		 }
	 }
	 for (int i = res_tmp.size() - 1; i >= 0; --i)
	 {
		 res.push_back(res_tmp.at(i));
	 }
	 return res;
 }


string replaceSpace(string s) {
	int space_num = 0;
	int src_str_size = s.size();
	for (char c :s)
	{
		if (c == ' ')
		{
			space_num++;
		}
	}
	s.resize(s.size() + space_num * 2, ' ');

	int insert_index = s.size() - 1;
	for (int j = src_str_size - 1; j >= 0 and space_num > 0; --j)
	{
		
		if (s[j] == ' ')
		{
			space_num--;
			s[insert_index--] = '0';
			s[insert_index--] = '2';
			s[insert_index--] = '%';
		}
		else
		{
			s[insert_index--] =s[j];
		}
	}
	return s;
}


//int main()
//{
// //   string s = "We are happy.";
//	//string ss = replaceSpace(s);
//	//cout << ss << endl;
//	ListNode* root = new ListNode(1);
//	ListNode* root1 = new ListNode(2);
//	ListNode* root2 = new ListNode(3);
//	root->next = root1;
//	root1->next = root2;
//	auto res = reversePrint(root);
//	return 0;
//}