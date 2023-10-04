#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto &x : a)

const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};

// A simple class to represent a file
class File
{
public:
    std::string name;
    std::string content;

    File(std::string name, std::string content) : name(name), content(content) {}
};

// A simple class to represent a node in the distributed file system
class Node
{
public:
    std::map<std::string, File> files;

    void addFile(File file)
    {
        files[file.name] = file;
    }

    File getFile(std::string name)
    {
        return files[name];
    }
};

// A simple class to represent the distributed file system
class DistributedFileSystem
{
public:
    std::map<std::string, Node> nodes;

    void addNode(std::string name, Node node)
    {
        nodes[name] = node;
    }

    Node getNode(std::string name)
    {
        return nodes[name];
    }
};

int main()
{
    // Create some files
    File file1("file1", "This is the content of file1");
    File file2("file2", "This is the content of file2");

    // Create a node and add the files to it
    Node node1;
    node1.addFile(file1);
    node1.addFile(file2);

    // Create the distributed file system and add the node to it
    DistributedFileSystem dfs;
    dfs.addNode("node1", node1);

    // Retrieve a file from the distributed file system
    File retrievedFile = dfs.getNode("node1").getFile("file1");
    std::cout << "Retrieved file content: " << retrievedFile.content << std::endl;

    return 0;
}
