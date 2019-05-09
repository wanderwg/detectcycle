//���������뻷�ĵ�һ���ڵ㣬�������ǻ�״�򷵻�NULL
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//�����ж������Ƿ�Ϊ��״�������ؿ���ָ��������
//�������㽫�����Ϊ��������
//����ת��Ϊ�����������һ�������ڵ������
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