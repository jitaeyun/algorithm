class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int,vector<int>,greater<int>> minHeap;
    priority_queue<int> maxHeap;
    int sz;
    MedianFinder() {
        sz=0;
    }
    
    void addNum(int num) {
        (++sz%2)? maxHeap.push(num) : minHeap.push(num);
        int l,r;
        if(sz>1 && (l=maxHeap.top())>(r=minHeap.top())){
            maxHeap.pop(); minHeap.pop();
            maxHeap.push(r); minHeap.push(l);
        }
    }
    
    double findMedian() {
        if(sz%2) return maxHeap.top();
        return ((double)maxHeap.top()+(double)minHeap.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */