template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}