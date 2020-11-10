#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#pragma warning (disable : 4996)

#define ass_ins assert (lst);           \
                assert (!isnan (num));  

#define ass_del assert (lst);       \
                assert (lst->head); \
                assert (lst->tail);

#define cal element* el_crt = (element*) calloc (1, sizeof (*el_crt));  \
            assert (el_crt);                                            \
            *el_crt = {nullptr, nullptr, num};                          \
            (lst->size)++;

#define del(el_del) el_del->next = nullptr; \
                    el_del->prev = nullptr; \
                    el_del->num  = NAN;     \
                    free (el_del);          \
                    (lst->size)--;

struct element
{
    element* prev = nullptr;
    element* next = nullptr;
    double num = NAN;
};

struct List
{
    element* head = nullptr;
    element* tail = nullptr;
    size_t size = 0;
};

element* InsertEmpty (List* lst, double num);

element* InsertHead (List* lst, double num);

element* InsertTail (List* lst, double num);

element* InsertBefore (List* lst, double num, element* el);

element* InsertAfter (List* lst, double num, element* el);

void DeleteEmpty (List* lst);

void DeleteHead (List* lst);

void DeleteTail (List* lst);

void Delete (List* lst, element* el);

void CreateDumb (List* lst);
