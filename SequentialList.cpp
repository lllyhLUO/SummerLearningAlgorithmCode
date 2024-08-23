#include <iostream>
#include <vector>
using namespace std;
int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size - 1;

    while (left < right) {
        int middle = left + (right - left) / 2;
        if (nums[middle] > target)
            right = middle - 1;
        else if (nums[middle] < target) 
            left = middle + 1;
        else 
            return middle;
    }
    return -1;
}

int removeElement(vector<int>& nums, int val) {
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        if (nums[i] == val)
            for (int j = i + 1; j < size; j++) 
                nums[j - 1] = nums[j];
        i--;
        size--;
    }
    return size;
}

int removeElement2(vector<int>& nums, int val) {
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) 
        if (nums[fastIndex] != val)
            nums[slowIndex++] = nums[fastIndex];
    return slowIndex;
}

int addedInteger(vector<int>& nums1, vector<int>& nums2) {
    int x = *min_element(nums2.begin(), nums2.end()) - *min_element(nums1.begin(), nums1.begin());
    for (int i = 0; i < nums1.size(); i++) {
        nums1[i] = nums1[i] + x;
        if (nums1[i] != nums2[i]) return -1;
    }
    return x;
}

int totalFruit(vector<int>& fruits) {
    int i = 0, j = 0;
    int class1 = 0, class2 = 0; // 类别起始索引，class1前类，class2后类
    int num = 0;
    for (; i < fruits.size(); i++) {
        if (fruits[i] != fruits[class1] and fruits[i] != fruits[class2]) {
            if (class1 = class2) {
                class2 = i; // 初始类别设置相同，寻找新类别时索引赋给class2
            }
            else {
                class2 = i; // 新类别赋给class2
                class1 = i - 1; // 新类别前一个元素一定为另一个类别
                num = i - j > num : i - j : num; // 比较上一段窗口与历史最长，保存最长
                j = i; // 从新类别前一个位置开始寻求左端点
                while (fruits[j - 1] == fruits[class2] or fruits[j - 1] == fruits[class1]) {
                    --j;
                }
                class1 = j;
            }
        }
    }
    return i - j > num ? i - j : num;
}

// 链表相交
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
}
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* curA = headA;
    ListNode* curB = headB;
    int lenA = 0, lenB = 0;
    while (curA != NULL) {
        lenA++;
        curA = curA->next;
    }
    while (curB != NULL) {
        lenB++;
        curB = curB->next;
    }
    curA = headA;
    curB = headB;
    if (lenB > lenA) {
        swap(lenA, lenB);
        swap(curA, curB);
    }
    int gap = lenA - lenB;
    while (gap--)
        curA = curA->next;
    while (curA != NULL) {
        if (curA == curB) {
            return curA;
        }
        curA = curA->next;
        curB = curB->next;
    }
    return NULL;
}

// 单链表
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* removeElement3(ListNode* head, int val) {
    // 删除头结点
    while (head != NULL && head->val == val) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }

    // 删除非头结点
    ListNode* cur = head;
    while (cur != NULL && cur->next != NULL) {
        if (cur->next->val == val) {
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
        else {
            cur = cur->next;
        }
    }
    return head;
}

// 设置一个虚拟头结点在进行移除节点操作
ListNode* removeElements4(ListNode* head, int val) {
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* cur = dummyHead;
    while (cur->next != NULL) {
        if (cur->next-val == val) {
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
        else {
            cur = cur->next;
        }
    }
    head = dummyHead->next;
    delete dummyHead;
    return head;
}
// C：用原来的链表操作
struct ListNode* removeElement5(struct ListNode* head, int val) {
    struct ListNode* temp;
    while (head && head->val == val) {
        temp = head;
        head = head->next;
        free(temp);
    }
    struct ListNode* cur = head;
    while (cur && (temp = cur->next)) {
        if (temp->val = val) {
            cur->next = temp->next;
            free(temp);
        }
        else 
            cur = cur->next;
    }
    return head;
}

struct ListNode* removeElement6(struct ListNode* head, int val) {
    typedef struct ListNode ListNode;
    ListNode* shead;
    shead = (ListNode*)malloc(sizeof(ListNode));
    shead->next = head;
    ListNode* cur = shead;
    while (cur->next != NULL) {
        if (cur->next->val == val) {
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            free(tmp);
        }
        else 
            cur = cur->next;
    }
    head = shead->next;
    free(shead);
    return head;
}