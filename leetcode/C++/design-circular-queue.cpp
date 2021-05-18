class MyCircularQueue {
public:
    vector<int> v;
    int sz,l,r;
    MyCircularQueue(int k) {
        sz=l=r=0;
        v=vector<int>(k+1,0);
    }
    
    bool enQueue(int value) {
        if(v.size()==sz+1) return false;
        v[r]=value;
        r=(r+1)%(v.size());
        ++sz;
        return true;
    }
    
    bool deQueue() {
        if(sz==0) return false;
        l=(l+1)%(v.size());
        --sz;
        return true;
    }
    
    int Front() {
        if(sz==0) return -1;
        return v[l];
    }
    
    int Rear() {
        if(sz==0) return -1;
        return v[(r+v.size()-1)%(v.size())];
    }
    
    bool isEmpty() {
        return sz==0;
    }
    
    bool isFull() {
        return sz+1==v.size();
    }
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