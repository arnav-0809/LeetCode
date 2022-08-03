class MyCalendar {
    class booking{
        public:
            int start,end;
            booking *left = NULL;
            booking *right = NULL;
            booking(int start, int end){
                this->start = start;
                this->end = end;
            }
    };
    
    booking*root;
public:
    MyCalendar() {
        root=new booking(0,0);
    }
    
    bool book(int start, int end) {
        if(root->start==0 && root->end==0){
            root->start=start;
            root->end=end;
            return true;
        }
        return insert(root,start,end);
    }
    
    bool insert(booking*root,int start,int end){
        if(!root)
            return false;
        if(root->start>=end){
            if(root->left)
                return insert(root->left,start,end);
            else{
                root->left=new booking(start,end);
                return true;
            }
        }
        
        if(root->end<=start){
            if(root->right)
                return insert(root->right,start,end);
            else{
                root->right=new booking(start,end);
                return true;
            }
        }
        
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */