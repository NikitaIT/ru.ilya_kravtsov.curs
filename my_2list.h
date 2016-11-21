#ifndef MY_2LIST
#define MY_2LIST

template< typename T >
class dlist{
public:
    typedef T value_type;
    //typedef Allocator allocator_type;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
private:
    struct Node
    {
        value_type _val;
        Node * _next;
        Node * _prev;
        Node(const value_type &val)
            :_val(val), _next(0),_prev(0)
        {}
        void insert_after( value_type val){
            Node * new_node = new Node(val);
            new_node->_next = _next;
            new_node->_prev = this->Node;
            _next = new_node;
        }
    };
    Node * _head;
    size_type _nelems;
    class iterator{
    public:
        Node * _current;
    public:
        iterator(Node *p) throw():_current(p){}
        bool operator==(const iterator & iter)const throw(){ return _current == iter._current; }
        bool operator!=(const iterator & iter)const throw(){ return !(*this == iter); }
        iterator & operator--(){
            _current = _current->_prev;
            return *this;
        }
        iterator & operator++(){
            _current = _current->_next;
            return *this;
        }
        iterator operator--(int){
            // RAII(захват ресурса есть инициализация)
            iterator temp(*this);
            operator--();
            return temp;
        }
        iterator operator++(int){
            // RAII(захват ресурса есть инициализация)
            iterator temp(*this);
            operator++();
            return temp;
        }
        value_type & operator*()throw(){ return _current->_val; }
        value_type operator*() const{ return _current->_val; }
        value_type operator->(){ return _current->_val; }
        const value_type operator->() const{ return _current->_val; }
    };
    iterator begin() throw(){ return iterator(_head); }
    iterator end() throw(){ return iterator(0); }
public:
    //Конструктор по умолчанию
    dlist() throw():_head(0), _nelems(0){}
    bool empty() const throw(){ return size() == 0; }
    size_type size() const throw(){ return _nelems; }

private:
    Node * last() throw(){
        if(empty()) return 0;
        Node *p = _head;
        while (p->_next)
            p = p->_next;
        return p;
    }
public:


    void push_back(const value_type & val)
    {
        Node *p = last();
        if(!p)
            _head = new Node(val);
        else
        {
            p->_next = new Node(val);
            p->_next->_prev = p;
        }
            ++_nelems;
    }
    void clear() throw(){
        while(_head){
            Node *p = _head->_next;
            delete _head;
            _head = p;
        }
        _nelems = 0;
    }
    void swap(dlist & lst) throw(){
        std::swap(_head, lst._head);
        std::swap(_nelems, lst._nelems);
    }
    void sort();
    ~dlist() throw(){ clear(); }
public:
    bool del(std::size_t nomber)
    {
        iterator b = begin();
        std::size_t i=0;
        for (; ((i < nomber)&&(b != end())); i++) {
            b++;
        }
        if((i == nomber)&&(nomber<_nelems)){
            if((b != begin())&&(b._current->_next != 0)){
                b._current->_prev->_next = b._current->_next;
                b._current->_next->_prev = b._current->_prev;
            } else {
                if(b._current->_next != 0){
                b._current->_next->_prev = 0;
                _head = b._current->_next;
                } else {
                    b._current->_prev->_next = 0;
                }
            }
            _nelems--;
            return 1;
        }
        return 0;
    }
    void console_log(){
        Node *temp = _head;
        for(int i=0;i<_nelems;i++)
        {
            std::cout<< i<< ": " <<temp->_val<< " ";
            temp = temp->_next;
        }
        std::cout<<std::endl;
    }
    void console_log_r(){
        Node *temp = last();
        for(int i=0;i<_nelems;i++)
        {
            std::cout<< i<< ": " <<temp->_val<< " ";
            temp = temp->_prev;
        }
        std::cout<<std::endl;
    }
};
#endif // MY_2LIST

