#include <iostream>
#include <cstdlib> // Necesario para realloc

struct Vector
{
    int* m_pVect; // Pointer to the buffer
    int m_nCount; // Control how many elements are actually used
    int m_nMax;   // Control how many are allocated as maximum
    int m_nDelta; // To control the growing
};



void Resize(Vector* pThis)
{
    pThis->m_pVect = (int*)realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta));

    // The Max has to be increased by delta
    pThis->m_nMax += pThis->m_nDelta;
}
void Insert(Vector* pThis, int elem)
{
    if (pThis->m_nCount == pThis->m_nMax) // Verify the overflow
        Resize(pThis); // Resize the vector before inserting elem

    // Insert the element at the end of the sequence
    pThis->m_pVect[pThis->m_nCount++] = elem;
}

int main()
{
    Vector vec;
    vec.m_nCount = 0;
    vec.m_nMax = 2;    
    vec.m_nDelta = 2;   
    vec.m_pVect = (int*)malloc(sizeof(int) * vec.m_nMax);

    Insert(&vec, 1);
    Insert(&vec, 2);
    Insert(&vec, 3);

    for (int i = 0; i < vec.m_nCount; ++i)
    {
        std::cout << vec.m_pVect[i] << " ";
    }

    free(vec.m_pVect); 

    return 0;
}
