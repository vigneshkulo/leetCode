class Solution {
public:
    string simplifyPath(string path) {
        string delim = "/";
        string output;

        int start = 1;
        int end = path.find(delim, start);
        
        vector<string> pathStack;
        
        do {
            string substr = path.substr(start, end - start);
            if (substr.compare(".") && substr.compare("")) {
                if (!substr.compare("..")) {
                    if (pathStack.size())
                        pathStack.pop_back();
                } else {
                    pathStack.push_back(substr);
                }
            }
            start += substr.length();
            start += delim.length();
            end = path.find(delim, start);
        } while (start < path.length());
        
        for (string item : pathStack) {
            output += "/";
            output += item;
        }
        
        if (pathStack.size()) {
            return output;
        }
        return "/";
    }
};
