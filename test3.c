//返回链表入环的第一个节点，如果链表非环状则返回NULL
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//首先判断链表是否为环状，并返回快慢指针相遇点
//用相遇点将链表分为两个链表
//问题转化为求两个链表第一个公共节点的问题
struct ListNode* detectCycle(struct ListNode *head) {
	if (head == NULL)
		return NULL;
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (1) {
		fast = fast->next;
		if (fast == NULL) {
			return NULL;
		}
		fast = fast->next;
		if (fast == NULL) {
			return NULL;
		}
		slow = slow->next;
		if (fast == slow) {
			break;
		}
	}
	struct ListNode* n1 = head;
	struct ListNode* n2 = slow;
	while (n1 != n2) {
		n1 = n1->next;
		n2 = n2->next;
	}
	return n1;
}