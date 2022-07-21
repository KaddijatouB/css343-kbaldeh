//
// 295. Find Median from Data Stream
// [Heap/priority queue]
//

class MedianFinder {
public:
    priority_queue<int> maxi;
    priority_queue<int,vector<int>, greater<int>> mini;


    MedianFinder() {

    }

    void addNum(int num) {
        //entering first element
        if(maxi.empty()){
            maxi.push(num);
            return ;
        }
        //entering second element
        if(maxi.size()==1 && mini.empty()){
            mini.push(num);
            if( mini.top()<maxi.top())
            {
                int temp1 =mini.top();
                int temp2 =maxi.top();
                mini.pop();
                maxi.pop();
                mini.push(temp2);
                maxi.push(temp1);

            }
            return;
        }
        // this was for the first two numbers
        // allocate the first two numbers appropriately

        //adding numbers appropriately to the two heaps
        if(num<=maxi.top()){
            maxi.push(num);
        }
        else if(num>maxi.top()){
            mini.push(num);
        }

        // keep their size difference at max 1
        if( mini.size()== maxi.size()+2){
            maxi.push(mini.top());
            mini.pop();
        }
        else if( maxi.size() == mini.size()+2){
            mini.push(maxi.top());
            maxi.pop();
        }
    }

    double findMedian() {


        double ans=0.0;
        //if only one element present
        if(maxi.size()+mini.size() ==1)
            return double(maxi.top());

        if(maxi.size()==mini.size())// even
            return (double)(maxi.top()+ mini.top())/(double)2;

        else{
            if(maxi.size()>mini.size())
                return (double)(maxi.top());
            else
                return (double)(mini.top());

        }
        return ans;
    }


};