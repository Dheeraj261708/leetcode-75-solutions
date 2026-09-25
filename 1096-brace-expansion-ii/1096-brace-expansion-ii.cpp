class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int pos = 0;

        function<set<string>()> parse = [&]() {
            set<string> result = {""};
            while (pos < expression.size() && expression[pos] != '}') {
                set<string> current;
                if (expression[pos] == '{') {
                    pos++; 
                    current = parse();
                    pos++; 
                } 
                else if (expression[pos] == ',') {
                    pos++;
                    set<string> next = parse();
                    result.insert(next.begin(), next.end());
                    return result;
                } 
                else {
                    string s(1, expression[pos]);
                    pos++;
                    current.insert(s);
                }
                set<string> temp;
                for (const string& a : result) {
                    for (const string& b : current) {
                        temp.insert(a + b);
                    }
                }
                result = temp;
            }
            return result;
        };
        set<string> expanded = parse();
        return vector<string>(expanded.begin(), expanded.end());
    }
};