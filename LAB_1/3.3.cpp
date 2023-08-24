#include <iostream>

class CVector
{
private:
    int* m_pVect;  // Pointer to the buffer
    int m_nCount;  // Control how many elements are actually used
    int m_nMax;    // Control how many are allocated as maximum
    int m_nDelta;  // To control the growing

    void Init(int delta);  // Init our private variables, etc
    void Resize();         // Resize the vector when an overflow occurs

public:
    CVector(int delta = 10);  // Constructor
    ~CVector();  // Destructor to release dynamically allocated memory
    void Insert(int elem);    // Insert a new element
    int GetElement(int index) const; // Get an element at a specific index
    int Size() const; // Get the number of elements in the vector
};

CVector::CVector(int delta)
{
    Init(delta);
}

CVector::~CVector()
{
    delete[] m_pVect; // Release the dynamically allocated memory
}

void CVector::Init(int delta)
{
    m_nCount = 0;
    m_nMax = delta;
    m_nDelta = delta;
    m_pVect = new int[m_nMax];
}

void CVector::Insert(int elem)
{
    if (m_nCount == m_nMax) // Verify the overflow
        Resize(); // Resize the vector before inserting elem
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}

void CVector::Resize()
{
    int* temp = new int[m_nMax + m_nDelta];
    for (int i = 0; i < m_nCount; ++i)
    {
        temp[i] = m_pVect[i];
    }
    delete[] m_pVect; // Free the old memory
    m_pVect = temp;
    m_nMax += m_nDelta;
}

int CVector::GetElement(int index) const
{
    if (index >= 0 && index < m_nCount)
        return m_pVect[index];
    else
        return -1; // Return an invalid value for out-of-bounds index
}

int CVector::Size() const
{
    return m_nCount;
}

int main()
{
    CVector vec;

    vec.Insert(1);
    vec.Insert(2);
    vec.Insert(3);

    for (int i = 0; i < vec.Size(); ++i)
    {
        std::cout << vec.GetElement(i) << " ";
    }

    return 0;
}
