class BrowserHistory {
public:
    //fwdhistory  
    //backwordhis
    //both the history init with homeapage
    //visit : clears fwd history and visit : url adds up to backword his 
    // back :add to fwd and   pop.back()  , if possible k step   : if(vec.size() - step  >=0) vec[vec.size() - step -1 ]
    //fwd : if possible k step 
    //vector<string >backhis ; 
    vector<string>fwd ;
    vector<string>backword ;
    BrowserHistory(string homepage) {
        backword.push_back(homepage);
    }
    
    void visit(string url) {
        fwd.clear(); 
        backword.push_back(url);
    }
    // backword [["leetcode.com"],["google.com"], linkedin
    //fwd :lc , yt  ,fb
    string back(int steps) {
       while(steps >0 && backword.size() > 1){
        steps--;
        fwd.push_back(backword.back());
        backword.pop_back();
       }
       return backword.back();

        
    }
    
    string forward(int steps) {
        string temp = "";
       while(steps>0 && fwd.size() >0){
        backword.push_back(fwd.back());
        fwd.pop_back();
        steps--;
       }
        return backword.back();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */


 // v : lc , google , fb , yt 
 // 