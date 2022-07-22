// 295. Find Median from Data Stream
// [Heap/priority queue]

class MedianFinder {
public:
    priority_queue<int> maximum;
    priority_queue<int, vector<int>, greater<int>> minimum;
    // initializes the MedianFinder object.
    MedianFinder() {
        maximum = priority_queue<int>();
        minimum = priority_queue < int, vector < int >, greater < int >> ();
    }
    //adds the integer num from the data stream
    void addNum(int num) {
        // Add to maximum heap
        if(maximum.empty() || maximum.top() > num){
            maximum.push(num);
        }else{
            minimum.push(num);
        }
        // balance the queue and size
        if(minimum.size() + 1 < maximum.size()){
            minimum.push(maximum.top());
            maximum.pop();
        }
        if(minimum.size() > 1 + maximum.size()){
            maximum.push(minimum.top());
            minimum.pop();
        }
    }
    // returns the median of all elements
    double findMedian() {
        double results;
        if(maximum.size() == minimum.size()){
            results= (maximum.top() + minimum.top()) / 2.0;
        }
        else if(maximum.size() > minimum.size()){
            results = maximum.top();
        }else{
            results = minimum.top();
        }
        return results;

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */