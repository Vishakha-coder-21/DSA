class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;

        string curr;
        int num = 0;

        for (char c : s) {

            if (isdigit(c))
                num = num * 10 + (c - '0');

            else if (c == '[') {
                st.push({move(curr), num});
                curr.clear();
                num = 0;
            }

            else if (c == ']') {

                auto [prev, k] = move(st.top());
                st.pop();

                prev.reserve(prev.size() + curr.size() * k);

                while (k--)
                    prev += curr;

                curr = move(prev);
            }

            else
                curr += c;
        }

        return curr;
    }
};
