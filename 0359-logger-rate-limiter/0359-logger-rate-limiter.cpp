class Logger {
  unordered_map<string,int> um;
public:
    Logger() {}
    bool shouldPrintMessage(int timestamp, string message) {
        if(um.find(message)==um.end()){
          um[message]=timestamp+10;
          return true;
        }else if(um[message]<=timestamp){
            um[message]=timestamp+10;
            return true;
        }
        return false;
    }
};