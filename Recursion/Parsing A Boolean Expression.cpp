class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char c : expression) {
            if (c == ',' || c == '(')
                continue;

            if (c != ')') {
                st.push(c);
                continue;
            }

            bool hasTrue = false;
            bool hasFalse = false;

            while (st.top() == 't' || st.top() == 'f') {
                if (st.top() == 't')
                    hasTrue = true;
                else
                    hasFalse = true;
                st.pop();
            }

            char op = st.top();
            st.pop();

            if (op == '!')
                st.push(hasFalse ? 't' : 'f');
            else if (op == '&')
                st.push(hasFalse ? 'f' : 't');
            else
                st.push(hasTrue ? 't' : 'f');
        }

        return st.top() == 't';
    }
};
