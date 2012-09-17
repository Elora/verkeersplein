#ifndef LIST
#define LIST

template <typename T> class List
{
public:
    List();
    void push_front(T);
    void push_back(T);
    void pop_front();
    void pop_back();
    bool komtAlVoor(T);
    T krijgKop();
    T geefPositie(int);
	int krijgGrootte();

private:
    struct lijst{
        T data;
        struct lijst* next;
    };
    struct lijst* kop;
    struct lijst* staart;
    struct lijst* hulp;
	int grootte;
};

#endif
