#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


using namespace std;


// 21. 合并两个有序链表
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    if (list1 == nullptr && list2 == nullptr) {
        return nullptr;
    }
    if (list1 == nullptr && list2 != nullptr) {
        return list2;
    }
    if (list1 != nullptr && list2 == nullptr) {
        return list1;
    }

    ListNode* temp_list = new ListNode(0);
    ListNode* current_list = temp_list;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            current_list->next = list1;
            list1 = list1->next;
        } else {
            current_list->next = list2;
            list2 = list2->next;
        }
        current_list = current_list->next;
    }
    if (list1 == nullptr) {
        current_list->next = list2;
    }
    if (list2 == nullptr) {
        current_list->next = list1;
    }

    return temp_list->next;
}

// 82 删除排序链表中的重复元素 II
ListNode* deleteDuplicates(ListNode* head)
{
    if (head->next == nullptr) {
        return head;
    }

    ListNode* temp_list = new ListNode(0);
    ListNode* current_list = temp_list;

    ListNode* pre_node = head;
    head = head->next;
    while (head != nullptr) {
        if (head->val != pre_node->val) {
            current_list->next = pre_node;
            current_list = current_list->next;
            pre_node = pre_node->next;
            head = head->next;
        } else {
            while (head->val == pre_node->val) {
                head = head->next;
            }
            current_list->next = pre_node;
            current_list = current_list->next;
            pre_node = head;
            head = head->next;
        }
    }
    current_list->next = pre_node;
    return temp_list->next;

}

// 83 删除排序链表中的重复元素
ListNode* deleteDuplicates2(ListNode* head)
{
    if (head->next == nullptr) {
        return head;
    }

    ListNode* temp_list = new ListNode(0);
    ListNode* current_list = temp_list;

    ListNode* pre_node = head;
    head = head->next;
    while (head != nullptr) {
        if (head->val != pre_node->val) {
            current_list->next = pre_node;
            current_list = current_list->next;
            pre_node = pre_node->next;
            head = head->next;
        } else {
            while (head->val == pre_node->val) {
                head = head->next;
            }
            pre_node = head;
            head = head->next;
        }
    }
    current_list->next = pre_node;
    return temp_list->next;

}

void test()
{
    int a = 5;
}

void test11223()
{

}

// 143 重排链表
void reorderList(ListNode* head)
{
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    ListNode* pre = head;
    ListNode* lat = head->next;
    while (lat != nullptr && lat->next != nullptr) {
        pre = pre->next;
        lat = lat->next->next;
    }

    ListNode* p = pre->next;
    pre->next = nullptr;

    ListNode* cur = nullptr;
    while (p != nullptr) {
        ListNode* q = p->next;
        p->next = cur;
        cur = p;
        p = q;
    }
    pre = head;
    while (pre != nullptr && cur != nullptr) {
        ListNode* tmp = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        pre = pre->next->next;
        cur = tmp;
    }
}


int main()
{
    /*ListNode* list1 = new ListNode{ 1 };
    ListNode* list2 = new ListNode{ 2 };
    ListNode* list3 = new ListNode{ 3 };
    ListNode* list4 = new ListNode{ 3 };
    ListNode* list5 = new ListNode{ 4 };
    ListNode* list6 = new ListNode{ 4 };
    ListNode* list7 = new ListNode{ 5 };
    list1->next = list2;
    list2->next = list3;
    list3->next = list4;
    list4->next = list5;
    list5->next = list6;
    list6->next = list7;

    deleteDuplicates2(list1);*/

    return 0;
}