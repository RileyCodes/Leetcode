class Logger {
public:
    unordered_map<string,int> cooldownCounter;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(cooldownCounter.count(message) > 0)
        {
            //cout << message << endl;
            //cout << "time: " << timestamp << " counter: " << cooldownCounter[message] << endl;
            if(timestamp - cooldownCounter[message] < 10)
                return false;
        }
        cooldownCounter[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */