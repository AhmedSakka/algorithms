struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

    ListNode* invertList(ListNode* head){
        ListNode* prev = nullptr;
        
        while(head != nullptr){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    
    int pairSum(ListNode* head) {
        ListNode* slowIterator = head, *fastIterator = head;
        int sum = 0;
        while(fastIterator != nullptr && fastIterator->next != nullptr){
            fastIterator = fastIterator->next->next;
            slowIterator = slowIterator->next;
        }
        
        slowIterator = invertList(slowIterator);
        ListNode* headIterator = head;
        
        while(slowIterator != nullptr)
        {
            sum = max(sum, slowIterator->val + headIterator->val);
            slowIterator = slowIterator->next;
            headIterator = headIterator->next;
        }
        
        return sum;
    }