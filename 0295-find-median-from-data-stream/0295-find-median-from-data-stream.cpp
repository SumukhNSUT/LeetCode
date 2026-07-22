class MedianFinder {
public:

    priority_queue<int> mx; //left
    priority_queue< int, vector<int>, greater<int> > mn; //right
    MedianFinder() {
        
    }
    
    void addNum(int num) { 
        mx.push(num);
        if(!mn.empty() && mx.top() > mn.top()){
            int ele=mx.top();
            mx.pop();
            mn.push(ele);
            if(mn.size() > mx.size()){
                int ele=mn.top();
                mn.pop();
                mx.push(ele);
            }
        }
        if(mx.size() > mn.size()+1){
            int ele=mx.top();
            mx.pop();
            mn.push(ele);
        }   
    }
    
    double findMedian() {
        double ans=-1;
        
        if(mn.size()==mx.size()){
            ans=(mn.top()+mx.top())/2.0;
            return ans;
        }else{
            ans=(double)mx.top();
            return ans;
        }

        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */