class MyCircularQueue {
public:
    MyCircularQueue(int k) : count(0), capacity(k), head(0), tail(0) 
    {
        buffer.resize(k);
    }
    
    bool enQueue(int value) 
    {
        if (isFull())
        {
            return false;
        }
        else
        {
            tail = (head + count) % capacity;
            buffer[tail] = value;
            ++count;
            return true;
        }
    }
    
    bool deQueue() 
    {
        if (isEmpty())
        {
            return false;
        }
        else
        {
            buffer[head] = 0;
            --count;
            head = (head + 1) % capacity;
            return true;
        }
        
    }
    
    int Front() 
    {
        if (isEmpty())
        {
            return -1;
        }
        
        return buffer[head];
    }
    
    int Rear() 
    {
        if (isEmpty())
        {
            return -1;
        }
        
        return buffer[tail];    
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
    std::vector<int> buffer;
    int head;
    int tail;
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