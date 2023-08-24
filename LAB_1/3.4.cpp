#include <iostream>

template <typename Type>
class CVector
{
private:
    Type* m_pVect;
    int m_nCount;
    int m_nMax;
    int m_nDelta;

    void Init(int delta);
    void Resize();

public:
    CVector(int delta = 10);
    ~CVector();
    void Insert(const Type &elem);
    int Size() const; // Agregado el método Size
    Type GetElement(int index) const; // Agregado el método GetElement
};

template <typename Type>
CVector<Type>::CVector(int delta)
{
    Init(delta);
}

template <typename Type>
CVector<Type>::~CVector()
{
    delete[] m_pVect;
}

template <typename Type>
void CVector<Type>::Init(int delta)
{
    m_nCount = 0;
    m_nMax = delta;
    m_nDelta = delta;
    m_pVect = new Type[m_nMax];
}

template <typename Type>
void CVector<Type>::Insert(const Type &elem)
{
    if (m_nCount == m_nMax)
        Resize();
    m_pVect[m_nCount++] = elem;
}

template <typename Type>
void CVector<Type>::Resize()
{
    Type* temp = new Type[m_nMax + m_nDelta];
    for (int i = 0; i < m_nCount; ++i)
    {
        temp[i] = m_pVect[i];
    }
    delete[] m_pVect;
    m_pVect = temp;
    m_nMax += m_nDelta;
}

template <typename Type>
int CVector<Type>::Size() const
{
    return m_nCount;
}

template <typename Type>
Type CVector<Type>::GetElement(int index) const
{
    if (index >= 0 && index < m_nCount)
        return m_pVect[index];
    else
        return Type(); // Return a default value for out-of-bounds index
}

int main()
{
    CVector<int> intVec;
    intVec.Insert(1);
    intVec.Insert(2);
    intVec.Insert(3);

    for (int i = 0; i < intVec.Size(); ++i)
    {
        std::cout << intVec.GetElement(i) << " ";
    }

    CVector<double> doubleVec;
    doubleVec.Insert(1.1);
    doubleVec.Insert(2.2);
    doubleVec.Insert(3.3);

    for (int i = 0; i < doubleVec.Size(); ++i)
    {
        std::cout << doubleVec.GetElement(i) << " ";
    }

    return 0;
}
