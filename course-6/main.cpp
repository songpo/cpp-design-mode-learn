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

struct PersistenceManager
{
    static void save(const Journal& j, const string& filename)
    {
        ofstream ofs(filename);
        for (auto& s : j.entries)
            ofs << s << endl;
    }
};

int main() {
    cout << "Hello, World!" << endl;

    Journal j{"Dear Diary"};
    j.add("I cried today");
    j.add("I ate a bug");

    return 0;
}
