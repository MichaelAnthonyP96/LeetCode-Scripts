class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : window_(), size_(size), oldIdx_(0), windowFull_(false)  {}
    
    double next(int val) {
        double divisor = -1.;
        if (!windowFull_)
        {
            window_.push_back(val);
            divisor = double(window_.size());
            if (window_.size() == size_)
            {
                windowFull_ = true;
            }
        }
        else
        {
            window_[oldIdx_] = val;
            if (++oldIdx_ >= size_)
            {
                oldIdx_ = oldIdx_ % size_;
                
            }
            divisor = double(size_);
        }
        
        double sum = std::accumulate(window_.begin(), window_.end(), 0);
        return (sum / divisor);
    }
private:
    std::vector<int> window_;
    int size_;
    int oldIdx_;
    bool windowFull_;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
