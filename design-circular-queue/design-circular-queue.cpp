class MyCircularQueue {
public:
    MyCircularQueue(int k) : count(0), capacity(k) {}
    
    bool enQueue(int value) 
    {
        if (isFull() || count == capacity)
        {
            return false;
        }
        else
        {
            buffer.push_back(value);
            ++count;
            return true;
        }
    }
    
    bool deQueue() 
    {
        if (isEmpty() || count == 0)
        {
            return false;
        }
        else
        {
            buffer.pop_front();
            --count;
            return true;
        }
        
    }
    
    int Front() 
    {
        if (isEmpty())
        {
            return -1;
        }
        
        return buffer.front();
    }
    
    int Rear() 
    {
        if (isEmpty())
        {
            return -1;
        }
        
        return buffer.back();    
    }
    
    bool isEmpty() 
    {
        return count == 0;    
    }
    
    bool isFull() 
    {
        return capacity == count;
    }
private: 
    std::list<int> buffer;
    int count;
    int capacity;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */