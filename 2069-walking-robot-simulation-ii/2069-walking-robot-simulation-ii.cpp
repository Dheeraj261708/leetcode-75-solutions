class Robot {
    private:
    int w, h;
    int perimeter;
    int pos = 0;
    bool moved = false;
public:
    Robot(int width, int height) : w(width), h(height){
        perimeter = 2 * (w + h - 2);
        
    }
    
    void step(int num) {
        moved = true;
        pos = (pos + num) % perimeter;
        
    }
    
    vector<int> getPos() {
        int curr = pos;
        if (curr < w) {
            return {curr, 0};
        }
        curr -= (w - 1);
        if (curr < h) {
            return {w - 1, curr};
        }
        curr -= (h - 1);
        if (curr < w) {
            return {w - 1 - curr, h - 1};
        }
        curr -= (w - 1);
        return {0, h - 1 - curr};
        
    }
    
    string getDir() {
        if (!moved) {
            return "East";
        }
        if (pos == 0) {
            return "South";
        }
        
        int curr = pos;
        if (curr <= w - 1) {
            return "East";
        }
        if (curr <= w + h - 2) {
            return "North";
        }
        if (curr <= 2 * w + h - 3) {
            return "West";
        }
        return "South";
        
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */