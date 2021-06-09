 #ifndef SORTEDLIST_H_ //SortedList.h
 #define SORTEDLIST_H_
#include <iostream>



namespace mtm
{
    class SortedList
    {
        public:
            class const_iterator;

            SortedList(); //constructor
            ~SortedList(); //destructor
            SortedList(const SortedList&); //copy constructor

            SortedList& operator=(const SortedList& other); // list1 = list2;
            void insert(int data);
            //void remove(const_iterator element);
            int length() const;
            
            /*
            apply and filter methodes to be done...
            */

            const_iterator begin() const;
            const_iterator end() const;

            void print() const;

        private:
            class Node;
            Node* head;
            void clearNodes();
    };

    class SortedList::const_iterator
    {
        friend class SortedList;
        const SortedList* list;
        int index;

        const_iterator(const SortedList* list, int index);


        public:
            ~const_iterator() = default;
            const_iterator(const const_iterator& iterator) = default;
            const_iterator& operator=(const const_iterator&) =default;

            const_iterator& operator++(); // Usage: ++ it1 , if out of bound, throw std::out_of_range
            bool operator==(const const_iterator& other) const;
            int operator*() const
            {
                return 0;
            }
    };

    class SortedList::Node
    {
        public:
            Node();
            Node(const int data);
            Node(const Node& node);
            ~Node();
        
            const int data; //int = T
            Node* next;
    };

    /* ********************* */
    /* *LIST IMPLEMENTATION* */
    /* ********************* */
    

    /* Constructor */
    SortedList::SortedList() : head(new Node())
    { }

    /* Destructor */
    SortedList::~SortedList()
    {
        clearNodes();
    }

    /* Copy Constructor */
    SortedList::SortedList(const SortedList& other) : head(new Node())
    {
        Node* ptr = other.head->next;

        while(ptr != nullptr)
        {
            insert(ptr->data);
            ptr = ptr->next;
        }
    }
    
    /* operator = */
    SortedList& SortedList::operator=(const SortedList& other)
    {
        if(this == &other)
        {
            return *this;
        }

        this->clearNodes();

        for (const_iterator it = begin(); ! (it == end()); ++it)
        {
            insert(*it);
        }
        return *this;
    }

    /* Insert */
    void SortedList::insert(int data)
    {
        Node* new_node = new Node(data);
        Node* prev = head;
        Node* current = prev->next;

        while(current != nullptr)
        {
            if(data < current->data)
            {
                prev->next = new_node;
                new_node->next = current;
                return;
            }
            prev = prev->next;
            current = current->next;
        }

        prev->next = new_node;
    }

    /* Length */
    int SortedList::length() const
    {
        Node* ptr = head;
        int count = 0;
        while(ptr->next != nullptr)
        {
            ptr = ptr->next;
            count++;
        }
        return count;
    }

    SortedList::const_iterator SortedList::begin() const
    {
        return const_iterator(this, 1);
    }

    SortedList::const_iterator SortedList::end() const
    {
        return const_iterator(this, this->length() + 1);
    }

    /* delete all the nodes in the list. */
    void SortedList::clearNodes()
    {
        Node* ptr = head;
        
        while(ptr != nullptr)
        {
            Node* next = ptr->next;

            delete ptr;

            ptr = next;
        }
    }

    /* DEBUG ONLY FUNCTIONS*/
    void SortedList::print() const
    {
        Node* ptr = head;
        std::cout << "HEAD -> ";
        for (int i = 0; i < this->length(); i++)
        {
            ptr = ptr->next;
            std::cout << ptr->data << " -> ";
        }
        std::cout << "END(nullptr)" << std::endl; 
    }

    /* ********************* */
    /* *NODE IMPLEMENTATION* */
    /* ********************* */

    /* Constructor */
    SortedList::Node::Node() : data(0), next(nullptr)
    { }

    /* NODE constructor */
    SortedList::Node::Node(const int data) : data(data), next(nullptr)
    {

    }

    /* copy constructor */
    SortedList::Node::Node(const Node& node) : data(node.data), next(node.next)
    {

    }

    /* Destructor */
    SortedList::Node::~Node()
    {
        //auto-call the destructor of data... ( T )
    }

    /* ************************* */
    /* *ITERATOR IMPLEMENTATION* */
    /* ************************* */
    SortedList::const_iterator::const_iterator(const SortedList* list, int index) : list(list), index(index)
    { }

    SortedList::const_iterator& SortedList::const_iterator::operator++()
    {
        index++;
        return *this;
    }

    bool SortedList::const_iterator::operator==(const const_iterator& other) const
    {
        return index == other.index;
    }

}
#endif