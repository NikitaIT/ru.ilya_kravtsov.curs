#ifndef MY_LIST_H
#define MY_LIST_H
#include <algorithm>
template< typename T >
class forward_list{
public:
    typedef T value_type;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
private:
    struct Node
    {
        value_type _val;
        Node * _next;
        Node(const value_type &val)
            :_val(val), _next(0)
        {}
    };
    Node * _head;
    size_type _nelems;
public:
    forward_list() throw():_head(0), _nelems(0){}
    bool empty() const throw(){ return size() == 0; }
    size_type size() const throw(){ return _nelems; }
    Node * last() throw(){
        if(empty()) return 0;
        Node *p = _head;
        while (p->_next)
            p = p->_next;
        return p;
    }
    void push_back(const value_type & val)
    {
        Node *p = last();
        if(!p)
            _head = new Node(val);
        else
            p->_next = new Node(val);
        ++_nelems;
    }
    void pop_front()
    {
        if(!empty())
        {
            _head = _head->_next;
            --_nelems;
        }
    }
    void print(){
        Node * temp = _head;
        for(int i=0;i<_nelems;i++)
        {
            std::cout <<temp->_val << std::endl;
            temp = temp->_next;
        }

    }
    ~forward_list() throw(){ }
};
#endif // MY_LIST_H

