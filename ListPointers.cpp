#include "ListPointers.h"

int main ()
{
    List lst = {};
    InsertTail (&lst, 1);
    element* el = InsertTail (&lst, 2);
    InsertTail (&lst, 3);
    InsertTail (&lst, 4);
    InsertBefore (&lst, 1.5, el);
    CreateDumb (&lst);
    return 0;
}

element* InsertEmpty (List* lst, double num)
{
    ass_ins;
    assert (lst->head == nullptr);
    assert (lst->tail == nullptr);

    cal;

    lst->head = el_crt;
    lst->tail = el_crt;

    return el_crt;
}

element* InsertHead (List* lst, double num)
{
    ass_ins;

    if (lst->head == nullptr)
        return InsertEmpty (lst, num);

    assert (lst->head->prev == nullptr);

    cal;

    lst->head->prev = el_crt;
    el_crt->next = lst->head;
    lst->head = el_crt;

    return el_crt;
}

element* InsertTail (List* lst, double num)
{
    ass_ins;

    if (lst->tail == nullptr)
        return InsertEmpty (lst, num);

    assert (lst->tail->next == nullptr);

    cal;

    lst->tail->next = el_crt;
    el_crt->prev = lst->tail;
    lst->tail = el_crt;

    return el_crt;
}

element* InsertBefore (List* lst, double num, element* el)
{
    ass_ins;
    assert (el);

    if (el == lst->head)
        return InsertHead (lst, num);

    assert (el->prev);

    return InsertAfter (lst, num, el->prev);
}

element* InsertAfter (List* lst, double num, element* el)
{
    ass_ins;
    assert (el);

    if (el == lst->tail)
        return InsertTail (lst, num);

    assert (el->next);

    element* el_next = el->next;
    cal;

    el->next      = el_crt;
    el_crt->prev  = el;
    el_next->prev = el_crt;
    el_crt->next  = el_next;

    return el_crt;
}

void DeleteEmpty (List* lst)
{
    ass_del;
    assert (lst->head == lst->tail);

    del (lst->head);
    lst->head = nullptr;
    lst->tail = nullptr;

    return;
}

void DeleteHead (List* lst)
{
    ass_del;

    if (lst->head == lst->tail)
        return DeleteEmpty (lst);

    element* new_head = lst->head->next;
    assert (new_head);

    del (lst->head);
    lst->head = new_head;
    lst->head->prev = nullptr;

    return;
}

void DeleteTail (List* lst)
{
    ass_del;

    if (lst->head == lst->tail)
        return DeleteEmpty (lst);

    element* new_tail = lst->tail->prev;
    assert (new_tail);

    del (lst->tail);
    lst->tail = new_tail;
    lst->tail->next = nullptr;

    return;
}

void Delete (List* lst, element* el)
{
    ass_del;
    assert (el);

    if (lst->head == lst->tail)
    {
        assert (el == lst->head);
        return DeleteEmpty (lst);
    }

    if (lst->head == el)
        return DeleteHead (lst);
    assert (el->prev);

    if (lst->tail == el)
        return DeleteTail (lst);
    assert (el->next);

    el->next->prev = el->prev;
    el->prev->next = el->next;
    del (el);

    return;
}

void CreateDumb (List* lst)
{
    FILE* graph = fopen ("Graph/out.dot", "w");
    fprintf (graph, "digraph G{\n" "rankdir = LR;\n");

    
    element* elem_now = lst->head;

    for (size_t passed_elems = 0; passed_elems < lst->size && elem_now != nullptr; passed_elems++)
    {
        element* elem_near = elem_now->prev;
        double num_near = (elem_near == nullptr) ? NAN : elem_near->num;
        fprintf (graph, "\"%p: %lf\" -> \"%p: %lf\" [label = \"prev\"]", 
            elem_now,  elem_now->num,
            elem_near, num_near);

        elem_near = elem_now->next;
        num_near = (elem_near == nullptr) ? NAN : elem_near->num;
        fprintf (graph, "\"%p: %lf\" -> \"%p: %lf\" [label = \"next\"]", 
            elem_now,  elem_now->num,
            elem_near, num_near);

        elem_now = elem_now->next;
    }

    fprintf (graph, "}");
    fclose (graph);

    system ("dot -Tpng Graph\\out.dot -o Graph\\gr.png");
    system ("start Graph\\gr.png");

    return;
}
