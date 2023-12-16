#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeLists(ListNode* list1, ListNode* list2) {
    ListNode* mergedList = new ListNode(0);
    ListNode* current = mergedList;

    while (list1 != nullptr || list2 != nullptr) {
        if (list1 == nullptr) {
            current->next = list2;
            break;
        }
        if (list2 == nullptr) {
            current->next = list1;
            break;
        }

        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        }
        else {
            current->next = list2;
            list2 = list2->next;
        }

        current = current->next;
    }

    return mergedList->next;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* mergedList = mergeLists(list1, list2);

    printList(mergedList);

    while (mergedList != nullptr) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
