#ifndef NODE
#define NODE

class Node 
{
    private:
    int data;
    Node *link;

    public:
    Node();
    Node(int _data, Node *_link);
    void setData(int _data);
    int getData();
    void setLink(Node * _link);
    Node *getLink();

};

#endif