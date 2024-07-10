#include <iostream>

using namespace std;

struct Journal
{
    string title;
    vector<string> entries;

    explicit Journal(const string& title) : title{title} {}
};

void Journal::add(const string& entry)
{
    static int count = 1;
    entries.push_back(boost::lexical_cast<string>(count++) + ": " + entry)
}

void Journal::save(const string& filename)
{
    ofstream ofs(filename);
    for (auto& s : entries)
        ofs << s << end;
}

int main() {
    cout << "Hello, World!" << endl;

    return 0;
}
