/// Name: String Split
/// Description: Split string and return vector with a number of Delimiters
/// Detail: Complexity: O(n)
/// Guarantee: vector<string> strsplit(
vector<string> strsplit(const string &text, const string &delims) {
    int beg, pos = 0;
    vector<string> ret;
    while((beg = text.find_first_not_of(delims, pos)) != string::npos) {
        pos = text.find_first_of(delims, beg+1);
        ret.emplace_back(text.substr(beg, pos - beg));
    }
    return ret;
}