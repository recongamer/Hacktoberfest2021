#include <new>
#include <vector>
#include <iostream>
using namespace std;
// I am so happy I got templates to work with this!
template <typename T>
class DNode
{
private:
    T element;
    DNode<T> *prev;
    DNode<T> *next;

    // Allows this class to access DLinkedList's private members

    template <typename H> // took me so long to figure out that I need a template
                          // before a friend

    friend class DLinkedList;
};

template <typename T>
class DLinkedList
{

public:
    // Constructor
    DLinkedList<T>()
    {
        header->next = trailer;
        trailer->prev = header;
    }

    // Might not be the best way to do it, but my method of copy-constructing
    // is to store the elements in a vector and retrieve them via a vector as
    // well

    DLinkedList<T>(const DLinkedList &v)
    {
        header->next = trailer;
        trailer->prev = header;

        vector<T> ele = v.get_elements();
        set_elements(ele);
    }

    DLinkedList<T> &operator=(const DLinkedList &v)
    {
        header = new (nothrow) DNode<T>;
        trailer = new (nothrow) DNode<T>;
        header->next = trailer;
        trailer->prev = header;

        vector<T> ele = v.get_elements();
        set_elements(ele);
        return *this;
    }

    // returns a vector of all elements
    vector<T> get_elements() const
    {
        DNode<T> *p = header->next;
        vector<T> elements;
        while (p->next != nullptr)
        {
            elements.push_back(p->element);
            p = p->next;
        }

        return elements;
    }

    void set_elements(vector<T> elementVec)
    {
        for (size_t x = 0; x < elementVec.size(); x++)
        {
            add_back(elementVec.at(x));
        }
    }

    const T &front() const { return header->next->element; } // get front element
    const T &back() const { return trailer->prev->element; } // get back element

    void add_front(const T &e)
    {
        add(header->next, e);
    } // add to front of list

    void add_back(const T &e)
    {
        add(trailer, e);
    } // add to back of list

    void remove_front() { remove(header->next); } // remove front
    void remove_back() { remove(trailer->prev); } // remove back

    bool organized();    // Is the list organzied least to greatest
    void organizeList(); // Organizes list least to greatest

    size_t size();
    DNode<T> *&search(T &val);

    void clear()
    {
        while (!empty())
        {
            remove_front();
        }
    }

    bool empty() const { return header->next == trailer; }

    // beginning of linked list is at index 0
    void swap_elements(size_t pos1, size_t pos2); // Swaps elements given index
    void swap_elements(DNode<T> *v, DNode<T> *w); // Swaps node elements directly

    void print_elements();

    void remove(DNode<T> *v);
    void remove(T key);

    long rand_range(long min, long max)
    {
        return rand() / (RAND_MAX / (max - min + 1) + 1) + min;
    }

private:
    DNode<T> *header = new (std::nothrow) DNode<T>;
    DNode<T> *trailer = new (std::nothrow) DNode<T>;

protected:
    void add(DNode<T> *v, const T &e);
};

// Not useful for this implementation. I made this because I misinterpreted what
// was asked for at first. Runs on O(n^2) time. Pretty bad.
template <typename T>
void DLinkedList<T>::organizeList()
{
    if (size() > 1)
    {
        bool isOrganized = organized();
        DNode<T> *a = header->next;
        DNode<T> *b = header->next->next;

        while (isOrganized == false)
        {
            a = header->next;
            b = header->next->next;
            while (b->next != nullptr)
            {

                if (a->element > b->element)
                {
                    swap_elements(a, b);
                }

                a = a->next;
                b = b->next;
            }

            isOrganized = organized();
        }
    }
}

template <typename T>
void DLinkedList<T>::add(DNode<T> *v, const T &e)
{
    DNode<T> *u = new (nothrow) DNode<T>;
    u->element = e;
    u->prev = v->prev;
    u->next = v;
    v->prev->next = u;
    v->prev = u;
}

template <typename T>
size_t DLinkedList<T>::size()
{
    DNode<T> *p = header->next;
    size_t size = 0;
    while (p->next != nullptr)
    {
        p = p->next;
        size++;
    }

    return size;
}

// takes advantage of things being in order
template <typename T>
DNode<T> *&DLinkedList<T>::search(T &val)
{
    DNode<T> *p = header;

    size_t count = 0;

    if (header->next->element == val)
    {
        return p;
    }

    while (p->next != trailer)
    {
        count++;

        if (p->element == val)
        {
            long dice = rand_range(1, count - 1); // Rolls the dice!
            DNode<T> *b = p;

            for (long x = 0; x < dice; x++)
            {
                b = b->prev;
            }
            // found
            swap_elements(b, p);

            return p;
        }
        p = p->next;
    }

    // not found
    return p;
}

template <typename T>
void DLinkedList<T>::print_elements()
{
    DNode<T> *p = header->next;
    while (p->next != nullptr)
    {
        std::cout << p->element << " ";
        p = p->next;
    }
}

// Not useful for this implementation.
// Returns true if list is organized least to greatest
template <typename T>
bool DLinkedList<T>::organized()
{
    if (header->next == trailer)
    {
        std::cerr << "\n\n\tEmpty list is always organized";
        return true;
    }

    DNode<T> *a = header->next;
    while (a->next->next != nullptr)
    {
        if (a->element > a->next->element)
        {
            return false;
        }
        a = a->next;
    }

    return true;
}

template <typename T>
void DLinkedList<T>::swap_elements(DNode<T> *v, DNode<T> *w)
{
    T temp = v->element;
    v->element = w->element;
    w->element = temp;
}

template <typename T>
void DLinkedList<T>::swap_elements(size_t pos1, size_t pos2)
{ // takes O(n) time
    DNode<T> *a = header->next;
    DNode<T> *b = header->next;

    size_t count1 = 0;
    size_t count2 = 0;
    while (count1 < pos1 && a->next != nullptr)
    {
        a = a->next;
        count1++;
    }

    while (count2 < pos2 && b->next != nullptr)
    {
        b = b->next;
        count2++;
    }

    if (count1 == pos1 && count2 == pos2)
    {
        T temp = a->element;
        a->element = b->element;
        b->element = temp;
    }
    else
    {
        std::cerr << "\n\n\tError: invalid swap position given";
    }
}

template <typename T>
void DLinkedList<T>::remove(DNode<T> *v)
{
    DNode<T> *n = v->next;
    DNode<T> *p = v->prev;

    p->next = n;
    n->prev = p;
    delete v;
}

template <typename T>
void DLinkedList<T>::remove(T key)
{
    DNode<T> *cur = header;

    if (cur->next != nullptr && cur->next->next == trailer && cur->next->element != key)
    {
        return;
    }

    if (cur->next->next != trailer && !empty())
    {
        while (cur->next->element != key)
        {
            if (cur->next == trailer)
                return;
            cur = cur->next;
        }

        if (cur->element == key)
        {
            DNode<T> *n = cur->next;
            DNode<T> *p = cur->prev;
            p->next = n;
            n->prev = p;
            delete cur;
        }
    }
}

int main()
{
    DLinkedList<long> list1;
    cout << "hi";
}