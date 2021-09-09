class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() : Head(nullptr), length(0)
    {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) 
    {
        if (index >= length || index < 0)
        {
            return -1;
        }
        else
        {
            auto itr = Head;
            while (index--)
            {
                itr = itr->next;
            }
            return itr->val;
        }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) 
    {
        ListNode* curr = new ListNode(val);
        curr->next = Head;
        Head = curr;
        ++length;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) 
    {
        if (0 == length)
        {
            addAtHead(val);
        }
        else
        {
            ListNode* curr = new ListNode(val);
            auto itr = Head;
            while (itr->next)
            {
                itr = itr->next;
            }
            itr->next = curr;
            ++length;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) 
    {
        if (index > length || index < 0)
        {
            return;
        }
        else if (0 == index)
        {
            addAtHead(val);
        }
        else
        {
            ListNode* curr = new ListNode(val);
            auto itr = Head;
            while (--index > 0)
            {
                itr = itr->next;
            }
            curr->next = itr->next;
            itr->next = curr;
            ++length;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) 
    {
        if (index >= length || index < 0)
        {
            return;
        }

        if (index == 0)
        {
            ListNode* tmp; 
            if (Head)
            {
                tmp = Head->next;
            }
            delete Head;
            Head = tmp;
        }
        else if (index == length-1)
        {
            auto itr = Head;
            while (--index > 0)
            {
                itr = itr->next;
            }
            ListNode* tmp = itr->next;
            itr->next = nullptr;
            delete tmp;
        }
        else
        {
            auto itr = Head;
            while (--index > 0)
            {
                itr = itr->next;
            }
            
            ListNode* tmp = nullptr;
            if (itr && itr->next)
            {
                tmp = itr->next->next;
            }
            delete itr->next;
            itr->next = tmp;
        }
    --length;   
    }
private:
    struct ListNode
    {
        ListNode* next;
        int val;
        ListNode() : next(nullptr), val(0) {};
        ListNode(int val_) : next(nullptr), val(val_) {};
    };
    ListNode* Head;    
    int length;
    
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */